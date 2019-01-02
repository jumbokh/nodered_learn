var myJSON = JSON.stringify(msg.payload.weather);
let user = JSON.parse(myJSON);
msg.payload = user.timestamp+","+user.Temp+","+user.Humi;
return msg;