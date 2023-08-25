import utime
import machine
pin21 = machine.Pin(2, machine.Pin.OUT)
while True:
        pin21.value(1)
        utime.sleep_ms(200)
        pin21.value(0)
        utime.sleep_ms(200)