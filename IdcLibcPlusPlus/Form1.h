#pragma once
#include <Windows.h>
#include <iostream>
#pragma comment(lib, "user32.lib")

BOOL GetProcAddresses(HINSTANCE* hLibrary, LPCWSTR lpszLibrary, INT nCount, ...)
{
	va_list va;
	va_start(va, nCount);

	if ((*hLibrary = LoadLibrary(lpszLibrary))
		!= NULL)
	{
		FARPROC* lpfProcFunction = NULL;
		LPSTR lpszFuncName = NULL;
		INT nIdxCount = 0;
		while (nIdxCount < nCount)
		{
			lpfProcFunction = va_arg(va, FARPROC*);
			lpszFuncName = va_arg(va, LPSTR);
			if ((*lpfProcFunction =
				GetProcAddress(*hLibrary,
					lpszFuncName)) == NULL)
			{
				lpfProcFunction = NULL;
				return FALSE;
			}
			nIdxCount++;
		}
	}
	else
	{
		va_end(va);
		return FALSE;
	}
	va_end(va);
	return TRUE;
}
namespace IdcLibcPlusPlus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Resumen de Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	//public: const int WM_NCLBUTTONDOWN = 0xA1;
	public: const int HT_CAPTION = 0x2;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelTopBlueBar;
	protected:
	private: System::Windows::Forms::Panel^ panelTopBar;
	private: System::Windows::Forms::PictureBox^ pbClose;
	private: System::Windows::Forms::PictureBox^ pbMaximize;
	private: System::Windows::Forms::PictureBox^ pbMinimize;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ bGetProfile;
	private: System::Windows::Forms::Button^ bGetAccessData;
	private: System::Windows::Forms::TextBox^ tDetails;
	private: System::Windows::Forms::TextBox^ tApiSecret;
	private: System::Windows::Forms::TextBox^ tGameId;

	private: System::Windows::Forms::TextBox^ tIdctk;
	private: System::Windows::Forms::TextBox^ tUserId;
	private: System::Windows::Forms::TextBox^ tUuid;
	private: System::Windows::Forms::Label^ lblInfo;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->panelTopBlueBar = (gcnew System::Windows::Forms::Panel());
			this->panelTopBar = (gcnew System::Windows::Forms::Panel());
			this->pbMinimize = (gcnew System::Windows::Forms::PictureBox());
			this->pbMaximize = (gcnew System::Windows::Forms::PictureBox());
			this->pbClose = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->bGetProfile = (gcnew System::Windows::Forms::Button());
			this->bGetAccessData = (gcnew System::Windows::Forms::Button());
			this->tDetails = (gcnew System::Windows::Forms::TextBox());
			this->tApiSecret = (gcnew System::Windows::Forms::TextBox());
			this->tGameId = (gcnew System::Windows::Forms::TextBox());
			this->tIdctk = (gcnew System::Windows::Forms::TextBox());
			this->tUserId = (gcnew System::Windows::Forms::TextBox());
			this->tUuid = (gcnew System::Windows::Forms::TextBox());
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panelTopBar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMinimize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMaximize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbClose))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelTopBlueBar
			// 
			this->panelTopBlueBar->BackColor = System::Drawing::SystemColors::Highlight;
			this->panelTopBlueBar->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelTopBlueBar->Location = System::Drawing::Point(0, 0);
			this->panelTopBlueBar->Name = L"panelTopBlueBar";
			this->panelTopBlueBar->Size = System::Drawing::Size(762, 8);
			this->panelTopBlueBar->TabIndex = 0;
			// 
			// panelTopBar
			// 
			this->panelTopBar->Controls->Add(this->pbMinimize);
			this->panelTopBar->Controls->Add(this->pbMaximize);
			this->panelTopBar->Controls->Add(this->pbClose);
			this->panelTopBar->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelTopBar->Location = System::Drawing::Point(0, 8);
			this->panelTopBar->Name = L"panelTopBar";
			this->panelTopBar->Size = System::Drawing::Size(762, 22);
			this->panelTopBar->TabIndex = 1;
			this->panelTopBar->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panelTopBar_Paint);
			this->panelTopBar->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panelTopBar_MouseMove);
			// 
			// pbMinimize
			// 
			this->pbMinimize->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbMinimize.BackgroundImage")));
			this->pbMinimize->Dock = System::Windows::Forms::DockStyle::Right;
			this->pbMinimize->Location = System::Drawing::Point(687, 0);
			this->pbMinimize->Name = L"pbMinimize";
			this->pbMinimize->Size = System::Drawing::Size(25, 22);
			this->pbMinimize->TabIndex = 0;
			this->pbMinimize->TabStop = false;
			this->pbMinimize->Click += gcnew System::EventHandler(this, &Form1::pbMinimize_Click);
			// 
			// pbMaximize
			// 
			this->pbMaximize->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbMaximize.BackgroundImage")));
			this->pbMaximize->Dock = System::Windows::Forms::DockStyle::Right;
			this->pbMaximize->Location = System::Drawing::Point(712, 0);
			this->pbMaximize->Name = L"pbMaximize";
			this->pbMaximize->Size = System::Drawing::Size(25, 22);
			this->pbMaximize->TabIndex = 1;
			this->pbMaximize->TabStop = false;
			this->pbMaximize->Click += gcnew System::EventHandler(this, &Form1::pbMaximize_Click);
			// 
			// pbClose
			// 
			this->pbClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbClose.BackgroundImage")));
			this->pbClose->Dock = System::Windows::Forms::DockStyle::Right;
			this->pbClose->Location = System::Drawing::Point(737, 0);
			this->pbClose->Name = L"pbClose";
			this->pbClose->Size = System::Drawing::Size(25, 22);
			this->pbClose->TabIndex = 2;
			this->pbClose->TabStop = false;
			this->pbClose->Click += gcnew System::EventHandler(this, &Form1::pbClose_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 30);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(762, 53);
			this->panel1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Candara Light", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(38, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(232, 39);
			this->label1->TabIndex = 0;
			this->label1->Text = L"IDCGames Tools";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 83);
			this->panel2->Name = L"panel2";
			this->panel2->Padding = System::Windows::Forms::Padding(30, 10, 30, 30);
			this->panel2->Size = System::Drawing::Size(762, 401);
			this->panel2->TabIndex = 3;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::LightGray;
			this->panel3->Controls->Add(this->bGetProfile);
			this->panel3->Controls->Add(this->bGetAccessData);
			this->panel3->Controls->Add(this->tDetails);
			this->panel3->Controls->Add(this->tApiSecret);
			this->panel3->Controls->Add(this->tGameId);
			this->panel3->Controls->Add(this->tIdctk);
			this->panel3->Controls->Add(this->tUserId);
			this->panel3->Controls->Add(this->tUuid);
			this->panel3->Controls->Add(this->lblInfo);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->label7);
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(30, 10);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(702, 361);
			this->panel3->TabIndex = 0;
			// 
			// bGetProfile
			// 
			this->bGetProfile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bGetProfile->Location = System::Drawing::Point(488, 155);
			this->bGetProfile->Name = L"bGetProfile";
			this->bGetProfile->Size = System::Drawing::Size(149, 30);
			this->bGetProfile->TabIndex = 15;
			this->bGetProfile->Text = L"Get User Profile";
			this->bGetProfile->UseVisualStyleBackColor = true;
			this->bGetProfile->Click += gcnew System::EventHandler(this, &Form1::bGetProfile_Click);
			// 
			// bGetAccessData
			// 
			this->bGetAccessData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bGetAccessData->Location = System::Drawing::Point(488, 104);
			this->bGetAccessData->Name = L"bGetAccessData";
			this->bGetAccessData->Size = System::Drawing::Size(146, 33);
			this->bGetAccessData->TabIndex = 14;
			this->bGetAccessData->Text = L"Get Access Data";
			this->bGetAccessData->UseVisualStyleBackColor = true;
			this->bGetAccessData->Click += gcnew System::EventHandler(this, &Form1::bGetAccessData_Click);
			// 
			// tDetails
			// 
			this->tDetails->Location = System::Drawing::Point(47, 230);
			this->tDetails->Multiline = true;
			this->tDetails->Name = L"tDetails";
			this->tDetails->Size = System::Drawing::Size(405, 110);
			this->tDetails->TabIndex = 13;
			// 
			// tApiSecret
			// 
			this->tApiSecret->Location = System::Drawing::Point(118, 166);
			this->tApiSecret->Name = L"tApiSecret";
			this->tApiSecret->Size = System::Drawing::Size(122, 20);
			this->tApiSecret->TabIndex = 12;
			// 
			// tGameId
			// 
			this->tGameId->Location = System::Drawing::Point(118, 72);
			this->tGameId->Name = L"tGameId";
			this->tGameId->Size = System::Drawing::Size(66, 20);
			this->tGameId->TabIndex = 11;
			// 
			// tIdctk
			// 
			this->tIdctk->Location = System::Drawing::Point(235, 72);
			this->tIdctk->Name = L"tIdctk";
			this->tIdctk->Size = System::Drawing::Size(217, 20);
			this->tIdctk->TabIndex = 10;
			// 
			// tUserId
			// 
			this->tUserId->Location = System::Drawing::Point(330, 163);
			this->tUserId->Name = L"tUserId";
			this->tUserId->Size = System::Drawing::Size(122, 20);
			this->tUserId->TabIndex = 9;
			// 
			// tUuid
			// 
			this->tUuid->Location = System::Drawing::Point(120, 117);
			this->tUuid->Name = L"tUuid";
			this->tUuid->Size = System::Drawing::Size(333, 20);
			this->tUuid->TabIndex = 8;
			// 
			// lblInfo
			// 
			this->lblInfo->AutoSize = true;
			this->lblInfo->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInfo->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblInfo->Location = System::Drawing::Point(121, 15);
			this->lblInfo->Name = L"lblInfo";
			this->lblInfo->Size = System::Drawing::Size(119, 24);
			this->lblInfo->TabIndex = 7;
			this->lblInfo->Text = L"USER NOT FOUND";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(44, 214);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 13);
			this->label8->TabIndex = 6;
			this->label8->Text = L"DETAILS:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(273, 169);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(54, 13);
			this->label7->TabIndex = 5;
			this->label7->Text = L"USER ID:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(41, 169);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(73, 13);
			this->label6->TabIndex = 4;
			this->label6->Text = L"API SECRET:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(59, 120);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 13);
			this->label5->TabIndex = 3;
			this->label5->Text = L"IDCUUID:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(190, 75);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"IDCTK";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(44, 75);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"IDCGAMEID:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(30, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"INFORMATION:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(762, 484);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panelTopBar);
			this->Controls->Add(this->panelTopBlueBar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->panelTopBar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMinimize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMaximize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbClose))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pbMaximize_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Form1::WindowState == FormWindowState::Normal) {
			Form1::WindowState = FormWindowState::Maximized;
		}
		else {
			Form1::WindowState = FormWindowState::Normal;
		}
	}
