using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class likeserach :BasePage
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void keyClick(object sender, EventArgs e)
    {
        Session.Add("KEY",keyTB.Text);
        keyTB.Text = "%" + keyTB.Text + "%";
    }
    protected void Gridview_DataBound(object sender, GridViewRowEventArgs e)
    {
        if (e.Row.RowType == DataControlRowType.DataRow)
        {

            switch (e.Row.Cells[4].Text.Trim())
            {
                case "0":
                    e.Row.Cells[4].Text = "可借阅";
                    break;
                case "1":
                    e.Row.Cells[4].Text = "已被借出";
                    break;
                case "2":
                    e.Row.Cells[4].Text = "不可借出";
                    break;
            }
        }
    }
}