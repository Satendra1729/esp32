# ESP32 with micropython



## download micropython firmware

## setup esptool.py

## erase esp32 memory and install downloaded firmware

```bash
esptool.py --chip esp32 --port /dev/ttyUSB0 erase_flash
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 460800 write_flash -z 0x1000 ESP32_GENERIC-20240222-v1.22.2.bin
```

## install rshell

## use command 'modinfo cp210x' to verify that cp210x, on already install or not on ubuntu

## make sure user is added to the dialout group

## make sure connector cable is cabable to transfer the data not only power

## use rshell for repl and copy the files into the esp32 as 

```bash 
    rshell -p /dev/ttyUSB0
    repl # It will present the python interpretor repl, exit() will not work to disconnect manuall unplut the esp
    cp local_file.py /pyboard/ # will copy the local file to the esp32

    picocom /dev/ttyUSB0 -b115200 # alternate to rshell picocom can be use to connect repl 
```


[reference](https://www.youtube.com/watch?v=w15-EQASP_Y&list=PLKGiH5V9SS1hUz5Jh_35oTFM4wPZYA4sT&index=1)