const app = require('express')();
const http = require('http');
//const io = require('socket.io')(http);
const server = http.createServer(app)

const WebSocket = require('ws');

socket = new WebSocket.Server({server});
app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});

socket.on('connection', function (ws,req) {
  

    const ip = req.socket.remoteAddress
    console.log("New client connected"+ip)

  console.log('started client interval');
  ws.on('message', function (msg) {
    console.log("message: "+msg);
    });
  ws.on('close', function () {
    console.log('stopping client interval');

  });
});
server.listen(3484, () => {
  console.log('listening on *:3484');
});
