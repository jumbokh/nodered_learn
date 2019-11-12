研究筆記 - AirBox API整理
 

- RootUrl: 
    - http://airbox.asuscloud.com/
    - https://airbox.asuscloud.com/

 

- GET airbox/messages/
    Description: 取得所有合法 AirBox 裝置最近一次通報紀錄
    Resource URL: http://airbox.asuscloud.com/airbox/messages/
    Example URL: http://airbox.asuscloud.com/airbox/messages/

 

- GET airbox/device/:id
    Description: 取得單一合法 AirBox 裝置一週內所有通報資料
    Resource URL: http://airbox.asuscloud.com/airbox/device/:id
        parameter:
        - id: AirBox 的 device id (required)
    Example URL: http://airbox.asuscloud.com/airbox/device/7BC4FFFF9874
     
- GET airbox/device/:id/:startTimestamp/:endTimeStamp
    description: 取得單一合法 AirBox 裝置特定時間區間內所有通報資料
    Resource URL: http://airbox.asuscloud.com/airbox/device/:id/:startTimestamp/:endTimestamp
        parameter:
        - id: AirBox 的 device id (required)
        - startTimestamp: 區間起始點的 timestamp (required)
        - endTimeStamp: 區間結束點的 timestamp (required)
    Example URL: http://airbox.asuscloud.com/airbox/device/7BC4FFFF9874/1456761600000/1459353600000
* [code](https://github.com/howardweng/FLASS)
