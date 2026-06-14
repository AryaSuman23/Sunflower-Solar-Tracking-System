Sunflower Solar Tracker

This is my first Arduino project—a dual-axis solar tracking system built using an Arduino Uno, four LDRs (Light Dependent Resistors), two servo motors,
resistors, jumper wires, and a breadboard. The inspiration behind the project was the natural behavior of a sunflower, which turns toward the sun 
throughout the day. The goal was to create a system that automatically detects the brightest light source and adjusts its position to face it.
The tracker continuously measures light intensity from four different directions using LDRs arranged in a cross pattern. Based on these readings,
the Arduino controls two servo motors to rotate toward the brightest source of light. One servo provides horizontal movement (left and right), 
while the other provides vertical movement (up and down).

The hardware setup consists of an Arduino Uno, four LDRs connected through 10kΩ resistors configured as voltage dividers,
and two SG90 servo motors. The LDRs are connected to analog input pins, while the servos are connected to PWM-capable digital pins.
During development, I learned the importance of understanding pin functionality. Initially, I made mistakes by connecting LDRs to digital pins and placing a 
servo on an unsuitable pin. Troubleshooting these issues helped me understand the difference between analog and digital 
signals and how PWM is used to control servo positions.

The software was developed using Arduino IDE and the Servo.h library. The program continuously reads the four LDR values, 
compares the light intensity on opposite sides, and moves the servos in small steps toward the brighter direction.
A threshold value was introduced to prevent unwanted servo jitter caused by minor fluctuations in sensor readings. 
This made the tracker smoother and more stable while still responding quickly to changes in light.

As my first Arduino project, Sunflower taught me valuable concepts in electronics, sensor interfacing, servo motor control,
debugging, and embedded programming. Future improvements include upgrading to an ESP32 for Wi-Fi connectivity, 
creating an IoT monitoring dashboard, implementing data logging, and eventually scaling the design to track a real solar panel. 
This project marks the beginning of my journey into embedded systems and IoT development. 🌻🚀
