const express = require('express');
const app = express();

const animals = [
    {id: 1, name: "dog"},
    {id: 2, name: "cat"},
    {id: 3, name: "monkey"},
]

app.get('/', function(req, res){
    res.send('this is root of the website!!');
});

app.get('/api/animals', function(req, res){
    res.send(animals);
});

app.get('/api/animals/:id', (req, res) => {
    const animal = animals.find(c => c.id === parseInt(res.params.id));
    if(!animal) res.status(404).send('Object not found.');
    res.send(animals);
})

const port = process.env.port || 3000;
app.listen(port, function() {console.log(`Listening to port ${port}`)});
