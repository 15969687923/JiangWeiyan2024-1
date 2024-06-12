using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class personsub : BasePage
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
    protected void subperson(object sender, EventArgs e)
    {
        if (personid.Text == "")
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
            com1.CommandText = "if exists (select * from person where personid=" + personid.Text + ") select '1' else select '0'";
            com1.CommandType = CommandType.Text;
            int i = Convert.ToInt32(com1.ExecuteScalar());//返回查询结果的第一行第一列

            if (i == 1)
            {
                SqlCommand com3 = new SqlCommand();              //定义数据库操作命令对象
                com3.Connection = con;                           //连接数据库
                com3.CommandText = "select password from person where personid='" + personid.Text + "'";
                com3.CommandType = CommandType.Text;
                int pw = Convert.ToInt32(com3.ExecuteScalar());//返回查询结果的第一行第一列

                if(pw == Convert.ToInt32(password.Text))
                {
                    SqlCommand com2 = new SqlCommand();              //定义数据库操作命令对象
                    com2.Connection = con;                           //连接数据库
                    com2.CommandText = "delete from person where personid='" + personid.Text + "'";
                    com2.CommandType = CommandType.Text;
                    com2.ExecuteNonQuery();                          //执行语句

                    ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('用户销户成功');window.location.reload(); ", true);
                }
                else
                {
                    ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('读者密码输入错误请重新输入'); ", true);
                }
            }
            else if (i == 0)
            {
                ScriptManager.RegisterStartupScript(this.Page, this.GetType(), "onekey", "alert('该用户不存在请重新输入');window.location.reload(); ", true);
            }
        }

    }
}