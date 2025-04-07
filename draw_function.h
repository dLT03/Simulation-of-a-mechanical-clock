#pragma once
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <conio.h>

#define PI acos(-1) 

void GearWheel(const float x, const float y, const float z, float radius, float width_GearWheel, float width_down, float width_top, float height_teeth, int number_teeth, float angle) {

    float alpha = 2 * asinf(width_down / (2 * radius));
    float beta = 2 * PI / number_teeth - alpha;
    float gamma = atanf(width_top / (2 * (height_teeth + radius * cosf(alpha / 2))));
    float delta = alpha / 2 - gamma;
    float r = width_top / (2 * sinf(gamma));

<<<<<<< HEAD
    //std::cout << 2 * radius * sinf(beta / 2) << std::endl;

    float x1, x2, x3, x4, y1, y2, y3, y4;
    // przód
=======
   //std::cout << 2 * radius * sinf(beta / 2) << std::endl;

    float x1, x2, x3, x4, y1, y2, y3, y4;
    // przÃ³d
>>>>>>> 6c372a52e57980ce15ae20a06ef860dfeeb53aba
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f); // Color Red

    glVertex3f(x, y, z);

<<<<<<< HEAD
    for (int i = 0; i <= number_teeth; i++)
    {
        x1 = x - radius * sinf((alpha + beta) * i + angle);
        y1 = y + radius * cosf((alpha + beta) * i + angle);

=======
    for (int i = 0; i <= number_teeth; i++) 
    {    
        x1 = x - radius * sinf((alpha + beta) * i + angle);
        y1 = y + radius * cosf((alpha + beta) * i + angle);
        
>>>>>>> 6c372a52e57980ce15ae20a06ef860dfeeb53aba
        x4 = x - radius * sinf((alpha + beta) * i + alpha + angle);
        y4 = y + radius * cosf((alpha + beta) * i + alpha + angle);

        x2 = x - r * sinf((alpha + beta) * i + delta + angle);
        y2 = y + r * cosf((alpha + beta) * i + delta + angle);

        x3 = x - r * sinf((alpha + beta) * i + (alpha - delta) + angle);
        y3 = y + r * cosf((alpha + beta) * i + (alpha - delta) + angle);

        glVertex3f(x1, y1, (z + width_GearWheel / 2));
        glVertex3f(x2, y2, (z + width_GearWheel / 2));
        glVertex3f(x3, y3, (z + width_GearWheel / 2));
        glVertex3f(x4, y4, (z + width_GearWheel / 2));
<<<<<<< HEAD

    }
    glEnd();

    //ty³
=======
       
    }
    glEnd();

    //tyÅ‚
>>>>>>> 6c372a52e57980ce15ae20a06ef860dfeeb53aba
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 1.0f, 0.0f); // Color Green

    glVertex3f(x, y, z);

    for (int i = 0; i <= number_teeth; i++)
    {
        x1 = x - radius * sinf((alpha + beta) * i + angle);
        y1 = y + radius * cosf((alpha + beta) * i + angle);

        x4 = x - radius * sinf((alpha + beta) * i + alpha + angle);
        y4 = y + radius * cosf((alpha + beta) * i + alpha + angle);

        x2 = x - r * sinf((alpha + beta) * i + delta + angle);
        y2 = y + r * cosf((alpha + beta) * i + delta + angle);

        x3 = x - r * sinf((alpha + beta) * i + (alpha - delta) + angle);
        y3 = y + r * cosf((alpha + beta) * i + (alpha - delta) + angle);

        glVertex3f(x1, y1, (z - width_GearWheel / 2));
        glVertex3f(x2, y2, (z - width_GearWheel / 2));
        glVertex3f(x3, y3, (z - width_GearWheel / 2));
        glVertex3f(x4, y4, (z - width_GearWheel / 2));

    }
    glEnd();


    // side

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.0f, 0.0f, 1.0f); // Color Blue

    for (int i = 0; i <= number_teeth; i++)
    {
        x1 = x - radius * sinf((alpha + beta) * i + angle);
        y1 = y + radius * cosf((alpha + beta) * i + angle);

        x4 = x - radius * sinf((alpha + beta) * i + alpha + angle);
        y4 = y + radius * cosf((alpha + beta) * i + alpha + angle);

        x2 = x - r * sinf((alpha + beta) * i + delta + angle);
        y2 = y + r * cosf((alpha + beta) * i + delta + angle);

        x3 = x - r * sinf((alpha + beta) * i + (alpha - delta) + angle);
        y3 = y + r * cosf((alpha + beta) * i + (alpha - delta) + angle);


        glVertex3f(x1, y1, (z - width_GearWheel / 2));
        glVertex3f(x1, y1, (z + width_GearWheel / 2));
        glVertex3f(x2, y2, (z - width_GearWheel / 2));
        glVertex3f(x2, y2, (z + width_GearWheel / 2));
        glVertex3f(x3, y3, (z - width_GearWheel / 2));
        glVertex3f(x3, y3, (z + width_GearWheel / 2));
        glVertex3f(x4, y4, (z - width_GearWheel / 2));
        glVertex3f(x4, y4, (z + width_GearWheel / 2));

    }
    glEnd();

}

