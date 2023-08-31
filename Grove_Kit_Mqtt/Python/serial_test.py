import serial
import time

serialPort = serial.Serial(
    port="COM3", baudrate=9600, timeout=2
)
serialString = ""  # Used to hold data coming over UART
serialString_cmp = ""  # Used to hold data coming over UART
while 1:
    # Wait until there is data waiting in the serial buffer
    if serialPort.in_waiting > 0:

        # Read data out of the buffer until a carraige return / new line is found
        serialString = serialPort.readline()

        # Print the contents of the serial data
        try:
            serialString_cmp = serialString.decode("Ascii")[:-2]
            print(len(serialString_cmp))
            if serialString_cmp == "<Arduino is ready>":
                serialPort.write(b'ON')
            if serialString_cmp == "LED is ON":
                serialPort.write(b'OFF')
            if serialString_cmp == "LED is OFF":
                serialPort.write(b'ON')
        except:
            continue
