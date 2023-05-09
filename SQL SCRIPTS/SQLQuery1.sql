Create Procedure USP_Listado_ca  '%'
@cTexto  varchar(100)=''
as
	select codigo_ca,descripcion_ca
	from TB_CATEGORIAS where estado=1  and 
	upper(trim(cast(codigo_ca as char))+ trim(descripcion_ca)) like '%'+upper(trim(@cTexto))+'%';
go