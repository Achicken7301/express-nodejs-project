const express = require('express');
const app = express();
const html = require(./index.html);

const fs = require('fs');

const animals = [
    {id: 1, name: "dog"},
    {id: 2, name: "cat"},
    {id: 3, name: "monkey"},
]

app.get('/', function(req, res){
    fs.readFile('index.html', function(err, data){
        res.writeHead(200, {'Content-Type': 'text/html'});
        res.write(data);
        return res.end();
    })
});

app.get('/api/animals', function(req, res){
    res.send(animals);
});

app.get('/api/animals/:id', (req, res) => {
    const animal = animals.find(c => c.id === parseInt(res.params.id));
    if(!animal) res.status(404).send('Object not found.');
    res.send(animals);
})

const port = process.env.port || 5500;
app.listen(port, function() {console.log(`Listening to port ${port}`)});
