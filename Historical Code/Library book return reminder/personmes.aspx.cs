using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class personmes : BasePage
{
    protected void Page_Load(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection();        //定义数据库连接对象
        con.ConnectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;  //定义数据库连接字符串
        con.Open();

        SqlCommand com1 = new SqlCommand();              //定义数据库操作命令对象
        com1.Connection = con;                           //连接数据库
        com1.CommandText = "select personname from person where personid='" + HttpContext.Current.User.Identity.Name.ToString() + "'";
        com1.CommandType = CommandType.Text;
        String name = Convert.ToString(com1.ExecuteScalar());//返回查询结果的第一行第一列
        nowname.Text = name;

        SqlCommand com2 = new SqlCommand();              //定义数据库操作命令对象
        com2.Connection = con;                           //连接数据库
        com2.CommandText = "select password from person where personid='" + HttpContext.Current.User.Identity.Name.ToString() + "'";
        com2.CommandType = CommandType.Text;
        String pw = Convert.ToString(com2.ExecuteScalar());//返回查询结果的第一行第一列
        nowpw.Text = pw;
    }
    protected void mesname(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection();        //定义数据库连接对象
        con.ConnectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;  //定义数据库连接字符串
        con.Open();

        SqlCommand com1 = new SqlCommand();              //定义数据库操作命令对象
        com1.Connection = con;                           //连接数据库
        com1.CommandText = "update person set personname='"+ personname.Text + "' where personid='" + HttpContext.Current.User.Identity.Name.ToString() + "'";
        com1.CommandType = CommandType.Text;
        com1.ExecuteNonQuery();//返回查询结果的第一行第一列

        ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('修改姓名为\"" + personname.Text + "\"成功');window.location.reload(); ", true);
    }

    protected void mespassword(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection();        //定义数据库连接对象
        con.ConnectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;  //定义数据库连接字符串
        con.Open();

        SqlCommand com1 = new SqlCommand();              //定义数据库操作命令对象
        com1.Connection = con;                           //连接数据库
        com1.CommandText = "update person set password='" + personpw.Text + "' where personid='" + HttpContext.Current.User.Identity.Name.ToString() + "'";
        com1.CommandType = CommandType.Text;
        com1.ExecuteNonQuery();//返回查询结果的第一行第一列

        ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('修改密码为\"" + personpw.Text + "\"成功');window.location.reload(); ", true);
    }
}