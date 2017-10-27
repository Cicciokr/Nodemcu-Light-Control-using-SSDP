const app = require('express')();
const server = require('http').createServer(app);
var Client = require('node-ssdp-js').Client, client = new Client();

var clientList = [];

  server.listen(3000, function() {
    console.log('Server in ascolto sulla porta 3000 ...');
  });


app.get('/', function(req, res) {
  res.sendFile(__dirname+'/html/index.html');
});

app.get('/devicelist', function(req,res,next){
    //req.query.name
    res.json(clientList);
});

client.on('response', function (response) {
    console.log('Response ssdp device:', response);
    var ipNodeMcuLight = response.referrer.address;
    console.log('IP:', ipNodeMcuLight);
    clientList.push(response);
});

client.browse('upnp:nodemculight');

setTimeout(function () {
    client.stop()
}, 10000);