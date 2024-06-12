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
    public partial class 供应商管理 : Form
    {
        DataView mydv = new DataView();
        public 供应商管理()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            管理员 a = new 管理员();
            a.ShowDialog();
        }

        private void gongying_Load(object sender, EventArgs e)
        {
            string sql = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            SqlConnection myconn = new SqlConnection(sql); //创建数据库连接对象
            myconn.Open();//打开数据库
            string contain = "select * FROM 进货商表"; //获取TestSave表的数据信息
            SqlCommand cmd = new SqlCommand(contain, myconn); //执行sqlcommand命令，就可以执行sql命令了
            DataSet myds = new DataSet();
            SqlDataAdapter myda = new SqlDataAdapter(cmd);
            myda.Fill(myds, "进货商表");
            mydv = myds.Tables["进货商表"].DefaultView;//获得DataView对象mydv;

            dataGridView1.DataSource = mydv;//设置datagridview属性
            dataGridView1.GridColor = Color.RoyalBlue;
            dataGridView1.ScrollBars = ScrollBars.Vertical;
            dataGridView1.CellBorderStyle = DataGridViewCellBorderStyle.Single;

            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            dataGridView1.Columns[0].HeaderCell.Value = "供货商编号";//重命名列号
            dataGridView1.Columns[1].HeaderCell.Value = "进货商名";
            dataGridView1.Columns[2].HeaderCell.Value = "进货商地址";
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
            com.CommandText = "INSERT  INTO 进货商表(Pno,Pname,Padd) VAlUES('" +
                textBox1.Text + "','" + textBox2.Text + "','"
                 + textBox3.Text + "')";//要执行的SQL语句
            SqlDataReader dr = com.ExecuteReader();//执行SQL语句
            dr.Close();//关闭执行
            con.Close();//关闭数据库

            string sql = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            SqlConnection myconn = new SqlConnection(sql); //创建数据库连接对象
            myconn.Open();//打开数据库
            string contain = "select * FROM 进货商表"; //获取TestSave表的数据信息
            SqlCommand cmd = new SqlCommand(contain, myconn); //执行sqlcommand命令，就可以执行sql命令了
            DataSet myds = new DataSet();
            SqlDataAdapter myda = new SqlDataAdapter(cmd);
            myda.Fill(myds, "进货商表");
            mydv = myds.Tables["进货商表"].DefaultView;//获得DataView对象mydv;

            dataGridView1.DataSource = mydv;//设置datagridview属性
            dataGridView1.GridColor = Color.RoyalBlue;
            dataGridView1.ScrollBars = ScrollBars.Vertical;
            dataGridView1.CellBorderStyle = DataGridViewCellBorderStyle.Single;

            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            dataGridView1.Columns[0].HeaderCell.Value = "供货商编号";//重命名列号
            dataGridView1.Columns[1].HeaderCell.Value = "进货商名";
            dataGridView1.Columns[2].HeaderCell.Value = "进货商地址";

            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection();
            con.ConnectionString = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            //获取数据库连接
            con.Open();
            Console.WriteLine(con);
            SqlCommand com = new SqlCommand();
            com.Connection = con;
            com.CommandType = CommandType.Text;
            com.CommandText = "delete from 进货商表 where Pno='" +
                textBox4.Text + "'";//要执行的SQL语句
            SqlDataReader dr = com.ExecuteReader();//执行SQL语句
            dr.Close();//关闭执行
            con.Close();//关闭数据库

            string sql = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            SqlConnection myconn = new SqlConnection(sql); //创建数据库连接对象
            myconn.Open();//打开数据库
            string contain = "select * FROM 进货商表"; //获取TestSave表的数据信息
            SqlCommand cmd = new SqlCommand(contain, myconn); //执行sqlcommand命令，就可以执行sql命令了
            DataSet myds = new DataSet();
            SqlDataAdapter myda = new SqlDataAdapter(cmd);
            myda.Fill(myds, "进货商表");
            mydv = myds.Tables["进货商表"].DefaultView;//获得DataView对象mydv;

            dataGridView1.DataSource = mydv;//设置datagridview属性
            dataGridView1.GridColor = Color.RoyalBlue;
            dataGridView1.ScrollBars = ScrollBars.Vertical;
            dataGridView1.CellBorderStyle = DataGridViewCellBorderStyle.Single;

            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            dataGridView1.Columns[0].HeaderCell.Value = "供货商编号";//重命名列号
            dataGridView1.Columns[1].HeaderCell.Value = "进货商名";
            dataGridView1.Columns[2].HeaderCell.Value = "进货商地址";

            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
        }
    }
}
