import serial
import matplotlib.pyplot as plt
import numpy as np

port = 'COM3'
baudrate = 115200
bytesize = serial.EIGHTBITS
parity = serial.PARITY_NONE
stopbits = serial.STOPBITS_ONE
ser = serial.Serial(port=port, baudrate=baudrate, bytesize=bytesize, parity=parity, stopbits=stopbits)

fileHandler = open("AccData.txt", "w")
fileHandler.write("X;Y;Z\n")

fileHandler2 = open("Acc_Mean_std.txt", "w")
fileHandler2.write("MeanX;MeanY;MeanZ;stdX;stdY;stdZ\n")

AccsX = np.asarray([])
AccsY = np.asarray([])
AccsZ = np.asarray([])

AccX_Mean = np.asarray([])
AccY_Mean = np.asarray([])
AccZ_Mean = np.asarray([])

AccX_STD = np.asarray([])
AccY_STD = np.asarray([])
AccZ_STD = np.asarray([])

fig_mean = plt.figure()
fig_std = plt.figure()

try: 
    while True:
        line = ser.readline().decode('ascii')
        print(line,end='')
        Acc_str = line.split()
        AccX = int(Acc_str[0][5:])
        AccY = int(Acc_str[1][5:])
        AccZ = int(Acc_str[2][5:])
    
        fileHandler.write(str(AccX)+";"+str(AccY)+";"+str(AccZ)+"\n")

        AccsX = np.append(AccsX,AccX)
        AccsY = np.append(AccsY,AccY)
        AccsZ = np.append(AccsZ,AccZ)
        if AccsX.shape[0] == 100:
            AccX_Mean = np.append(AccX_Mean,np.mean(AccsX))
            AccX_STD = np.append(AccX_STD,np.std(AccsX))

            AccY_Mean = np.append(AccY_Mean,np.mean(AccsY))
            AccY_STD = np.append(AccY_STD,np.std(AccsY))

            AccZ_Mean = np.append(AccZ_Mean,np.mean(AccsZ))
            AccZ_STD = np.append(AccZ_STD,np.std(AccsZ))
            
            xdata = range(AccX_Mean.shape[0])
            
            fig_mean.clf()
            ax = fig_mean.add_subplot(1, 1, 1)
            ax.plot(xdata, AccX_Mean)
            ax.plot(xdata, AccY_Mean)
            ax.plot(xdata, AccZ_Mean)
            plt.show()
            plt.pause(0.0001)
            
            fig_std.clf()
            ax = fig_std.add_subplot(1, 1, 1)
            ax.plot(xdata, AccX_STD)
            ax.plot(xdata, AccY_STD)
            ax.plot(xdata, AccZ_STD)
            plt.show()
            plt.pause(0.0001)
            
            fileHandler2.write(str(np.mean(AccsX))+";"+
                               str(np.mean(AccsY))+";"+
                               str(np.mean(AccsZ))+";"+
                               str(np.std(AccsX))+";"+
                               str(np.std(AccsY))+";"+
                               str(np.std(AccsZ))+"\n")
            AccsX = np.asarray([])
            AccsY = np.asarray([])
            AccsZ = np.asarray([])
            
            
            
            
except KeyboardInterrupt:
    fileHandler.close()
    fileHandler2.close()
    ser.close()