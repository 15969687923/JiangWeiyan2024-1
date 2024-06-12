using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class browse :BasePage
{
    protected void Page_Load(object sender, EventArgs e)
    {
      
    }
    protected void abc(object sender, EventArgs e)
    {
        string A="";
        string B = "";
        if (AorP.SelectedItem.Text=="请选择")
        {
          /*  DropDownList1.Items.Clear();
            DropDownList1.Items.Add("请选择");*/
         }
        else {
            if (AorP.SelectedItem.Text == "作者")
            {
                A = "authorSource";
                B = "authorID";
            }
            if (AorP.SelectedItem.Text == "出版社")
            {
                A = "printSource";
                B = "printhouseID";
            }
            DropDownList1.Items.Clear();
            DropDownList1.DataSourceID = A;
            DropDownList1.DataValueField = B;
            DropDownList1.DataTextField = AorP.SelectedValue;
           // DropDownList1.AppendDataBoundItems = true;
        }
     
    }
    protected void showbooks(object sender, EventArgs e)
    {
        if (AorP.SelectedItem.Text == "作者")
        {
            showBooks.DataSourceID = "authorbookSource";
        }
        if (AorP.SelectedItem.Text == "出版社")
        {
            showBooks.DataSourceID = "printbookSource";
        }
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