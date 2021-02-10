const express = require('express');
const app = express();
const https = require('https')
const fs = require('fs');
var url = require('url')

app.get('/', function(req, res){
  fs.readFile('Tryapi.html', function(err, data) {
      res.writeHead(200, {'Content-type': 'text/html'});
      res.write(data);
      return res.end();
  });
});
const port = 8080
app.listen(port, function() {console.log(`Listening to port ${port}`)});