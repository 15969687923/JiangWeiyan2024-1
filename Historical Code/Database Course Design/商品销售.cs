using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Data.OleDb;

namespace 数据库课设
{
    public partial class 商品销售 : Form
    {
        DataView mydv = new DataView();
        public 商品销售()
        {
            InitializeComponent();
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void xiaoshou_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“数据库课设DataSet1.出售商品表”中。您可以根据需要移动或删除它。
            //this.出售商品表TableAdapter.Fill(this.数据库课设DataSet1.出售商品表);
            // TODO: 这行代码将数据加载到表“数据库课设DataSet.商品表”中。您可以根据需要移动或删除它。
            //this.商品表TableAdapter.Fill(this.数据库课设DataSet.商品表);
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

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView1_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
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
            //com.CommandText = "INSERT  INTO 出售商品表(Sellnum,Gno,Gname,Gp,Amount,Smonedy,Selldate,Sno) VAlUES('" +
            //    textBox1.Text + "','" + textBox2.Text + "','"
            //     + textBox3.Text + "'," + "(select Gp from 商品表 where " + textBox2.Text + " = 商品表.Gno)" + "," + textBox4.Text + "," +
            //     textBox5.Text + ",'" + dateTimePicker1.Value + "','" + "001" + "')";//要执行的SQL语句
            //SqlDataReader dr = com.ExecuteReader();//执行SQL语句

            com.CommandText = "Select Gam From 商品表 where Gno=" + textBox2.Text;
            SqlDataReader dr = com.ExecuteReader();//执行spl语句
            string numm,numm1;
            int num1,num2,num3;
            while (dr.Read())
            {
                numm = dr[0].ToString().Trim();
                int.TryParse(numm, out num1);
                numm1 = textBox4.Text;
                int.TryParse(numm1, out num2);
                num3 = num1 - num2;
                if (num3 >= 0)
                {
                    dr.Close();//关闭执行
                    com.CommandText = "update 商品表 set Gam=" + num3 + " where Gno='" + textBox2.Text + "'";//要执行的SQL语句
                    dr = com.ExecuteReader();//执行SQL语句

                    dr.Close();//关闭执行
                    com.CommandText = "INSERT  INTO 出售商品表(Sellnum,Gno,Gname,Gp,Amount,Smonedy,Selldate,Sno) VAlUES('" +
                        textBox1.Text + "','" + textBox2.Text + "','"
                         + textBox3.Text + "'," + "(select Gp from 商品表 where " + textBox2.Text + " = 商品表.Gno)" + "," + textBox4.Text + "," +
                         textBox5.Text + ",'" + dateTimePicker1.Value + "','" + "001" + "')";//要执行的SQL语句
                    dr = com.ExecuteReader();//执行SQL语句
                }
                else
                {
                    MessageBox.Show("库存不足！！！");
                    textBox1.Text = "";
                    textBox2.Text = "";
                    textBox3.Text = "";
                    textBox4.Text = "";
                    textBox5.Text = "";
                }
            }

            dr.Close();//关闭执行
            con.Close();//关闭数据库


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

            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            普通员工 a = new 普通员工();
            a.ShowDialog();
        }
    }
}
