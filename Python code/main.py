# To use this program, upload the radar.ino to the arduino. Then run the program.
# Remember to close the arduino page while running the python program
# The serial port can only connect to one program at a time


import time
import serial
import turtle as td

arduino = serial.Serial('COM3', 9600)  # Or your real port
print("Connected!")

time.sleep(3)

td.colormode(255)
td.pensize(10)
td.speed("fastest")


def draw_line(distance, angle):
    td.pensize(10)
    td.speed("fastest")
    td.setpos(0, 0)
    td.setheading(angle)
    td.color(0, 255, 0)
    if distance <= 250:
        td.forward(distance)
    else:
        td.forward(250)


def draw_semicircle():
    td.speed("fastest")
    td.colormode(255)
    td.setpos(-250, 0)
    td.setheading(90)
    td.fillcolor(255, 0, 0)
    td.color(255, 0, 0)
    td.begin_fill()
    td.circle(-250, 180)
    td.end_fill()


draw_semicircle()
while True:
    if arduino.in_waiting > 0:  # 有資料可以讀
        line = arduino.readline().decode('utf-8').strip()
        part = line.split(",")
        distance_received = int(float(part[0]) // 1) / 2
        angle_received = int(part[1])
        print(distance_received)
        print(angle_received)

        draw_line(distance_received, angle_received)

        if angle_received == 0 or angle_received == 180:
            td.clearscreen()
            draw_semicircle()
