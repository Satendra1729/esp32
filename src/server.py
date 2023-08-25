import machine
from time import time

def server(): 
    pins = [machine.Pin(i, machine.Pin.IN) for i in (0, 4, 5, 12, 13, 14, 15)]    
    
    p2 = machine.Pin(2,machine.Pin.OUT)
    toggle = False; 


    html = """<!DOCTYPE html>
    <html>
        <head> <title>ESP8266 Pins</title> </head>
        <body> <h1>ESP8266 Pins at %s </h1>
            <table border="1"> <tr><th>Pin</th><th>Value</th></tr> %s </table>
        </body>
    </html>
    """

    import socket
    addr = socket.getaddrinfo('0.0.0.0', 80)[0][-1]

    s = socket.socket()
    s.bind(addr)
    s.listen(1)

    print('listening on', addr)

    while True:
        cl, addr = s.accept()
        print('client connected from', addr)
        cl_file = cl.makefile('rwb', 0)
        while True:
            line = cl_file.readline()
            if not line or line == b'\r\n':
                break
        rows = ['<tr><td>%s</td><td>%d</td></tr>' % (str(p), p.value()) for p in pins]
        response = html % (time(),'\n'.join(rows))
        toggle = not(toggle)
        if toggle : 
            p2.on() 
        else : 
            p2.off()
        cl.send('HTTP/1.0 200 OK\r\nContent-type: text/html\r\n\r\n')
        cl.send(response)
        cl.close()

if __name__=="__main__" : 
    server(); 