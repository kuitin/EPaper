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

String UtilGoogle::ConvertASCIIToUTF8(const String& stAscii)
{
  String result = stAscii;
  
  result.replace("°", "\xB0");
  result.replace("º", "\xba");
  result.replace("À", "\xC0");
  result.replace("Á", "\xC1");
  result.replace("Â", "\xC2");
  result.replace("Ã", "\xC3");
  result.replace("Ä", "\xC4");
  result.replace("Å", "\xC5");
  result.replace("Æ", "\xC6");
  result.replace("Ç", "\xC7");
  result.replace("È", "\xC8");
  result.replace("É", "\xC9");
  result.replace("Ê", "\xCA");
  result.replace("Ë", "\xCB");
  result.replace("Ì", "\xCC");
  result.replace("Í", "\xCD");
  result.replace("Î", "\xCE");
  result.replace("Ï", "\xCF");
  result.replace("Ð", "\xD0");
  result.replace("Ñ", "\xD1");
  result.replace("Ò", "\xD2");
  result.replace("Ó", "\xD3");
  result.replace("Ô", "\xD4");
  result.replace("Õ", "\xD5");
  result.replace("Ö", "\xD6");
  result.replace("×", "\xD7");
  result.replace("Ø", "\xD8");
  result.replace("Ù", "\xD9");
  result.replace("Ú", "\xDA");
  result.replace("Û", "\xDB");
  result.replace("Ü", "\xDC");
  result.replace("Ý", "\xDD");
  result.replace("Þ", "\xDE");
  result.replace("ß", "\xDF");
  result.replace("à", "\xE0");
  result.replace("á", "\xE1");
  result.replace("â", "\xE2");
  result.replace("ã", "\xE3");
  result.replace("ä", "\xE4");
  result.replace("å", "\xE5");
  result.replace("æ", "\xE6");
  result.replace("ç", "\xE7");
  result.replace("è", "\xE8");
  result.replace("é", "\xE9");
  result.replace("ê", "\xEA");
  result.replace("ë", "\xEB");
  result.replace("ì", "\xEC");
  result.replace("í", "\xED");
  result.replace("î", "\xEE");
  result.replace("ï", "\xEF");
  result.replace("ð", "\xF0");
  result.replace("ñ", "\xF1");
  result.replace("ò", "\xF2");
  result.replace("ó", "\xF3");
  result.replace("ô", "\xF4");
  result.replace("õ", "\xF5");
  result.replace("ö", "\xF6");
  result.replace("÷", "\xF7");
  result.replace("ø", "\xF8");
  result.replace("ù", "\xF9");
  result.replace("ú", "\xFA");
  result.replace("û", "\xFB");
  result.replace("ü", "\xFC");
  result.replace("ý", "\xFD");
  result.replace("þ", "\xFE");
  result.replace("ÿ", "\xFF");


  return result;
}