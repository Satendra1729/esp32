from machine import Pin;
from time import sleep; 

def blink(): 
    p = Pin(2,Pin.OUT)

    toggle = True; 
    while True : 
        toggle = not(toggle); 
        print("toggel flag :: ", toggle)
        if toggle: 
            p.on(); 
            sleep(1)
        else : 
            p.off()
            sleep(5)
    
if __name__=="__main__" : 
    blink()
 
    