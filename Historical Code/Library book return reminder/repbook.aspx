<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="repbook.aspx.cs" Inherits="repbook" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
    <style>
        .GridViewstyle{
            width:400px;
            height:200px;
            background-color:#f2f4f6;
            text-align:center;
            margin-left:120px

        }
    </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <asp:ScriptManager runat ="server" ></asp:ScriptManager>
    <asp:UpdatePanel runat ="server" >
        <ContentTemplate>
            <div  style="margin-top:50px;margin-left:160px;" >
                <%--<asp:SqlDataSource ID="BookSource" runat="server" ConnectionString="<%$ connectionStrings: ConnectionString %>"
                    SelectCommand="select bookname,author,printhouse from Book where bookname like @parament">
                    <SelectParameters>
                        <asp:ControlParameter  Name="parament" ControlID="keyTB"  PropertyName="Text" Type ="String" />
                    </SelectParameters>
                </asp:SqlDataSource>--%>

                <asp:Label runat ="server" Text="书籍编号:"></asp:Label>
                <%--查询记录存放在session里--%>
                <%--<% if (Session["PID"] != null) { personid.Text = Session["PID"].ToString();} %>--%>
                <asp:TextBox runat="server" ID="bookid"  Width="200px" Height="22px"  ></asp:TextBox>

                <asp:Button ID="addp" runat ="server" Text="归还" Height="28px" OnClick="bookrep"/>
                <br /><br /><br /><br />
            </div> 
            

        </ContentTemplate>
    </asp:UpdatePanel>
</asp:Content>
