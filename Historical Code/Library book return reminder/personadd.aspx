<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="personadd.aspx.cs" Inherits="personadd" %>

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

               <%-- <asp:Label runat ="server" Text="读者编号:"></asp:Label>
              
                <asp:TextBox runat="server" ID="personid"  Width="200px" Height="22px"  ></asp:TextBox>

                <asp:Label runat ="server" Text="读者姓名:"></asp:Label>
                
                <asp:TextBox runat="server" ID="personname"  Width="200px" Height="22px"  ></asp:TextBox>
                <br /><br />
                <asp:Label runat ="server" Text="初始密码:"></asp:Label>
                
                <asp:TextBox runat="server" ID="password"  Width="200px" Height="22px"  ></asp:TextBox>

                <asp:Button ID="addp" runat ="server" Text="新增" Height="28px" OnClick="addperson"/>
                <br /><br /><br /><br />--%>

                <asp:Label runat ="server" Text="用户编号:"></asp:Label>
                <%--查询记录存放在session里--%>
                <%--<% if (Session["PID"] != null) { personid.Text = Session["PID"].ToString();} %>--%>
                <asp:TextBox runat="server" ID="personid4"  Width="200px" Height="22px"  ></asp:TextBox>
                <br /><br />
                <asp:Label runat ="server" Text="借阅书数:"></asp:Label>
                <%--查询记录存放在session里--%>
                <%--<% if (Session["PID"] != null) { personid.Text = Session["PID"].ToString();} %>--%>
                <asp:TextBox runat="server" ID="booknum"  Width="200px" Height="22px"  ></asp:TextBox>

                <asp:Button ID="Button3" runat ="server" Text="修改书籍借阅值" Height="28px" OnClick="upmaxbooknum"/>

                <br /><br /><br /><br />
                <asp:Label runat ="server" Text="用户编号:"></asp:Label>
                <%--查询记录存放在session里--%>
                <%--<% if (Session["PID"] != null) { personid.Text = Session["PID"].ToString();} %>--%>
                <asp:TextBox runat="server" ID="personid2"  Width="200px" Height="22px"  ></asp:TextBox>

                <asp:Button ID="Button1" runat ="server" Text="设为管理员" Height="28px" OnClick="setadministrator"/>

                <br /><br /><br /><br />
                <asp:Label runat ="server" Text="用户编号:"></asp:Label>
                <%--查询记录存放在session里--%>
                <%--<% if (Session["PID"] != null) { personid.Text = Session["PID"].ToString();} %>--%>
                <asp:TextBox runat="server" ID="personid3"  Width="200px" Height="22px"  ></asp:TextBox>

                <asp:Button ID="Button2" runat ="server" Text="撤销管理员" Height="28px" OnClick="revadministrator"/>

            </div> 
            

        </ContentTemplate>
    </asp:UpdatePanel>
</asp:Content>

