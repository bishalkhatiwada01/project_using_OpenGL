#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <GLUT/glut.h>


// Define the value of PI, upto 12 decimal places
#define PI 3.1415926535




// Function to Draw Circle
void drawCircle(GLfloat x, GLfloat y,
                GLfloat r, GLfloat g, GLfloat b,
                GLfloat sx, GLfloat sy,
                GLfloat radius) {
    glPushMatrix();
    
    glTranslatef(x, y, 0);
    glScalef(sx, sy, 0);
    
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    for (GLfloat i = 0; i < 360; i += 5)
        glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();
    
    glPopMatrix();
}



void drawBackground() {
    
    // Night sky
    glBegin(GL_POLYGON);
    glColor3ub(10, 10, 40); // Dark blue
    glVertex2f(0, 800);
    
    glVertex2f(1400, 800);
    
    
    glVertex2f(1400, 400);
    
    
    glVertex2f(0, 400);
    
    glEnd();
    
    
}
void drawMoon() {
    // moon
    drawCircle(300 , 700,
               246, 241, 213,
               1, 1,
               50);
}

void drawRoad() {
    // Road
    glBegin(GL_POLYGON);
    glColor3ub(40, 40, 40);
    glVertex2f(0, 175);
    glVertex2f(1400, 175);
    glVertex2f(1400, 75);
    glVertex2f(0, 75);
    glEnd();
    
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0, 125);
    glVertex2f(200, 125);
    
    glVertex2f(300, 125);
    glVertex2f(500, 125);
    
    glVertex2f(600, 125);
    glVertex2f(800, 125);
    
    glVertex2f(900, 125);
    glVertex2f(1100, 125);
    
    glVertex2f(1200, 125);
    glVertex2f(1400, 125);
    glEnd();
    glLineWidth(1);
}

void drawHome() {
    // Home Bottom
    glBegin(GL_POLYGON);
    glColor3ub(169, 117, 83);
    glVertex2f(1375, 175);
    glVertex2f(1375, 300);
    glVertex2f(1100, 300);
    glVertex2f(1100, 175);
    glEnd();
    
    
    // Home Top Left
    glBegin(GL_POLYGON);
    glColor3ub(169, 117, 83);
    glVertex2f(1100, 300);
    glVertex2f(1220, 300);
    glVertex2f(1220, 400);
    glVertex2f(1100, 400);
    glEnd();
    
    
    
    // Triangle Rooftop
    glBegin(GL_TRIANGLES);
    glColor3ub(69, 39, 23);
    glVertex2f(1090, 400);
    glVertex2f(1230, 400);
    glVertex2f(1160, 450);
    glEnd();
    
    
    
    // Home Top Right
    glBegin(GL_POLYGON);
    glColor3ub(69, 39, 23);
    glVertex2f(1220, 375);
    glVertex2f(1375, 375);
    glVertex2f(1375, 300);
    glVertex2f(1220, 300);
    glEnd();
    
    
    // Home Bottom-Top Divider
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(20, 20, 20);
    glVertex2f(1090, 300);
    glVertex2f(1385, 300);
    glEnd();
    glLineWidth(1);
    
    // Door
    glBegin(GL_POLYGON);
    glColor3ub(31, 47, 53);
    glVertex2f(1130, 175);
    glVertex2f(1130, 280);
    glVertex2f(1190, 280);
    glVertex2f(1190, 175);
    glEnd();
    
    
    // Top Window
    glBegin(GL_POLYGON);
    glColor3ub(59, 91, 132);
    glVertex2f(1130, 330);
    glVertex2f(1130, 370);
    glVertex2f(1190, 370);
    glVertex2f(1190, 330);
    glEnd();
    
    
    
    // Rectangular Window
    glBegin(GL_POLYGON);
    glColor3ub(59, 91, 132);
    glVertex2f(1240, 280);
    glVertex2f(1240, 240);
    glVertex2f(1355, 240);
    glVertex2f(1355, 280);
    glEnd();
    
    
    // Rectangular Window Grill
    glBegin(GL_LINES);
    glColor3ub(20, 20, 20);
    glVertex2f(1297, 280);
    glVertex2f(1297, 240);
    glVertex2f(1355, 260);
    glVertex2f(1240, 260);
    glEnd();
    
    //     Top Circle
    drawCircle(1160, 420,
               255, 255, 255,
               1, 1,
               10);
}

