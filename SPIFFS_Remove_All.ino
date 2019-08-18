//Remove all files on the SPIFFS file system
//Help from: https://techtutorialsx.com/2019/02/24/esp32-arduino-removing-a-file-from-the-spiffs-file-system/
//and https://arduino-esp8266.readthedocs.io/en/latest/filesystem.html
//and https://www.esp8266.com/viewtopic.php?t=8459
//Author: Miles Young, 08 2019

#include <FS.h>

void listFiles();
void removeFiles();

void setup() {
    Serial.begin(115200);

    if (!SPIFFS.begin()){
        Serial.println("\nSPIFFS init failed...");
        while (1) { delay(1); } //stop program
    }
    Serial.println("\nSPIFFS init");

    listFiles();
    removeFiles();
    listFiles();
    Serial.println("Done"); 
}

void loop() {
    delay(1); //infinite loop
}

void listFiles() {
    Dir root = SPIFFS.openDir("/"); //open root directory

    Serial.println("Current Files:");
    while (root.next()) {
        Serial.print(root.fileName());
        Serial.println();
    }
}

void removeFiles(){
    Serial.println("FORMATTING SPIFFS");
    Serial.println("This may take several seconds...");
    bool formatted = SPIFFS.format();
    if (formatted){
        Serial.println("SPIFFS formatted");
    }
    else {
        Serial.println("SPIFFS not formatted");
    }
}
