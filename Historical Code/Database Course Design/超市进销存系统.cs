using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace 数据库课设
{
    public partial class 超市进销存系统 : Form
    {
        DataView mydv = new DataView();
        public 超市进销存系统()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string user_name = textBox1.Text;
            string mima = textBox2.Text;
            string leixing = comboBox1.Text;
            string usmima="";
            string ab = "false";

            if (leixing == "普通员工")
            {
                SqlConnection con = new SqlConnection();
                con.ConnectionString = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
                //获取数据库连接
                con.Open();
                Console.WriteLine(con);
                SqlCommand com = new SqlCommand();
                com.Connection = con;
                com.CommandType = CommandType.Text;


                com.CommandText = "Select Mima From 员工表 where Sno=" + textBox1.Text;//查询是否是已有供应商供货
                SqlDataReader dr = com.ExecuteReader();//执行查询语句
                while (dr.Read())
                {
                    usmima = dr[0].ToString().Trim();
                    if (usmima == mima)
                    {
                        Hide();
                        //this.Close();
                        普通员工 a = new 普通员工(user_name);
                        a.ShowDialog();
                        ab = "true";
                        break;
                    }
                }
                if (ab == "false")
                {
                    MessageBox.Show("登入失败！！！");
                    textBox1.Text = "";
                    textBox2.Text = "";
                }
            }
            if (leixing == "管理员")
            {
                SqlConnection con = new SqlConnection();
                con.ConnectionString = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
                //获取数据库连接
                con.Open();
                Console.WriteLine(con);
                SqlCommand com = new SqlCommand();
                com.Connection = con;
                com.CommandType = CommandType.Text;


                com.CommandText = "Select Mima From 管理员表 where Mno=" + textBox1.Text;//查询是否是已有供应商供货
                SqlDataReader dr = com.ExecuteReader();//执行查询语句
                while (dr.Read())
                {
                    usmima = dr[0].ToString().Trim();
                    if (usmima == mima)
                    {
                        Hide();
                        //this.Close();
                        管理员 a = new 管理员(user_name);
                        a.ShowDialog();
                        ab = "true";
                        break;
                    }
                }
                if (ab == "false")
                {
                    MessageBox.Show("登入失败！！！");
                    textBox1.Text = "";
                    textBox2.Text = "";
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void 超市进销存系统_Load(object sender, EventArgs e)
        {

        }
    }
}
