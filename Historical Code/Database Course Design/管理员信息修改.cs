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
    public partial class 管理员信息修改 : Form
    {
        DataView mydv = new DataView();
        string userno;
        public 管理员信息修改()
        {
            InitializeComponent();
        }

        public 管理员信息修改(string user_name)
        {
            InitializeComponent();
            userno = user_name;
        }

        private void 管理员信息修改_Load(object sender, EventArgs e)
        {
            string sql = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            SqlConnection myconn = new SqlConnection(sql); //创建数据库连接对象
            myconn.Open();//打开数据库
            string contain = "select * FROM 管理员表 where Mno='" + userno + "'"; //获取TestSave表的数据信息
            SqlCommand cmd = new SqlCommand(contain, myconn); //执行sqlcommand命令，就可以执行sql命令了
            DataSet myds = new DataSet();
            SqlDataAdapter myda = new SqlDataAdapter(cmd);
            myda.Fill(myds, "管理员表");
            mydv = myds.Tables["管理员表"].DefaultView;//获得DataView对象mydv;

            dataGridView1.DataSource = mydv;//设置datagridview属性
            dataGridView1.GridColor = Color.RoyalBlue;
            dataGridView1.ScrollBars = ScrollBars.Vertical;
            dataGridView1.CellBorderStyle = DataGridViewCellBorderStyle.Single;

            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            dataGridView1.Columns[0].HeaderCell.Value = "管理员编号";//重命名列号
            dataGridView1.Columns[1].HeaderCell.Value = "管理员姓名";
            dataGridView1.Columns[2].HeaderCell.Value = "性别";
            dataGridView1.Columns[3].HeaderCell.Value = "出生日期";
            dataGridView1.Columns[4].HeaderCell.Value = "入职时间";
            dataGridView1.Columns[5].HeaderCell.Value = "联系电话";
            dataGridView1.Columns[6].HeaderCell.Value = "登录密码";
            dataGridView1.Columns[7].HeaderCell.Value = "薪资";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            管理员 a = new 管理员();
            a.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection();
            con.ConnectionString = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            //获取数据库连接
            con.Open();
            Console.WriteLine(con);
            SqlCommand com = new SqlCommand();
            com.Connection = con;
            com.CommandType = CommandType.Text;
            com.CommandText = "update 管理员表 set Mima='" + textBox1.Text + "' where Mno='" + userno + "'";//要执行的SQL语句
            SqlDataReader dr = com.ExecuteReader();//执行SQL语句
            dr.Close();//关闭执行
            con.Close();//关闭数据库

            string sql = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            SqlConnection myconn = new SqlConnection(sql); //创建数据库连接对象
            myconn.Open();//打开数据库
            string contain = "select * FROM 管理员表 where Mno='" + userno + "'"; //获取TestSave表的数据信息
            SqlCommand cmd = new SqlCommand(contain, myconn); //执行sqlcommand命令，就可以执行sql命令了
            DataSet myds = new DataSet();
            SqlDataAdapter myda = new SqlDataAdapter(cmd);
            myda.Fill(myds, "管理员表");
            mydv = myds.Tables["管理员表"].DefaultView;//获得DataView对象mydv;

            dataGridView1.DataSource = mydv;//设置datagridview属性
            dataGridView1.GridColor = Color.RoyalBlue;
            dataGridView1.ScrollBars = ScrollBars.Vertical;
            dataGridView1.CellBorderStyle = DataGridViewCellBorderStyle.Single;

            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            dataGridView1.Columns[0].HeaderCell.Value = "管理员编号";//重命名列号
            dataGridView1.Columns[1].HeaderCell.Value = "管理员姓名";
            dataGridView1.Columns[2].HeaderCell.Value = "性别";
            dataGridView1.Columns[3].HeaderCell.Value = "出生日期";
            dataGridView1.Columns[4].HeaderCell.Value = "入职时间";
            dataGridView1.Columns[5].HeaderCell.Value = "联系电话";
            dataGridView1.Columns[6].HeaderCell.Value = "登录密码";
            dataGridView1.Columns[7].HeaderCell.Value = "薪资";
        }
    }
}
