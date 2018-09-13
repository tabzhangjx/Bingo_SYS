using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SYS_Scheduling
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            MessageBox.Show("welcome to Bingo Scheduling System");
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void tabPage2_Click(object sender, EventArgs e)
        {

        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void tabPage3_Click(object sender, EventArgs e)
        {

        }

        private void tabPage4_Click(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void time_input_Paint(object sender, PaintEventArgs e)
        {
            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        string drawText = "双击选择文字";

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }
        int[] a = new int[35];
        

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void panel10_Paint(object sender, PaintEventArgs e)
        {

        }

        private void panel10_Click(object sender, EventArgs e)
        {
            // panel单击事件，变绿色  
            if (a[0] == 0)
            {
                panel10.BackColor = Color.Green;
                a[0] = 1;
            }
            else if (a[0] == 1)
            {
                panel10.BackColor = Color.LightSkyBlue;
                a[0] = 0;
            }

        }

    }
}
