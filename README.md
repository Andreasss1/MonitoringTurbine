# MonitoringTurbine

# Introduction:
This system aims to monitor turbine performance remotely with 4G communication connected through the Blynk platform. This system monitors the turbine performance from the rotation speed (rpm) and the equilibrium between the two vibration values at each end of the turbine.

# Tools and Materials:
1. ESP8266
2. Digital vibration sensor (SW-420)
3. Speed sensor (IR Speed)
4. Arduino IDE
5. Jumper cables
6. Red LED & Green LED

# How it works:
The two vibration sensors are mounted on each end of the turbine to read the indication of equilibrium using AND logic when both sensors are 1 it will turn on the green LED for a balanced indication and if the two sensors have different values it will turn on the red LED and as an indication of unbalanced. The speed sensor will read the speed of a turbine in rpm using an IR speed sensor to determine whether the turbine is working normally or there is an anomaly in the turbine.
