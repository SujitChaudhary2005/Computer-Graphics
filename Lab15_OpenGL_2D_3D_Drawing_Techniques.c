#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw a point
    glPointSize(5.0f);
    glBegin(GL_POINTS);
        glColor3f(1, 0, 0);
        glVertex3f(-0.8f, 0.8f, 0.0f);
    glEnd();

    // Draw a line
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3f(0, 1, 0);
        glVertex3f(-0.8f, 0.6f, 0.0f);
        glVertex3f(-0.2f, 0.6f, 0.0f);
    glEnd();

    // Draw a triangle
    glBegin(GL_TRIANGLES);
        glColor3f(0, 0, 1);
        glVertex3f(-0.8f, 0.3f, 0.0f);
        glVertex3f(-0.6f, 0.5f, 0.0f);
        glVertex3f(-0.4f, 0.3f, 0.0f);
    glEnd();

    // Draw a quadrilateral
    glBegin(GL_QUADS);
        glColor3f(1, 1, 0);
        glVertex3f(0.2f, 0.8f, 0.0f);
        glVertex3f(0.6f, 0.8f, 0.0f);
        glVertex3f(0.6f, 0.6f, 0.0f);
        glVertex3f(0.2f, 0.6f, 0.0f);
    glEnd();

    // Draw a polygon (pentagon)
    glBegin(GL_POLYGON);
        glColor3f(0, 1, 1);
        glVertex3f(0.4f, 0.3f, 0.0f);
        glVertex3f(0.5f, 0.5f, 0.0f);
        glVertex3f(0.7f, 0.5f, 0.0f);
        glVertex3f(0.8f, 0.3f, 0.0f);
        glVertex3f(0.6f, 0.1f, 0.0f);
    glEnd();

    // Draw a 3D cube (filled)
    glPushMatrix();
    glTranslatef(0.0f, -0.5f, -2.0f);
    glRotatef(30, 1, 1, 0);

    // Filled cube
    glColor3f(1, 0, 1); // Magenta
    glutSolidCube(0.5);

    // Wireframe overlay
    glColor3f(1, 1, 1); // White
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glutWireCube(0.5);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Reset to fill mode

    glPopMatrix();

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background to black
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)w/h, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,2, 0,0,0, 0,1,0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Basic Drawing Techniques in OpenGL");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}