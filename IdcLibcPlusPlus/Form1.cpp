#include "Form1.h"
using namespace System;
using namespace System::Windows::Forms;

String ^getArgValue(String ^item, array <String^>^ args) {
	int posIniArg;
	int posIniValue;
	int posFinValue;
	for (int i = 0; i < args->Length; ++i) {
		if (args[i] == "-" + item) {
			if (i + 1 < args->Length) { // Make sure we aren't at the end of argv!
				return args[i+1]; // Increment 'i' so we don't get the argument as the next argv[i].
			}
			else { // Uh-oh, there was no argument to the destination option.
				return "";
			}
		}
		else {
			posIniArg = args[i]->IndexOf("-" + item);
			if (posIniArg >= 0) {
				posIniValue = posIniArg + item->Length + 1;
				if (args[i]->Length < posIniValue + 1) {
					return "";
				}
				posFinValue = args[i]->IndexOf(" ", posIniValue + 1);
				if (posFinValue >= 0)
				{
					return args[i]->Substring(posIniValue, posFinValue - posIniValue);
				}
				else
				{
					return args[i]->Substring(posIniValue);
				}
			}
		}
	}
	return "";
}

[STAThreadAttribute]
int main(array <String^>^ args) {
	String ^idcgameid = getArgValue ("idcgameid",args);
	String ^idctk = getArgValue("idctk", args);
	String ^idcuuid = getArgValue("idcuuid", args);
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	IdcLibcPlusPlus::Form1 form;
	form.setgameidvalue(idcgameid);
	form.setidctkvalue(idctk);
	form.setuuidvalue(idcuuid);
	form.GetUserIdAndToken(idcgameid, idctk, idcuuid);
	Application::Run(% form);
	return 0;
}