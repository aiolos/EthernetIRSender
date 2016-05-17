/*
  Ethernet IR Sender

  Ethernet IR Sender to send IR command through an ethernet enabled Arduino (With Wiznet Ethernet Shield)
  - Put an IR led to Pin3 of the arduino
  - Point your browser to the given IP address (default 192.168.1.177)
  - Click one of the predefined commands

  - An URL is formed like: http://192.168.1.177/?code=C0D&protocol=1&repeat=1
    Where 
    - code: is the hexadecimal code of the command (recodable by putting a IR receiver on pin 5)
    - protocol: is the protocol to use, for now: 1 = rc5, 2=NEC, 3=Samsung
    - repeat: is the number of repeats of the command, defaults to 1  
 */

#include <SPI.h>
#include <Ethernet.h>
#include <IRremote.h>
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

int RECV_PIN = 5;

IRsend irsend;
IRrecv irrecv(RECV_PIN);
decode_results results;

String readString; 
int repeat = 3;
unsigned long uli;
char p;
char data[100];
int protocol = 1; // 1 = "rc5", 2 = "nec", 3 = "samsung";
unsigned long code;
bool commandSend = false;

unsigned long irCode;
String irProtocol;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

  irrecv.enableIRIn(); // Start the receiver
}

unsigned long last = millis();

void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();

  if (irrecv.decode(&results)) {
    if (millis() - last > 250) {
      dump(&results);
    }
    last = millis();      
    irrecv.resume(); // Receive the next value
  }

  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
      
        char c = client.read();
        //read char by char HTTP request
        if (readString.length() < 100) {

          //store characters to string 
          readString += c; 
        } 
        //Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n') {
          ///////////////
          Serial.println(readString); //print to serial monitor for debuging 

          //now output HTML data header
          client.println("HTTP/1.1 200 OK"); //send new page
          client.println("Content-Type: text/html");
          client.println();

          client.println("<HTML><HEAD>");
          client.println("<TITLE>Ethernet IR Sender</TITLE></HEAD>");
          client.println("<BODY>");

          client.println("<H1>Ethernet IR sender</H1>");

          client.println("<h2>Philips</h2>");
          client.println("<a href='/?code=410&protocol=1'>Vol +</a>"); 
          client.println("<a href='/?code=411&protocol=1'>Vol -</a>"); 
          client.println("<a href='/?code=47F&protocol=1&repeat=10'>Tuner aan</a>"); 
          client.println("<a href='/?code=44C&protocol=1'>Uit</a>"); 
          client.println("<a href='/?code=C0D&protocol=1'>Mute</a>"); 

          client.println("<h2>Pioneer</h2>");
          client.println("<a href='/?code=A55A50AF&p=2&r=1'>Vol +</a>"); 
          client.println("<a href='/?code=A55AD02F&p=2&r=1'>Vol -</a>"); 
          client.println("<a href='/?code=47F&repeat=10'>Tuner aan</a>"); 
          client.println("<a href='/?code=A55A38C7&p=2&r=1'>Uit</a>"); 
          client.println("<a href='/?code=A55A48B7&p=2&r=1'>Mute</a>"); 

          client.println("<h2>Samsung</h2>");
          client.println("<a href='/?code=E0E040BF&p=3&r=1'>Aan/Uit</a>"); 

          client.println("<h2>IrCode:</h2>");
          if (irCode > 0) {
            client.println(irCode, HEX);
            client.println("<br>");
            client.println(irProtocol);
          } else {
            client.println("Geen code ontvangen");
          }

          client.println("</BODY></HTML>");

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
                   if (strcmp(name, "protocol") == 0 || strcmp(name, "p") == 0) {
                    protocol = atoi(value);
                   } else if (strcmp(name, "repeat") == 0 || strcmp(name, "r") == 0) {
                    repeat = atoi(value);
                   } else if (strcmp(name, "code") == 0) {
                    code = x2i(value);
                   }
                   
                   name = strtok(NULL, "="); // Get the next name
                }
             }
  
            if (commandSend) {
              Serial.println("protocol/code/repeat");
              Serial.println(protocol);
              Serial.println(code);
              Serial.println(repeat);
              if (repeat > 10) {
                repeat = 10;
              }
  
              if (protocol == 1) {
                for (int i = 0; i < repeat; i++) {
                  if (protocol == 1) {
                    irsend.sendRC5(code, 12); // d4c
                    Serial.println("Protocol rc5");
                    delay(40);
                  }
                  else if (protocol == 2) {
                    irsend.sendNEC(code, 32);
                    Serial.println("Protocol nec");
                  }
                  else if (protocol == 3) {
                    irsend.sendSAMSUNG(code, 32);
                    Serial.println("Sending Protocol samsung");
                  }
                }
              }
            }
  
            //clearing string for next read
            commandSend = false;
            readString="";
            repeat = 1;
            protocol = 1; //"rc5";
            // Re-enable the IR receive
            irrecv.enableIRIn();
          }
        }
      }
    }
  }
}

// Dumps out the decode_results structure.
// Call this after IRrecv::decode()
// void * to work around compiler issue
//void dump(void *v) {
//  decode_results *results = (decode_results *)v
void dump(decode_results *results) {
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.println("Could not decode message");
  } 
  else {
    if (results->decode_type == NEC) {
      Serial.print("Decoded NEC: ");
      irProtocol = "NEC";
    } 
    else if (results->decode_type == SONY) {
      Serial.print("Decoded SONY: ");
      irProtocol = "SONY";
    } 
    else if (results->decode_type == RC5) {
      //Serial.print(results->decode_type);
      Serial.print("Decoded RC5: ");
      irProtocol = "RC6";
    } 
    else if (results->decode_type == RC6) {
      Serial.print("Decoded RC6: ");
      irProtocol = "RC6";
    }
    irCode = results->value;
    Serial.print(results->value, HEX);
    Serial.print(" (");
    Serial.print(results->bits, DEC);
    Serial.println(" bits)");
  }
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 0; i < count; i++) {
    if ((i % 2) == 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    } 
    else {
      Serial.print(-(int)results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println("");
}

int x2i(char *s) 
{
 int x = 0;
 for(;;) {
   char c = *s;
   if (c >= '0' && c <= '9') {
      x *= 16;
      x += c - '0'; 
   }
   else if (c >= 'A' && c <= 'F') {
      x *= 16;
      x += (c - 'A') + 10; 
   }
   else if (c >= 'a' && c <= 'f') {
      x *= 16;
      x += (c - 'a') + 10; 
   }
   else break;
   s++;
 }
 return x;
}