private: System::Void pbClose_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void pbMinimize_Click(System::Object^ sender, System::EventArgs^ e) {
	Form1::WindowState = FormWindowState::Minimized;
}
private: System::Void bGetAccessData_Click(System::Object^ sender, System::EventArgs^ e) {
	GetUserIdAndToken(tGameId->Text, tIdctk->Text, tUuid->Text);
}

public: System::Void setidctkvalue(String ^value) {
	tIdctk->Text = value;
}
public: System::Void setgameidvalue(String^ value) {
	tGameId->Text = value;
}
public: System::Void setuuidvalue(String^ value) {
	tUuid->Text = value;
}

public: System::Void GetUserIdAndToken(String ^idcgameid, String ^idctk, String ^idcuuid) {
	idcgameid = idcgameid->Trim();
	idctk = idctk->Trim();
	idcuuid = idcuuid->Trim();
	int gameid;
	int userid;
	String ^NewLine = "\r\n";
	char idctkaux[1024];
	char idcuuidaux[1024];
	char usercrc[1024];
	char country[3];
	char language[3];
	char currency[6];

#if _WIN64
	LPCWSTR libName = L"idclib_64.dll";
#else
	LPCWSTR libName = L"idclib.dll";
#endif

	int result;
	HINSTANCE hLib;
	typedef int (WINAPI* GETACCESSDATA)
		(int, LPCSTR, LPCSTR, int*, char*, LPCSTR, LPCSTR, LPCSTR);
	GETACCESSDATA GetAccessData = NULL;
	if (GetProcAddresses(&hLib, libName, 1, &GetAccessData, "GetAccessData"))
	{
		int gameid = -1;
		/*+
			NewLine + "avatar : {3}" + NewLine + "custom : {4}" + NewLine +
			"country : {5}" + NewLine + "language : {6}" + NewLine + "currency : {7}" + NewLine;*/

		if (tGameId->Text != "") {
			try {
				gameid = System::Int32::Parse(idcgameid);
			}
			catch (std::exception & ex) {
				gameid = -1;
			}
		}
		//char uuidaux[1024] = "6022DAAE-03F7-11E9-BB88-E86A6485A3C7";
		result = 1;
		strcpy (idctkaux,(char*)(void*)Marshal::StringToHGlobalAnsi(idctk));
		strcpy(idcuuidaux, (char*)(void*)Marshal::StringToHGlobalAnsi(idcuuid));
		result = GetAccessData(gameid, idctkaux, idcuuidaux, &userid, usercrc, country, language, currency);
		if (result == 0) {
			tUserId->Text = System::Convert::ToString(userid);
			String ^sUsercrc = gcnew String(usercrc);
			ShowInfo("Access data for user " + tUserId->Text + "(usercrc: " + sUsercrc + ")");
		}
		else {
			ShowError("Error " +System::Convert::ToString(result) + " calling GetAccessData");
		}
	}
}

