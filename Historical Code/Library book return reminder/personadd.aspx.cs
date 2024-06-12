using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;


//HttpContext.Current.User.Identity.Name.ToString()
//获得用户名

public partial class personadd : BasePage
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
    //protected void addperson(object sender, EventArgs e)
    //{
    //    if (personid.Text == "")
    //    {
    //        ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('用户编号为空！');window.location.reload(); ", true);
    //    }
    //    else
    //    {
    //        SqlConnection con = new SqlConnection();        //定义数据库连接对象
    //        con.ConnectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;  //定义数据库连接字符串
    //        con.Open();

    //        SqlCommand com1 = new SqlCommand();              //定义数据库操作命令对象
    //        com1.Connection = con;                           //连接数据库
    //        com1.CommandText = "if exists (select * from person where personid=" + personid.Text + ") select '1' else select '0'";
    //        com1.CommandType = CommandType.Text;
    //        int i = Convert.ToInt32(com1.ExecuteScalar());//返回查询结果的第一行第一列

    //        if (i == 0)
    //        {
    //            SqlCommand com2 = new SqlCommand();              //定义数据库操作命令对象
    //            com2.Connection = con;                           //连接数据库
    //            com2.CommandText = "insert into person(personid,personname,password,ifadministrator,booknum,maxbooknum) values ('" + personid.Text + "','" + personname.Text + "','" + password.Text + "','0','0','5')";
    //            com2.CommandType = CommandType.Text;
    //            com2.ExecuteNonQuery();                          //执行语句

    //            ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('添加新用户成功');window.location.reload(); ", true);

    //        }
    //        else if (i == 1)
    //        {
    //            ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('用户编号已存在请重新输入');window.location.reload(); ", true);
    //        }
    //    }

    //}

    protected void setadministrator(object sender, EventArgs e)
    {
        if (personid2.Text == "")
        {
            ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('用户编号为空！');window.location.reload(); ", true);
        }
        else
        {
            SqlConnection con = new SqlConnection();        //定义数据库连接对象
            con.ConnectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;  //定义数据库连接字符串
            con.Open();

            SqlCommand com1 = new SqlCommand();              //定义数据库操作命令对象
            com1.Connection = con;                           //连接数据库
            com1.CommandText = "if exists (select * from person where personid=" + personid2.Text + ") select '1' else select '0'";
            com1.CommandType = CommandType.Text;
            int i = Convert.ToInt32(com1.ExecuteScalar());//返回查询结果的第一行第一列
            if (i == 1)
            {
                SqlCommand com2 = new SqlCommand();              //定义数据库操作命令对象
                com2.Connection = con;                           //连接数据库
                com2.CommandText = "update person set ifadministrator='1' where personid='" + personid2.Text + "'";
                com2.CommandType = CommandType.Text;
                com2.ExecuteNonQuery();                          //执行语句

                ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('设置用户" + personid2.Text + "为管理员成功');window.location.reload(); ", true);
            }
            else if (i == 0)
            {
                ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('该用户编号不存在请重新输入');window.location.reload(); ", true);
            }
        }
    }

    protected void revadministrator(object sender, EventArgs e)
    {
        if (personid3.Text == "")
        {
            ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('用户编号为空！');window.location.reload(); ", true);
        }
        else
        {
            SqlConnection con = new SqlConnection();        //定义数据库连接对象
            con.ConnectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;  //定义数据库连接字符串
            con.Open();

            SqlCommand com1 = new SqlCommand();              //定义数据库操作命令对象
            com1.Connection = con;                           //连接数据库
            com1.CommandText = "if exists (select * from person where personid=" + personid3.Text + ") select '1' else select '0'";
            com1.CommandType = CommandType.Text;
            int i = Convert.ToInt32(com1.ExecuteScalar());//返回查询结果的第一行第一列
            if (i == 1)
            {
                SqlCommand com2 = new SqlCommand();              //定义数据库操作命令对象
                com2.Connection = con;                           //连接数据库
                com2.CommandText = "update person set ifadministrator='0' where personid='" + personid3.Text + "'";
                com2.CommandType = CommandType.Text;
                com2.ExecuteNonQuery();                          //执行语句

                ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('设置用户" + personid3.Text + "为管理员成功');window.location.reload(); ", true);
            }
            else if (i == 0)
            {
                ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('该用户编号不存在请重新输入');window.location.reload(); ", true);
            }
        }
    }
    protected void upmaxbooknum(object sender, EventArgs e)
    {
        if (personid4.Text == "")
        {
            ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('用户编号为空！');window.location.reload(); ", true);
        }
        else
        {
            SqlConnection con = new SqlConnection();        //定义数据库连接对象
            con.ConnectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;  //定义数据库连接字符串
            con.Open();

            SqlCommand com1 = new SqlCommand();              //定义数据库操作命令对象
            com1.Connection = con;                           //连接数据库
            com1.CommandText = "if exists (select * from person where personid=" + personid4.Text + ") select '1' else select '0'";
            com1.CommandType = CommandType.Text;
            int i = Convert.ToInt32(com1.ExecuteScalar());//返回查询结果的第一行第一列
            if (i == 1)
            {
                if(booknum.Text=="")
                {
                    ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('请先输入要修改的借阅书数量！'); ", true);
                }
                else
                {
                    int num = Convert.ToInt32(booknum.Text);
                    SqlCommand com2 = new SqlCommand();              //定义数据库操作命令对象
                    com2.Connection = con;                           //连接数据库
                    com2.CommandText = "update person set maxbooknum=" + num + " where personid='" + personid4.Text + "'";
                    com2.CommandType = CommandType.Text;
                    com2.ExecuteNonQuery();                          //执行语句

                    ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('更新用户" + personid3.Text + "借阅书数成功');window.location.reload(); ", true);
                }
               
            }
            else if (i == 0)
            {
                ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('该用户编号不存在请重新输入');window.location.reload(); ", true);
            }
        }
    }

}