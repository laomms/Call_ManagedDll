using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LoadUnoadDll
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            LocalLoader ll = new LocalLoader();

            ll.LoadAssembly("D:\\DigitalAct\\DllUnload\\Debug\\DllUnload.dll");

            label1.Text = ll.FullName;

            //ll.Unload();
            string dllpath = "D:\\DigitalAct\\DllUnload\\Debug\\DllUnload.dll";
            try
            {
                File.Delete(dllpath);
                MessageBox.Show("删除成功");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message.ToString());
                MessageBox.Show(ex.Message.ToString());
                //goto Loop;	
            }

        }
    }
}
