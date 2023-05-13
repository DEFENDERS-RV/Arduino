const {getConnection} = require('./conexion')

const sql = require('mssql')


const checkConexion = async function(){
        const SQL_QUERY = 'SELECT GETDATE() AS FECHA_COMPLETA'
        const conexion = await getConnection()

        console.log("Conexion Realizada con Exito!")
        
        const result = await conexion.request().query(SQL_QUERY)

        console.log(`Datos devueltos de la Query de prueba...`)

        console.log(result.recordset)  //DEVUELVE UNA LISTA DE OBJETOS

        console.log(result.recordset[0]) //DE LA LISTA DE OBJETOS SOLO SE RECUPERA UN OBJETO (EL PRIMERO EN ESTE CASO)

        console.log(result.recordset[0].FECHA_COMPLETA) //SE ACCEDE A UNA DE LAS PROPIEDADES DEL OBJETO DEVUELTO

}

//checkConexion()

const selectAll = async function(){
        const SQL_QUERY = 'SELECT * FROM USUARIOS'
        const conexion = await getConnection()
        const result = await conexion.request().query(SQL_QUERY)
        console.log(result.recordset)
}


//selectAll()

const inserUsuario = async function(){
    const SQL_QUERY = 'INSERT INTO USUARIOS (ID_USUARIO,ID_SUCURSAL,NOMBRE) values (@id_usuario,@id_sucursal,@nombre)'
    const conexion = await getConnection()
    const result = await conexion
    .request()
        .input("nombre", sql.VarChar, 'NOMBRE X' )
        .input("id_usuario", sql.Int, 10 )
        .input("id_sucursal", sql.Int, 12 )
         .query(SQL_QUERY)
    console.log(result)
}

//inserUsuario()


const getUsuario = async function(){
    const SQL_QUERY = 'SELECT * FROM USUARIOS WHERE ID_USUARIO = @ID'
    const conexion = await getConnection()
    const result = await conexion
    .request()        
        //.input("ID", sql.Int, 10 )        
        .input("ID", 10 )        
         .query(SQL_QUERY)
    console.log(result)
}

//getUsuario()


const deleteUsuario = async function(){
    const SQL_QUERY = 'DELETE USUARIOS FROM USUARIOS WHERE ID_USUARIO = @ID'
    const conexion = await getConnection()
    const result = await conexion
    .request()        
        //.input("ID", sql.Int, 10 )        
        .input("ID", 2 )        
         .execute(SQL_QUERY)
    console.log(result)
}

//deleteUsuario()


const updateUsuario = async function(){
    const SQL_QUERY = 'UPDATE USUARIOS SET nombre=@nombre WHERE ID_USUARIO = @ID'
    const conexion = await getConnection()
    const result = await conexion
    .request()        
        .input("nombre", sql.VarChar, "Nuevo Nombre" )        
        .input("ID", 10 )        
         .query(SQL_QUERY)
    console.log(result)
}

//updateUsuario()


const sp_selectall_sensorinfo = async function(){    
    const conexion = await getConnection()
    const result = await conexion
    .request()        
    .execute('sp_selectall_sensorinfo')
    console.log(result.recordset)
}
sp_selectall_sensorinfo()
const sp_selectall_records = async function(){    
    const conexion = await getConnection()
    const result = await conexion
    .request()        
    .execute('sp_selectall_records')
    console.log(result.recordset)
}
sp_selectall_records()

//sp_SelectALL()


const sp_select_sensor = async function(){    
    const conexion = await getConnection()
    const result = await conexion
    .request()        
        //.input("nombre", sql.VarChar, "Nuevo Nombre" )        
         .input("Id_sensor", 1 )        
         .execute('sp_select_sensor')
    console.log(result)
}

//sp_select_sensor()