void drawCylinderGearWheel(const float x, const float y, const float z, float radiusOUT, float radiusIN, float width_GearWheel, int number_teeth, float alpha, float angle) {
    float beta = (2 * PI / number_teeth - alpha);
    float x1, x2, x3, x4, y1, y2, y3, y4;

    // Front face
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f); // Color Red
    for (int i = 0; i <= number_teeth; i++) {
        x1 = x - radiusIN * sinf((alpha + beta) * i + angle);
        y1 = y + radiusIN * cosf((alpha + beta) * i + angle);

        x2 = x - radiusOUT * sinf((alpha + beta) * i + angle);
        y2 = y + radiusOUT * cosf((alpha + beta) * i + angle);

        x3 = x - radiusOUT * sinf((alpha + beta) * i + alpha + angle);
        y3 = y + radiusOUT * cosf((alpha + beta) * i + alpha + angle);

        x4 = x - radiusIN * sinf((alpha + beta) * i + alpha + angle);
        y4 = y + radiusIN * cosf((alpha + beta) * i + alpha + angle);

        glVertex3f(x1, y1, (z + width_GearWheel / 2));
        glVertex3f(x2, y2, (z + width_GearWheel / 2));
        glVertex3f(x4, y4, (z + width_GearWheel / 2));
        glVertex3f(x3, y3, (z + width_GearWheel / 2));
    }
    glEnd();

    // Back face
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f); // Color Green
    for (int i = 0; i <= number_teeth; i++) {
        x1 = x - radiusIN * sinf((alpha + beta) * i + angle);
        y1 = y + radiusIN * cosf((alpha + beta) * i + angle);

        x2 = x - radiusOUT * sinf((alpha + beta) * i + angle);
        y2 = y + radiusOUT * cosf((alpha + beta) * i + angle);

        x3 = x - radiusOUT * sinf((alpha + beta) * i + alpha + angle);
        y3 = y + radiusOUT * cosf((alpha + beta) * i + alpha + angle);

        x4 = x - radiusIN * sinf((alpha + beta) * i + alpha + angle);
        y4 = y + radiusIN * cosf((alpha + beta) * i + alpha + angle);

        glVertex3f(x1, y1, (z - width_GearWheel / 2));
        glVertex3f(x2, y2, (z - width_GearWheel / 2));
        glVertex3f(x4, y4, (z - width_GearWheel / 2));
        glVertex3f(x3, y3, (z - width_GearWheel / 2));
    }
    glEnd();

    // Side faces - in
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.0f, 0.0f, 1.0f); // Color Blue
    for (int i = 0; i <= number_teeth; i++) {
        x1 = x - radiusIN * sinf((alpha + beta) * i + angle);
        y1 = y + radiusIN * cosf((alpha + beta) * i + angle);

        x4 = x - radiusIN * sinf((alpha + beta) * i + alpha + angle);
        y4 = y + radiusIN * cosf((alpha + beta) * i + alpha + angle);

        glVertex3f(x1, y1, (z - width_GearWheel / 2));
        glVertex3f(x1, y1, (z + width_GearWheel / 2));
        glVertex3f(x4, y4, (z - width_GearWheel / 2));
        glVertex3f(x4, y4, (z + width_GearWheel / 2));
    }
    glEnd();

    // Side faces - out
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.0f, 0.0f, 1.0f); // Color Blue
    for (int i = 0; i <= number_teeth; i++) {
        x2 = x - radiusOUT * sinf((alpha + beta) * i + angle);
        y2 = y + radiusOUT * cosf((alpha + beta) * i + angle);

        x3 = x - radiusOUT * sinf((alpha + beta) * i + alpha + angle);
        y3 = y + radiusOUT * cosf((alpha + beta) * i + alpha + angle);

        glVertex3f(x2, y2, (z - width_GearWheel / 2));
        glVertex3f(x2, y2, (z + width_GearWheel / 2));
        glVertex3f(x3, y3, (z - width_GearWheel / 2));
        glVertex3f(x3, y3, (z + width_GearWheel / 2));
    }
    glEnd();
}

