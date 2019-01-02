
var myJSON = JSON.stringify(msg.payload.weather);
let user = JSON.parse(myJSON);
var msg = {};
var msg1 = {};

msg.payload = user.Temp;
msg.topic = "Temperature";

msg1.payload = user.Humi;
msg1.topic = "Humidilty";
return [msg, msg1];