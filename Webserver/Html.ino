const char PROGMEM INDEX_HTML[] = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Socket Thing1</title>
</head>
<body>
    Client1
    <button onclick="sendMessage()">Try it </button>
    <button onclick="Try()">test</button>
</body>
<script>
    // Create WebSocket connection.
    const socket = new WebSocket('ws://' + window.location.hostname + ':'+3484+'/');

    // Connection opened
    socket.addEventListener('connect', function (event) {
        console.log(event)
        console.log(event.data)
    });

    // Listen for messages
    socket.addEventListener('message', function (event) {
        console.log('Message from server ', event.data);
        console.log(event)
    });
     socket.addEventListener('test', function (event) {
        console.log('Message from server ', event.data);
    });

    const sendMessage = () => {
        socket.send('Hello From Client1!');
    }
    const Try = () => {
        socket.send(Date.now())
    }
</script>
</html>
)rawliteral";