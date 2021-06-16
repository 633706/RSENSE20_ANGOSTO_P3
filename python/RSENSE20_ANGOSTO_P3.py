import serial

port = 'COM3'
baudrate = 115200
bytesize = serial.EIGHTBITS
parity = serial.PARITY_NONE
stopbits = serial.STOPBITS_ONE
ser = serial.Serial(port=port, baudrate=baudrate, bytesize=bytesize, parity=parity, stopbits=stopbits)

fileHandler = open("AccData.txt", "w")
fileHandler.write("X;Y;Z\n",)
try: 
    while True:
    #    print(ser.readline().decode('ascii'),end='')
        line = ser.readline().decode('ascii')
        Acc_str = line.split()
        AccX = int(Acc_str[0][5:])
        AccY = int(Acc_str[1][5:])
        AccZ = int(Acc_str[2][5:])
    
        fileHandler.write(str(AccX)+";"+str(AccY)+";"+str(AccZ)+"\n")
except KeyboardInterrupt:
    fileHandler.close()
    ser.close()