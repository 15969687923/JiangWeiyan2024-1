using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class MasterPage : System.Web.UI.MasterPage
{
    protected void Page_Load(object sender, EventArgs e)
    {
        //if (!IsPostBack)
        //{
        //    if (Request.Cookies["themeName"] != null)
        //    {
        //        string T_name = Request.Cookies["themeName"].Value;
        //        if (T_name == "grey") { T_name = "白色"; }
        //        if (T_name == "white") { T_name = "淡粉"; }
        //        if (!string.IsNullOrEmpty(T_name))
        //        {
        //            ListItem anItem = DDL.Items.FindByText(T_name);
        //            if (anItem != null)
        //            {
        //                DDL.SelectedItem.Selected = false;
        //                anItem.Selected = true;
        //            }
        //        }
        //    }

        //}
    }
    //protected void  DDL_changed(object sender, EventArgs e)
    //{
    //    string T_name = DDL.SelectedItem.Text;
    //    HttpCookie cookie = new HttpCookie("themeName");
    //    if (T_name == "白色") { T_name = "grey"; }
    //    if (T_name == "淡粉") { T_name = "white"; }
    //    //把选定好的主题存入cookie中
    //    cookie.Value = T_name;
    //    cookie.Expires = DateTime.Now.AddDays(1);
    //    //把值发回浏览器
    //    Response.Cookies.Add(cookie);
    //    //页面重定位
    //    Response.Redirect(Request.Url.ToString());

    //}

    protected void treeT_SelectedNodeChanged(object sender, EventArgs e)
    {

    }

    protected void LoginStatus1_LoggingOut(object sender, LoginCancelEventArgs e)
    {
        
    }
}
