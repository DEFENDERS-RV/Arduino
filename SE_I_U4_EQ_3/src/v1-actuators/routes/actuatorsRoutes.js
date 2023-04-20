const express = require('express')

//RUTAS
const router = express.Router()

router
.get("/" , function(req,res){})
.get("/:idActuator" , function(req,res){})
.get("/idActuator/registros" , function(req,res){})
.post("/" , function(req,res){})
.patch("/:idActuator",function(req,res){})
.delete("/:idActuator" , function(req,res){});


module.exports = router;



