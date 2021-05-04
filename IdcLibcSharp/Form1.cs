using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MetroFramework.Forms;


/*
 * If you want to test the application with arguments you can add -gameid, -idctk and -uuid parameters with values in 
 * Project properties->Degub->Command line arguments
 */
namespace IdcLibcSharp
{
    public partial class IDCGamesTools : MetroForm
    {
        [DllImportAttribute("user32.dll")]
        public static extern int SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);
        [DllImportAttribute("user32.dll")]
        public static extern bool ReleaseCapture();

#if WIN64
        [DllImportAttribute("idclib_64.dll")]
        public static extern int getAccessData(int idcgameid, string idctk, string idcuuid,
                    ref int iduser, [Out] StringBuilder usercrc,
                    [Out] StringBuilder language, [Out] StringBuilder country,
                    [Out] StringBuilder currency);

        [DllImportAttribute("idclib_64.dll")]
        public static extern int getUserProfileInfo(int userid, string secret,
            [Out] StringBuilder nick, [Out] StringBuilder email,
            [Out] StringBuilder status, [Out] StringBuilder avatar,
            [Out] StringBuilder custom, [Out] StringBuilder language,
            [Out] StringBuilder country, [Out] StringBuilder currency);
        /*[DllImport("idclib_64.dll", CharSet = CharSet.Unicode)]
        private static extern bool sendNotifications(string msg);*/

        [DllImport("idclib_64.dll")]
        private static extern int activatePurchaseNotifications(string gameId, string gameSecret, PurchaseNotifyCallBack callBack);


        [DllImport("idclib_64.dll", CharSet = CharSet.Unicode)]
        private static extern int shopPurchase(string transactionid, string extra, int userlevel);


        [DllImport("idclib_64.dll", CharSet = CharSet.Unicode)]
        private static extern int directPurchase(string transactionid, float amount, string currencyiso, string description);

        [DllImport("idclib_64.dll", CharSet = CharSet.Ansi)]
        private static extern int closePurchaseTransaction(string userId, string transactionId, string idcPaymentId);
#else
        [DllImportAttribute("idclib.dll")]
        public static extern int getAccessData(int idcgameid, string idctk, string idcuuid,
                    ref int iduser, [Out] StringBuilder usercrc,
                    [Out] StringBuilder language, [Out] StringBuilder country,
                    [Out] StringBuilder currency);

        [DllImportAttribute("idclib.dll")]
        public static extern int getUserProfileInfo(int userid, string secret,
            [Out] StringBuilder nick, [Out] StringBuilder email,
            [Out] StringBuilder status, [Out] StringBuilder avatar,
            [Out] StringBuilder custom, [Out] StringBuilder language,
            [Out] StringBuilder country, [Out] StringBuilder currency);

        [DllImport("idclib.dll")]
        private static extern int activatePurchaseNotifications(string gameId, string gameSecret, PurchaseNotifyCallBack callBack);

        [DllImport("idclib.dll", CharSet = CharSet.Unicode)]
        private static extern int shopPurchase(string transactionid, string extra, int userlevel);


        [DllImport("idclib.dll", CharSet = CharSet.Unicode)]
        private static extern int directPurchase(string transactionid, float amount, string currencyiso, string description);

        [DllImport("idclib.dll", CharSet = CharSet.Ansi)]
        private static extern int closePurchaseTransaction(string userId, string transactionId, string idcPaymentId);
#endif
        public const int WM_NCLBUTTONDOWN = 0xA1;
        public const int HT_CAPTION = 0x2;
        int receivedUserId = -1;

        public IDCGamesTools()
        {
            InitializeComponent();
        }


