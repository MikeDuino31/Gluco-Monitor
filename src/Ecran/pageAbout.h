#pragma once
#include <Arduino.h>
#include "Config.h"
#include <Arduino_GFX_Library.h>
#include "Ecran/Gestion.h"
#include "Langues/Langue.h"

void pageAboutSetup();
void handleTouch_About(uint16_t touchX, uint16_t touchY,int16_t DeltaTouchY);