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
var day = now.getDayName();
var month = now.getMonthName();

// Variablen für Objekt
var Wert1 = global.get('Stundenzähler1FBup') ||0;
var Time = global.get('StundeFBup') ||0;




// laden des Objekts
var m =Wert1+','+Time;


return {payload:[m]};