#pragma once
#include "Libraries.h"
#include "Struct.h"
#include "Sound.h"

void drawCircle(float radius, int segments)
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.75f, 0.75f, 0.75f);

    for (int i = 0; i <= segments; ++i) {
        float angle = 2.0f * PI * i / segments;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

void drawHand(float length, float width) {
    glBegin(GL_QUADS);
    pointXYZ points[] = {
        {-width / 2, 0.0f, 0.02f},
        {width / 2, 0.0f, 0.02f},
        {width / 2, length, 0.02f},
        {-width / 2, length, 0.02f}
    };

    for (const auto& point : points) {
        glVertex3f(point.x, point.y, point.z);
    }
    glEnd();
}

void drawCuboid(float x, float y1, float y2)
{
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.3f, 0.1f);
    pointXYZ front[] = {
        {-x, -y1, 1.0f},
        {x, -y1, 1.0f},
        {x, y2, 1.0f},
        {-x, y2, 1.0f}
    };
    for (const auto& point : front) {
        glVertex3f(point.x, point.y, point.z);
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.25f, 0.08f);
    pointXYZ back[] = {
        {-x, -y1, -1.0f},
        {x, -y1, -1.0f},
        {x, y2, -1.0f},
        {-x, y2, -1.0f}
    };
    for (const auto& point : back) {
        glVertex3f(point.x, point.y, point.z);
    }
    glEnd();

    glBegin(GL_QUADS);
    pointXYZ left[] = {
        {-x, -y1, -1.0f},
        {-x, -y1, 1.0f},
        {-x, y2, 1.0f},
        {-x, y2, -1.0f}
    };
    for (const auto& point : left) {
        glVertex3f(point.x, point.y, point.z);
    }
    glEnd();

    glBegin(GL_QUADS);
    pointXYZ right[] = {
        {x, -y1, -1.0f},
        {x, -y1, 1.0f},
        {x, y2, 1.0f},
        {x, y2, -1.0f}
    };
    for (const auto& point : right) {
        glVertex3f(point.x, point.y, point.z);
    }
    glEnd();

    glBegin(GL_QUADS);
    pointXYZ bottom[] = {
        {-x, -y1, 1.0f},
        {x, -y1, 1.0f},
        {x, -y1, -1.0f},
        {-x, -y1, -1.0f}
    };
    for (const auto& point : bottom) {
        glVertex3f(point.x, point.y, point.z);
    }
    glEnd();
}

void drawCylinder()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.6f, 0.3f, 0.1f);
    glVertex3f(0.0f, 1.0f, 1.0f);
    for (int i = 0; i <= 100; ++i) {
        float angle = PI * i / 100;
        glVertex3f(cos(angle), sin(angle) + 1.0f, 1.0f);
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.25f, 0.08f);
    for (int i = 0; i < 100; ++i) {
        float angle1 = PI * i / 100;
        float angle2 = PI * (i + 1) / 100;
        pointXYZ points[] = {
            {cos(angle1), sin(angle1) + 1.0f, 1.0f},
            {cos(angle2), sin(angle2) + 1.0f, 1.0f},
            {cos(angle2), sin(angle2) + 1.0f, -1.0f},
            {cos(angle1), sin(angle1) + 1.0f, -1.0f}
        };
        for (const auto& point : points) {
            glVertex3f(point.x, point.y, point.z);
        }
    }
    glEnd();
}

void cCylinder(float segments, float radius, float a, float b)
{
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float angle = 2.0f * PI * i / segments;
        float x = radius * cos(angle) + a;
        float y = radius * sin(angle) + b;

        glVertex3f(x, y, -1.0);
        glVertex3f(x, y, 1.0);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.6f, 0.3f, 0.1f);
    glVertex3f(a, b, -1.0f);
    for (int i = 0; i <= segments; ++i) {
        float angle = 2.0f * PI * i / segments;
        float x = radius * cos(angle) + a;
        float y = radius * sin(angle) + b;
        glVertex3f(x, y, 1.0);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.5f, 0.25f, 0.08f);
    glVertex3f(a, b, 1.0f);
    for (int i = 0; i <= segments; ++i) {
        float angle = 2.0f * PI * i / segments;
        float x = radius * cos(angle) + a;
        float y = radius * sin(angle) + b;
        glVertex3f(x, y, -1.0);
    }
    glEnd();
}

void Cylinders()
{
    glPushMatrix();
    glScalef(-1.5f, 0.7f, 1.0f);
    drawCylinder();
    glPopMatrix();

    cCylinder(200, 0.1, 0.0, 2.0);
    cCylinder(200, 0.05, 0.1, 2.0);
    cCylinder(200, 0.05, -0.1, 2.0);
}

