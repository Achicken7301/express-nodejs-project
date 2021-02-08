const express = require('express');
const app = express();

const fs = require('fs');

const animals = [
    {id: 1, name: "dog"},
    {id: 2, name: "cat"},
    {id: 3, name: "monkey"},
]

app.get('/', function(req, res){
    fs.readFile('index.html', function(err, data) {
        res.writeHead(200, {'Content-type': 'text/html'});
        res.write(data);
        return res.end();
    });
});

const port = process.env.port || 8080;
app.listen(port, function() {console.log(`Listening to port ${port}`)});
