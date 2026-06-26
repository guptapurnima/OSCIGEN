import socket
import time

ESP32_IP = "192.168.4.1"
ESP32_PORT = 23

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect((ESP32_IP, ESP32_PORT))
print("Connected to ESP32!")

sock.sendall(b"Hello from phone!\n")
time.sleep(0.5)
response = sock.recv(1024)
print(f"ESP32 replied: {response.decode()}")
sock.close()