void drawGearWheel(const float x, const float y, const float z, float radiusOUT, float radiusIN, float width_GearWheel, float width_down, float width_top, float height_teeth, int number_teeth, float angle) {
    float alpha = 2 * asinf(width_down / (2 * radiusOUT));
    float beta = 2 * PI / number_teeth - alpha;
    float gamma = atanf(width_top / (2 * (height_teeth + radiusOUT * cosf(alpha / 2))));
    float delta = alpha / 2 - gamma;
    float r = width_top / (2 * sinf(gamma));

    drawCylinderGearWheel(x, y, z, radiusOUT, radiusIN, width_GearWheel, number_teeth, alpha, angle);

    // draw teeth GearWheel
    float x1, x2, x3, x4, y1, y2, y3, y4;
    for (int i = 0; i < number_teeth; i++) {
        x1 = x - radiusOUT * sinf((alpha + beta) * i + angle);
        y1 = y + radiusOUT * cosf((alpha + beta) * i + angle);

        x4 = x - radiusOUT * sinf((alpha + beta) * i + alpha + angle);
        y4 = y + radiusOUT * cosf((alpha + beta) * i + alpha + angle);

        x2 = x - r * sinf((alpha + beta) * i + delta + angle);
        y2 = y + r * cosf((alpha + beta) * i + delta + angle);

        x3 = x - r * sinf((alpha + beta) * i + (alpha - delta) + angle);
        y3 = y + r * cosf((alpha + beta) * i + (alpha - delta) + angle);

        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f); // Color Green (Back face)
        glVertex3f(x1, y1, (z - width_GearWheel / 2));
        glVertex3f(x2, y2, (z - width_GearWheel / 2));
        glVertex3f(x3, y3, (z - width_GearWheel / 2));
        glVertex3f(x4, y4, (z - width_GearWheel / 2));

        glColor3f(1.0f, 0.0f, 0.0f); // Color Red (Front face)
        glVertex3f(x1, y1, (z + width_GearWheel / 2));
        glVertex3f(x2, y2, (z + width_GearWheel / 2));
        glVertex3f(x3, y3, (z + width_GearWheel / 2));
        glVertex3f(x4, y4, (z + width_GearWheel / 2));
        glEnd();

        glBegin(GL_QUAD_STRIP);
        glColor3f(0.0f, 0.0f, 1.0f); // Color Blue (Side faces)
        glVertex3f(x1, y1, (z - width_GearWheel / 2));
        glVertex3f(x1, y1, (z + width_GearWheel / 2));
        glVertex3f(x2, y2, (z - width_GearWheel / 2));
        glVertex3f(x2, y2, (z + width_GearWheel / 2));
        glVertex3f(x3, y3, (z - width_GearWheel / 2));
        glVertex3f(x3, y3, (z + width_GearWheel / 2));
        glVertex3f(x4, y4, (z - width_GearWheel / 2));
        glVertex3f(x4, y4, (z + width_GearWheel / 2));
        glEnd();
    }

}

