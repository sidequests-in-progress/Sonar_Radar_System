This is a radar system that uses an Arduino sonar component to plot the surroundings.
Uses an SG-90 180° positional motor and HC-SR04 sonar component.
The Arduino Uno is connected via the serial port to a Python program that plots the results from the sonar component via the turtle UI.

Note: Run the Python program first, then restart the Arduino to obtain the result.
Note: While running the program, the serial port only allows either the Python program or the Arduino DIE to read the values. Cannot debug the values through Arduino DIE while the Python program is running and reading them.


<img width="1570" height="1420" alt="Scheme-it-export-HardHack26-2026-01-25-10-16" src="https://github.com/sidequests-in-progress/Sonar_Radar_System/blob/main/Radar_system_Schematics.png" />
