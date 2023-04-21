const express = require('express')

//RUTAS
const router = express.Router()

router
.get("/" ,
 function(req,res){
    console.log('SELECT * FROM ...')
    res.status(210).send({dato1:'valor1' , dato2: 'valor2'})

 }
 )//EQUIVALENTE EN SQL-CRUD: SELECT * FROM...
.get("/:idActuator" , function(req,res){
    console.log('SELECT*FROM...WHERE')
}) //EQUIVALENTE EN SQL - CRUD: SELECT*FROM..WHERE
.get("/idActuator/registros" , function(req,res){
    console.log('SELECT * FROM ... INNER JOIN...WHERE')
})
.post("/" , function(req,res){
    console.log('INSERT')
}) //EQUIVALENTE EN SQL-CRUD:INSERT
.patch("/:idActuator",function(req,res){
    console.log('UPDATE')
})//EQUIVALENTE EN SQL-CRUD: INSERT
.delete("/:idActuator" , function(req,res){
    console.log('DELETE * FROM ...')
});


module.exports = router;



