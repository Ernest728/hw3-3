#include "mbed.h"
#include "accelerometer.h"
#include "gyro.h"

#define MAXIMUM_BUFFER_SIZE 6

AnalogOut Aout(PA_4);
EventQueue queue(32 * EVENTS_EVENT_SIZE);
static BufferedSerial serial_port(USBTX, USBRX);
Accelerometer acc;
Gyro gyro;
double XYZ[3]={0};
int counter=0;
int idR[128] = {0};
int indexR = 0;
Thread thread1;
Thread thread2;

void print(void) {
    while (1) {
    char buf2[MAXIMUM_BUFFER_SIZE];
    acc.GetAcceleromterSensor(XYZ);
    if (serial_port.readable()) {
      serial_port.read(buf2, 1);

      if (buf2[0] == '1') {
        acc.GetAcceleromterCalibratedData(XYZ);
        printf("%f\n", XYZ[0]);
      } else if (buf2[0] == '2') {
        acc.GetAcceleromterCalibratedData(XYZ);
        printf("%f\n", XYZ[1]);
      } else if (buf2[0] == '3') {
        acc.GetAcceleromterCalibratedData(XYZ);
        printf("%f\n", XYZ[2]);
      } else {}
    }
    ThisThread::sleep_for(20ms);
  }
}

int main() {
    thread2.start(print);
}
