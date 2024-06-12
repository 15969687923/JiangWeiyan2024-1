<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="browse.aspx.cs" Inherits="browse" %>


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
    <asp:ScriptManager runat="server"></asp:ScriptManager>
    <asp:UpdatePanel runat ="server">
        <ContentTemplate>
             <div style="margin-top:30px;margin-left:160px;" >
                <!--第一个下拉框选择浏览依据-->
                <asp:Label runat ="server" Text ="分类依据:" Font-Size="Medium"></asp:Label>
                <asp:DropDownList runat="server"  AutoPostBack="true" ID="AorP"  OnSelectedIndexChanged="abc"  Font-Size="Medium" ForeColor="#58748e" Width="200px">
                     <asp:ListItem  Value="*" >请选择</asp:ListItem>
                     <asp:ListItem  Value ="author">作者</asp:ListItem>
                     <asp:ListItem  Value="printhouse">出版社</asp:ListItem>
                </asp:DropDownList><br /><br />
                <!--连接数据库-->
                <!--作者数据源-->
                 <asp:SqlDataSource ID="authorSource" runat="server" ConnectionString="<%$ connectionStrings: ConnectionString %>"
                        SelectCommand="select distinct author,authorID from Book ">
                    </asp:SqlDataSource>
                <!--出版社数据源-->
                <asp:SqlDataSource ID="printSource" runat="server" ConnectionString="<%$ connectionStrings: ConnectionString %>"
                        SelectCommand="select distinct printhouse,printhouseID from Book ">
                    </asp:SqlDataSource>

                <!--第二个下拉框显示对应依据数据库里的数据-->
                <asp:Label runat ="server" Text ="类别内容:"  Font-Size="Medium"></asp:Label>
                <asp:DropDownList runat="server" ID="DropDownList1"  OnSelectedIndexChanged="showbooks" AutoPostBack="true"
                                             ForeColor="#58748e" Font-Size="Medium" Width="200px">
                     <asp:ListItem Text="请选择"></asp:ListItem>
                </asp:DropDownList><br /><br /><br /><br />
                <!--Gridview显示选择的图书-->
                <!--作者数据源-->
                 <asp:SqlDataSource ID="authorbookSource" runat="server" ConnectionString="<%$ connectionStrings: ConnectionString %>"
                        SelectCommand="select bookid,author,bookname,printhouse,ifborrowed,ruturntime from Book where authorID = @authorparament">
                     <SelectParameters>
                         <asp:ControlParameter  Name="authorparament" ControlID="DropDownList1"  PropertyName="SelectedValue" />
                     </SelectParameters>
                    </asp:SqlDataSource>
                <!--出版社数据源-->
                <asp:SqlDataSource ID="printbookSource" runat="server" ConnectionString="<%$ connectionStrings: ConnectionString %>"
                        SelectCommand="select bookid,author,bookname,printhouse,ifborrowed,ruturntime from Book where printhouseID = @printhouseparament">
                     <SelectParameters>
                         <asp:ControlParameter  Name="printhouseparament" ControlID="DropDownList1"  PropertyName="SelectedValue" />
                     </SelectParameters>
                </asp:SqlDataSource>
           </div>

            <!--Gridview控件内容-->
            <asp:GridView ID="showBooks" CssClass="GridViewstyle"  runat ="server" AutoGenerateColumns="false" OnRowDataBound="Gridview_DataBound"  >
                <Columns>
                    <asp:BoundField HeaderText="书籍编号" DataField="bookid"/>
                    <asp:BoundField HeaderText="作者" DataField="author"/>
                    <asp:BoundField HeaderText="书名" DataField="bookname" />
                    <asp:BoundField HeaderText="出版社" DataField="printhouse"/>
                    <asp:BoundField HeaderText="是否可借" DataField="ifborrowed"/>
                    <asp:BoundField HeaderText="预计还回时间" DataField="ruturntime"/>
                    <%--<asp:BoundField HeaderText="作者编号" DataField="authorID"/>
                    <asp:BoundField HeaderText="出版社编号" DataField="printhouseID"/>
                    <asp:BoundField HeaderText="书籍编号" DataField="bookid" />--%>
                </Columns>
            </asp:GridView>
        </ContentTemplate>
    </asp:UpdatePanel>
</asp:Content>

