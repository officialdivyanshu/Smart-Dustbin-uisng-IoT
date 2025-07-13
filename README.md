# Smart Dustbin using IoT

🚮 An **Arduino-based Smart Dustbin** that automatically opens the lid using an ultrasonic sensor when it detects a hand nearby and displays the **fill level on a 16x2 LCD (I2C)** using the same sensor. Designed for **efficient waste management and hygiene improvement**.

---

## 📌 Features

✅ Automatic lid opening when a hand is detected.  
✅ Automatic lid closing after use.  
✅ Fill level monitoring using a single ultrasonic sensor.  
✅ Fill level displayed in **percentage** on a 16x2 LCD (I2C).  
✅ Simple, low-cost, beginner-friendly IoT project for learning and real-life implementation.

---

## 🛠️ Components Used

- Arduino Uno
- Ultrasonic Sensor (HC-SR04)
- Servo Motor (SG90 or equivalent)
- 16x2 LCD (I2C module)
- Jumper wires
- Breadboard or direct wiring

---

## ⚡ Working Principle

- **Hand Detection:**  
  The ultrasonic sensor detects a hand within 15cm, triggering the servo motor to open the lid for 3 seconds, then automatically closes it.

- **Fill Level Measurement:**  
  After closing, the sensor measures the distance from the sensor to the trash to calculate the fill level, displayed on the LCD in percentage.

---

## 🖥️ Circuit Connections

| Component | Arduino Pin |
| --------- | ------------ |
| Ultrasonic VCC | 5V |
| Ultrasonic GND | GND |
| Ultrasonic TRIG | Pin 2 |
| Ultrasonic ECHO | Pin 3 |
| Servo Signal | Pin 10 |
| Servo VCC | 5V |
| Servo GND | GND |
| LCD SDA | A4 |
| LCD SCL | A5 |
| LCD VCC | 5V |
| LCD GND | GND |

---

## 🖼️ Diagram

The project diagram is available in `diagram.json` and can be opened in [Wokwi](https://wokwi.com/) for simulation.

---

## 🚀 How to Run

1️⃣ Clone this repository or download the `.ino` file.  
2️⃣ Open in **Arduino IDE** or **Wokwi** for testing.  
3️⃣ Connect your hardware as per the circuit diagram.  
4️⃣ Upload the code to your Arduino Uno.  
5️⃣ Power the system and test hand detection and level monitoring.

---

## 🪐 Future Improvements

✅ Add **WiFi module (ESP8266/ESP32)** to send fill level data to a cloud dashboard.  
✅ Add **buzzer alert** when the dustbin is full.  
✅ Use **battery + solar charging** for outdoor use.  
✅ Integrate with **Blynk/ThingSpeak** for remote monitoring.

---

## 🧑‍💻 Author

Divyanshu Shekhar

---

## 📜 License

This project is licensed under the MIT License - feel free to use and modify it for learning and academic projects.

---

## 🌟 Acknowledgements

- Inspired by smart waste management solutions for clean and sustainable environments.
- Uses open-source Arduino libraries and Wokwi simulator for testing and demonstration.

---

