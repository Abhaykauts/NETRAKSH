# Gesture-Controlled Home Automation System

### A portable home automation system designed to assist senior citizens and disabled individuals in controlling their home devices through hand gestures and voice commands.

## Overview

 The system enables users to control their home devices with hand gestures using **OpenCV** technology and voice commands. It is equipped with a **fall detection system** for additional safety. 

The project is built to be portable, cost-effective, and designed to work both during the day and at night.

## Key Features

- **Gesture Control**: Hand gestures are detected using a **NOIR camera** connected to a **Raspberry Pi 5**.
- **Voice Commands**: Integrated voice command system for hands-free device control.
- **Haptic Feedback**: Provides tactile feedback for gesture recognition.
- **Fall Detection System**: Monitors body movement and detects falls using an **MPU 6050 gyroscope sensor**.
- **Portable and Cost-Effective**: Powered by a power bank, making it easy to use anywhere in the home.
  
## Components

- **Raspberry Pi 5**: The central control unit of the system.
- **NOIR Camera**: Used for gesture detection in low-light conditions.
- **NodeMCU ESP32**: Facilitates communication between sensors and devices.
- **MPU 6050 Gyroscope Sensor**: Used for fall detection.
- **Vibration Motor**: Provides haptic feedback.
- **Power Bank**: Portable power source for the Raspberry Pi.

## Installation and Setup

### Prerequisites

- **Raspberry Pi 5** with Raspbian OS installed.
- **NOIR Camera** connected to the CSI port of the Raspberry Pi.
- **MPU 6050 Gyroscope Sensor** connected to the GPIO pins of the Raspberry Pi.
- **NodeMCU ESP32** connected via USB for serial communication.
- **Python** installed on the Raspberry Pi.
- **OpenCV** library for gesture detection.

### Steps to Run

1. **Clone the repository**:

   ```bash
   git clone https://github.com/your-username/home-automation-system.git
   cd home-automation-system
   ```

2. **Install dependencies**:

   ```bash
   pip install -r requirements.txt
   ```

3. **Set up Firebase**:

   - Create a Firebase project.
   - Set up real-time database for storing gesture commands and fall detection alerts.
   - Update Firebase configuration in the project.

4. **Connect the hardware**:
   - Plug the NOIR camera into the Raspberry Pi CSI port.
   - Connect the NodeMCU ESP32 and MPU 6050 sensors as per the wiring diagram.
   
5. **Run the application**:

   ```bash
   python main.py
   ```

6. **Upload gestures to Firebase**:
   - The system will capture and save gestures to Firebase in real-time.

## Usage

- **Gesture Control**: Perform predefined hand gestures in front of the camera to control connected devices.
- **Voice Commands**: Use the microphone to give voice commands for device control.
- **Fall Detection**: The system monitors body movements and sends alerts in case of a fall.

## Feasibility

- **Social Benefits**: Empowers disabled and elderly individuals to live independently by controlling their home appliances through intuitive gestures and voice commands.
- **Economic Impact**: The cost-effective design ensures accessibility for a wider audience.
- **Environmental Impact**: Reduces energy consumption by enabling better control over household devices.

## Future Enhancements

- **Night Vision Enhancements**: Improve gesture recognition in low-light conditions.
- **Integration with IoT Devices**: Add more devices and sensors for extended functionality.
- **Mobile App**: Develop a mobile application for monitoring and control via smartphones.

## Team

- Abhay Kauts – Project Captain & Developer.
- Aditya Chandra Verma – Hardware Lead.
- Vaibhav Arya- Electronics Head.
- Kartik Gupta- AI/ML Head.
- Rishi Arora- Android Developer.
- Kajal Savita- Android Developer.
