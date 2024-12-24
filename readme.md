# 🌱 **Agricultural Monitoring System Using Arduino and Blynk 2.0** 🌾

The **Agricultural Monitoring System** is an IoT-based solution designed to monitor and automate agricultural processes in real-time. By utilizing the NodeMCU ESP8266 and the Blynk 2.0 platform, this system monitors environmental parameters like soil moisture, temperature, humidity, and rain, while automating irrigation based on real-time data.

---

## 📋 **Overview**

This project integrates various sensors and components to provide a comprehensive solution for farmers. With features such as **real-time data collection**, **remote monitoring** via the Blynk app, and **automated irrigation**, this system helps optimize farming operations. Key highlights include:

- **Environmental monitoring**: Track soil moisture, temperature, humidity, and rain.
- **Automated irrigation**: Based on soil moisture levels.
- **Alerts**: Receive notifications for abnormal conditions via a buzzer and the Blynk app.
- **Local & Remote Monitoring**: Check live sensor readings via OLED display and Blynk app.

---

## 🚀 **Features**

- 📡 **Real-time soil moisture monitoring**
- 🌡️ **Temperature and humidity tracking** (DHT11 and DS18B20)
- 🌧️ **Rain detection system**
- 💧 **Automated irrigation control via relay module**
- 🖥️ **OLED display for local monitoring**
- 📱 **Blynk 2.0 app integration** for remote monitoring and control
- ⚠️ **Alert system** with buzzer for abnormal conditions
- 🛠️ **Easy setup** with comprehensive documentation

---

## 🛠️ **Hardware Requirements**

- **NodeMCU ESP8266-12E** board
- **Capacitive soil moisture sensor**
- **DHT11 temperature & humidity sensor**
- **DS18B20 waterproof temperature sensor**
- **Rain detector sensor**
- **0.96" I2C OLED display**
- **5V single-channel relay module**
- **5V small buzzer**
- **5V DC water pump**
- **4.8 kΩ resistor**
- **Jumper wires**
- **Breadboard (2x)**

---

## 💻 **Software Requirements**

### Arduino IDE
Ensure you have the appropriate version of the Arduino IDE installed.

### Arduino Libraries

Make sure to install the following libraries using the Arduino Library Manager:

- `Accessory_Shield`
- `Adafruit_10DOF`
- `Adafruit_BMP085_Unified`
- `Adafruit_BusIO`
- `Adafruit_GFX_Library`
- `Adafruit_L3GD20_U`
- `Adafruit_LSM303DLHC`
- `Adafruit_SSD1306`
- `Adafruit_Unified_Sensor`
- `AM232X`
- `AM2302-Sensor`
- `Blynk`
- `BlynkNcpDriver`
- `Bonezegei_DHT11`
- `DallasTemperature`
- `DHT_kxn`
- `Makerlabvn_I2C_Motor_Driver`
- `SimpleTimer`
- `OneWire`

---

## 🔌 **Wiring Connections**

Below are the connections for each component:

### **DHT11 Temperature & Humidity Sensor**
- **Data Pin(+ve)** -> D4
- **VCC(middle)** -> 3V3
- **GND(-ve)** -> GND

### **Capacitive Soil Moisture Sensor**
- **GND** -> GND
- **VCC** -> 3V3
- **AOUT** -> A0

### **Buzzer**
- **Negative (small pin)** -> GND
- **Positive (large pin)** -> D5

### **OLED Display (I2C)**
- **GND** -> GND
- **VCC** -> 3V3
- **SCK** -> D1
- **SDA** -> D2

### **Rain Detector Sensor**
- **DO** -> D7
- **GND** -> GND
- **VCC** -> Vin
- **AO** -> Not connected

### **Relay Module**
- **IN** -> D0
- **GND** -> GND
- **VCC** -> 3V3
- **NO (Normally Open)** -> Water pump connection
- **COM** -> 3V3

### **DS18B20 Temperature Sensor**
- **Red wire** -> Vin
- **Black wire** -> GND
- **Yellow wire** -> D6
- **4.8 kΩ resistor** -> Between yellow and red wires

### **Water Pump**
- **GND (Black wire)** -> GND
- **Red wire** -> NO (Normally Open) on relay

---

## ⚙️ **Setup Instructions**

### 1. **Install Arduino IDE**:
   - Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
   
### 2. **Install Libraries**:
   - Open Arduino IDE, go to **Sketch > Include Library > Manage Libraries...** and install the libraries listed in the **Software Requirements** section.

### 3. **Create a Blynk 2.0 Project**:
   - Download and install the **Blynk 2.0** app from the App Store or Google Play.
   - Create a new project, choose **ESP8266** as the hardware, and note down the **Auth Token**.
   - Configure virtual pins in the Blynk app to match your sensors and actuators.
   - **Note**: Detailed Blynk setup instructions are included in the [**Blynk Setup PDF**](setup.pdf).

### 4. **Configure Arduino IDE**:
   - Select **NodeMCU 1.0 (ESP-12E Module)** under **Tools > Board**.
   - Set the **Upload Speed** to **115200** in **Tools > Upload Speed**.

### 5. **Wiring the Components**:
   - Connect the components as shown in the **Wiring Connections** section.

### 6. **Upload the Code**:
   - Open the project code in Arduino IDE and upload it to the NodeMCU.

### 7. **Configure Blynk App**:
   - Add widgets in the Blynk app corresponding to your sensors (soil moisture, temperature, humidity, rain detection).
   - Use virtual pins for each sensor to enable real-time data tracking.

---

## 🛠️ **Troubleshooting**

- Ensure all connections are secure.
- Verify the 3.3V power supply for sensors.
- Check the Blynk authentication token.
- Confirm WiFi credentials are correct.
- Ensure all libraries are properly installed.

---

## ⚠️ **Safety Notes**

- Keep water away from electronic components.
- Use an appropriate power supply.
- Ensure proper grounding.
- Double-check all connections before powering on.

---

## 👨‍💻 **Contributors**

- [Shivadarshan](https://github.com/shivadarshan-devadiga)

---

## 📜 **License**

This project is licensed under the [MIT License](LICENSE).

---

## 🛠 **Feedback and Support**

For any feedback or support regarding this project, please [open an issue](https://github.com/shivadarshan-devadiga/Agricultural-Monitoring-System-Using-Arduino-and-Blynk-2.0/issues) on GitHub.

---

Thank you for exploring the **Agricultural Monitoring System**! 🌱