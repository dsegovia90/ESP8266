/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://192.168.199.110/gpio/0 will set the GPIO2 low,
 *    http://192.168.199.110/gpio/1 will set the GPIO2 high
 *  server_ip is the IP address of the ESP8266 module, will be 
 *  printed to Serial when the module is connected.
 */

#include <ESP8266WiFi.h>

const char* ssid = "Dabici";
const char* password = "dabici1a2b3c4d";
String firstValue;
String secondValue;
String thirdValue;
String myString;
// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  delay(10);

  // prepare GPIO2
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  //Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
    
    String buffer =req.getBuffer();
 
    String setting=buffer.substring(5,9);
	String set=buffer.substring(10,12);
   
   if(setting!="favi"){
    Serial.println(setting+","+set);
    }

     client.flush();
	if (Serial.available()){
		myString=Serial.readString();
		int commaIndex = myString.indexOf(',');
		int secondCommaIndex = myString.indexOf(',', commaIndex+1);
		 firstValue = myString.substring(0, commaIndex);
		 secondValue = myString.substring(commaIndex+1, secondCommaIndex);
		 thirdValue = myString.substring(secondCommaIndex+1); //To the end of the string
		
	} 
	 
	 
	
	 
	
	
	 
	 
	 	String s =  "<!DOCTYPE html>"
	 				"<html>"
					"<body>"
	 				"<p>"
					"<input type=\"submit\" name=\"btnCool\" value=\"Cool\"  id=\"btnCool\" class=\"buttonSearch\" />"
					"<input name=\"search\" type=\"text\" maxlength=\"512\" id=\"searchcool\" class=\"searchField\" autocomplete=\"off\" title="" />"
					"<script type=\"text/javascript\">"
					"var button= document.getElementById('btnCool');"
					"button.onclick= function(){"
					"var text= document.getElementById('searchcool').value;"
					"location.href='http://192.168.199.105/cool/'+text;"
	 				"}"
	 				"</script>"
	 				"</p>"
	 				"<p>"
	 				"<input type=\"submit\" name=\"btnHeat\" value=\"Heat\"  id=\"btnHeat\" class=\"buttonSearch\" />"
	 				"<input name=\"search\" type=\"text\" maxlength=\"512\" id=\"searchheat\" class=\"searchField\" autocomplete=\"off\" title="" />"
	 				"<script type=\"text/javascript\">"
	 				"var button= document.getElementById('btnHeat');"
	 				"button.onclick= function(){"
		 			"var text= document.getElementById('searchheat').value;"
		 			"location.href='http://192.168.199.105/heat/'+text;"
	 				"}"
	 				"</script>"
	 				"</p>"
	 				"<p>"
	 				"<input type=\"submit\" name=\"btnDelta\" value=\"Delta\"  id=\"btnDelta\" class=\"buttonSearch\" />"
	 				"<input name=\"search\" type=\"text\" maxlength=\"512\" id=\"searchdelta\" class=\"searchField\" autocomplete=\"off\" title="" />"
	 				"<script type=\"text/javascript\">"
	 				"var button= document.getElementById('btnDelta');"
	 				"button.onclick= function(){"
		 			"var text= document.getElementById('searchdelta').value;"
		 			"location.href='http://192.168.199.105/delt/'+text;"
	 				"}"
	 				"</script>"
	 				"</p>"
	 				"<p>"
	 				"<input type=\"submit\" name=\"btnStep\" value=\"Step\"  id=\"btnStep\" class=\"buttonSearch\" />"
	 				"<input name=\"search\" type=\"text\" maxlength=\"512\" id=\"searchstep\" class=\"searchField\" autocomplete=\"off\" title="" />"
	 				"<script type=\"text/javascript\">"
	 				"var button= document.getElementById('btnStep');"
	 				"button.onclick= function(){"
		 			"var text= document.getElementById('searchstep').value;"
		 			"location.href='http://192.168.199.105/step/'+text;"
	 				"}"
	 				"</script>"
	 				"</p>"
	 				"<p>"
					"<input type=\"submit\" name=\"btnMaxTemp\" value=\"Max Temp\"  id=\"btnMaxTemp\" class=\"buttonSearch\" />"
	 				"<input name=\"search\" type=\"text\" maxlength=\"512\" id=\"searchmaxtemp\" class=\"searchField\" autocomplete=\"off\" title="" />"
	 				"<script type=\"text/javascript\">"
					"var button= document.getElementById('btnMaxTemp');"
	 				"button.onclick= function(){"
		 			"var text= document.getElementById('searchmaxtemp').value;"
		 			"location.href='http://192.168.199.105/maxt/'+text;"
	 				"}"
					"</script>"
	 				"</p>"
	 				"<p>"
	 				"<input type=\"submit\" name=\"btnMinTemp\" value=\"Min Temp\"  id=\"btnMinTemp\" class=\"buttonSearch\" />"
	 				"<input name=\"search\" type=\"text\" maxlength=\"512\" id=\"searchmintemp\" class=\"searchField\" autocomplete=\"off\" title="" />"
	 				"<script type=\"text/javascript\">"
	 				"var button= document.getElementById('btnMinTemp');"
	 				"button.onclick= function(){"
		 			"var text= document.getElementById('searchmintemp').value;"
		 			"location.href='http://192.168.199.105/mint/'+text;"
					"}"
					"</script>"
	 				"</p>"
	 				"<p>"
	 				"<p><b>Fan</b></p>"
	 				"<form action=\"http://192.168.199.105/fann/1\">"
	 				"<input type=\"submit\" value=\"On\">"
	 				"</form>"
	 				"<form action=\"http://192.168.199.105/fann/0\">"
	 				"<input type=\"submit\" value=\"Off\">"
	 				"</form>"
	 				"</p>"
					 "<p>"
					 "<p><b>Update Configuration</b></p>"
					 "<form action=\"http://192.168.199.105/conf/\">"
					 "<input type=\"submit\" value=\"Update\">"
					 "</form>"
					 "</p>";
		    String w="<p></p>"
					 "<p><b>Ambient Temp :"+firstValue+" </b></p>"
					 "<p><b>Target Temp :"+secondValue+" </b></p>"
					 "<p><b>Mode : "+thirdValue+"</b></p>"
					 "<p><b>Max Temp : </b></p>"
					 "<p><b>Min Temp : </b></p>"
					 "<p><b>Step : </b></p>"
					 "<p><b>Delta : </b></p>"
					 "</body>"
					 "</html>";
					    client.print(s);
					 	client.print(w);
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	
}
