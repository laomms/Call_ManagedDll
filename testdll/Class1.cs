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

		public static string apprun2(int apidata, [MarshalAs(UnmanagedType.LPStr)] string pluginkey)
		{
			int n = apidata + 0x210;
			return pluginkey + "-" + n.ToString("X2");
		}


		[DllExport(CallingConvention = CallingConvention.StdCall)]
		[return: MarshalAs(UnmanagedType.LPStr)]
		public static string apprun(int apidata, [MarshalAs(UnmanagedType.LPStr)] string pluginkey)
		{
			int n = apidata + 0x210;
			return pluginkey +"-" + n.ToString("X2");
		}

		
	}
}