void Mechanizm(float angle) {

    float extra_stock = 0.1;
    float radius_GWsecond = 1.0f;
    float height_GWsecond = 0.2f;

    float radius_GWhour = 0.2f;
    float height_GWhour = 0.1f;

    float height_mainstick = 1.5f;
    float radius_mainstick = 0.06f;

    float height_gear1 = 0.2f;
    float radius_gear1 = 0.3f;

    float height_between = 0.3;
    height_between = height_between + extra_stock + height_GWsecond + height_gear1;

    float height_gear2 = 0.1f;
    float radius_gear2 = 0.3f;

    float height_gear3 = 0.4f;
    float radius_gear3 = 0.09f;

    float height_gear4 = 0.05f;
    float radius_gear4 = 0.12f;

    //drawGearWheel(-1, 0, 0, 1.0f, 0.5f, 0.4f, 0.3f, 0.2f, 0.2f, 16, angle);

    // main stick
    drawGearWheel(0, 0, height_mainstick / 2, radius_mainstick, 0, height_mainstick, 0.1, 0.1, 0, 60, angle);

    // second
<<<<<<< HEAD
    drawGearWheel(0, 0, extra_stock + height_GWsecond / 2, radius_GWsecond, radius_mainstick, height_GWsecond, 0.05f, 0.04f, 0.03f, 60, angle);
=======
    drawGearWheel(0, 0, extra_stock + height_GWsecond/2, radius_GWsecond, radius_mainstick, height_GWsecond, 0.05f, 0.04f, 0.03f, 60, angle);
>>>>>>> 6c372a52e57980ce15ae20a06ef860dfeeb53aba
    drawGearWheel(0, 0, extra_stock + height_GWsecond + height_gear1 / 2, radius_gear1, radius_mainstick, height_gear1, 0.1, 0.1, 0, 60, angle);

    // minute
    drawGearWheel(0, 0, height_between + height_gear2 / 2, radius_gear2, radius_mainstick, height_gear2, 0.1, 0.1, 0, 60, angle);
    drawGearWheel(0, 0, height_between + height_gear2 + height_gear3 / 2, radius_gear3, radius_mainstick, height_gear3, 0.1, 0.1, 0, 60, angle);

    // hour
    drawGearWheel(0, 0, height_between + height_gear2 + height_GWhour / 2, radius_GWhour, radius_gear3, height_GWhour, 0.1, 0.1, 0, 60, angle);
<<<<<<< HEAD
    drawGearWheel(0, 0, height_between + height_gear2 + height_GWhour + height_gear4 / 2, radius_gear4, radius_gear3, radius_gear4, 0.1, 0.1, 0, 60, angle);
=======
    drawGearWheel(0, 0, height_between + height_gear2 + height_GWhour + height_gear4 / 2 , radius_gear4, radius_gear3, radius_gear4, 0.1, 0.1, 0, 60, angle);
>>>>>>> 6c372a52e57980ce15ae20a06ef860dfeeb53aba


    //drawCylinder(-1, 0, 0, 0.2, 0.4, 60);
    //std::cin.get(); // zczytanie odleg?o?ci mi?dzy ko?ami
<<<<<<< HEAD
    //GearWheel(1, 0, 0, 0.2f, 0.4f, 0.06f, 0.054f, 0.02f, 18, 0);#pragma once
=======
    //GearWheel(1, 0, 0, 0.2f, 0.4f, 0.06f, 0.054f, 0.02f, 18, 0);
>>>>>>> 6c372a52e57980ce15ae20a06ef860dfeeb53aba
