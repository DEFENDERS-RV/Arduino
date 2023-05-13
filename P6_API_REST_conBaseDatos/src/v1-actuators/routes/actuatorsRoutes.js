const express = require('express')

const controlActuator = require('../../controllers/actuatorController')
//RUTAS
const router = express.Router()

router
.get("/" ,controlActuator.getAll)//EQUIVALENTE EN SQL-CRUD: SELECT * FROM...

.get("/:idActuator" , controlActuator.getOne)
 //EQUIVALENTE EN SQL - CRUD: SELECT*FROM..WHERE
.get("/idActuator/registros" , controlActuator.getLeftJoin)

.post("/" , controlActuator.insertOne) //EQUIVALENTE EN SQL-CRUD:INSERT

.patch("/:idActuator",controlActuator.updateOne)//EQUIVALENTE EN SQL-CRUD: INSERT

.delete("/:idActuator" , controlActuator.deleteOne);

module.exports = router;



