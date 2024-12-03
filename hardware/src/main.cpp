// #include <ESP8266WiFi.h>
// #include <ESP8266mDNS.h>
// #include <ESPAsyncTCP.h>
// #include <ESPAsyncWebServer.h>
// #include <Adafruit_Fingerprint.h>




// Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial);

// // Access Point credentials
// const char* ssid = "ESP8266-AP";
// const char* password = "12345678";

// AsyncWebServer server(80);
// AsyncEventSource events("/events"); // Server-Sent Events handler
// String displayedText = "Initial Text";

// // Function to update displayed text
// void updateText(String newText) {
//   displayedText = newText;
//   events.send(displayedText.c_str(), "update", millis());
// }


// uint8_t getFingerprintID() {
//   uint8_t p = finger.getImage();
//   switch (p) {
//     case FINGERPRINT_OK:
//       updateText("Image taken");
//       break;
//     case FINGERPRINT_NOFINGER:
//       updateText("No finger detected");
//       return p;
//     case FINGERPRINT_PACKETRECIEVEERR:
//       updateText("Communication error");
//       return p;
//     case FINGERPRINT_IMAGEFAIL:
//       updateText("Imaging error");
//       return p;
//     default:
//       updateText("Unknown error");
//       return p;
//   }

//   // OK success!

//   p = finger.image2Tz();
//   switch (p) {
//     case FINGERPRINT_OK:
//       updateText("Image converted");
//       break;
//     case FINGERPRINT_IMAGEMESS:
//       updateText("Image too messy");
//       return p;
//     case FINGERPRINT_PACKETRECIEVEERR:
//       updateText("Communication error");
//       return p;
//     case FINGERPRINT_FEATUREFAIL:
//       updateText("Could not find fingerprint features");
//       return p;
//     case FINGERPRINT_INVALIDIMAGE:
//       updateText("Could not find fingerprint features");
//       return p;
//     default:
//       updateText("Unknown error");
//       return p;
//   }

//   // OK converted!
//   p = finger.fingerSearch();
//   if (p == FINGERPRINT_OK) {
//     updateText("Found a print match!");
//   } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
//     updateText("Communication error");
//     return p;
//   } else if (p == FINGERPRINT_NOTFOUND) {
//     updateText("Did not find a match");
//     return p;
//   } else {
//     updateText("Unknown error");
//     return p;
//   }

//   // found a match!
//   updateText("Found ID #" + String(finger.fingerID) + " with confidence of " + String(finger.confidence));

//   return finger.fingerID;
// }

// // returns -1 if failed, otherwise returns ID #
// int getFingerprintIDez() {
//   uint8_t p = finger.getImage();
//   if (p != FINGERPRINT_OK)  return -1;

//   p = finger.image2Tz();
//   if (p != FINGERPRINT_OK)  return -1;

//   p = finger.fingerFastSearch();
//   if (p != FINGERPRINT_OK)  return -1;

//   // found a match!
//   updateText("Found ID #" + String(finger.fingerID) + " with confidence of " + String(finger.confidence));
//   return finger.fingerID;
// }

// void setup() {

//   // Set up Access Point
//   WiFi.softAP(ssid, password);
//   updateText("\n\nAdafruit finger detect test");

//   // set the data rate for the sensor serial port
//   finger.begin(57600);
//   delay(5);
//   if (finger.verifyPassword()) {
//     updateText("Found fingerprint sensor!");
//   } else {
//     updateText("Did not find fingerprint sensor :(");
//     while (1) { delay(1); }
//   }

//   updateText("Reading sensor parameters");
//   finger.getParameters();
//   updateText("Status: 0x" + String(finger.status_reg, HEX));
//   updateText("Sys ID: 0x" + String(finger.system_id, HEX));
//   updateText("Capacity: " + String(finger.capacity));
//   updateText("Security level: " + String(finger.security_level));
//   updateText("Device address: " + String(finger.device_addr, HEX));
//   updateText("Packet len: " + String(finger.packet_len));
//   updateText("Baud rate: " + String(finger.baud_rate));

//   finger.getTemplateCount();

//   if (finger.templateCount == 0) {
//     updateText("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
//   }
//   else {
//     updateText("Waiting for valid finger...");
//     updateText("Sensor contains " + String(finger.templateCount) + " templates");
//   }

//   // Serve the main HTML page
//   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
//     request->send_P(200, "text/html", R"rawliteral(
//       <!DOCTYPE html>
//       <html>
//       <head>
//         <title>ESP8266 Web Server</title>
//         <script>
//           const eventSource = new EventSource('/events');
//           eventSource.addEventListener('update', function(event) {
//             document.getElementById('textDisplay').innerText = event.data;
//           });
//         </script>
//       </head>
//       <body>
//         <h1>ESP8266 Web Server</h1>
//         <p id="textDisplay">Loading...</p>
//       </body>
//       </html>
//     )rawliteral");
//   });

//   // Add Server-Sent Events handler
//   server.addHandler(&events);

//   // Start server
//   server.begin();
// }

// void loop() {
//   // Simulate updating text every 10 seconds
//     getFingerprintID();
//     delay(10);

// }
