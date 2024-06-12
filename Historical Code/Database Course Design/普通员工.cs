using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace 数据库课设
{
    public partial class 普通员工 : Form
    {
        string userno;
        public 普通员工()
        {
            InitializeComponent();
        }

        public 普通员工(string user_name)
        {
            InitializeComponent();
            userno = user_name;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            商品销售 a = new 商品销售();
            a.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            商品查询 a = new 商品查询();
            a.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            进货提醒 a = new 进货提醒();
            a.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            普通员工信息修改 a = new 普通员工信息修改(userno);
            a.ShowDialog();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            超市进销存系统 a = new 超市进销存系统();
            a.ShowDialog();
        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            顾客退货 a = new 顾客退货();
            a.ShowDialog();
        }

        private void 普通员工_Load(object sender, EventArgs e)
        {

        }
    }
}
