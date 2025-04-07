#pragma once
#include "Struct.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <conio.h>

#define PI (float)acos(-1)

class GearWheel
{
public:
    pointXYZ position;
    float radiusOUT;
    float radiusIN;
    float width_GearWheel;
    float width_down;
    float width_top;
    float height_teeth;
    int number_teeth;
    const float Red;
    const float Green;
    const float Blue;

    GearWheel(pointXYZ pos, float rOut, float rIn, float wGW, float wDown, float wTop, float hTeeth, int numTeeth, float R, float G, float B);

    void drawCylinderGearWheel(float angle);
    void drawGearWheel(float angle);
    void drawRadiarWeb(float radiusOUT, float radiusIN, float width_line, int number_lines, float angle);
};