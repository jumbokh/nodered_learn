(function() {
    var days = ['Sonntag','Montag','Dienstag','Mittwoch','Donnerstag','Freitag','Samstag'];

    var months = ['January','February','March','April','May','June','July','August','September','October','November','December'];

    Date.prototype.getMonthName = function() {
        return months[ this.getMonth() ];
    };
    Date.prototype.getDayName = function() {
        return days[ this.getDay() ];
    };
})();

var now = new Date();
var year    = now.getFullYear();
var monthX   = now.getMonth()+1; 
var dayX     = now.getDate();
var hour    = now.getHours();
var minute  = now.getMinutes();
var second  = now.getSeconds(); 
if(monthX.toString().length == 1) 
{
var monthX = '0'+monthX;
}
if(dayX.toString().length == 1) 
{
var dayX = '0'+dayX;
}   
if(hour.toString().length == 1) 
{
var hour = '0'+hour;
}
if(minute.toString().length == 1) 
{
var minute = '0'+minute;
}
if(second.toString().length == 1) 
{
var second = '0'+second;
} 

var day = now.getDayName();
var month = now.getMonthName();

// Variablen für Objekt
var Wert1 = global.get('Stundenzähler1FBup') ||0;
var Time = global.get('StundeFBup') ||0;

// Stunde

    // Zählen von Wert1
    Wert1 = global.get('Stundenzähler1FBup')||0;
    Wert1++;
    global.set('Stundenzähler1FBup', Wert1);
        
var Time = global.set('StundeFBup',day+' '+dayX+'.'+monthX+'.'+year+' '+hour+':'+minute+':'+second); 
return msg;

    