#include "GearWheel.h"

GearWheel::GearWheel(pointXYZ pos, float rOut, float rIn, float wGW, float wDown, float wTop, float hTeeth, int numTeeth, float R, float G, float B)
    : position(pos), radiusOUT(rOut), radiusIN(rIn), width_GearWheel(wGW),
    width_down(wDown), width_top(wTop), height_teeth(hTeeth), number_teeth(numTeeth), Red(R), Green(G), Blue(B) {}

void GearWheel::drawCylinderGearWheel(float angle) {
    float alpha = 2 * asinf(width_down / (2 * radiusOUT));
    float beta = (2 * PI / number_teeth - alpha);
    float x1, x2, x3, x4, y1, y2, y3, y4;

    glColor3ub(Red, Green, Blue);
    // Front face
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= number_teeth; i++) {
        x1 = position.x - radiusIN * sinf((alpha + beta) * i + angle);
        y1 = position.y + radiusIN * cosf((alpha + beta) * i + angle);
        x2 = position.x - radiusOUT * sinf((alpha + beta) * i + angle);
        y2 = position.y + radiusOUT * cosf((alpha + beta) * i + angle);
        x3 = position.x - radiusOUT * sinf((alpha + beta) * i + alpha + angle);
        y3 = position.y + radiusOUT * cosf((alpha + beta) * i + alpha + angle);
        x4 = position.x - radiusIN * sinf((alpha + beta) * i + alpha + angle);
        y4 = position.y + radiusIN * cosf((alpha + beta) * i + alpha + angle);

        glVertex3f(x1, y1, (position.z + width_GearWheel / 2));
        glVertex3f(x2, y2, (position.z + width_GearWheel / 2));
        glVertex3f(x4, y4, (position.z + width_GearWheel / 2));
        glVertex3f(x3, y3, (position.z + width_GearWheel / 2));
    }
    glEnd();

    // Back face
    glBegin(GL_QUAD_STRIP);
    glColor3ub(Red, Green, Blue);
    for (int i = 0; i <= number_teeth; i++) {
        x1 = position.x - radiusIN * sinf((alpha + beta) * i + angle);
        y1 = position.y + radiusIN * cosf((alpha + beta) * i + angle);
        x2 = position.x - radiusOUT * sinf((alpha + beta) * i + angle);
        y2 = position.y + radiusOUT * cosf((alpha + beta) * i + angle);
        x3 = position.x - radiusOUT * sinf((alpha + beta) * i + alpha + angle);
        y3 = position.y + radiusOUT * cosf((alpha + beta) * i + alpha + angle);
        x4 = position.x - radiusIN * sinf((alpha + beta) * i + alpha + angle);
        y4 = position.y + radiusIN * cosf((alpha + beta) * i + alpha + angle);

        glVertex3f(x1, y1, (position.z - width_GearWheel / 2));
        glVertex3f(x2, y2, (position.z - width_GearWheel / 2));
        glVertex3f(x4, y4, (position.z - width_GearWheel / 2));
        glVertex3f(x3, y3, (position.z - width_GearWheel / 2));
    }
    glEnd();

    // Side faces - out
    glColor3ub(Red * 0.7, Green * 0.7, Blue * 0.7);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= number_teeth; i++) {
        x2 = position.x - radiusOUT * sinf((alpha + beta) * i + angle);
        y2 = position.y + radiusOUT * cosf((alpha + beta) * i + angle);
        x3 = position.x - radiusOUT * sinf((alpha + beta) * i + alpha + angle);
        y3 = position.y + radiusOUT * cosf((alpha + beta) * i + alpha + angle);

        glVertex3f(x2, y2, (position.z - width_GearWheel / 2));
        glVertex3f(x2, y2, (position.z + width_GearWheel / 2));
        glVertex3f(x3, y3, (position.z - width_GearWheel / 2));
        glVertex3f(x3, y3, (position.z + width_GearWheel / 2));
    }
    glEnd();

    glColor3ub(Red * 0.75, Green * 0.75, Blue * 0.75);
    // Side faces - in
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= number_teeth; i++) {
        x1 = position.x - radiusIN * sinf((alpha + beta) * i + angle);
        y1 = position.y + radiusIN * cosf((alpha + beta) * i + angle);
        x4 = position.x - radiusIN * sinf((alpha + beta) * i + alpha + angle);
        y4 = position.y + radiusIN * cosf((alpha + beta) * i + alpha + angle);

        glVertex3f(x1, y1, (position.z - width_GearWheel / 2));
        glVertex3f(x1, y1, (position.z + width_GearWheel / 2));
        glVertex3f(x4, y4, (position.z - width_GearWheel / 2));
        glVertex3f(x4, y4, (position.z + width_GearWheel / 2));
    }
    glEnd();

}

