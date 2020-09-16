#include "pch.h"
#include "Windows.h"




extern "C" __declspec(dllexport) const char* __stdcall apprun(const char* apidata, const char* pluginkey)
{
	return "";
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:

	default:
		break;
	}
	return TRUE;
}