const wchar_t* GetWC(const char* c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}

private: String ^GetUtf8String(String ^text)
{
	String ^convertedText = System::Text::Encoding::UTF8->GetString(System::Text::Encoding::Default->GetBytes(text));
	return convertedText;
}

String^ UTF8ToString(const char* s) {
	int len = strlen(s);
	array<unsigned char>^ a = gcnew array<unsigned char>(len);
	int i = len;
	while (i-- > 0) {
		a[i] = s[i];
	}
	return System::Text::Encoding::UTF8->GetString(a);
}

public: System::Void GetInformationForUser(String^ userid, String^ secret) {
	userid = userid->Trim();
	secret = secret->Trim();
	String^ NewLine = "\r\n";
	//int userid = 1; //userid is already defined for getAccessData
	char useridaux[1024];
	char secretaux[1024];
	char nick[1024];
	char email[1024];
	char status[1024];
	char avatar[1024];
	char custom[1024];
	char country[3];
	char language[3];
	char currency[6];

#if _WIN64
	LPCWSTR libName = L"idclib_64.dll";
#else
	LPCWSTR libName = L"idclib.dll";
#endif

	int result;
	HINSTANCE hLib;
	typedef int (WINAPI* GETUSERPROFILEINFO)
		(int, LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPCSTR);
	GETUSERPROFILEINFO GetUserProfileInfo = NULL;
	if (GetProcAddresses(&hLib, libName, 1, &GetUserProfileInfo, "GetUserProfileInfo"))
	{
		int iuserid = -1;
		/*+
			NewLine + "avatar : {3}" + NewLine + "custom : {4}" + NewLine +
			"country : {5}" + NewLine + "language : {6}" + NewLine + "currency : {7}" + NewLine;*/

		if (userid != "") {
			try {
				iuserid = System::Int32::Parse(userid);
			}
			catch (std::exception & ex) {
				iuserid = -1;
			}
		}
		//char uuidaux[1024] = "6022DAAE-03F7-11E9-BB88-E86A6485A3C7";
		result = 1;
		strcpy(secretaux, (char*)(void*)Marshal::StringToHGlobalAnsi(secret));
		result = GetUserProfileInfo(iuserid, secretaux, nick, email, status, avatar, custom, country, language, currency);
		if (result == 0) {
			String^ sNick = gcnew String(nick);
			String^ sEmail = gcnew String(email);
			String^ sStatus = GetUtf8String(gcnew String(status));
			String^ sAvatar = gcnew String(avatar);
			String^ sCustom = GetUtf8String(gcnew String(custom));
			//String^ sCustom = UTF8ToString(custom);
			String^ sCountry = gcnew String(country);
			String^ sLanguage = gcnew String(language);
			String^ sCurrency = gcnew String(currency);
			tDetails->Text = ("Nick: " + sNick + NewLine + "Email: " + sEmail + NewLine + "Status: " + sStatus +
				NewLine + "Avatar: " + sAvatar + NewLine + "Custom: " + sCustom + NewLine +
				"Country: " + sCountry + NewLine + "Language: " + sLanguage + NewLine + "Currency: " + sCurrency + NewLine);
		}
		else {
			ShowError("Error " + System::Convert::ToString(result) + " calling GetUserProfileInfo");
		}
	}
}

private: System::Void ShowError(String ^text) {
	lblInfo->Text = text;
	lblInfo->ForeColor = System::Drawing::Color::Red;
}
private: System::Void ShowInfo(String^ text) {
	lblInfo->Text = text;
	lblInfo->ForeColor = System::Drawing::Color::ForestGreen;
}
private: System::Void bGetProfile_Click(System::Object^ sender, System::EventArgs^ e) {
	GetInformationForUser(tUserId->Text, tApiSecret->Text);
}
private: System::Void panelTopBar_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void panelTopBar_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		ReleaseCapture();
		SendMessage(GetActiveWindow(), WM_NCLBUTTONDOWN, HT_CAPTION, 0);
	}
}
};
}
