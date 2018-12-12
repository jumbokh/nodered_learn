var max = 22;
var min = 20;
var newValue = Math.random() * (max - min) + min;
var hValue = Math.random() * (100 - 0) + 0;
msg.payload = JSON.stringify({
    Temp: newValue.toFixed(2),
    Humi: hValue.toFixed(2)
});
return msg;