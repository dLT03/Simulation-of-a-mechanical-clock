#pragma once
#include "Libraries.h"
#include "GearWheel.h"

// radian
float calculateHandAngle(int unit, int maxUnits) {
    return -360.0f * (static_cast<float>(unit) / maxUnits) * PI / 180.0f;
}

void drawHand(pointXYZ pos, float radiusOUT, float radiusIN, float length, float width, float angle, float Red, float Green, float Blue) {
    float halfWidth = width / 2.0f;
    angle = -angle;

    float x1 = pos.x + (radiusIN * sinf(angle)) - (halfWidth * cosf(angle));
    float y1 = pos.y + (radiusIN * cosf(angle)) + (halfWidth * sinf(angle));
    float x2 = pos.x + (radiusIN * sinf(angle)) + (halfWidth * cosf(angle));
    float y2 = pos.y + (radiusIN * cosf(angle)) - (halfWidth * sinf(angle));
    float x3 = pos.x + ((radiusIN + length) * sinf(angle)) + (halfWidth * cosf(angle));
    float y3 = pos.y + ((radiusIN + length) * cosf(angle)) - (halfWidth * sinf(angle));
    float x4 = pos.x + ((radiusIN + length) * sinf(angle)) - (halfWidth * cosf(angle));
    float y4 = pos.y + ((radiusIN + length) * cosf(angle)) + (halfWidth * sinf(angle));

    // side- Hand
    glColor3ub(Red * 0.75, Green * 0.75, Blue * 0.75);
    glBegin(GL_QUAD_STRIP);
    glVertex3f(x1, y1, pos.z);
    glVertex3f(x1, y1, pos.z - 0.05);
    glVertex3f(x4, y4, pos.z);
    glVertex3f(x4, y4, pos.z - 0.05);
    glVertex3f(x3, y3, pos.z);
    glVertex3f(x3, y3, pos.z - 0.05);
    glVertex3f(x2, y2, pos.z);
    glVertex3f(x2, y2, pos.z - 0.05);
    glEnd();

    // front & back hand
    glColor3ub(Red, Green, Blue);
    glBegin(GL_QUADS);
    glVertex3f(x1, y1, pos.z);
    glVertex3f(x2, y2, pos.z);
    glVertex3f(x3, y3, pos.z);
    glVertex3f(x4, y4, pos.z);
    glVertex3f(x1, y1, pos.z - 0.05);
    glVertex3f(x2, y2, pos.z - 0.05);
    glVertex3f(x3, y3, pos.z - 0.05);
    glVertex3f(x4, y4, pos.z - 0.05);
    glEnd();
}

