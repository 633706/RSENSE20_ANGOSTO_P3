import serial
port = 'COM3'
baudrate = 115200
bytesize = serial.EIGHTBITS
parity = serial.PARITY_NONE
stopbits = serial.STOPBITS_ONE
ser = serial.Serial(port=port, baudrate=baudrate, bytesize=bytesize, parity=parity, stopbits=stopbits)

while True:
    line = ser.readline()
    print(line.decode('ascii'),end='')
ser.close()