        private string GetArgValue(string name, string[] commands)
        {
            string value = "";
            string arg = "-" + name;
            int posIniArg;
            int posIniValue;
            int posFinValue;
            string command;

            for (int i = 0; i < commands.Length; i++)
            {
                if (commands[i] == arg)
                {
                    value = commands[i + 1];
                    return value;
                }
                else
                {
                    command = commands[i];
                    posIniArg = command.IndexOf(arg);
                    if (posIniArg >= 0)
                    {
                        posIniValue = posIniArg + arg.Length + 1;
                        posFinValue = command.IndexOf(" ", posIniValue);
                        if (posFinValue >= 0)
                        {
                            value = command.Substring(posIniValue, posFinValue - posIniValue);
                        }
                        else
                        {
                            value = command.Substring(posIniValue);
                        }
                        return value;
                    }
                }
            }

            return value;
        }

        private string GetUtf8String(string text)
        {
            string convertedText = Encoding.UTF8.GetString(Encoding.Default.GetBytes(text));
            return convertedText;
        }


        public int GetInformationForUser(int receivedGameId, string secret)
        {
            int userid = receivedGameId;
            //getUserInfo params
            //int gameid; //already defined in getAccessData params
            StringBuilder nickaux = new StringBuilder(1024);
            StringBuilder emailaux = new StringBuilder(1024);
            StringBuilder statusaux = new StringBuilder(1024);
            StringBuilder avataraux = new StringBuilder(1024);
            StringBuilder customaux = new StringBuilder(1024);
            StringBuilder countryaux = new StringBuilder(1024);
            StringBuilder languageaux = new StringBuilder(3);
            StringBuilder currencyaux = new StringBuilder(3);
            string nick;
            string email;
            string status;
            string avatar;
            string custom;
            string country;
            string language;
            string currency;

            int result;

            string profileInfoString = "nick : {0}" + Environment.NewLine + "email : {1}" + Environment.NewLine + "status : {2}" +
                Environment.NewLine + "avatar : {3}" + Environment.NewLine + "custom : {4}" + Environment.NewLine +
                "country : {5}" + Environment.NewLine + "language : {6}" + Environment.NewLine + "currency : {7}" + Environment.NewLine;
            result = getUserProfileInfo(userid, secret, nickaux, emailaux, statusaux, avataraux, customaux, countryaux, languageaux, currencyaux);
            if (result == 0)
            {
                nick = nickaux.ToString();
                email = emailaux.ToString();
                status = GetUtf8String(statusaux.ToString());
                avatar = avataraux.ToString();
                custom = GetUtf8String(customaux.ToString());
                country = countryaux.ToString();
                language = languageaux.ToString();
                currency = currencyaux.ToString();
                tUserProfileInfo.Text = string.Format(profileInfoString, nick, email, status, avatar, custom, country, language, currency);
            }
            else
            {
                ShowError(string.Format("Error {0} calling getUserProfileInfo", result.ToString()));
            }
            return result;
        }

        public int GetUserIdAndToken(int receivedGameId, string receivedIdctk, string receivedUuid)
        {
            //getAcessData params
            int gameid = receivedGameId;
            string token = receivedIdctk;
            string uuid = receivedUuid;
            int userid = -1;
            StringBuilder usercrcaux = new StringBuilder(1024);
            StringBuilder countryaux = new StringBuilder(1024);
            StringBuilder languageaux = new StringBuilder(3);
            StringBuilder currencyaux = new StringBuilder(3);
            string usercrc;
            /*
             * string country;
             * string language;
             * string currency;*/
            string accessDataText = "Access data for user: {0} (usercrc: {1})";


            int result;
            result = getAccessData(gameid, token, uuid, ref userid, usercrcaux, countryaux, languageaux, currencyaux);
            if (result == 0)
            {
                usercrc = usercrcaux.ToString();
                /*
                 * country = countryaux.ToString();
                 * language = languageaux.ToString();
                 * currency = currencyaux.ToString();
                 */
                receivedUserId = userid;
                ShowInfo(string.Format(accessDataText, userid.ToString(), usercrc));
                tUserId.Text = userid.ToString();
            }
            else
            {
                receivedUserId = -1;
                //lblInfo.Text = "User not found";
                ShowError(string.Format("Error {0} calling getAccessData", result.ToString()));
            }
            return result;
        }


