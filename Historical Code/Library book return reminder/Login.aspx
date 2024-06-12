<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Login.aspx.cs" Inherits="Login" %>

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
    <asp:HyperLink ID="HyperLink2" runat="server" NavigateUrl="~/Register.aspx">新用户注册</asp:HyperLink>
    <br />
<asp:Login ID="Login1" runat="server" BackColor="#F7F7DE" BorderColor="#CCCC99" BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" Font-Size="10pt" Height="161px" Width="269px">
    <TitleTextStyle BackColor="#6B696B" Font-Bold="True" ForeColor="#FFFFFF" />
</asp:Login>
<asp:HyperLink ID="HyperLink3" runat="server" NavigateUrl="~/PasswordRecovery.aspx">忘记密码</asp:HyperLink>
<asp:ValidationSummary ID="ValidationSummary1" runat="server" ValidationGroup="Login1" />
<asp:ScriptManager runat ="server" ></asp:ScriptManager>
    <asp:UpdatePanel runat ="server" >
        <ContentTemplate>
            <div  style="margin-top:50px;margin-left:160px;" >
                


            </div> 
            

        </ContentTemplate>
    </asp:UpdatePanel>
</asp:Content>
