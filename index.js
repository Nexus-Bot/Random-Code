var express = require('express');
var socket = require('socket.io');

// app setup
var app = express();

//server
var server = app.listen(9000 ,function(){
    console.log('listening to port 9000');
});
//static files
app.use(express.static('public'));

// socket setup
var io = socket(server);
io.on('connection', function(socket){
    console.log('made socket connection', socket.id);

    socket.on('chat',function(data){
        io.sockets.emit('chat',data);
    });
    socket.on('typing',function(data){
        socket.broadcast.emit('typing',data);
    });
});