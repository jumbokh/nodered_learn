/*
 Control of Humidifier Connected to a RC Socket
 https://github.com/krzychb/OnlineHumidifier
 Part 6 - Chart
 
 Copyright (c) 2015 Krzysztof Budzynski. All rights reserved.
 This file is part of OnlineHumidifier project - https://github.com/krzychb/OnlineHumidifier

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */


//
// Measure ambient humidity using DHT sensor
//
void measureHnT(void)
{
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  if (isnan(humidity)||isnan(temperature))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%");
  Serial.print("\t\tTemperature: ");
  Serial.print(temperature);
  Serial.println(" C");
}