        private void ShowInfo(string text)
        {
            lblInfo.Text = text;
            lblInfo.ForeColor = Color.ForestGreen; //green
        }
        private void ShowError(string text)
        {
            lblInfo.Text = text;
            lblInfo.ForeColor = Color.Red; //red
        }

        private void IDCGamesTools_Load(object sender, EventArgs e)
        {
            string[] args = System.Environment.GetCommandLineArgs();
            string idcgameId = GetArgValue("idcgameid", args);
            string idcidctk = GetArgValue("idctk", args);
            string idcuuid = GetArgValue("idcuuid", args);
            tGameId.Text = idcgameId;
            tIdctk.Text = idcidctk;
            tUuid.Text = idcuuid;

            if (idcgameId == "" && idcidctk == "" && idcuuid == "")
            {
                ShowError("Missing command line arguments");
                return;
            }
            if (idcgameId == "")
            {
                ShowError("Missing -gameid command line argument");
                return;
            }
            if (idcidctk == "")
            {
                ShowError("Missing -idctk command line argument");
                return;
            }
            int gameId;
            try
            {
                gameId = int.Parse(idcgameId);
            }
            catch
            {
                ShowError("Invalid arguments. -gameid parameter should be an integer");
                return;
            }
            GetUserIdAndToken(gameId, idcidctk, idcuuid);
            panelGetAccessData.BringToFront();
            //Debug
            DateTime dt = new DateTime();
            DateTime.TryParse("26/03/2021", out dt);
            if (DateTime.Now < dt)
            {
                tSecret.Text = "11187637358920143fd36b8fb8f24023d334";
            }
        }

        private void CloseButton_Click(object sender, EventArgs e)
        {
            Environment.Exit(Environment.ExitCode);
            Application.Exit();
        }

