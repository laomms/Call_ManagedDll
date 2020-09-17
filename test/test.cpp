#include "Windows.h"
#include <iostream>
#include <tchar.h>
#include<cstdio>
#include <unordered_map>
using namespace std;


typedef const char* (__stdcall *apprun)(int apidata, const char* pluginkey);

int _tmain(int argc, _TCHAR* argv[])
{

	HMODULE hModule = LoadLibrary(L"D:\\DigitalAct\\DllUnload\\Debug\\DllUnload.dll");	
	if (hModule != NULL)
	{
		apprun pAppRun = (apprun)GetProcAddress(hModule, "apprun");
		const char* ss= pAppRun(123,"456");
		cout << ss << endl;
		pAppRun = NULL;
		ss = NULL;
		FreeLibrary(hModule);
	}    


	const char* savePath = "D:\\DigitalAct\\DllUnload\\Debug\\DllUnload.dll";
	int res = remove(savePath);
	if (res == 0)
	{
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "删除失败" << endl;
	}
	system("pause");
	return 0;
}


