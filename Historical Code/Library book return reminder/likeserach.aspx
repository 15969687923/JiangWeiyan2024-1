<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="likeserach.aspx.cs" Inherits="likeserach" %>

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
                <asp:SqlDataSource ID="BookSource" runat="server" ConnectionString="<%$ connectionStrings: ConnectionString %>"
                SelectCommand="select bookid,bookname,author,printhouse,ifborrowed,ruturntime from Book where bookname like @parament">
             <SelectParameters>
                 <asp:ControlParameter  Name="parament" ControlID="keyTB"  PropertyName="Text" Type ="String" />
             </SelectParameters>
            </asp:SqlDataSource>

                <asp:Label runat ="server" Text="关键字:"></asp:Label>
             <% if (Session["KEY"] != null) { keyTB.Text = Session["KEY"].ToString();} %>
                <asp:TextBox runat="server" ID="keyTB"  Width="200px" Height="22px"  ></asp:TextBox>
                <asp:Button ID="keyB" runat ="server" Text="查询" Height="28px" OnClick="keyClick"/>
                <br /><br /><br /><br />
            </div> 
            
            


            <asp:GridView ID="showBooks" CssClass="GridViewstyle" runat ="server" AutoGenerateColumns="false"  DataSourceID="BookSource" OnRowDataBound="Gridview_DataBound" >
                <Columns>
                    <asp:BoundField HeaderText="书籍编号" DataField="bookid" />
                    <asp:BoundField HeaderText="书名" DataField="bookname" />
                    <asp:BoundField HeaderText="作者" DataField="author"/>
                    <asp:BoundField HeaderText="出版社" DataField="printhouse"/>
                    <asp:BoundField HeaderText="是否可借" DataField="ifborrowed"/>
                    <asp:BoundField HeaderText="预计还回时间" DataField="ruturntime"/>
                </Columns>
            </asp:GridView>

            
        </ContentTemplate>
    </asp:UpdatePanel>
</asp:Content>

