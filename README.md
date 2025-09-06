# ESP32 Ultrasonic Distance-Based LED Indicator

This project uses an **ESP32** microcontroller and an **HC-SR04 ultrasonic sensor** to measure distance. Based on the measured distance, different LEDs are activated to provide a visual indication of how close an object is.

## 📦 Components Used

- ESP32 Development Board  
- HC-SR04 Ultrasonic Distance Sensor  
- LEDs (x5)  
- Resistors (typically 220Ω)  
- Breadboard & Jumper Wires  
- USB Cable for programming  

## ⚙️ Pin Configuration

| Component     | ESP32 GPIO Pin |
|--------------|----------------|
| HC-SR04 Trig | GPIO 5 (D5)    |
| HC-SR04 Echo | GPIO 18 (D18)  |
| LED (Close)  | GPIO 2         |
| LED1         | GPIO 23        |
| LED2         | GPIO 13        |
| LED3         | GPIO 14        |
| LED4         | GPIO 12        |

## 📏 Distance Range & LED Behavior

| Distance Range (cm) | LEDs Activated                 |
|---------------------|--------------------------------|
| 0 – 10              | `LED_PIN` (GPIO 2)             |
| 11 – 20             | `LIGHT1` (GPIO 23), `LIGHT2` (GPIO 13) |
| 21 – 50             | `LIGHT3` (GPIO 14), `LIGHT4` (GPIO 12) |
| > 50 or Invalid     | All LEDs OFF                   |

## 🧠 How It Works

1. The **HC-SR04** emits a 10µs ultrasonic pulse via the **Trig** pin.
2. The **Echo** pin listens for the reflected signal.
3. The time it takes for the echo to return is used to calculate the **distance**.
4. Based on the distance, the corresponding LEDs light up to indicate proximity.

## 🛠️ Setup Instructions

1. Wire your components according to the pin configuration above.
2. Upload the provided Arduino sketch using the Arduino IDE or PlatformIO.
3. Open the **Serial Monitor** at 115200 baud to view real-time distance measurements.

## ⏱️ Delay

- The loop uses a 500ms delay to avoid excessive readings and potential sensor instability.

## 📝 Arduino Sketch Overview

The main logic is contained in the `loop()`:
```cpp
// Sample code snippet
if (distance > 0 && distance <= 10) {
  digitalWrite(LED_PIN, HIGH);
} else {
  digitalWrite(LED_PIN, LOW);
}
