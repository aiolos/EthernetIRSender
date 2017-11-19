# EthernetIRSender

Ethernet IR Sender to send IR command through an ethernet enabled Arduino (With Wiznet Ethernet Shield)
  - Put an IR led to Pin3 of the Arduino
  - Point your browser to the given IP address (default 192.168.38.177, you can change this in the .ino file)
  - Click one of the predefined commands

  - An URL is formed like: http://192.168.38.177/?code=C0D&p=1&r=1&d=20&f=38
    Where
    - code: is the hexadecimal code of the command (recordable by putting an IR receiver on pin 5)
    - sc = second code: the second (hexadecimal) code for a single command
    - p = protocol: is the protocol to use, for now: 1 = rc5, 2=NEC, 3=Samsung
    - r = repeat: is the number of repeats of the command, defaults to 1
    - d = delay: delay between repetitive commands, in milliseconds.
    - f = frequency: use a different frequency than the default 38Khz. (most IR devices have a frequency somewhere between 36 and 40Khz)

## Dependencies
You need my fork of IRLib (https://github.com/aiolos/IRLib), since this repo depends on an adjustable frequency in the IRLib library.
