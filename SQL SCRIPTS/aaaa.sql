USE [master]
GO
/*Crea la base de datos*/
CREATE DATABASE [BD_API_RESTful_SE_I]
GO
/*Configura la base de datos*/
ALTER DATABASE [BD_API_RESTful_SE_I] SET ARITHABORT OFF 
GO
/*Selecciona la base de datos para trabajar con ella*/
USE [BD_API_RESTful_SE_I]
GO
/*Crea la tabla devide_manager y le inserta registros*/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO


CREATE TABLE [dbo].[sensor_info](
	[id_sensor] [numeric](18, 0) IDENTITY(1,1) NOT NULL PRIMARY KEY,
	[name] [nvarchar](100) NOT NULL,
	[id_owner] [numeric](18,0) NOT NULL,
	[id_type] [numeric](18,0) NOT NULL,	
)
CREATE TABLE [dbo].[sensor_records](
	[id_record] [numeric](18, 0) IDENTITY(1,1) NOT NULL PRIMARY KEY,
	[id_sensor] [numeric](18, 0) NOT NULL,
	[current_value] [numeric](18,0) NOT NULL,
	[date_record] DATETIME NOT NULL,
)
CREATE TABLE [dbo].[locations](
	[id_location] [numeric](18, 0) IDENTITY(1,1) NOT NULL PRIMARY KEY,
	[name] [nvarchar](100) NOT NULL,
	[lat] float NULL,
	[lon] float NULL,
)
CREATE TABLE [dbo].[types](
	[id_type] [numeric](18, 0) IDENTITY(1,1) NOT NULL PRIMARY KEY,
	[name] [nvarchar](100) NOT NULL,
	[min_value] [numeric] (18, 0) NULL,
	[max_value] [numeric] (18, 0) NULL,
)
CREATE TABLE [dbo].[owner_info](
	[id_owner] [numeric](18, 0) IDENTITY(1,1) NOT NULL PRIMARY KEY,
	[name] [nvarchar](100) NOT NULL,
	[ap_paterno] [nvarchar] (100) NOT NULL,
	[ap_materno] [nvarchar] (100) NULL,
	[id_location] [numeric] (18,0) NOT NULL,
	[jerarquia] [numeric] (18,0) NULL,
)
SELECT * FROM dbo.locations
SELECT * FROM dbo.owner_info
SELECT * FROM dbo.sensor_info
SELECT * FROM dbo.sensor_records
SELECT * FROM dbo.types

GO
SET IDENTITY_INSERT [dbo].[device_manager] ON 

INSERT [dbo].[device_manager] ([id_device], [device_name], [current_value], [owner_name], [max_value], [min_value], [setpoint]) VALUES (CAST(1 AS Numeric(18, 0)), N'device 1', CAST(150 AS Numeric(18, 0)), NULL, NULL, NULL, NULL)
INSERT [dbo].[device_manager] ([id_device], [device_name], [current_value], [owner_name], [max_value], [min_value], [setpoint]) VALUES (CAST(2 AS Numeric(18, 0)), N'device 2', CAST(120 AS Numeric(18, 0)), NULL, NULL, NULL, NULL)
SET IDENTITY_INSERT [dbo].[device_manager] OFF
GO
/*crea los procedimientos almacenados*/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE [dbo].[SP_Delete_Device] 
	-- Add the parameters for the stored procedure here
	@id_device as numeric(18,0)	
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

	DELETE [dbo].[device_manager]
	FROM  [dbo].[device_manager]		
    WHERE 
			id_device = @id_device
    
END
GO
/****** Object:  StoredProcedure [dbo].[SP_Insert_Device]    Script Date: 22/04/2022 04:18:39 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE [dbo].[SP_Insert_Device] 
	-- Add the parameters for the stored procedure here
	@device_name as nvarchar(100), 
	@current_value as numeric(18,0)
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

	INSERT INTO [dbo].[device_manager]
           ([device_name]
           ,[current_value]
		   )
     VALUES
           (@device_name
           ,@current_value
           )
    
END
GO
/****** Object:  StoredProcedure [dbo].[SP_Select_Device]    Script Date: 22/04/2022 04:18:39 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE [dbo].[SP_Select_Device]
	-- Add the parameters for the stored procedure here
		@id_device as numeric(18,0)	
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

	SELECT *
	FROM  [dbo].[device_manager]		
    WHERE 
			id_device = @id_device
    
END
GO
/****** Object:  StoredProcedure [dbo].[SP_SelectALL_Devices]    Script Date: 22/04/2022 04:18:39 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE [dbo].[SP_SelectALL_Devices]
	-- Add the parameters for the stored procedure here	
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

	SELECT *
	FROM  [dbo].[device_manager]		   
    
END
GO
/****** Object:  StoredProcedure [dbo].[SP_Update_Device]    Script Date: 22/04/2022 04:18:39 p. m. ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE [dbo].[SP_Update_Device] 
	-- Add the parameters for the stored procedure here
	@id_device as numeric(18,0),	
	@current_value as numeric(18,0)
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

	UPDATE [dbo].[device_manager]
	SET 
		[current_value] = @current_value		   
     WHERE 
			id_device = @id_device
    
END
GO
/*regresa a la base de datos que se uso de pivote*/
USE [master]
GO

