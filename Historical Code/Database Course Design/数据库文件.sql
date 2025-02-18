USE [master]
GO
/****** Object:  Database [数据库课设]    Script Date: 2019/6/27 11:59:19 ******/
CREATE DATABASE [数据库课设]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'数据库课设', FILENAME = N'D:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\DATA\数据库课设.mdf' , SIZE = 5120KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'数据库课设_log', FILENAME = N'D:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\DATA\数据库课设_log.ldf' , SIZE = 1024KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
ALTER DATABASE [数据库课设] SET COMPATIBILITY_LEVEL = 110
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [数据库课设].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [数据库课设] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [数据库课设] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [数据库课设] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [数据库课设] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [数据库课设] SET ARITHABORT OFF 
GO
ALTER DATABASE [数据库课设] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [数据库课设] SET AUTO_CREATE_STATISTICS ON 
GO
ALTER DATABASE [数据库课设] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [数据库课设] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [数据库课设] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [数据库课设] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [数据库课设] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [数据库课设] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [数据库课设] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [数据库课设] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [数据库课设] SET  DISABLE_BROKER 
GO
ALTER DATABASE [数据库课设] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [数据库课设] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [数据库课设] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [数据库课设] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [数据库课设] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [数据库课设] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [数据库课设] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [数据库课设] SET RECOVERY FULL 
GO
ALTER DATABASE [数据库课设] SET  MULTI_USER 
GO
ALTER DATABASE [数据库课设] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [数据库课设] SET DB_CHAINING OFF 
GO
ALTER DATABASE [数据库课设] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [数据库课设] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
EXEC sys.sp_db_vardecimal_storage_format N'数据库课设', N'ON'
GO
USE [数据库课设]
GO
/****** Object:  Table [dbo].[出售商品表]    Script Date: 2019/6/27 11:59:19 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[出售商品表](
	[Sellnum] [nchar](50) NOT NULL,
	[Gno] [nchar](50) NULL,
	[Gname] [nchar](50) NULL,
	[Gp] [float] NULL,
	[Amount] [int] NULL,
	[Smonedy] [float] NULL,
	[Selldate] [date] NULL,
	[Sno] [nchar](50) NULL,
 CONSTRAINT [PK_出售商品表] PRIMARY KEY CLUSTERED 
(
	[Sellnum] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[顾客退货表]    Script Date: 2019/6/27 11:59:19 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[顾客退货表](
	[Regnum] [nchar](50) NOT NULL,
	[Gno] [nchar](50) NULL,
	[Gp] [float] NULL,
	[Amount] [int] NULL,
	[Regmoney] [float] NULL,
 CONSTRAINT [PK_顾客退货表] PRIMARY KEY CLUSTERED 
(
	[Regnum] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[管理员表]    Script Date: 2019/6/27 11:59:19 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[管理员表](
	[Mno] [nchar](50) NOT NULL,
	[Mname] [nchar](50) NULL,
	[Msex] [nchar](50) NULL,
	[Mbirth] [date] NULL,
	[Rzday] [date] NULL,
	[Mph] [nchar](50) NULL,
	[Mima] [nchar](50) NULL,
	[Msal] [float] NULL,
 CONSTRAINT [PK_管理员表] PRIMARY KEY CLUSTERED 
(
	[Mno] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[进货表]    Script Date: 2019/6/27 11:59:19 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[进货表](
	[Buynum] [nchar](50) NOT NULL,
	[Buydate] [date] NULL,
	[Pno] [nchar](50) NULL,
	[Bgno] [nchar](50) NULL,
	[Amount] [int] NULL,
	[Btp] [float] NULL,
 CONSTRAINT [PK_进货表] PRIMARY KEY CLUSTERED 
(
	[Buynum] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[进货商表]    Script Date: 2019/6/27 11:59:19 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[进货商表](
	[Pno] [nchar](50) NOT NULL,
	[Pname] [nchar](50) NULL,
	[Padd] [nchar](50) NULL,
 CONSTRAINT [PK_进货商表] PRIMARY KEY CLUSTERED 
(
	[Pno] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[商品表]    Script Date: 2019/6/27 11:59:19 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[商品表](
	[Gno] [nchar](50) NOT NULL,
	[Gname] [nchar](50) NULL,
	[Gcla] [nchar](50) NULL,
	[Gp] [float] NULL,
	[Gam] [int] NULL,
	[Pno] [nchar](50) NULL,
 CONSTRAINT [PK_商品表] PRIMARY KEY CLUSTERED 
(
	[Gno] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[统计表]    Script Date: 2019/6/27 11:59:19 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[统计表](
	[Tnum] [nchar](50) NOT NULL,
	[Sno] [nchar](50) NULL,
	[Xsm] [float] NULL,
 CONSTRAINT [PK_Table_1] PRIMARY KEY CLUSTERED 
(
	[Tnum] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[退货表]    Script Date: 2019/6/27 11:59:19 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[退货表](
	[Retnum] [nchar](50) NOT NULL,
	[Retreatdate] [date] NULL,
	[Rgno] [nchar](50) NULL,
	[Amount] [int] NULL,
	[Remoney] [float] NULL,
	[Rtp] [float] NULL,
 CONSTRAINT [PK_退货表] PRIMARY KEY CLUSTERED 
(
	[Retnum] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[员工表]    Script Date: 2019/6/27 11:59:19 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[员工表](
	[Sno] [nchar](50) NOT NULL,
	[Sname] [nchar](50) NULL,
	[Ssex] [nchar](10) NULL,
	[Sbirth] [date] NULL,
	[Sidn] [nchar](50) NULL,
	[Rzday] [date] NULL,
	[Mima] [nchar](50) NULL,
	[Sph] [nchar](50) NULL,
	[Ssal] [float] NULL,
 CONSTRAINT [PK_员工表] PRIMARY KEY CLUSTERED 
(
	[Sno] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
ALTER TABLE [dbo].[出售商品表]  WITH CHECK ADD  CONSTRAINT [FK_出售商品表_商品表] FOREIGN KEY([Gno])
REFERENCES [dbo].[商品表] ([Gno])
GO
ALTER TABLE [dbo].[出售商品表] CHECK CONSTRAINT [FK_出售商品表_商品表]
GO
ALTER TABLE [dbo].[出售商品表]  WITH CHECK ADD  CONSTRAINT [FK_出售商品表_员工表] FOREIGN KEY([Sno])
REFERENCES [dbo].[员工表] ([Sno])
GO
ALTER TABLE [dbo].[出售商品表] CHECK CONSTRAINT [FK_出售商品表_员工表]
GO
ALTER TABLE [dbo].[顾客退货表]  WITH CHECK ADD  CONSTRAINT [FK_顾客退货表_商品表] FOREIGN KEY([Gno])
REFERENCES [dbo].[商品表] ([Gno])
GO
ALTER TABLE [dbo].[顾客退货表] CHECK CONSTRAINT [FK_顾客退货表_商品表]
GO
ALTER TABLE [dbo].[进货表]  WITH CHECK ADD  CONSTRAINT [FK_进货表_进货商表] FOREIGN KEY([Pno])
REFERENCES [dbo].[进货商表] ([Pno])
GO
ALTER TABLE [dbo].[进货表] CHECK CONSTRAINT [FK_进货表_进货商表]
GO
ALTER TABLE [dbo].[商品表]  WITH CHECK ADD  CONSTRAINT [FK_商品表_进货商表] FOREIGN KEY([Pno])
REFERENCES [dbo].[进货商表] ([Pno])
GO
ALTER TABLE [dbo].[商品表] CHECK CONSTRAINT [FK_商品表_进货商表]
GO
ALTER TABLE [dbo].[统计表]  WITH CHECK ADD  CONSTRAINT [FK_统计表_员工表] FOREIGN KEY([Sno])
REFERENCES [dbo].[员工表] ([Sno])
GO
ALTER TABLE [dbo].[统计表] CHECK CONSTRAINT [FK_统计表_员工表]
GO
ALTER TABLE [dbo].[退货表]  WITH CHECK ADD  CONSTRAINT [FK_退货表_商品表] FOREIGN KEY([Rgno])
REFERENCES [dbo].[商品表] ([Gno])
GO
ALTER TABLE [dbo].[退货表] CHECK CONSTRAINT [FK_退货表_商品表]
GO
USE [master]
GO
ALTER DATABASE [数据库课设] SET  READ_WRITE 
GO
