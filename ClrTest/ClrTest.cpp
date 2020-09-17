#include "pch.h"

#using <D:\\DigitalAct\\DllUnload\\Debug\\DllUnload.dll>

using namespace System;
using namespace System::Runtime::InteropServices; 
using namespace testdll;

int main(array<System::String ^> ^args)
{
    Class1^ pInstance = gcnew Class1();
    String^ rez = pInstance->apprun2(0x123, "456");
    Console::WriteLine(rez);
    Console::ReadLine();
    return 0;
}
