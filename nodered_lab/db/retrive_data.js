var max = 22;
var min = 20;
var newValue = Math.random() * (max - min) + min;
var hValue = Math.random() * (100 - 0) + 0;
var myDate = new Date();
var t = myDate.getFullYear()+"-"+(myDate.getMonth()+1)+"-"+
  myDate.getDate()+"-"+myDate.getHours() + ":" + 
  myDate.getMinutes() + ":" + myDate.getSeconds();
var date = myDate.getFullYear()+"-"+(myDate.getMonth()+1)+"-"+
           myDate.getDate();
var time = myDate.getHours() + ":" + myDate.getMinutes() + 
           ":" + myDate.getSeconds();
  
msg.payload ={
weather: {
    timestamp: t,
    Temp: newValue.toFixed(2),
    Humi: hValue.toFixed(2),
	date: date,
	time: time
}
};
return msg;