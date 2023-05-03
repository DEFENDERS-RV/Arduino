const getAll = (req, res)=>{
    console.log('SELECT * FROM ...')
    res.status(210).send({dato1:'valor1' , dato2: 'valor'})
}

const getOne = function(req,res){
    const {params:{idActuator}} = req

    //MENSAJE DE CONFIRMACION EN CONSOLA 
    console.log(`SELECT*FROM...WHERE ID = ${idActuator}`)
    res.status(201)
    .send(`Informacion del actuador con ID: ${idActuator}`)
}

const getLeftJoin = function(req,res){
    console.log(`SELECT*FROM...INNER JOIN ... WHERE`)
}
const insertOne = function(req,res){
    console.log(`INSERT`)
}

const updateOne = function(req,res){
    const {params:{idActuator},body} = req
    console.log(`UPDATE del Actuador con el ID: ` , idActuator)
    res.status(200)
    .send({Info:"Registro Actualizado" , Description:body}
    
    )
}
const deleteOne = function(req,res){
    console.log('DELETE * FROM ...')
}

module.exports = {
    getAll,
    getOne,
    getLeftJoin,
    insertOne,
    updateOne,
    deleteOne
}