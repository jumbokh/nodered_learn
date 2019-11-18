## 亂數
* var num = Math.floor(Math.random()*6)+1;
* msg.payload = num;
* msg.topic="hello";
* return msg;


### 亂數產生函數
* function getRandom(min,max){
*     return Math.floor(Math.random()*max)+min;
* }
* 
* var num = getRandom(16,31);
* msg.payload = num;
* return msg;
