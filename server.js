const app = require('express')();
const http = require('http').Server(app);
const io = require('socket.io')(http);
const ip = require('ip');
//const  socket = require('socket.io')(http)();


app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});

io.on('connection', (socket) => {
  console.log('connected');
  socket.on('event_name', function(data) {
      socket.emit('greating', "this message from nodejs");
  });

  socket.on('disconnect', () => {
      console.error('disconnected.');
  });

  socket.on('greating', (data) => {
    console.log(data);
  });
});

http.listen(3000);
console.log(ip.address());