        private void MinimizeButton_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;
        }


        private void TopBar_Mouse(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                ReleaseCapture();
                SendMessage(Handle, WM_NCLBUTTONDOWN, HT_CAPTION, 0);
            }
        }

        private void BGetUserProfile_Click(object sender, EventArgs e)
        {
            if (receivedUserId != -1)
                GetInformationForUser(Convert.ToInt32(tUserId.Text), tSecret.Text);
            else
                ShowError("Invalid user. Please use getAccessData with correct parameters.");
        }

        private void BGetAccessData_Click(object sender, EventArgs e)
        {
            int gameId;
            try
            {
                gameId = int.Parse(tGameId.Text);
            }
            catch
            {
                ShowError("Invalid arguments. Game Id should be an integer");
                return;
            }
            panelGetAccessData.BringToFront();
            GetUserIdAndToken(gameId, tIdctk.Text, tUuid.Text);

        }


        private void bActivateNotifications_Click(object sender, EventArgs e) {
            if (tGameId.Text == "")
            {
                ShowError("Game is not found, please start the application from the launcher");
                return;
            }
            if (tSecret.Text == "")
            {
                ShowError("Please insert a valid Api Secret");
                return;
            }
            activatePurchaseNotifications(tGameId.Text, tSecret.Text);
        }

        private void tCloseTransaction_Click(object sender, EventArgs e)
        {
            if (tUserId.Text == "")
            {
                ShowError("UserID is not found, please start the application from the launcher");
                return;
            }
            if (tShopTransactionId.Text == "")
            {
                ShowError("Please insert a transactionid");
                return;
            }
            if (tPaymentId.Text == "")
            {
                ShowError("Please insert a paymentid");
                return;
            }
            closeShopTransaction(tUserId.Text, tShopTransactionId.Text, tPaymentId.Text);
        }

        private void bShopPurchase_Click(object sender, EventArgs e)
        {
            if (tShopTransactionId.Text == "")
            {
                ShowError("Please insert a transactionid");
                return;
            }
            string extra = "";
            int userLevel = 0;
            openShopPurchase(tShopTransactionId.Text, extra, userLevel);
        }

        //funcion called whenever a new notification is received
        //data: Json with purchases data information
        //len: length of the json string
        private void OnNotifyMessage(IntPtr data, int len)
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new Action(() => this.OnNotifyMessage(data, len)));
                return;
            }

            if (len > 0)
            {
                var arr = new byte[len];
                Marshal.Copy(data, arr, 0, len);
                var msg = Encoding.Unicode.GetString(arr);
                tReceivedNotifications.AppendText(DateTime.Now.ToShortDateString() + " " + DateTime.Now.ToLongTimeString() + ">" + msg + Environment.NewLine);
            }
        }

        public delegate void PurchaseNotifyCallBack(string userId, string transactionId, string idcPaymentId, IntPtr data, int len);
        private void activatePurchaseNotifications(string gameId, string secret)
        {
            //gameId            - Id for the game in IDCGames portal. Provided by IDCGames
            //gameSecret        - Keyword for game in IDCGames portal. Provided by IDCGames
            //OnPurchaseNotify   - name of the function that will be executed when a notification is received. In order to use it you need to declare a PurchaseNotifyCallBack delegate
            int iRet = activatePurchaseNotifications(tGameId.Text, tSecret.Text, OnPurchaseNotify);
            if (iRet == 0)
            {
                bActivateNotifications.Enabled = false;
            }

        }

        //funcion called whenever a new purchase notification is received
        //userId: User Id in IdcPlatform. Received in IDCLogin
        //transactionID - Game Id for the transaction. Generated by game when transaction is created
        //idcPyamentId: Payment Id assigned by IDCGames to the transaction.
        //data: Json with purchases data information
        //len: length of the json string
        private void OnPurchaseNotify(string userId, string transactionId, string idcPaymentId, IntPtr data, int len)
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new Action(() => this.OnPurchaseNotify(userId, transactionId, idcPaymentId, data, len)));
                return;
            }

            if (len > 0)
            {
                var arr = new byte[len];
                Marshal.Copy(data, arr, 0, len);
                var msg = Encoding.Unicode.GetString(arr).TrimEnd(new Char[] { '\0' });
                tShopTransactionId.Text = transactionId;
                tPaymentId.Text = idcPaymentId;
                tReceivedNotifications.AppendText(DateTime.Now.ToShortDateString() + " " + DateTime.Now.ToLongTimeString() + Environment.NewLine + "Transaction ID: " + transactionId +Environment.NewLine + "Payment ID: " + idcPaymentId + Environment.NewLine + "Purchase data:" + msg + Environment.NewLine + Environment.NewLine);
            }
        }

        private void openShopPurchase(string transactionid, string extra, int userLevel)
        {
            //transactionID - Game Id for the transaction. Generated by game when transaction is requested and received in payment notification
            //extra         - Json with information about transaction, for example, selected items. Check format in documentation.
            //userlevel     - Used if game has different shops for different user levels configured
            int ret = shopPurchase(tShopTransactionId.Text, extra,userLevel);
            if (ret != 0)
            {
                ShowError("Error creating shop transaction");
            }
        }

        private void closeShopTransaction(string userId, string transactionId, string idcPaymentId)
        {
            //userId        - User Id in IdcPlatform. Received in IDCLogin
            //transactionID - Game Id for the transaction. Generated by game when transaction is created and received in payment notification
            //idcPaymentID  - Payment Id assigned by IDCGames to the transaction. Received in payment notification
            int ret = closePurchaseTransaction(userId, transactionId, idcPaymentId);
            if (ret == 0)
            {
                MessageBox.Show("Transaction closed successfully");
            }
            else
            {
                ShowError("Error closing transaction");
            }
        }

    }
}
