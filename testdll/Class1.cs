using RGiesecke.DllExport;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace testdll
{
    public class Class1
    {
		//[DllExport(CallingConvention = CallingConvention.StdCall)]
		//[return: MarshalAs(UnmanagedType.LPStr)]
		public static string apprun(int apidata, [MarshalAs(UnmanagedType.LPStr)] string pluginkey)
		{
			return "abc";
		}

		//      //c# 中加载卸载模式
		//      public static void LoadUnloadDll(string apidata, string pluginkey)
		//      {
		//          AppDomain ad = AppDomain.CreateDomain("AppDomain DLL TEST");
		//          Assembly a = ad.Load(new AssemblyName("testdll"));
		//          object d = a.CreateInstance("testdll.Class1");
		//          Type t = d.GetType();
		//          string result = (string)t.InvokeMember("apprun", BindingFlags.InvokeMethod, null, d, new object[] { apidata, pluginkey });
		//          AppDomain.Unload(ad);
		//      }
	}
}
