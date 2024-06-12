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
    public partial class 管理员 : Form
    {
        string userno;
        public 管理员()
        {
            InitializeComponent();
        }

        public 管理员(string user_name)
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
            进货管理 a = new 进货管理();
            a.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            超市退货 a = new 超市退货();
            a.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            供应商管理 a = new 供应商管理();
            a.ShowDialog();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            进货提醒 a = new 进货提醒();
            a.ShowDialog();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            销售统计 a = new 销售统计();
            a.ShowDialog();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            管理员信息修改 a = new 管理员信息修改(userno);
            a.ShowDialog();
        }

        private void 管理员_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            超市进销存系统 a = new 超市进销存系统();
            a.ShowDialog();
        }
    }
}
