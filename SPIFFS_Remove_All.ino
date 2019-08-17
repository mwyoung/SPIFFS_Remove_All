//Remove all files on the SPIFFS file system
//Help from: https://techtutorialsx.com/2019/02/24/esp32-arduino-removing-a-file-from-the-spiffs-file-system/
//and https://arduino-esp8266.readthedocs.io/en/latest/filesystem.html
//Author: Miles Young, 08 2019

#include <FS.h>

void listFiles();
void removeAllFiles(bool removeFiles);

void setup() {
    Serial.begin(115200);

    if (!SPIFFS.begin()){
        Serial.println("SPIFFS init failed...");
        while (1) { delay(1); } //stop program
    }
    Serial.println("SPIFFS init");

    listFiles();
    removeAllFiles(true);
}

void loop() {
    delay(1); //infinite loop
}

void listFiles() {
    removeAllFiles(false);
}

void removeAllFiles(bool removeFiles) {
    File root = SPIFFS.open("/"); //open root directory
    File file;

    Serial.println("Current Files:");
    do{
        file = root.openNextFile();
        Serial.print(file.name());

        if(removeFiles){
            SPIFFS.remove(file.name());
            Serial.print("\tREMOVED");
        }
        Serial.println();
    } while(file);
}
