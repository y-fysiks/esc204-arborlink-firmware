/*

 █████  ██████  ███████   █████  ██████
██   ██ ██  ███ ██   ███ ██   ██ ██  ███
███████ ██████  ███████  ██   ██ ██████
██   ██ ██   ██ ██   ███ ██   ██ ██   ██
██   ██ ██   ██ ███████   █████  ██   ██

File: main.cpp
Auth: Alex Wang, Yubo Wang
Desc: Source file for MCU

*/

// I made cahnges!!!!!!!!

#include <Arduino.h>

#include <Wire.h>
#include <SparkFun_KX13X.h> // Click here to get the library: http://librarymanager/All#SparkFun_KX13X

SparkFun_KX132 kxAccel; // Create an instance of the KX132 class

outputData myData; // Struct for the accelerometer's data

void setup()
{

    Wire1.begin();

    Serial.begin(115200);
    Serial.println("Welcome.");

    // Wait for the Serial monitor to be opened.
    while (!Serial)
        delay(50);

    if (!kxAccel.begin(Wire1))
    {
        Serial.println("Could not communicate with the the KX13X. Freezing.");
        while (1)
            ;
    }

    Serial.println("Ready.");

    if (kxAccel.softwareReset())
        Serial.println("Reset.");

    // Give some time for the accelerometer to reset.
    // It needs two, but give it five for good measure.
    delay(5);

    // Many settings for KX13X can only be
    // applied when the accelerometer is powered down.
    // However there are many that can be changed "on-the-fly"
    // check datasheet for more info, or the comments in the
    // "...regs.h" file which specify which can be changed when.
    kxAccel.enableAccel(false);

    kxAccel.setRange(SFE_KX132_RANGE16G); // 16g Range
    // kxAccel.setRange(SFE_KX134_RANGE16G);         // 16g for the KX134

    kxAccel.enableDataEngine(); // Enables the bit that indicates data is ready.
    // kxAccel.setOutputDataRate(); // Default is 50Hz
    kxAccel.enableAccel();
}

void loop()
{
    // put your main code here, to run repeatedly:
}