void drawLegs(float x1, float x2, float x3, float x4, float y1, float y2, float z1, float z2)
{

    // front
    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.225f, 0.072f);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y1, z1);
    glVertex3f(x3, y2, z1);
    glVertex3f(x4, y2, z1);
    glEnd();
    // back
    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.225f, 0.072f);
    glVertex3f(x1, y1, z2);
    glVertex3f(x2, y1, z2);
    glVertex3f(x3, y2, z2);
    glVertex3f(x4, y2, z2);
    glEnd();

    // left
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.25f, 0.08f);
    glVertex3f(x2, y1, z2);
    glVertex3f(x2, y1, z1);
    glVertex3f(x3, y2, z1);
    glVertex3f(x3, y2, z2);
    glEnd();

    // right
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.25f, 0.08f);
    glVertex3f(x1, y1, z2);
    glVertex3f(x1, y1, z1);
    glVertex3f(x4, y2, z1);
    glVertex3f(x4, y2, z2);
    glEnd();
}

void drawRectangle(float width, float height) {
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    pointXYZ points[] = {
        {-width / 2, -height / 2, 1.03f},
        {width / 2, -height / 2, 1.03f},
        {width / 2, height / 2, 1.03f},
        {-width / 2, height / 2, 1.03f}
    };
    for (const auto& point : points) {
        glVertex3f(point.x, point.y, point.z);
    }
    glEnd();
}

void drawHourMarkers(float radius) {
    for (int i = 1; i <= 12; ++i) {
        float angle = i * 30.0f - 90.0f;
        float x = radius * std::sin(angle * PI / 180.0f);
        float y = radius * std::cos(angle * PI / 180.0f) + 1.0;
        glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glRotatef(-angle, 0.0f, 0.0f, 1.0f); 
        drawRectangle(0.05f, 0.1f);
        glPopMatrix();
    }
}

void drawMinuteMarkers(float radius) {
    for (int i = 0; i < 60; ++i) {
        if (i % 5 == 0) continue;
        float angle = i * 6.0f;
        float x = radius * std::sin(angle * PI / 180.0f);
        float y = radius * std::cos(angle * PI / 180.0f) + 1.0;
        glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glRotatef(-angle, 0.0f, 0.0f, 1.0f);
        drawRectangle(0.02f, 0.05f);
        glPopMatrix();
    }
}

// degrees
float calculateHandAngles(int unit, int maxUnits) {
    return -360.0f * (static_cast<float>(unit) / maxUnits);
}

void Visualisation(float angle) {
    time_t rawTime;
    struct tm currentTime;
    errno_t err;

    time(&rawTime);
    err = localtime_s(&currentTime, &rawTime);

    int hours = currentTime.tm_hour;
    int minutes = currentTime.tm_min;
    int seconds = currentTime.tm_sec;

    float hourAngle = calculateHandAngles((hours % 12) * 60 + minutes, 12 * 60);
    float minuteAngle = calculateHandAngles(minutes * 60 + seconds, 60 * 60);
    float secondAngle = calculateHandAngles(seconds, 60);

    drawCuboid(1.0f, 1.0f, 1.0f);
    drawCuboid(1.5f, 1.0f, 0.7f);
    Cylinders();
    drawCylinder();

    drawLegs(-0.9, -1.3, -1.5, -0.7, -1.2, -1.0, 1.0, 0.5);
    drawLegs(0.9, 1.3, 1.5, 0.7, -1.2, -1.0, 1.0, 0.5);
    drawLegs(-0.9, -1.3, -1.5, -0.7, -1.2, -1.0, -1.0, -0.5);
    drawLegs(0.9, 1.3, 1.5, 0.7, -1.2, -1.0, -1.0, -0.5);

    drawHourMarkers(0.65f);
    drawMinuteMarkers(0.68f);

    glTranslatef(0.0f, 1.0f, 1.02f);
    drawCircle(0.7, 100);

    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef(hourAngle, 0.0, 0.0, 1.0);
    drawHand(0.35, 0.04);
    glPopMatrix();

    glColor3f(0.45f, 0.225f, 0.072f);
    glPushMatrix();
    glRotatef(minuteAngle, 0.0, 0.0, 1.0);
    drawHand(0.55, 0.03);
    glPopMatrix();

    glColor3f(0.5f, 0.25f, 0.08f);
    glPushMatrix();
    glRotatef(secondAngle, 0.0, 0.0, 1.0);
    drawHand(0.7, 0.01);
    glPopMatrix();

    glFlush();
}
