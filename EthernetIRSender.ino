/*
  Ethernet IR Sender

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
 */

#include <SPI.h>
#include <Ethernet.h>
#include <IRLib.h>
#include <stdlib.h> 


// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

//int RECV_PIN = 5;

IRsend irsend;

String readString; 
int repeat = 3;
int frequency = 38;
int delayValue = 40;
char p;
char data[100];
int protocol = 1; // 1 = "rc5", 2 = "nec", 3 = "samsung";
unsigned long code;
unsigned long secondcode;
bool commandSend = false;

//unsigned long irCode;
//String irProtocol;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print(F("server is at "));
  Serial.println(Ethernet.localIP());
}

unsigned long last = millis();

void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();

  if (client) {
    Serial.println(F("new client"));
    // an http request ends with a blank line
    //boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
      
        char c = client.read();
        //read char by char HTTP request
        if (readString.length() < 100) {

          //store characters to string 
          readString += c; 
        } 
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n') {
          ///////////////
          Serial.println(readString); //print to serial monitor for debuging 

          //now output HTML data header
          client.println(F("HTTP/1.1 200 OK")); //send new page
          client.println(F("Content-Type: text/html"));
          client.println();

          client.println(F("<HTML><HEAD>"));
          client.println(F("<TITLE>Ethernet IR Sender</TITLE></HEAD>"));
          client.println(F("<BODY>"));

          client.println(F("<a href='/'><H1>Ethernet IR sender</H1></a>"));

          client.println(F("<h2>Philips</h2>"));
          client.println(F("<a href='/?code=410&p=1'>Vol +</a>")); 
          client.println(F("<a href='/?code=411&p=1'>Vol -</a>")); 
          client.println(F("<a href='/?code=47F&p=1&r=10'>Tuner aan</a>")); 
          client.println(F("<a href='/?code=44C&p=1'>Uit</a>")); 
          client.println(F("<a href='/?code=C0D&p=1'>Mute</a>")); 

          client.println(F("<h2>Pioneer</h2>"));
          client.println(F("<a href='/?code=A55A50AF&p=2&r=3&f=40&d=20'>Vol +</a>")); 
          client.println(F("<a href='/?code=A55AD02F&p=2&r=3&f=40&d=20'>Vol -</a>")); 
          client.println(F("<a href='/?code=A55AD827&p=2&r=5&f=40&d=20'>Uit</a>"));  
          client.println(F("<a href='/?code=A55A58A7&p=2&r=5&f=40&d=20'>Aan</a>")); 
          client.println(F("<a href='/?code=A55A8A75&p=2&r=3&f=40&d=20'>Mute aan</a>"));
          client.println(F("<a href='/?code=A55A4AB5&p=2&r=3&f=40&d=20'>Mute Off</a>"));
          client.println(F("<a href='/?code=A55A48B7&p=2&r=3&f=40&d=20'>Mute</a>"));
          client.println(F("<a href='/?code=A55A7A85&sc=A55A837C&p=2&r=3&f=40&d=20'>D AUX</a>"));
          client.println(F("<a href='/?code=A55AF20D&p=2&r=3&f=40&d=20'>A AUX</a>"));
          client.println(F("<a href='/?code=A55AA15E&p=2&r=3&f=40&d=20'>AppleTV</a>"));
          client.println(F("<a href='/?code=A55A3AC5&sc=A55A03FC&p=2&r=3&f=40&d=20'>AppleTV3</a>"));

          client.println(F("<h2>DAB</h2>"));
          client.println(F("<a href='/?code=40BF18E7&p=2&r=1'>Vol +</a>")); 
          client.println(F("<a href='/?code=40BF30CF&p=2&r=1'>Vol -</a>")); 
          client.println(F("<a href='/?code=40BFC837&p=2&r=1'>Uit</a>")); 
          client.println(F("<a href='/?code=40BF609F&p=2&r=1'>Mute</a>"));
          client.println(F("<a href='/?code=40BFC03F&p=2&r=1'>Up</a>"));
          client.println(F("<a href='/?code=40BF906F&p=2&r=1'>Down</a>"));
          client.println(F("<a href='/?code=40BFA05F&p=2&r=1'>Left</a>"));
          client.println(F("<a href='/?code=40BF9867&p=2&r=1'>Right</a>"));
          client.println(F("<a href='/?code=40BF22DD&p=2&r=1'>Select</a>"));
          client.println(F("<a href='/?code=40BF20DF&p=2&r=1'>Mode+</a>")); 
          client.println(F("<a href='/?code=40BFE01F&p=2&r=1'>Mode-</a>")); 
          client.println(F("<a href='/?code=40BF02FD&p=2&r=1'>1</a>")); 
          client.println(F("<a href='/?code=40BFD827&p=2&r=1'>2</a>")); 
          client.println(F("<a href='/?code=40BF827D&p=2&r=1'>3</a>")); 
          client.println(F("<a href='/?code=40BF42BD&p=2&r=1'>4</a>")); 
          client.println(F("<a href='/?code=40BF08F7&p=2&r=1'>5</a>")); 
          client.println(F("<a href='/?code=40BF48B7&p=2&r=1'>6</a>")); 
          client.println(F("<a href='/?code=40BF38C7&p=2&r=1'>7</a>")); 
          client.println(F("<a href='/?code=40BFB847&p=2&r=1'>8</a>")); 
          client.println(F("<a href='/?code=40BFF807&p=2&r=1'>9</a>")); 
          client.println(F("<a href='/?code=40BF28D7&p=2&r=1'>10</a>")); 
          client.println(F("<a href='/?code=40BFF00F&p=2&r=1'>11</a>")); 
          client.println(F("<a href='/?code=40BFD02F&p=2&r=1'>12</a>")); 

          client.println(F("<h2>Samsung</h2>"));
          client.println(F("<a href='/?code=E0E040BF&p=3&r=2'>Aan/Uit</a>"));
          client.println(F("<a href='/?code=E0E09966&p=3&r=2'>Aan</a>"));
          client.println(F("<a href='/?code=E0E019E6&p=3&r=2'>Uit</a>"));
          client.println(F("<a href='/?code=E0E043BC&p=3&r=2'>HDMI3</a>"));
          client.println(F("<a href='/?code=E0E0D827&p=3&r=2'>TV</a>"));

          client.println(F("</BODY></HTML>"));

          delay(1);
          //stopping client
          client.stop();

          readString.replace(" HTTP/1.1", "");
          readString.toCharArray(data, 100);
          //Serial.println(data);
          char *token = strtok(data, "?"); // Get everything up to the /
          if(token) // If we got something
          {
             char *name = strtok(NULL, "="); // Get the first name. Use NULL as first argument to keep parsing same string
             while(name)
             {
                commandSend = true;
                char *value = strtok(NULL, "&");
                if(value)
                {
                   // Do something with name and valu
                   if (strcmp(name, "p") == 0) {
                    protocol = atoi(value);
                   } else if (strcmp(name, "r") == 0) {
                    repeat = atoi(value);
                   } else if (strcmp(name, "code") == 0) {
                    code = strtoul(value, 0, 16);
                   } else if (strcmp(name, "sc") == 0) {
                    secondcode = strtoul(value, 0, 16);
                   } else if (strcmp(name, "f") == 0) {
                    frequency = atoi(value);
                   } else if (strcmp(name, "d") == 0) {
                    delayValue = atoi(value);
                   }
                   
                   name = strtok(NULL, "="); // Get the next name
                }
             }
  
            if (commandSend) {
              Serial.println(F("protocol/code/repeat"));
              Serial.println(protocol);
              Serial.println(code);
              Serial.println(repeat);
              if (repeat > 10) {
                repeat = 10;
              }
  
              for (int i = 0; i < repeat; i++) {
                if (protocol == 1) {
                  irsend.send(RC5, code, 12, 38); // d4c
                  Serial.println(F("Sending protocol rc5"));
                  delay(delayValue);
                }
                else if (protocol == 2) {
                  irsend.send(NEC, code, 32, frequency);
                  if (secondcode > 0) {
                    delay(20);
                    irsend.send(NEC, secondcode, 32, frequency);
                  }
                  Serial.println(F("Sending protocol nec"));
                  delay(delayValue);
                }
                else if (protocol == 3) {
                  irsend.send(NECX, code, 32, frequency);
                  Serial.println(F("Sending Protocol samsung"));
                  delay(delayValue);
                }
              }
            }
  
            //clearing string for next read
            commandSend = false;
            readString="";
            frequency = 38;
            repeat = 3;
            secondcode = 0;
            delayValue = 40;
            protocol = 1; //"rc5";
            // Re-enable the IR receive
            //irrecv.enableIRIn();
          }
        }
      }
    }
  }
}



