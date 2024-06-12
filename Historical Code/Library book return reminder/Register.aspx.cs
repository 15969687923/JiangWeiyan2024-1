using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Register : BasePage
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void CreateUserWizard1_CreatedUser(object sender, EventArgs e)
    {
        
    }

    protected void ContinueButton_Click(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection();        //定义数据库连接对象
        con.ConnectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;  //定义数据库连接字符串
        con.Open();

        SqlCommand com1 = new SqlCommand();              //定义数据库操作命令对象
        com1.Connection = con;                           //连接数据库
        com1.CommandText = "insert into person(personid,ifadministrator,booknum,maxbooknum) values ('" + HttpContext.Current.User.Identity.Name.ToString() + "','0','0','5')";
        com1.CommandType = CommandType.Text;
        com1.ExecuteNonQuery();//执行sql语句
    }
}