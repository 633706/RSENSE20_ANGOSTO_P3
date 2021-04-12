import serial
import opencv as cv2

ser = serial.Serial()
ser.baudrate = 115200
ser.port = 'COM3'
ser.open()
print(ser)

while True:
    cv2.waitKey(10)    
ser.close() 