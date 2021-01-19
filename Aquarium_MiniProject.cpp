#include <GL/glut.h>
#include <math.h>

int state = 1;int state1 = 1;int state2 = 1;int state3 = 1;int state4 = 1;
float b1 = 0;float b2=0;float x = 0;float x1 = 0;float x2 = 0;
float x3 = 0;float x4 = 5;
float y3=0;float y=0;

void reshape(int w, int h) //user-defined function
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //resets projection matrix
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}
void timer(int time) //purple fish
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);

    switch (state)
    {
    case 1:
        if (x < 12)
        {
            x += 0.095;
        }
        else
        {
            state = -1;
        }

        break;
    case -1:
        if (x > 12)
        {
            x = -15;
            state = 1;
        }

        break;
    }
}
void timer1(int) //orange fish
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer1, 0);

    switch (state1)
    {

    case 1:
        if (x1 > -15)
        {
            x1 -= 0.09;
            y-=0.05;

        }
        else
        {
            state1 = -1;
        }

        break;
    case -1:
        if (x1 < -10)
        {
            x1 = 13;
            y=4;
            state1 = 1;
        }

        break;
    }
}
void timer2(int) //yellow fish
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer2, 0);

    switch (state2)
    {
    case 1:
        if (x2 < 19)
        {
            x2 += 0.1;
        }
        else
        {
            state2 = -1;
        }

        break;
    case -1:
        if (x2 > 19)
        {
            x2 = -14;
            state2 = 1;
        }

        break;
    }
}
void timer3(int) //red fish
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer3, 0);

    switch (state3)
    {
    case 1:
        if (x3 < 16)
        {
            x3 += 0.08;
            y3 -=0.03;
        }
        else
        {
            state3 = -1;
        }

        break;
    case -1:
        if (x3 > 16)
        {
            x3 = -7;
            y3=5;
            state3 = 1;
        }

        break;
    }
}
void timer4(int) //pink fish
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer4, 0);

    switch (state4)
    {

    case 1:
        if (x4 > -15)
        {
            x4 -= 0.085;
        }
        else
        {
            state4 = -1;
        }

        break;
    case -1:
        if (x4 < -10)
        {
            x4 = 13;
            state4 = 1;
        }

        break;
    }
}
void timer5(int) //bubbles b1
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer5, 0);
    for (int i = 0; i < 10; i++)
    {
        if (b1 < 12)
        {
            b1 += 0.02;
        }
        else if (b1 > 12)
        {
            b1 = -8;
        }
    }
}
void timer6(int) //bubbles b2
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 80, timer6, 0);
    for (int i = 0; i < 10; i++)
    {
        if (b2 < 12)
        {
            b2 += 0.01;
        }
        else if (b2 > 12)
        {
            b2 = -8;
        }
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_POLYGON); //Light blue box
    glColor3f(0.1, 0.7, 0.9);
    glVertex2f(-10, -10);
    glVertex2f(-10, 5);
    glVertex2f(10, 5);
    glVertex2f(10, -10);
    glEnd();

    glBegin(GL_POLYGON); //Dark blue box
    glColor3f(0, 0.2, 0.7);
    glVertex2f(-10, 5);
    glVertex2f(-8, 8);
    glVertex2f(8, 8);
    glVertex2f(10, 5);
    glEnd();

    for (int i = 0; i < 17; i++) //lines in dark blue box
    {
        glColor3f(0, 0.9, 0.2);
        glBegin(GL_LINES);
        glVertex2f(-8 + i, 8);
        glVertex2f(-9 + i, 5);
        glEnd();
    }

    glBegin(GL_POLYGON); //Small rectangle on top
    glColor3f(0, 0.2, 0.7);
    glVertex2f(5.5, 8);
    glVertex2f(5.5, 9.5);
    glVertex2f(7, 9.5);
    glVertex2f(7, 8);
    glEnd();

    for (int i = 0; i < 20; i += 9) //big green grasses
    {
        glBegin(GL_TRIANGLES);
        glColor3f(0, 0.4, 0);
        glVertex2f(-10+i , -10);
        glVertex2f(-9.5+i , -3.5);
        glVertex2f(-9 +i, -10);

        glVertex2f(-9+i , -10);
        glVertex2f(-8.5+i , -5);
        glVertex2f(-8.5+i, -10);
        glEnd();
    }

    for (int i = 0; i < 20; i++) //small lightgreen grasses
    {
        glBegin(GL_POLYGON);
        glColor3f(0, 0.7, 0);
        glVertex2f(-8 + i, -10);
        glVertex2f(-8.6 + i, -9.0);
        glVertex2f(-8 + i, -9.7);
        glVertex2f(-7.8 + i, -8.5);
        glVertex2f(-7.7 + i, -9.7);
        glVertex2f(-7.2 + i, -9.3);
        glVertex2f(-7.5 + i, -10);
        glEnd();
    }
    for (int i = 0; i < 20; i += 2) //middle semi green grasses
    {
        glBegin(GL_TRIANGLES);
        glColor3f(0, 0.5, 0);
        glVertex2f(-7.5 + i, -10);
        glVertex2f(-7.3 + i, -7.6);
        glVertex2f(-7.2 + i, -10);
        glEnd();
    }
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.5); //body of purple fish
    glVertex2f(4 + x, 2);
    glVertex2f(6 + x, 3);
    glVertex2f(7 + x, 2);
    glVertex2f(6 + x, 1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 1); //tail of purple fish
    glVertex2f(4.2 + x, 2);
    glVertex2f(3 + x, 1);
    glVertex2f(3.3 + x, 2);
    glVertex2f(3 + x, 3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 1); //eyes of purplefish
    glVertex2f(6.3 + x, 1.8);
    glVertex2f(6.4 + x, 2.0);
    glVertex2f(6.5 + x, 1.8);

    glColor3f(0.3, 0.2, 1); //upper wings of purple fish
    glVertex2f(6 + x, 3);
    glVertex2f(5 + x, 3);
    glVertex2f(5.5 + x, 2.7);

    glVertex2f(6 + x, 1); //lower wings of purple fish
    glVertex2f(5 + x, 1);
    glVertex2f(5.5 + x, 1.3);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.4, 0); //body of orange fish
    glVertex2f(-4 + x1, 0+y);
    glVertex2f(-3 + x1, -1+y);
    glVertex2f(-1 + x1, 0+y);
    glVertex2f(-3 + x1, 1+y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.3, 0.2); //tail of orange fish
    glVertex2f(-1.5 + x1, 0+y);
    glVertex2f(-0.5 + x1, 0.5+y);
    glVertex2f(-0.5 + x1, -0.5+y);

    glVertex2f(-3 + x1, 1+y); //upper wing of orange fish
    glVertex2f(-2 + x1, 1.5+y);
    glVertex2f(-2.5 + x1, 0.5+y);

    glVertex2f(-3 + x1, -1+y); //lower wing of orange fish
    glVertex2f(-2 + x1, -1.5+y);
    glVertex2f(-2.5 + x1, -0.5+y);

    glColor3f(1, 1, 1); //eyes of orange fish
    glVertex2f(-3.5 + x1, 0+y);
    glVertex2f(-3.2 + x1, 0+y);
    glVertex2f(-3.3 + x1, 0.3+y);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.9, 0); //body of yellow fish
    glVertex2f(-7 + x2, -3);
    glVertex2f(-7.5 + x2, -4);
    glVertex2f(-9 + x2, -3);
    glVertex2f(-7.5 + x2, -2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.7, 0.2); //tail of yellow fish
    glVertex2f(-9 + x2, -3);
    glVertex2f(-9.6 + x2, -3.5);
    glVertex2f(-9.6 + x2, -2.6);

    glColor3f(0, 0, 0); //eyes of yellow fish
    glVertex2f(-7.5 + x2, -2.7);
    glVertex2f(-7.8 + x2, -2.7);
    glVertex2f(-7.6 + x2, -2.5);

    glColor3f(0.8, 0.7, 0.2);
    glVertex2f(-7.5 + x2, -2); //upper wing of yellow fish
    glVertex2f(-8.5 + x2, -2);
    glVertex2f(-8.1 + x2, -2.4);

    glVertex2f(-7.5 + x2, -4); //lower wing of yellow fish
    glVertex2f(-8.5 + x2, -4);
    glVertex2f(-8.1 + x2, -3.5);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0, 0); //body of red fish
    glVertex2f(-3 + x3, -5+y3);
    glVertex2f(-4 + x3, -4+y3);
    glVertex2f(-5.5 + x3, -5+y3);

    glVertex2f(-3 + x3, -5+y3);
    glVertex2f(-4 + x3, -6+y3);
    glVertex2f(-5.5 + x3, -5+y3);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.0, 0.1); //tail of red fish
    glVertex2f(-5 + x3, -5+y3);
    glVertex2f(-6.5 + x3, -4+y3);
    glVertex2f(-6 + x3, -5+y3);
    glVertex2f(-6.5 + x3, -6+y3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0); //eyes of red fish
    glVertex2f(-3.5 + x3, -4.9+y3);
    glVertex2f(-3.7 + x3, -4.9+y3);
    glVertex2f(-3.6 + x3, -4.6+y3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.9, 0.1, 0.7); //body of pink fish
    glVertex2f(4 + x4, -7);
    glVertex2f(5 + x4, -6);
    glVertex2f(5 + x4, -8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.3, 0.9); //tail of pink fish
    glVertex2f(5 + x4, -7);
    glVertex2f(5.5 + x4, -6);
    glVertex2f(5.3 + x4, -7);
    glVertex2f(5.5 + x4, -8);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0); //eyes of pink fish
    glVertex2f(4.3 + x4, -7);
    glVertex2f(4.5 + x4, -7);
    glVertex2f(4.4 + x4, -6.7);
    glEnd();

    glBegin(GL_TRIANGLES);//star fish
    glColor3f(0.5,0,0.2);
    glVertex2f(-4,-7);
    glVertex2f(-3.7,-8.3);
    glVertex2f(-4.2,-8.3);

    glVertex2f(-3.8,-8.3);
    glVertex2f(-2.7,-8.3);
    glVertex2f(-3.5,-8.8);

    glVertex2f(-3.5,-8.7);
    glVertex2f(-2.8,-9.8);
    glVertex2f(-3.8,-9.3);

    glVertex2f(-3.7,-9.3);
    glVertex2f(-5,-9.6);
    glVertex2f(-4.3,-8.8);

    glVertex2f(-4.3,-8.8);
    glVertex2f(-5.2,-8.3);
    glVertex2f(-4.2,-8.3);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-3.7,-8.3);
    glVertex2f(-3.5,-8.8);
    glVertex2f(-3.8,-9.3);
    glVertex2f(-4.3,-8.8);
    glVertex2f(-4.2,-8.3);
    glEnd();

    

    float theta;
    for (int i = 0; i < 30; i += 2) //right side bubbles b1
    {
        glBegin(GL_POLYGON);
        for (int j = 0; j < 360; j++)
        {
            glColor3f(0.1, 0.6, 1);
            theta = j * 3.14 / 180;
            glVertex2f(7 + 0.4 * cos(theta), ((-9 + 0.5 * sin(theta)) + b1 - i));
        }
        glEnd();
    }
    for (int i = 0; i < 30; i += 2) //right side bubbles b2
    {
        glBegin(GL_POLYGON);
        for (int j = 0; j < 360; j++)
        {
            glColor3f(0.1, 0.6, 1);
            theta = j * 3.14 / 180;
            glVertex2f(7 + 0.4 * cos(theta), ((-9 + 0.5 * sin(theta)) + b2 - i));
        }
        glEnd();
    }
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.5,0.9);
    glVertex2f(6.7,-9.2);
    glVertex2f(7.5,-9.2);
    glVertex2f(7.5,-10);
    glVertex2f(6.7,-10);
    glEnd();
    for (int i = 0; i < 30; i += 2) //left side bubbles b1
    {
        glBegin(GL_POLYGON);
        for (int j = 0; j < 360; j++)
        {
            glColor3f(0.1, 0.6, 1);
            theta = j * 3.14 / 180;
            glVertex2f(-7 + 0.4 * cos(theta), ((-9 + 0.5 * sin(theta)) + b1 - i));
        }
        glEnd();
    }
    for (int i = 0; i < 30; i += 2) //left side bubbles b2
    {
        glBegin(GL_POLYGON);
        for (int j = 0; j < 360; j++)
        {
            glColor3f(0.1, 0.6, 1);
            theta = j * 3.14 / 180;
            glVertex2f(-7 + 0.4 * cos(theta), ((-9 + 0.5 * sin(theta)) + b2 - i));
        }
        glEnd();
    }
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.5,0.9);
    glVertex2f(-6.6,-9.2);
    glVertex2f(-7.4,-9.2);
    glVertex2f(-7.4,-10);
    glVertex2f(-6.6,-10);
    glEnd();
    for (int i = 0; i < 20; i+=5)//stones
    {
        glBegin(GL_POLYGON); 
        for (int j = 0; j < 360; j++)
        {
            glColor3f(0.7, 0.2, 0.1);
            theta = j * 3.14 / 180;
            glVertex2f(-6+i + 0.5 * cos(theta), ((-9.6 + 0.4 * sin(theta))));
        }
        glEnd();
    }
    for (int i = 0; i < 20; i+=10)//stones
    {
        glBegin(GL_POLYGON); 
        for (int j = 0; j < 360; j++)
        {
            glColor3f(0.7, 0.2, 0.1);
            theta = j * 3.14 / 180;
            glVertex2f(-5.3+i + 0.3 * cos(theta), ((-9.8 + 0.3 * sin(theta))));
        }
        glEnd();
    }

    

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(500, 500);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Aquarium");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutTimerFunc(0, timer1, 0);
    glutTimerFunc(0, timer2, 0);
    glutTimerFunc(0, timer3, 0);
    glutTimerFunc(0, timer4, 0);
    glutTimerFunc(0, timer5, 0);
    glutTimerFunc(1.5, timer6, 0);
    
    glutMainLoop();
}