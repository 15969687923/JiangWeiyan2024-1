using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;


public partial class borbook : BasePage
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void bookbor(object sender, EventArgs e)
    {
        string date = DateTime.Now.ToString("D");
        string date2 = DateTime.Now.AddDays(30).ToString("D");    //取得一个月后的日期
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

            if (i == 1)
            {
                SqlCommand com6 = new SqlCommand();              //定义数据库操作命令对象
                com6.Connection = con;                           //连接数据库
                com6.CommandText = "select ifborrowed from book where bookid='" + bookid.Text + "'";
                com6.CommandType = CommandType.Text;
                int i4 = Convert.ToInt32(com6.ExecuteScalar());//返回查询结果的第一行第一列

                if (i4 == 0)
                {
                    SqlCommand com2 = new SqlCommand();              //定义数据库操作命令对象
                    com2.Connection = con;                           //连接数据库
                    com2.CommandText = "select booknum from person where personid='"+ HttpContext.Current.User.Identity.Name.ToString() + "'";
                    com2.CommandType = CommandType.Text;
                    int i2 = Convert.ToInt32(com2.ExecuteScalar());//返回查询结果的第一行第一列

                    SqlCommand com3 = new SqlCommand();              //定义数据库操作命令对象
                    com3.Connection = con;                           //连接数据库
                    com3.CommandText = "select maxbooknum from person where personid='" + HttpContext.Current.User.Identity.Name.ToString() + "'";
                    com3.CommandType = CommandType.Text;
                    int i3 = Convert.ToInt32(com3.ExecuteScalar());//返回查询结果的第一行第一列

                    if (i2 < i3)
                    {
                        SqlCommand com4 = new SqlCommand();              //定义数据库操作命令对象
                        com4.Connection = con;                           //连接数据库
                        i2 = i2 + 1;
                        com4.CommandText = "update person set booknum=" + i2 + " where personid='" + HttpContext.Current.User.Identity.Name.ToString() + "'";
                        com4.CommandType = CommandType.Text;
                        com4.ExecuteNonQuery();//执行sql语句

                        SqlCommand com5 = new SqlCommand();              //定义数据库操作命令对象
                        com5.Connection = con;                           //连接数据库
                        com5.CommandText = "update book set ifborrowed='1',borrowedid='" + HttpContext.Current.User.Identity.Name.ToString() + "',borrowedtime='" + date + "',ruturntime='" + date2 + "' where bookid='" + bookid.Text + "'";
                        com5.CommandType = CommandType.Text;
                        com5.ExecuteNonQuery();//执行sql语句

                        ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('借阅成功！');window.location.reload(); ", true);
                    }
                    else
                    {
                        ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('抱歉您的借书数量已达上限！不能再借阅书籍！');window.location.reload(); ", true);
                    }
                }
                else if (i4 == 1)
                {
                    ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('抱歉此书已被借出！');window.location.reload(); ", true);
                }
                else if (i4 == 2)
                {
                    ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('抱歉此书是古旧典籍只能在馆阅览不能借出！');window.location.reload(); ", true);
                }

            }
            else if (i == 0)
            {
                ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('书籍编号不存在请重新输入');window.location.reload(); ", true);
            }
        }

    }

}