#include <Modules/Utils/UtilGoogle.h>
#include <Trad/DisplayEPaperTrad.h>
#include "WiFiClientSecure.h"

String UtilGoogle::GetDataGoogleScript(const String& url, String & error)
{
    WiFiClientSecure client;
    String movedURL;
    String line;

    // if (1)Serial.println("Connection to script.google.com");
    if (!client.connect("script.google.com", 443))
    {
        if (1) Serial.println("Connection to server failed!");
        error =  "Connection to server failed!";
        return "";
    }

    // if (1) Serial.println("Connecté!");
    // ESP32 Erzeugt HTTPS Anfrage an Google sheets
    client.println("GET " + url );
    client.println("Host: script.google.com" );
    client.println("Connection: close");
    client.println();

     // ESP32 empfängt antwort vom Google sheets
  int timeout = 0;
  int maxTimeout = 25;
  while (client.connected() && timeout < maxTimeout )     // ESP32  empfängt Header
  {
    line = client.readStringUntil('\n');
    // if (1) Serial.println(line);
   if (line == "\r") break;      // Ende Des Headers empfangen
    if (line.indexOf ( "Location" ) >= 0)   // Weiterleitung im Header?
    { // Neue URL merken
      movedURL = line.substring ( line.indexOf ( ":" ) + 2 ) ;
     
    }
    //Serial.println(timeout);
    timeout++;
    
  }
  if(timeout >= maxTimeout) 
  {
    Serial.println(" out 1");
    error =  "out 1";
    client.stop();
    return "";
  }
  timeout = 0;
  client.stop();
  if(timeout >= maxTimeout) 
  {
    Serial.println("2");
    error =  "out 2";
     return "";
  }

  movedURL.trim(); // leerzeichen, \n entfernen

  if (!client.connect("script.google.com", 443))
  {
    Serial.println("Connection to server failed!");
    error =  "Connection to server failed!";
    return "";
  }

  // // ESP32 Erzeugt HTTPS Anfrage an Google Tabellen
  client.println("GET " + movedURL );
  client.println("Host: script.google.com");
  client.println("Connection: close");
  client.println();
  // Serial.print("END ------------ END");
  timeout = 0;
  while (client.connected() && timeout < maxTimeout) // ESP32  empfängt Header
  {
    line = client.readStringUntil('\n');
    if (line == "\r")break;
    //Serial.println(timeout);
    timeout ++;
  }
  if(timeout >= maxTimeout) 
  {
    //Serial.println("3");
    error =  "timeout google";
    client.stop();
    return "";
  }
  
   timeout = 0;
   // get available data size
  size_t sizeArray = client.available();
  //  Serial.print("size "); Serial.println(sizeArray);
  while ( client.connected() && timeout < maxTimeout) // Google Antwort HTML Zeilenweise Lesen
  {
    if (client.available() )
    {
       // void* temp ;
     //  read( temp, 60); 
     line = client.readStringUntil('\r');
      client.stop();
      //  if (1) Serial.println(line);
    }
   timeout ++;
  }
  if(timeout >= maxTimeout) 
  {
    Serial.println("google timeout");
    client.stop();
    error = "google timeout"; 
    return "";
  }
  client.stop();
  return line;
  // Serial.print("client stop");
}