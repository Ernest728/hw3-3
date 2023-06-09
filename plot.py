import numpy as np
import serial
import matplotlib.pyplot as plt
import time
serdev = 'COM4'
s = serial.Serial(serdev)
x = []
y = []
z = []
t = np.arange(0,2.54,0.02)
s.write(b'1')
time.sleep(10)
for i in range(0, 127):
    x.append(float(s.readline().decode()))
    y.append(float(s.readline().decode()))
    z.append(float(s.readline().decode()))
fig, ax = plt.subplots(3, 1)
y_ticks = np.linspace(min(x), max(x), 10)
plt.yticks(y_ticks)
ax[0].plot(t,x)
ax[0].set_xlabel('Time')
ax[0].set_ylabel('X-axis')
y_ticks = np.linspace(min(y), max(y), 10)
plt.yticks(y_ticks)
ax[1].plot(t,y)
ax[1].set_xlabel('Time')
ax[1].set_ylabel('Y-axis')
y_ticks = np.linspace(min(z), max(z), 10)
plt.yticks(y_ticks)
ax[2].plot(t,z)
ax[2].set_xlabel('Time')
ax[2].set_ylabel('Z-axis')
plt.show()
s.close()
