<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="borrowed.aspx.cs" Inherits="borrowed" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
    <style>
        .GridViewstyle{
            width:500px;
            height:100px;
            background-color:#00ffff;
            text-align:center;
            margin-left:80px

        }
    </style>
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">

    <asp:Label ID="message1" Text="" runat="server"/>

    <asp:ScriptManager runat="server"></asp:ScriptManager>
    <asp:UpdatePanel runat ="server">
        <ContentTemplate>
            <!--Cridview控件内容-->
            <asp:GridView ID="showBooks" CssClass="GridViewstyle"  runat ="server" AutoGenerateColumns="false"  >
                <Columns>
                    <asp:BoundField HeaderText="书籍编号" DataField="bookid"/>
                    <asp:BoundField HeaderText="书籍名称" DataField="bookname" />
                    <asp:BoundField HeaderText="作者" DataField="author"/>
                    <asp:BoundField HeaderText="出版社" DataField="printhouse"/>
                    <asp:BoundField HeaderText="借阅时间" DataField="borrowedtime"/>
                    <asp:BoundField HeaderText="应还时间" DataField="ruturntime"/>
                </Columns>
            </asp:GridView>
        </ContentTemplate>
    </asp:UpdatePanel>
</asp:Content>