void drawCollege() {
    // College Building
    glBegin(GL_POLYGON);
    glColor3ub(184, 88, 68);
    glVertex2f(400, 175);
    glVertex2f(1000, 175);
    glVertex2f(1000, 500);
    glVertex2f(400, 500);
    glEnd();
    
    // College Board
    glBegin(GL_POLYGON);
    glColor3ub(183, 184, 188);
    glVertex2f(570, 530);
    glVertex2f(830, 530);
    glVertex2f(830, 470);
    glVertex2f(570, 470);
    glEnd();
    
    
    const char* collegeName = "Sunway College";
    
    glColor3ub(255, 255, 255); // Set text color to white
    glRasterPos2i(630, 490);  // Set the position for the text
    for (int i = 0; i < strlen(collegeName); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, collegeName[i]);
    }
    
    
    // College Windows upper 2 row
    for (int i = 0; i <= 500; i+=100) {
        for (int j = 0; j <= 100; j+=80) {
            glBegin(GL_POLYGON);
            glColor3ub(59, 91, 132);
            glVertex2f(425 + i, 450 - j);
            glVertex2f(475 + i, 450 - j);
            glVertex2f(475 + i, 400 - j);
            glVertex2f(425 + i, 400 - j);
            glEnd();
        }
    }
    
    
    // College Door
    glBegin(GL_POLYGON);
    glColor3ub(183, 184, 188);
    glVertex2f(600, 175);
    glVertex2f(600, 280);
    glVertex2f(800, 280);
    glVertex2f(800, 175);
    glEnd();
    
    
    // College Door Divider
    glBegin(GL_LINES);
    glColor3ub(20, 20, 20);
    glVertex2f(700, 280);
    glVertex2f(700, 175);
    glEnd();
    
    
    
    //    ground floor windows
    
    glBegin(GL_POLYGON);
    glColor3ub(59, 91, 132);
    glVertex2f(425, 280);
    glVertex2f(475, 280);
    glVertex2f(475, 200);
    glVertex2f(425, 200);
    glEnd();
    
    
    
    glBegin(GL_POLYGON);
    glColor3ub(59, 91, 132);
    glVertex2f(525, 280);
    glVertex2f(575, 280);
    glVertex2f(575, 200);
    glVertex2f(525, 200);
    glEnd();
    
    
    
    glBegin(GL_POLYGON);
    glColor3ub(59, 91, 132);
    glVertex2f(825, 280);
    glVertex2f(875, 280);
    glVertex2f(875, 200);
    glVertex2f(825, 200);
    glEnd();
    
    
    
    glBegin(GL_POLYGON);
    glColor3ub(59, 91, 132);
    glVertex2f(925, 280);
    glVertex2f(975, 280);
    glVertex2f(975, 200);
    glVertex2f(925, 200);
    glEnd();
    
    
    
}

void drawTuition() {
    // Tuition Building
    glBegin(GL_POLYGON);
    glColor3ub(151, 188, 207);
    glVertex2f(25, 175);
    glVertex2f(300, 175);
    glVertex2f(300, 350);
    glVertex2f(25, 350);
    glEnd();
    
    
    // Tuition Board
    glBegin(GL_POLYGON);
    glColor3ub(255, 218, 154);
    glVertex2f(50, 375);
    glVertex2f(180, 375);
    glVertex2f(180, 325);
    glVertex2f(50, 325);
    glEnd();
    
    
    glColor3ub(255, 255, 255); // Set text color to white
    glRasterPos2i(80, 343);  // Set the position for the text
    
    const char* collegeName = "Tution";
    
    // Change the font to GLUT_BITMAP_TIMES_ROMAN_24 (Times Roman with size 24)
    for (int i = 0; i < strlen(collegeName); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, collegeName[i]);
    }
    
    
    
    
    // Tuition Door
    glBegin(GL_POLYGON);
    glColor3ub(70, 39, 21);
    glVertex2f(55, 175);
    glVertex2f(55, 280);
    glVertex2f(115, 280);
    glVertex2f(115, 175);
    glEnd();
    
    
    
    // Tuition Rectangular Window
    glBegin(GL_POLYGON);
    glColor3ub(59, 91, 132);
    glVertex2f(155, 280);
    glVertex2f(155, 240);
    glVertex2f(270, 240);
    glVertex2f(270, 280);
    glEnd();
    
    
    // Tuition Rectangular Window Grill
    glBegin(GL_LINES);
    glColor3ub(20, 20, 20);
    glVertex2f(213, 280);
    glVertex2f(213, 240);
    glVertex2f(155, 260);
    glVertex2f(270, 260);
    glEnd();
}
void drawLights() {
    // Left Light Pole
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(200, 200, 200);
    glVertex2f(350, 175);
    glVertex2f(350, 300);
    glEnd();
    glLineWidth(1);
    
    // Right Light Pole
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(200, 200, 200);
    glVertex2f(1050, 175);
    glVertex2f(1050, 300);
    glEnd();
    glLineWidth(1);
    
    // Left Bulb (change color to yellow)
    drawCircle(350,300,
               255, 255, 0, // Yellow color
               1, 1,
               15);
    
    // Right Bulb (change color to yellow)
    drawCircle(1050,300,
               255, 255, 0, // Yellow color
               1, 1,
               15);
}

// Variables for Random Star Generation
int star_alpha, no_of_stars, stars_array[40][2];

void drawStars() {
    
    for (int i = 0, j = 0; i < 40; i++) {
        stars_array[i][j] = 0 + (rand() % (int)(1400 - 0 + 1));
        stars_array[i][j+1] = 530 + (rand() % (int)(800 - 530 + 1));
        no_of_stars++;
        
        glPointSize(2);
        glBegin(GL_POINTS);
        glColor4ub(255, 255, 255, star_alpha);
        for (int i = 0, j = 0; i < no_of_stars; i++)
            glVertex2f(stars_array[i][j], stars_array[i][j+1]);
        glEnd();
        glPointSize(1);
    }
}





void myCollege() {
    // Background
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawBackground();
    drawMoon();
    drawStars();
    drawRoad();
    drawCollege();
    drawHome();
    
    drawTuition();
    drawLights();
}


// Function to Render Scene
void renderScene() {
    myCollege();
    glFlush();
}


// Function to Initialize Screen
void initializeScreen() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1400, 0, 800);
}

// Main Function
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1400, 800);
    glutCreateWindow("My College");
    
    
    // Display Function
    glutDisplayFunc(renderScene);
    initializeScreen();
    glutMainLoop();
    
    return 0;
}
