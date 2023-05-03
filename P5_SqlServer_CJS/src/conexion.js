const sql = require('mssql')

const config = {
    user:'sa',
    password:'Garuco19',
    server:'localhost',
    database:'BD_API_RESTful_SE',
    options: {
        encrypt: true, // for azure
        trustServerCertificate: true // change to true for local dev / self-signed certs
      }
}

const getConnection = async function (){
    try{
        const conexion = await sql.connect(config) //conexion es el objeto que representa la conexion logica con la base de datos
        return conexion
    }
    catch(error){
        console.log(error)
    }    
}

module.exports = {
    getConnection
}
