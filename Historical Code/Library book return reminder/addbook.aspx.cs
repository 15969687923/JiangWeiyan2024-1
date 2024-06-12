using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class addbook : BasePage
{
    protected void Page_Load(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection();        //定义数据库连接对象
        con.ConnectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;  //定义数据库连接字符串
        con.Open();

        SqlCommand com1 = new SqlCommand();              //定义数据库操作命令对象
        com1.Connection = con;                           //连接数据库
        com1.CommandText = "select ifadministrator from person where personid = '" + HttpContext.Current.User.Identity.Name.ToString() + "'";
        com1.CommandType = CommandType.Text;
        int j = Convert.ToInt32(com1.ExecuteScalar());//返回查询结果的第一行第一列

        if (j == 0)
        {
            ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('抱歉您不是管理员没有此权限');window.location.reload(); ", true);
            Response.Redirect("index.aspx");
        }
    }
    protected void bookadd(object sender, EventArgs e)
    {
        if (bookid.Text == "")
        {
            ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('书籍编号为空！');window.location.reload(); ", true);
        }
        else
        {
            SqlConnection con = new SqlConnection();        //定义数据库连接对象
            con.ConnectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;  //定义数据库连接字符串
            con.Open();

            SqlCommand com1 = new SqlCommand();              //定义数据库操作命令对象
            com1.Connection = con;                           //连接数据库
            com1.CommandText = "if exists (select * from book where bookid=" + bookid.Text + ") select '1' else select '0'";
            com1.CommandType = CommandType.Text;
            int i = Convert.ToInt32(com1.ExecuteScalar());//返回查询结果的第一行第一列

            if (i == 0)
            {
                SqlCommand com2 = new SqlCommand();              //定义数据库操作命令对象
                com2.Connection = con;                           //连接数据库
                com2.CommandText = "insert into book(bookid,bookname,printhouse,printhouseid,author,authorid,price,ifborrowed,borrowedid) values ('"+ bookid.Text + "','" + bookname.Text + "','" + printhouse.Text + "','" + printhouseid.Text + "','" + author.Text + "','" + authorid.Text + "','" + price.Text + "','0','0000000')";
                com2.CommandType = CommandType.Text;
                com2.ExecuteNonQuery();                          //执行语句

                ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('添加新书成功');window.location.reload(); ", true);

            }
            else if (i == 1)
            {
                ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('书籍编号已存在请重新输入');window.location.reload(); ", true);
            }
        }

    }
}