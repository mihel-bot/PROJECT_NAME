#include <Arduino.h>
#include "task3.h"


void task3(){
    enum class Task3States{
        INIT,
        WAIT_TO_TOGGLE_LED
    };
    static Task3States task3State = Task3States::INIT;
    static uint32_t lasTime;
    static constexpr uint32_t INTERVAL = 333;
    static constexpr uint8_t ledBlue = 26;
    static bool ledStatus = false;

    switch(task3State){
        case Task3States::INIT:{
            pinMode(ledBlue,OUTPUT);
            lasTime = millis();
            task3State = Task3States::WAIT_TO_TOGGLE_LED;
            break;
        }

        case Task3States::WAIT_TO_TOGGLE_LED:{
            // evento 1:
            uint32_t currentTime = millis();
            if( (currentTime - lasTime) >= INTERVAL ){
                lasTime = currentTime;
                digitalWrite(ledBlue,ledStatus);
                ledStatus = !ledStatus;
            }
            break;
        }

        default:{
            break;
        }
    }

}
