const express = require('express')

const v1Actuators = require('./v1-actuators/routes/actuatorsRoutes')

const app = express();
const PORT = process.env.PORT || 3000;
app.use(express.json())

app.use("/api/v1-sensors/actuators" , v1Actuators)

app.get("/",(req , res)=>{
    res.send(`<h1>API RESTful en NodeJs para Servicios Embebidos</h1>`)
})


app.listen(PORT ,()=>{
    console.log(`Servidor escuchado en el Puerto: ${PORT}`);
})

