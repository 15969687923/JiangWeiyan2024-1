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
    public partial class 进货提醒 : Form
    {
        DataView mydv = new DataView();
        public 进货提醒()
        {
            InitializeComponent();
        }

        private void tixing_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“数据库课设DataSet3.商品表”中。您可以根据需要移动或删除它。
            //this.商品表TableAdapter.Fill(this.数据库课设DataSet3.商品表);

            string sql = "server=.;database=数据库课设;uid=sa;pwd=root";//获得连接数据的基本信息
            SqlConnection myconn = new SqlConnection(sql); //创建数据库连接对象
            myconn.Open();//打开数据库
            string contain = "select * FROM 商品表 where Gam<10"; //获取TestSave表的数据信息
            SqlCommand cmd = new SqlCommand(contain, myconn); //执行sqlcommand命令，就可以执行sql命令了
            DataSet myds = new DataSet();
            SqlDataAdapter myda = new SqlDataAdapter(cmd);
            myda.Fill(myds, "商品表");
            mydv = myds.Tables["商品表"].DefaultView;//获得DataView对象mydv;

            dataGridView1.DataSource = mydv;//设置datagridview属性
            dataGridView1.GridColor = Color.RoyalBlue;
            dataGridView1.ScrollBars = ScrollBars.Vertical;
            dataGridView1.CellBorderStyle = DataGridViewCellBorderStyle.Single;
            //dataGridView1.Columns[0].AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            //dataGridView1.Columns[1].AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            //dataGridView1.Columns[2].AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            //dataGridView1.Columns[3].AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            //dataGridView1.Columns[4].AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            //dataGridView1.Columns[5].AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;

            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.ColumnHeader;

            dataGridView1.Columns[0].HeaderCell.Value = "商品编号";//重命名列号
            dataGridView1.Columns[1].HeaderCell.Value = "商品名称";
            dataGridView1.Columns[2].HeaderCell.Value = "商品类别";
            dataGridView1.Columns[3].HeaderCell.Value = "商品价格";
            dataGridView1.Columns[4].HeaderCell.Value = "商品库存";
            dataGridView1.Columns[5].HeaderCell.Value = "供应商编号"; 

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Hide();
            //this.Close();
            管理员 a = new 管理员();
            a.ShowDialog();
        }
    }
}
