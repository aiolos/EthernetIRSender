# EthernetIRSender

Ethernet IR Sender to send IR command through an ethernet enabled Arduino (With Wiznet Ethernet Shield)
  - Put an IR led to Pin3 of the arduino
  - Point your browser to the given IP address (default 192.168.1.177)
  - Click one of the predefined commands

  - An URL is formed like: http://192.168.1.177/?code=C0D&p=1&r=1
    Where
    - code: is the hexadecimal code of the command (recodable by putting a IR receiver on pin 5)
    - sc = secondcode: the second code for a single command
    - p = protocol: is the protocol to use, for now: 1 = rc5, 2=NEC, 3=Samsung
    - r = repeat: is the number of repeats of the command, defaults to 1
    - d = delay: delay between repetitive commands