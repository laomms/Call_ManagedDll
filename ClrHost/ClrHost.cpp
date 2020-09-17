#include <windows.h>
#include <comdef.h>
#include <mscoree.h> 
#include <metahost.h>
#include <string>
#include <iostream>  
#include <fstream>  

#pragma comment(lib, "mscoree.lib")  

#import <mscorlib.tlb> raw_interfaces_only			\
    	high_property_prefixes("_get","_put","_putref")		\
    	rename("ReportEvent", "InteropServices_ReportEvent")	\
	rename("or", "InteropServices_or")

using namespace mscorlib;
using namespace std;

char* readFileBytes(const char* name)
{
    ifstream fl(name);
    fl.seekg(0, ios::end);
    size_t len = fl.tellg();
    char* ret = new char[len];
    fl.seekg(0, ios::beg);
    fl.read(ret, len);
    fl.close();
    return ret;
}

int main()
{
    PCWSTR pszVersion = L"v4.0.30319";
    PCWSTR pszAssemblyName = L"DllUnload";
    PCWSTR ClassName = L"testdll.Class1";
    PCWSTR MethodName = L"apprun2";
    int Agr1 = 0x123;
    const char* Agr2 = "456";

    HRESULT hr;
    ICLRMetaHost* pMetaHost = NULL;
    ICLRRuntimeInfo* pRuntimeInfo = NULL;
    ICorRuntimeHost* pCorRuntimeHost = NULL;
    IUnknownPtr spAppDomainThunk = NULL;
    _AppDomainPtr spDefaultAppDomain = NULL;
    bstr_t bstrAssemblyName(pszAssemblyName);
    _AssemblyPtr spAssembly = NULL;
    bstr_t bstrClassName(ClassName);
    _TypePtr spType = NULL;
    variant_t vtEmpty;
    bstr_t bstrStaticMethodName(MethodName);
    variant_t vtLengthRet;
    hr = CLRCreateInstance(CLSID_CLRMetaHost, IID_PPV_ARGS(&pMetaHost));
    hr = pMetaHost->GetRuntime(pszVersion, IID_PPV_ARGS(&pRuntimeInfo));
    BOOL fLoadable;
    hr = pRuntimeInfo->IsLoadable(&fLoadable);

    hr = pRuntimeInfo->GetInterface(CLSID_CorRuntimeHost, IID_PPV_ARGS(&pCorRuntimeHost));
    hr = pCorRuntimeHost->Start();
    hr = pCorRuntimeHost->GetDefaultDomain(&spAppDomainThunk);
    hr = spAppDomainThunk->QueryInterface(IID_PPV_ARGS(&spDefaultAppDomain));


    hr = spDefaultAppDomain->Load_2(bstrAssemblyName, &spAssembly);
    hr = spAssembly->GetType_2(bstrClassName, &spType);

    SAFEARRAY* pArguments = NULL;
    pArguments = SafeArrayCreateVector(VT_VARIANT, 0, 2);
    LONG AgrIndex = 0;
    variant_t  vtIntArg(Agr1);
    hr = SafeArrayPutElement(pArguments, &AgrIndex, &vtIntArg);

    AgrIndex = 1;
    variant_t vtStringArg(Agr2);
    hr = SafeArrayPutElement(pArguments, &AgrIndex, &vtStringArg);

    variant_t vtStringRet;
    hr = spType->InvokeMember_3(bstrStaticMethodName, static_cast<BindingFlags>(BindingFlags_InvokeMethod | BindingFlags_Static | BindingFlags_Public), NULL, vtEmpty, pArguments, &vtStringRet);
    if (FAILED(hr))
    {
        wprintf(L"Failed to invoke GetStringLength w/hr 0x%08lx\n", hr);
    }
    wprintf(L"Call %s.%s(%d,%s) => %s\n", static_cast<PCWSTR>(bstrClassName), static_cast<PCWSTR>(bstrStaticMethodName), vtIntArg.bVal, static_cast<PCWSTR>(vtStringArg.bstrVal), static_cast<PCWSTR>(vtStringRet.bstrVal));

    spType.Release();
    spAssembly.Release();
    spDefaultAppDomain.Release();
    spAppDomainThunk.Release();    
    if (pArguments)
    {
        SafeArrayDestroy(pArguments);
        pArguments = NULL;
    }
    if (pMetaHost)
    {
        pMetaHost->Release();
        pMetaHost = NULL;
    }
    if (pRuntimeInfo)
    {
        pRuntimeInfo->Release();
        pRuntimeInfo = NULL;
    }
    pCorRuntimeHost->Stop();
    if (pCorRuntimeHost)
    {
        pCorRuntimeHost->Release();
        pCorRuntimeHost = NULL;
    }
	system("pause");
	return 0;
}

