#include <SD.h>
#include <TMRpcm.h>

TMRpcm tmrpcm;

void setup() {
  tmrpcm.speakerPin = 9; // Set the pin connected to the amplifier module
  Serial.begin(9600);

  if (!SD.begin(10)) {
    Serial.println("SD card initialization failed!");
    return;
  }

  Serial.println("SD card initialized");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    if (command == 'p') {
      // Play audio file
      tmrpcm.play("audio/example.wav"); // Replace with your file name
    } else if (command == 's') {
      // Stop playback
      tmrpcm.stopPlayback();
    }
  }
}
