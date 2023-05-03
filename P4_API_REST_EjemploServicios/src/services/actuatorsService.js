const getAll = ()=>{
return "Todos los registros"
}

const getOne = function(id){
    return `Datos del ID ${id}`
}
const getLeftJoin = function(id){
    return `Datos JOIN ID ${id}`
}
const insertOne = function(objeto){
    return `Datos del objeto ${objeto}`
}

const updateOne = function(id, objeto){
    return `Update de los datos del ID ${id} objeto: ${objeto}`

}
const deleteOne = function(id){
    return `Datos del ID ${id} borrados`   
}

module.exports = {
    getAll,
    getOne,
    getLeftJoin,
    insertOne,
    updateOne,
    deleteOne
}