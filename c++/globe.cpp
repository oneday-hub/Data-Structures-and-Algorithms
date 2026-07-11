#include <GL/glut.h>

// Function to draw a simple Earth model
void drawEarth() {
    glColor3f(0.0, 0.5, 1.0);  // Blue color for Earth
    glutSolidSphere(1.0, 50, 50);  // Draw a sphere representing Earth
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Position the Earth
    glTranslatef(0.0, 0.0, -5.0);

    // Rotate the Earth (optional)
    static float angle = 0.0;
    angle += 0.5;
    glRotatef(angle, 0.0, 1.0, 0.0);

    drawEarth();

    glutSwapBuffers();
}

// Reshape callback function
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (double)w / h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Earth Model");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
