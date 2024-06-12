using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;


public partial class repbook : BasePage
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void bookrep(object sender, EventArgs e)
    {
        string date = DateTime.Now.ToString("D");

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

            if (i == 1)//书籍存在
            {
                SqlCommand com6 = new SqlCommand();              //定义数据库操作命令对象
                com6.Connection = con;                           //连接数据库
                com6.CommandText = "select borrowedid from book where bookid='" + bookid.Text + "'";
                com6.CommandType = CommandType.Text;
                int i4 = Convert.ToInt32(com6.ExecuteScalar());//返回查询结果的第一行第一列

                if (i4 == Convert.ToInt32(HttpContext.Current.User.Identity.Name.ToString()))//书籍是本账号借的
                {
                    SqlCommand com7 = new SqlCommand();              //定义数据库操作命令对象
                    com7.Connection = con;                           //连接数据库
                    com7.CommandText = "select ruturntime from book where bookid='" + bookid.Text + "'";
                    com7.CommandType = CommandType.Text;
                    string i5 = Convert.ToString(com7.ExecuteScalar());//返回查询结果的第一行第一列

                    DateTime dt1 = Convert.ToDateTime(date);
                    DateTime dt2 = Convert.ToDateTime(i5);

                    if (DateTime.Compare(dt1, dt2) < 0)//还书时间是否在一个月内
                    {
                        SqlCommand com2 = new SqlCommand();              //定义数据库操作命令对象
                        com2.Connection = con;                           //连接数据库
                        com2.CommandText = "select booknum from person where personid='" + HttpContext.Current.User.Identity.Name.ToString() + "'";
                        com2.CommandType = CommandType.Text;
                        int i2 = Convert.ToInt32(com2.ExecuteScalar());//返回查询结果的第一行第一列

                        i2 = i2 - 1;
                        SqlCommand com4 = new SqlCommand();              //定义数据库操作命令对象
                        com4.Connection = con;                           //连接数据库
                        com4.CommandText = "update person set booknum=" + i2 + " where personid='" + HttpContext.Current.User.Identity.Name.ToString() + "'";
                        com4.CommandType = CommandType.Text;
                        com4.ExecuteNonQuery();//执行sql语句

                        SqlCommand com5 = new SqlCommand();              //定义数据库操作命令对象
                        com5.Connection = con;                           //连接数据库
                        com5.CommandText = "update book set ifborrowed='0',borrowedid='0000000',borrowedtime=null,ruturntime=null where bookid='" + bookid.Text + "'";
                        com5.CommandType = CommandType.Text;
                        com5.ExecuteNonQuery();//执行sql语句

                        ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('还书成功！');window.location.reload(); ", true);
                    }
                }
                else
                {
                    ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('此书不是你借的无法归还！请使用借书账号还书！');window.location.reload(); ", true);
                }
                
            }
            else if (i == 0)
            {
                ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('书籍编号不存在请重新输入');window.location.reload(); ", true);
            }
        }

    }

}