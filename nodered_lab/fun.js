var max = 22;

var min = 20;

var maxp=80;

var minp=0;

var newValue = Math.random() * (max - min) + min;

var hValue = Math.random() * (100 - 0) + 0;

var pm25 = Math.random() * (maxp - minp) + minp;

var t = new Date();

var dt = t.getFullYear()+"-"+(t.getMonth()+1)+"-"+t.getDate()+"-"+t.getHours()+":"+
    
    t.getMinutes()+":"+t.getSeconds()

var newmsg = {
    
      Timestamp: dt,
    
      Temp: newValue.toFixed(2),
    
      Humi: hValue.toFixed(2),
    
      PM25: pm25.toFixed(2)

};

var nmsg = JSON.parse(newmsg);

msg.payload = nmsg.Timestamp+","+nmsg.Temp+","+
    
     nmsg.Humi+","+nmsg.PM25;

return msg;