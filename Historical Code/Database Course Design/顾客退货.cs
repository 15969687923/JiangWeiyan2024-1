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
    public partial class 顾客退货 : Form
    {
        DataView mydv = new DataView();
        public 顾客退货()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            普通员工 a = new 普通员工();
            a.ShowDialog();
        }

        private void gktuihuo_Load(object sender, EventArgs e)
        {
            string sql = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            SqlConnection myconn = new SqlConnection(sql); //创建数据库连接对象
            myconn.Open();//打开数据库
            string contain = "select * FROM 顾客退货表"; //获取TestSave表的数据信息
            SqlCommand cmd = new SqlCommand(contain, myconn); //执行sqlcommand命令，就可以执行sql命令了
            DataSet myds = new DataSet();
            SqlDataAdapter myda = new SqlDataAdapter(cmd);
            myda.Fill(myds, "顾客退货表");
            mydv = myds.Tables["顾客退货表"].DefaultView;//获得DataView对象mydv;

            dataGridView1.DataSource = mydv;//设置datagridview属性
            dataGridView1.GridColor = Color.RoyalBlue;
            dataGridView1.ScrollBars = ScrollBars.Vertical;
            dataGridView1.CellBorderStyle = DataGridViewCellBorderStyle.Single;

            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            dataGridView1.Columns[0].HeaderCell.Value = "退货编号";//重命名列号
            dataGridView1.Columns[1].HeaderCell.Value = "商品编号";
            dataGridView1.Columns[2].HeaderCell.Value = "商品单价";
            dataGridView1.Columns[3].HeaderCell.Value = "退货数量";
            dataGridView1.Columns[4].HeaderCell.Value = "退货总价";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection();
            con.ConnectionString = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            //获取数据库连接
            con.Open();
            Console.WriteLine(con);
            SqlCommand com = new SqlCommand();
            com.Connection = con;
            com.CommandType = CommandType.Text;
            //com.CommandText = "INSERT  INTO 顾客退货表(Regnum,Gno,Gp,Amount,Regmoney) VAlUES('" +
            //    textBox1.Text + "','" + textBox2.Text + "','"
            //     + textBox3.Text + "','" + textBox4.Text + "','" +
            //     textBox5.Text + "')";//要执行的SQL语句
            //SqlDataReader dr = com.ExecuteReader();//执行SQL语句

            com.CommandText = "Select Gam From 商品表 where Gno=" + textBox2.Text;
            SqlDataReader dr = com.ExecuteReader();//执行spl语句
            string numm, numm1;
            int num1, num2, num3;
            while (dr.Read())
            {
                numm = dr[0].ToString().Trim();
                int.TryParse(numm, out num1);
                numm1 = textBox4.Text;
                int.TryParse(numm1, out num2);
                num3 = num1 + num2;
                if (num3 >= 0)
                {
                    dr.Close();//关闭执行
                    com.CommandText = "update 商品表 set Gam=" + num3 + " where Gno='" + textBox2.Text + "'";//要执行的SQL语句
                    dr = com.ExecuteReader();//执行SQL语句

                    dr.Close();//关闭执行
                    com.CommandText = "INSERT  INTO 顾客退货表(Regnum,Gno,Gp,Amount,Regmoney) VAlUES('" +
                        textBox1.Text + "','" + textBox2.Text + "','"
                         + textBox3.Text + "','" + textBox4.Text + "','" +
                         textBox5.Text + "')";//要执行的SQL语句
                    dr = com.ExecuteReader();//执行SQL语句
                }
            }

            dr.Close();//关闭执行
            con.Close();//关闭数据库

            string sql = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            SqlConnection myconn = new SqlConnection(sql); //创建数据库连接对象
            myconn.Open();//打开数据库
            string contain = "select * FROM 顾客退货表"; //获取TestSave表的数据信息
            SqlCommand cmd = new SqlCommand(contain, myconn); //执行sqlcommand命令，就可以执行sql命令了
            DataSet myds = new DataSet();
            SqlDataAdapter myda = new SqlDataAdapter(cmd);
            myda.Fill(myds, "顾客退货表");
            mydv = myds.Tables["顾客退货表"].DefaultView;//获得DataView对象mydv;

            dataGridView1.DataSource = mydv;//设置datagridview属性
            dataGridView1.GridColor = Color.RoyalBlue;
            dataGridView1.ScrollBars = ScrollBars.Vertical;
            dataGridView1.CellBorderStyle = DataGridViewCellBorderStyle.Single;

            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            dataGridView1.Columns[0].HeaderCell.Value = "退货编号";//重命名列号
            dataGridView1.Columns[1].HeaderCell.Value = "商品编号";
            dataGridView1.Columns[2].HeaderCell.Value = "商品单价";
            dataGridView1.Columns[3].HeaderCell.Value = "退货数量";
            dataGridView1.Columns[4].HeaderCell.Value = "退货总价";
        }
    }
}
