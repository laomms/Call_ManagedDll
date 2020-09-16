using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LoadUnoadDll
{
    public class RemoteLoader : MarshalByRefObject

    {

        private Assembly assembly;

        public void LoadAssembly(string fullName)

        {
            try
            {
                assembly = Assembly.LoadFrom(fullName);
            }
            catch(Exception e)
            {
                MessageBox.Show(e.Message.ToString());
            }
            

        }

        public string FullName
        {
            get { return assembly.FullName; }
        }

    }


}
