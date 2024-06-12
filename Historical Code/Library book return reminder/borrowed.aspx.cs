using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class borrowed : BasePage
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            GetData();
        }

    }
    protected void GetData()
    {
        SqlConnection con = new SqlConnection();        //定义数据库连接对象
        con.ConnectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;  //定义数据库连接字符串
        con.Open();

        SqlCommand com1 = new SqlCommand();              //定义数据库操作命令对象
        com1.Connection = con;                           //连接数据库
        com1.CommandText = "select booknum from person where personid = '" + HttpContext.Current.User.Identity.Name.ToString() + "' ";
        com1.CommandType = CommandType.Text;
        int i = Convert.ToInt32(com1.ExecuteScalar());//返回查询结果的第一行第一列
        if (i == 0)
        {
            message1.Text = "您还没有借阅图书！";
        }
        else
        {
            SqlCommand com = new SqlCommand();              //定义数据库操作命令对象
            com.Connection = con;                           //连接数据库
            com.CommandText = "select bookid,bookname,author,printhouse,borrowedtime,ruturntime from Book where borrowedid = '" + HttpContext.Current.User.Identity.Name.ToString() + "'"; //定义执行查询操作的sql语句
            SqlDataAdapter da = new SqlDataAdapter();       //创建数据适配器对象
            da.SelectCommand = com;                         //执行数据库操作命令
            DataSet ds = new DataSet();                     //创建数据集对象
            da.Fill(ds, "customers");                        //填充数据集
            showBooks.DataSource = ds.Tables["Customers"].DefaultView;//设置gridview控件的数据源为创建的数据集ds
            showBooks.DataBind();                           //绑定数据库表中数据
        }

    }
}