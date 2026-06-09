from machine import Pin, I2C
import time

# Set up I2C communication on pins 21 and 22
i2c = I2C(0, scl=Pin(22), sda=Pin(21), freq=400000)

# Wake up MPU6050 (it sleeps by default)
i2c.writeto_mem(0x68, 0x6B, bytes([0]))

print("OSCIGEN - MPU6050 Online!")

while True:
    # Read 6 bytes of accelerometer data
    data = i2c.readfrom_mem(0x68, 0x3B, 6)
    
    # Convert raw bytes into numbers
    ax = (data[0] << 8 | data[1])
    ay = (data[2] << 8 | data[3])
    az = (data[4] << 8 | data[5])
    
    print(f"X: {ax}  Y: {ay}  Z: {az}")
    time.sleep(0.5)