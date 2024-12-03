// #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>

// const char *ssid = "hacked";     // Set your SSID name for the ESP's access point
// const char *password = "rgcore24";   // Password for access point (min 8 characters)


// ESP8266WebServer server(80);  // Create a web server on port 80
// void handleRoot();            // Function to handle root requests
// void handleToggle();          // Function to handle button toggle requests


// const int outputPin = 15;       // GPIO2 (D4 on some boards)

// void setup() {
//   Serial.begin(115200);
//   pinMode(outputPin, OUTPUT);
//   digitalWrite(outputPin, LOW);  // Initialize the pin to LOW

//   // Set up ESP8266 as an access point
//   WiFi.softAP(ssid, password);
//   Serial.println("Access point started.");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.softAPIP());

//   // Define the route for the root ("/") to serve the HTML page
//   server.on("/", handleRoot);

//   // Define the route for the button action
//   server.on("/toggle", handleToggle);

//   server.begin();
//   Serial.println("Web server started.");
// }


// void loop() {
//   server.handleClient();  // Handle incoming client requests
// }

// // Function to serve the main HTML page
// void handleRoot() {
//   String html = R"(
//     <!DOCTYPE html>
//     <html lang="en">
//     <head>
//       <meta charset="UTF-8">
//       <meta name="viewport" content="width=device-width, initial-scale=1.0">
//       <title>ESP8266 Control</title>
//       <style>
//         body { font-family: Arial, sans-serif; display: flex; flex-direction: column; align-items: center; justify-content: center; height: 100vh; margin: 0; background-color: #f2f2f2; }
//         .button { padding: 15px 30px; font-size: 1.5em; color: white; background-color: #007bff; border: none; border-radius: 5px; cursor: pointer; text-decoration: none; transition: background-color 0.3s; }
//         .button:hover { background-color: #0056b3; }
//       </style>
//     </head>
//     <body>
//       <h1>ESP8266 Web Server</h1>
//       <p><a href="/toggle" class="button">Open</a></p>
//     </body>
//     </html>
//   )";
//   server.send(200, "text/html", html);  // Send HTML page
// }

// // Function to handle the button press
// void handleToggle() {
//   // Set the output pin HIGH, wait, then set it LOW
//   digitalWrite(outputPin, HIGH);
//   delay(500);  // Wait for 0.5 seconds
//   digitalWrite(outputPin, LOW);

//   // Send a redirect to the root page after toggling
//   server.sendHeader("Location", "/", true);
//   server.send(302, "text/plain", "");  // Empty response with redirect
// }