void GearWheel::drawGearWheel(float angle) {
    float alpha = 2 * asinf(width_down / (2 * radiusOUT));
    float beta = 2 * PI / number_teeth - alpha;
    float gamma = atanf(width_top / (2 * (height_teeth + radiusOUT * cosf(alpha / 2))));
    float delta = alpha / 2 - gamma;
    float r = width_top / (2 * sinf(gamma));

    drawCylinderGearWheel(angle);

    // draw teeth GearWheel
    float x1, x2, x3, x4, y1, y2, y3, y4;
    for (int i = 0; i < number_teeth; i++) {
        x1 = position.x - radiusOUT * sinf((alpha + beta) * i + angle);
        y1 = position.y + radiusOUT * cosf((alpha + beta) * i + angle);
        x4 = position.x - radiusOUT * sinf((alpha + beta) * i + alpha + angle);
        y4 = position.y + radiusOUT * cosf((alpha + beta) * i + alpha + angle);
        x2 = position.x - r * sinf((alpha + beta) * i + delta + angle);
        y2 = position.y + r * cosf((alpha + beta) * i + delta + angle);
        x3 = position.x - r * sinf((alpha + beta) * i + (alpha - delta) + angle);
        y3 = position.y + r * cosf((alpha + beta) * i + (alpha - delta) + angle);

        glBegin(GL_QUADS);
        glColor3ub(Red, Green, Blue);
        glVertex3f(x1, y1, (position.z - width_GearWheel / 2));
        glVertex3f(x2, y2, (position.z - width_GearWheel / 2));
        glVertex3f(x3, y3, (position.z - width_GearWheel / 2));
        glVertex3f(x4, y4, (position.z - width_GearWheel / 2));

        glVertex3f(x1, y1, (position.z + width_GearWheel / 2));
        glVertex3f(x2, y2, (position.z + width_GearWheel / 2));
        glVertex3f(x3, y3, (position.z + width_GearWheel / 2));
        glVertex3f(x4, y4, (position.z + width_GearWheel / 2));

        glColor3ub(Red * 0.75, Green * 0.75, Blue * 0.75);
        glVertex3f(x1, y1, (position.z - width_GearWheel / 2));
        glVertex3f(x1, y1, (position.z + width_GearWheel / 2));
        glVertex3f(x2, y2, (position.z + width_GearWheel / 2));
        glVertex3f(x2, y2, (position.z - width_GearWheel / 2));

        glVertex3f(x2, y2, (position.z - width_GearWheel / 2));
        glVertex3f(x2, y2, (position.z + width_GearWheel / 2));
        glVertex3f(x3, y3, (position.z + width_GearWheel / 2));
        glVertex3f(x3, y3, (position.z - width_GearWheel / 2));

        glVertex3f(x4, y4, (position.z - width_GearWheel / 2));
        glVertex3f(x3, y3, (position.z - width_GearWheel / 2));
        glVertex3f(x3, y3, (position.z + width_GearWheel / 2));
        glVertex3f(x4, y4, (position.z + width_GearWheel / 2));
        glEnd();
    }
}

void GearWheel::drawRadiarWeb(float radiusOUT, float radiusIN, float width_line, int number_lines, float angle) {
    float alpha = 2 * PI / number_lines;
    float beta = asinf(width_line / radiusOUT);
    angle = -angle;

    float x1, x2, x0, X0, y1, y2, y0, Y0;
    for (int i = 0; i < number_lines; i++) {

        x1 = position.x + radiusOUT * sinf(alpha * i + angle);
        y1 = position.y + radiusOUT * cosf(alpha * i + angle);
        x2 = position.x + radiusOUT * sinf(alpha * i + angle + beta);
        y2 = position.y + radiusOUT * cosf(alpha * i + angle + beta);
        X0 = position.x + radiusIN * sinf(alpha * i + angle + beta / 2);
        Y0 = position.y + radiusIN * cosf(alpha * i + angle + beta / 2);
        x0 = (x1 - x2) / 2;
        y0 = (y1 - y2) / 2;

        glBegin(GL_QUADS);
        glColor3ub(Red, Green, Blue);
        glVertex3f(X0 + x0, Y0 + y0, position.z + width_GearWheel / 2);
        glVertex3f(x1, y1, position.z + width_GearWheel / 2);
        glVertex3f(x2, y2, position.z + width_GearWheel / 2);
        glVertex3f(X0 - x0, Y0 - y0, position.z + width_GearWheel / 2);

        glVertex3f(X0 + x0, Y0 + y0, position.z - width_GearWheel / 2);
        glVertex3f(x1, y1, position.z - width_GearWheel / 2);
        glVertex3f(x2, y2, position.z - width_GearWheel / 2);
        glVertex3f(X0 - x0, Y0 - y0, position.z - width_GearWheel / 2);

        glColor3ub(Red * 0.75, Green * 0.75, Blue * 0.75);
        glVertex3f(X0 + x0, Y0 + y0, position.z + width_GearWheel / 2);
        glVertex3f(x1, y1, position.z + width_GearWheel / 2);
        glVertex3f(x1, y1, position.z - width_GearWheel / 2);
        glVertex3f(X0 + x0, Y0 + y0, position.z - width_GearWheel / 2);

        glVertex3f(X0 - x0, Y0 - y0, position.z + width_GearWheel / 2);
        glVertex3f(x2, y2, position.z + width_GearWheel / 2);
        glVertex3f(x2, y2, position.z - width_GearWheel / 2);
        glVertex3f(X0 - x0, Y0 - y0, position.z - width_GearWheel / 2);

        glVertex3f(X0 + x0, Y0 + y0, position.z + width_GearWheel / 2);
        glVertex3f(X0 - x0, Y0 - y0, position.z + width_GearWheel / 2);
        glVertex3f(X0 - x0, Y0 - y0, position.z - width_GearWheel / 2);
        glVertex3f(X0 + x0, Y0 + y0, position.z - width_GearWheel / 2);
        glEnd();
    }
}