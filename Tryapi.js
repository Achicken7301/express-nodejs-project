const express = require('express');
const app = express();
const https = require('https');
const fs = require('fs');
var url = require('url');
const fetch = require("node-fetch");
app.get('/',function(req,res){ 
  fs.readFile('Tryapi.html', function(err, data) {
    res.writeHead(200, {'Content-type': 'text/html'});
    res.write(data);
    return res.end();
})
})
app.get('/action_page.php',function(req,res){ 
    res.write(data);
    return res.end();

})
app.get('/Api.js',function(req,res){ 
  fs.readFile('Api.js', function(err, data) {
    res.write(data);
    return res.end();
})
})
const port = 8080
app.listen(port, function() {console.log(`Listening to port ${port}`)});