void Mechanizm(float angle) {

    time_t rawTime;
    struct tm currentTime;
    errno_t err;

    time(&rawTime);
    err = localtime_s(&currentTime, &rawTime);

    if (err) {
        std::cerr << "Error getting local time" << std::endl;
        return;
    }

    int hours = currentTime.tm_hour;
    int minutes = currentTime.tm_min;
    int seconds = currentTime.tm_sec;

    // curent time
    float hourAngle = calculateHandAngle((hours % 12) * 60 + minutes, 12 * 60); 
    float minuteAngle = calculateHandAngle(minutes * 60 + seconds, 60 * 60);    
    float secondAngle = calculateHandAngle(seconds, 60);

    float extra_stock = 0.1;
    float radius_GWhour = 2.0f;
    float height_GWhour = 0.2f;

    float radius_GWsecond = 1.2f;
    float radius_GWsecondIN = 0.4f;
    float height_GWsecond = 0.1f;
    float height_teeth2 = 0.04f;

    float radius_GWminute = 1.494f;
    float radius_GWminuteIN = radius_GWminute - 0.2;
    float height_GWminute = 0.1f;
    float radius_GWminuteINin = 0.4f;
    float width_line = 0.3f;
    float height_teeth_minute = 0.03f;

    float radius_mainstick = 0.06f;
    float height_mainstick = 1.3f;

    float radius_gear1 = 0.8f;
    float height_gear1 = 0.2f;
    float radius_gear1_down = 0.6f;

    float height_between = 0.2;
    height_between = height_between + extra_stock + height_GWhour + height_gear1;

    float radius_gear2 = 0.6f;
    float height_gear2 = height_GWminute;

    float radius_gear3 = 0.12f;
    float height_gear3 = 0.4f;

    float radius_gear4 = 0.2f;
    float height_gear4 = 0.3f;

    float radius_gear5 = 0.28f;
    float height_gear5 = height_GWsecond;

    float radius_supply = 1.0f;
    float height_supply = 0.3f;
    float height_teeth_supply = 0.04f;

    // main stick
    GearWheel mainStick({ 0, 0, height_mainstick / 2 }, radius_mainstick, 0, height_mainstick, 0.01, 0.01, 0, 64, 225, 143, 1);
    mainStick.drawGearWheel(hourAngle);

    // hour
    GearWheel hour({ 0, 0, extra_stock + height_GWhour / 2 }, radius_GWhour, radius_mainstick, height_GWhour, 0.07f, 0.04f, 0.03f, 120, 225, 143, 1);
    hour.drawGearWheel(-hourAngle);

    //supply
    GearWheel supply({ (radius_supply + radius_gear1 + height_teeth_supply), 0, extra_stock + height_GWhour + height_supply / 2 },
        radius_supply, radius_supply * 0.6f, height_supply, 0.1, 0.05, height_teeth_supply, 40, 143, 115, 66);
    supply.drawGearWheel(angle * 0.8f);

    GearWheel supplyInner({ (radius_supply + radius_gear1 + height_teeth_supply), 0, extra_stock + height_GWhour + height_supply / 2 },
        radius_supply * 0.6f, 0, height_supply - 0.1f, 0.1, 0, 0, 60, 143 * 0.85, 115 * 0.85, 66 * 0.85);
    supplyInner.drawGearWheel(angle * 0.8f);
    // gear1 connected to supply
    GearWheel gear1({ 0, 0, extra_stock + height_GWhour + height_gear1 / 2 }, radius_gear1, radius_gear1_down, height_gear1, 0.1, 0.05, height_teeth_supply, 32, 143, 115, 66);
    gear1.drawGearWheel(-angle - 0.82);
    GearWheel gear1MainStick({ 0, 0, extra_stock + height_GWhour + height_gear1 / 2 }, radius_mainstick + 0.2f, radius_mainstick, height_gear1, 0.1, 0.05, 0, 32, 143, 115, 66);
    gear1MainStick.drawGearWheel(-angle - 0.82);
    GearWheel gear1Down({ 0, 0, extra_stock + height_GWhour + height_gear1 / 2 }, radius_gear1_down, radius_mainstick, height_gear1 - 0.1f, 0.1, 0.05, 0, 32, 143 * 0.85, 115 * 0.85, 66 * 0.85);
    gear1Down.drawGearWheel(-angle - 0.82);

    // minute
    GearWheel minute({ 0, 0, height_between + height_GWminute / 2 },
        radius_GWminute, radius_GWminuteIN, height_GWminute, 0.05, 0.03, height_teeth_minute, 100, 132, 0, 224);
    minute.drawGearWheel(minuteAngle + 0.5f);
    minute.drawRadiarWeb(radius_GWminuteIN + 0.1, radius_GWminuteINin, width_line, 8, minuteAngle + 0.5f);
    GearWheel minuteInner({ 0, 0, height_between + height_GWminute / 2 },
        radius_GWminuteINin + 0.1f, radius_gear3, height_GWminute, 0.05, 0.03, 0, 60, 132, 0, 224);
    minuteInner.drawGearWheel(minuteAngle + 0.5f);
    // gear 5 connected with minute
    GearWheel gear5({ -(radius_GWsecond + radius_gear2 + height_teeth2 / 2), 0, height_between + height_GWminute / 2 },
        radius_gear5, 0.05f, height_gear5, 0.05, 0.03, height_teeth_minute, 20, 132, 0, 224);
    gear5.drawGearWheel(-minuteAngle * 5);
    //  gear3 - part to hand
    GearWheel gear3Indicator({ 0, 0, height_between + height_GWminute + height_gear3 / 2 },
        radius_gear3, radius_mainstick, height_gear3, 0.1, 0.1, 0, 60, 132, 0, 224);
    gear3Indicator.drawGearWheel(minuteAngle);

    // second
    GearWheel second({ -(radius_GWsecond + radius_gear2 + height_teeth2), 0, height_between + height_gear2 + height_GWsecond / 2 },
        radius_GWsecond, radius_GWsecond - 0.2f, height_GWsecond, 0.1, 0.04, height_teeth2, 44, 74, 41, 97);
    second.drawGearWheel(secondAngle + 4.485f);
    second.drawRadiarWeb(radius_GWsecond, radius_GWsecondIN, width_line, 6, secondAngle + 4.485f);

    GearWheel secondInner({ -(radius_GWsecond + radius_gear2 + height_teeth2), 0, height_between + height_gear2 + height_GWsecond / 2 },
        radius_GWsecondIN + 0.1f, 0.2f, height_GWsecond, 0.1, 0.1, 0, 60, 74, 41, 97);
    secondInner.drawGearWheel(secondAngle + 4.485f);
    // gear2 conected with second
    GearWheel gear2({ 0, 0, height_between + height_gear2 + height_GWsecond / 2 },
        radius_gear2, radius_gear2 * 0.8f, height_gear2, 0.1, height_teeth2, 0.04, 22, 74, 41, 97);
    gear2.drawGearWheel(-secondAngle * 2);

    GearWheel gear2Inner({ 0, 0, height_between + height_gear2 + height_GWsecond / 2 },
        radius_gear2 * 0.8f, radius_gear4, height_gear2 - 0.1f, 0.1, 0, 0.04, 22, 74 * 0.85, 41 * 0.85, 97 * 0.85);
    gear2Inner.drawGearWheel(-secondAngle * 2);
    // gear4 - - part to hand
    GearWheel gear3Upper({ 0, 0, height_between + height_GWsecond + height_gear2 + height_gear4 / 2 - 0.1f },
        radius_gear4, radius_gear3, height_gear4, 0.1, 0.1, 0, 60, 74, 41, 97);
    gear3Upper.drawGearWheel(secondAngle);

    //hand hour
    drawHand({ 0,0,  height_mainstick }, radius_mainstick, 0, 1.0f, 0.1, hourAngle, 225, 143, 1);
    //hand minut
    drawHand({ 0,0, height_between + height_GWminute + height_gear3 }, radius_gear3, radius_mainstick, 1.4f, 0.06, minuteAngle, 132, 0, 224);
    // hand second 
    drawHand({ 0,0, height_between + height_GWminute + height_gear2 + height_gear4 - 0.1f }, radius_GWminuteINin + 0.1f, radius_gear3, 1.8f, 0.02, secondAngle, 74, 41, 97);

}