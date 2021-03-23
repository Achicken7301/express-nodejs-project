const app = require('express')();
const http = require('http');
const server = http.createServer(app)
const WebSocket = require('ws');

socket = new WebSocket.Server({ server });
app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});

socket.on('connection', function (ws, req) {
  const ip = req.socket.remoteAddress
  //in ra dia chi ip cua client ket noi toi
  console.log("New client connected" + ip);

  //
  ws.on('message', function (msg) {
    console.log("Client sent a message: " + msg);

    //tin nhan nay gui duoi dang object
    ws.send('tin nhan nay gui toi web client!');
  });

  ws.on('close', ()=>{console.log("A Client has disconnected from Server")});
});

server.listen(3000, () => {
  console.log('listening on *:3000');
});
