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
    public partial class 销售统计 : Form
    {
        DataView mydv = new DataView();
        public 销售统计()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string sql = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            SqlConnection myconn = new SqlConnection(sql); //创建数据库连接对象
            myconn.Open();//打开数据库
            string contain = "select * FROM 出售商品表 where Gno=" + textBox1.Text; //获取TestSave表的数据信息
            SqlCommand cmd = new SqlCommand(contain, myconn); //执行sqlcommand命令，就可以执行sql命令了
            DataSet myds = new DataSet();
            SqlDataAdapter myda = new SqlDataAdapter(cmd);
            myda.Fill(myds, "出售商品表");
            mydv = myds.Tables["出售商品表"].DefaultView;//获得DataView对象mydv;

            dataGridView1.DataSource = mydv;//设置datagridview属性
            dataGridView1.GridColor = Color.RoyalBlue;
            dataGridView1.ScrollBars = ScrollBars.Vertical;
            dataGridView1.CellBorderStyle = DataGridViewCellBorderStyle.Single;

            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            dataGridView1.Columns[0].HeaderCell.Value = "出售商品编号";//重命名列号
            dataGridView1.Columns[1].HeaderCell.Value = "商品编号";
            dataGridView1.Columns[2].HeaderCell.Value = "商品名称";
            dataGridView1.Columns[3].HeaderCell.Value = "商品价格";
            dataGridView1.Columns[4].HeaderCell.Value = "商品数量";
            dataGridView1.Columns[5].HeaderCell.Value = "出售价格";
            dataGridView1.Columns[6].HeaderCell.Value = "出售日期";
            dataGridView1.Columns[7].HeaderCell.Value = "员工编号";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            管理员 a = new 管理员();
            a.ShowDialog();
        }

        private void 销售统计_Load(object sender, EventArgs e)
        {
            string sql = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            SqlConnection myconn = new SqlConnection(sql); //创建数据库连接对象
            myconn.Open();//打开数据库
            string contain = "select * FROM 出售商品表"; //获取TestSave表的数据信息
            SqlCommand cmd = new SqlCommand(contain, myconn); //执行sqlcommand命令，就可以执行sql命令了
            DataSet myds = new DataSet();
            SqlDataAdapter myda = new SqlDataAdapter(cmd);
            myda.Fill(myds, "出售商品表");
            mydv = myds.Tables["出售商品表"].DefaultView;//获得DataView对象mydv;

            dataGridView1.DataSource = mydv;//设置datagridview属性
            dataGridView1.GridColor = Color.RoyalBlue;
            dataGridView1.ScrollBars = ScrollBars.Vertical;
            dataGridView1.CellBorderStyle = DataGridViewCellBorderStyle.Single;

            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            dataGridView1.Columns[0].HeaderCell.Value = "出售商品编号";//重命名列号
            dataGridView1.Columns[1].HeaderCell.Value = "商品编号";
            dataGridView1.Columns[2].HeaderCell.Value = "商品名称";
            dataGridView1.Columns[3].HeaderCell.Value = "商品价格";
            dataGridView1.Columns[4].HeaderCell.Value = "商品数量";
            dataGridView1.Columns[5].HeaderCell.Value = "出售价格";
            dataGridView1.Columns[6].HeaderCell.Value = "出售日期";
            dataGridView1.Columns[7].HeaderCell.Value = "员工编号";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string sql = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            SqlConnection myconn = new SqlConnection(sql); //创建数据库连接对象
            myconn.Open();//打开数据库
            string contain = "select * FROM 出售商品表 where Sno=" + textBox2.Text; //获取TestSave表的数据信息
            SqlCommand cmd = new SqlCommand(contain, myconn); //执行sqlcommand命令，就可以执行sql命令了
            DataSet myds = new DataSet();
            SqlDataAdapter myda = new SqlDataAdapter(cmd);
            myda.Fill(myds, "出售商品表");
            mydv = myds.Tables["出售商品表"].DefaultView;//获得DataView对象mydv;

            dataGridView1.DataSource = mydv;//设置datagridview属性
            dataGridView1.GridColor = Color.RoyalBlue;
            dataGridView1.ScrollBars = ScrollBars.Vertical;
            dataGridView1.CellBorderStyle = DataGridViewCellBorderStyle.Single;

            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            dataGridView1.Columns[0].HeaderCell.Value = "出售商品编号";//重命名列号
            dataGridView1.Columns[1].HeaderCell.Value = "商品编号";
            dataGridView1.Columns[2].HeaderCell.Value = "商品名称";
            dataGridView1.Columns[3].HeaderCell.Value = "商品价格";
            dataGridView1.Columns[4].HeaderCell.Value = "商品数量";
            dataGridView1.Columns[5].HeaderCell.Value = "出售价格";
            dataGridView1.Columns[6].HeaderCell.Value = "出售日期";
            dataGridView1.Columns[7].HeaderCell.Value = "员工编号";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string sql = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            SqlConnection myconn = new SqlConnection(sql); //创建数据库连接对象
            myconn.Open();//打开数据库
            string contain = "select * FROM 出售商品表 where Selldate='" + dateTimePicker1.Value + "'"; //获取TestSave表的数据信息
            SqlCommand cmd = new SqlCommand(contain, myconn); //执行sqlcommand命令，就可以执行sql命令了
            DataSet myds = new DataSet();
            SqlDataAdapter myda = new SqlDataAdapter(cmd);
            myda.Fill(myds, "出售商品表");
            mydv = myds.Tables["出售商品表"].DefaultView;//获得DataView对象mydv;

            dataGridView1.DataSource = mydv;//设置datagridview属性
            dataGridView1.GridColor = Color.RoyalBlue;
            dataGridView1.ScrollBars = ScrollBars.Vertical;
            dataGridView1.CellBorderStyle = DataGridViewCellBorderStyle.Single;

            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            dataGridView1.Columns[0].HeaderCell.Value = "出售商品编号";//重命名列号
            dataGridView1.Columns[1].HeaderCell.Value = "商品编号";
            dataGridView1.Columns[2].HeaderCell.Value = "商品名称";
            dataGridView1.Columns[3].HeaderCell.Value = "商品价格";
            dataGridView1.Columns[4].HeaderCell.Value = "商品数量";
            dataGridView1.Columns[5].HeaderCell.Value = "出售价格";
            dataGridView1.Columns[6].HeaderCell.Value = "出售日期";
            dataGridView1.Columns[7].HeaderCell.Value = "员工编号";
        }
    }
}
