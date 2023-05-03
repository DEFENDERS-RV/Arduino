USE [master]
GO
/*Crea la base de datos*/
CREATE DATABASE [BD_API_RESTful_SE]
GO
/*Configura la base de datos*/
ALTER DATABASE [BD_API_RESTful_SE] SET ARITHABORT OFF 
GO
/*Selecciona la base de datos para trabajar con ella*/
USE [BD_API_RESTful_SE]
GO
/*Crea la tabla devide_manager y le inserta registros*/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[device_manager](
	[id_device] [numeric](18, 0) IDENTITY(1,1) NOT NULL PRIMARY KEY,
	[device_name] [nvarchar](100) NOT NULL,
	[current_value] [numeric](18, 0) NOT NULL,
	[owner_name] [nvarchar](150) NULL,
	[max_value] [numeric](18, 0) NULL,
	[min_value] [numeric](18, 0) NULL,
	[setpoint] [numeric](18, 0) NULL
)
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

