CREATE PROCEDURE [dbo].[SP_Select_Types]
AS
BEGIN
    SET NOCOUNT ON;
    SELECT * FROM types;
END

CREATE PROCEDURE [dbo].[SP_Insert_Types]
@type_name as varchar(50)
AS
BEGIN
    SET NOCOUNT ON;
    INSERT INTO types (name) VALUES (@type_name);
END

CREATE PROCEDURE [dbo].[SP_Update_Types]
@type_id as numeric(18,0),
@type_name as varchar(50)
AS
BEGIN
    SET NOCOUNT ON;
    UPDATE types SET name = @type_name WHERE id_type = @type_id;
END

CREATE PROCEDURE [dbo].[SP_Delete_Types]
@type_id as numeric(18,0)
AS
BEGIN
    SET NOCOUNT ON;
    DELETE FROM types WHERE id_type = @type_id;
END


CREATE PROCEDURE [dbo].[SP_Delete_Sensor]
@id_sensor as numeric(18,0)
AS
BEGIN 
    SET NOCOUNT ON;
    
    --Borrar el sensor
    DELETE [dbo].[sensor_info]
    FROM [dbo].[sensor_info]
    WHERE id_sensor = @id_sensor;

    --borrar los registros
    DELETE [dbo].[sensor_records]
    FROM [dbo].[sensor_records]
    WHERE id_sensor = @id_sensor;
END

CREATE PROCEDURE [dbo].[SP_Select_Sensor] 
@id_device as numeric(18,0)
AS
BEGIN
    SET NOCOUNT ON;
    SELECT SI.id_sensor, SI.name AS "SENSOR", T.name AS "TYPE", O.name AS "OWNER", L.name AS "LOCATION"
    FROM sensor_info SI
    INNER JOIN type T ON SI.id_type = T.id_type
    INNER JOIN owener_info O ON O.id_owner = SI.id_owner
    INNER JOIN locations L ON O.id_location = L.id_location
    WHERE id_sensor = @id_sensor;
END

CREATE PROCEDURE [dbo].[SP_Select_SensorRecords]
@id_sensor as numeric(18,0)
AS
BEGIN
    SET NOCOUNT ON;
    SELECT * FROM sensor_records WHERE id_sensor = @id_sensor;
END 
--PROCEDIMIENTO ALMACENADO PARA SENSOR RECORDS

CREATE PROCEDURE [dbo].[SP_Select_SensorRecords]
@id_sensor as numeric(18,0)
AS
BEGIN
    SET NOCOUNT ON;
    SELECT * FROM sensor_records WHERE id_sensor = @id_sensor;
END

CREATE PROCEDURE [dbo].[SP_Insert_SensorRecords]
@id_sensor as numeric(18,0),
@reading_time as datetime,
@reading_value as decimal(18,2)
AS
BEGIN
    SET NOCOUNT ON;
    INSERT INTO sensor_records (id_sensor, reading_time, reading_value)
    VALUES (@id_sensor, @reading_time, @reading_value);
END

CREATE PROCEDURE [dbo].[SP_Update_SensorRecords]
@record_id as numeric(18,0),
@id_sensor as numeric(18,0),
@reading_time as datetime,
@reading_value as decimal(18,2)
AS
BEGIN
    SET NOCOUNT ON;
    UPDATE sensor_records
    SET id_sensor = @id_sensor, reading_time = @reading_time, reading_value = @reading_value
    WHERE id_record = @record_id;
END

CREATE PROCEDURE [dbo].[SP_Delete_SensorRecords]
@record_id as numeric(18,0)
AS
BEGIN
    SET NOCOUNT ON;
    DELETE FROM sensor_records WHERE id_record = @record_id;
END
