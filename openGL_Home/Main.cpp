l//------------------------------------------------------------------------------
#include "stdafx.h"
#include <windows.h>
#include <gl\gl.h>
#include <gl\glut.h>
//------------------------------------------------------------------------------
float angle = 0;
float tx = 0 , ty = 0 , tz = 0;
float sx = 1 , sy = 1 , sz = 1;
//------------------------------------------------------------------------------
void Init()
{
	// Set Background Color
    glClearColor(0.0,0.0,0.0,0.0);

    // Enable 3D Rendering
    glEnable(GL_DEPTH_TEST);
}
//------------------------------------------------------------------------------
// Mouse handling
void handleMouse(int mouse,int state,int x,int y)
{
     if(mouse == GLUT_LEFT_BUTTON)
     {
		 angle += 3;
		 glutPostRedisplay();
     }
     if(mouse == GLUT_RIGHT_BUTTON)
     {
		 angle -= 3;
		 glutPostRedisplay();
     }
}
//------------------------------------------------------------------------------
// Keyboard handling
void handleKey(unsigned char key,int x,int y)
{
     if(key == 's'){
			tx += 0.1 , ty += 0.1 , tz += 0.1;
			glutPostRedisplay();
     }else if(key == 'a'){
			tx -= 0.1 , ty -= 0.1 , tz -= 0.1;
			glutPostRedisplay();
     }
     else if(key == 'w')
     {
            sx *= 0.9 , sy *= 0.9 , sz *= 0.9;
            glutPostRedisplay();
     }
	 else if(key == 'q')
     {
            sx *= 1.1 , sy *= 1.1 , sz *= 1.1;
			glutPostRedisplay();
     }
     else if(key == 'x')
     {
       exit(0);
     }
}
//------------------------------------------------------------------------------
// Drawing function
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glRotatef(angle,1,1,1);
	glTranslatef(tx , ty , tz);
	glScalef(sx , sy , sz);

	//Door
    glColor3f(1,3,0.1);
    glBegin(GL_POLYGON);
        glVertex3f(-0.15,-0.5,-0.501) , glVertex3f(0.15, -0.5,-0.501);
		glVertex3f( 0.15,-0.25,-0.501) , glVertex3f(-0.15,-0.25,-0.501);
    glEnd();

	//Windows front left
	glColor3f(1,3,0.1);
    glBegin(GL_POLYGON);
        glVertex3f(-0.45,0,-0.501) , glVertex3f(-0.35,0,-0.501);
		glVertex3f(-0.35,0.1,-0.501) , glVertex3f(-0.45,0.1,-0.501);
    glEnd();

	//Windows front right
	glColor3f(1,3,0.1);
    glBegin(GL_POLYGON);
        glVertex3f(0.35,0,-0.501) , glVertex3f(0.45,0,-0.501);
		glVertex3f(0.45,0.1,-0.501) , glVertex3f(0.35,0.1,-0.501);
    glEnd();

	//Windows front middle
	glColor3f(0.5,4,0.3);
    glBegin(GL_POLYGON);
        glVertex3f(-0.25,-0.1,-0.501) , glVertex3f(0.25,-0.1,-0.501);
		glVertex3f(0.25,0.2,-0.501) , glVertex3f(-0.25,0.2,-0.501);
    glEnd();

	///////////////////////////////////////////////////////////////////
	// Garden
	//Garden Front
	glColor3f(0.7,2,0.2);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,-0.9) , glVertex3f(0.5,-0.5,-0.9);
		glVertex3f(0.5,-0.5,-0.5),glVertex3f(-0.5,-0.5,-0.5);
    glEnd();
	// Garden sorha left
	glColor3f(0.2,0.1,0.1);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,-0.9) , glVertex3f(-0.5,-0.2,-0.9);
		glVertex3f(-0.5,-0.2,-0.5) , glVertex3f(-0.5,-0.5,-0.5);
    glEnd();
	// Garden sorha right
	glColor3f(0.2,0.1,0.1);
    glBegin(GL_POLYGON);
        glVertex3f(0.5,-0.5,-0.9) , glVertex3f(0.5,-0.2,-0.9);
		glVertex3f(0.5,-0.2,-0.5) , glVertex3f(0.5,-0.5,-0.5);
    glEnd();
	// Garden sorha front
	glColor3f(0.2,0.1,0.1);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,-0.9) , glVertex3f(-0.5, -0.2,-0.9);
		glVertex3f( 0.5, -0.2,-0.9) , glVertex3f( 0.5,-0.5,-0.9);
    glEnd();
	//Door
    glColor3f(1,3,0.1);
    glBegin(GL_POLYGON);
        glVertex3f(-0.15,-0.5,-0.91) , glVertex3f(0.15, -0.5,-0.91);
		glVertex3f( 0.15,-0.15,-0.91) , glVertex3f(-0.15,-0.15,-0.91);
    glEnd();
	///////////////////////////////////////////////////////////////////



	//traingle above
	//back
    glColor3f(1.5,3,3.7);
	glBegin(GL_TRIANGLES);
        glVertex3f(-0.5,0.5,-0.5),glVertex3f(0.5, 0.5,-0.5),glVertex3f( 0, 0.9,0);
    glEnd();

	//Front
    glColor3f(1.5,3,3.7);
	glBegin(GL_TRIANGLES);
        glVertex3f(-0.5,0.5,0.5),glVertex3f(0.5, 0.5,0.5),glVertex3f( 0, 0.9,0);
    glEnd();

	//Left
    glColor3f(1.5,3,3.7);
	glBegin(GL_TRIANGLES);
        glVertex3f(-0.5,0.5,-0.5),glVertex3f(-0.5, 0.5,0.5),glVertex3f( 0, 0.9,0);
    glEnd();

	//RIGHTs
    glColor3f(1.5,3,3.7);
	glBegin(GL_TRIANGLES);
        glVertex3f(0.5,0.5,-0.5),glVertex3f(0.5, 0.5,0.5),glVertex3f( 0, 0.9,0);
    glEnd();
	///////////////////////////

	//bottom
    glColor3f(1.5,0,3.7);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,0.5),glVertex3f(0.5, -0.5,0.5);
		glVertex3f( 0.5, -0.5,-0.5),glVertex3f( -0.5, -0.5,-0.5);
    glEnd();

	//bottom
    glColor3f(2.5,0,1.7);
    glBegin(GL_POLYGON);
        glVertex3f(-0.35,-0.35,0.501),glVertex3f(0.35, -0.35,0.501);
		glVertex3f( 0.35, 0.35,0.501),glVertex3f(-0.35, 0.35,0.501);
    glEnd();

	// left
    glColor3f(1,0.8,2.7);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,-0.5),glVertex3f(-0.5, -0.5,0.5);
		glVertex3f( -0.5, 0.5,0.5),glVertex3f( -0.5, 0.5,-0.5);
    glEnd();

	// right
    glColor3f(1,0.8,0.2);
    glBegin(GL_POLYGON);
        glVertex3f(0.5,-0.5,-0.5),glVertex3f(0.5, -0.5,0.5);
		glVertex3f(0.5, 0.5,0.5),glVertex3f(0.5, 0.5,-0.5);
    glEnd();

    // Front
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,-0.5),glVertex3f(-0.5, 0.5,-0.5);
		glVertex3f( 0.5, 0.5,-0.5),glVertex3f( 0.5,-0.5,-0.5);
    glEnd();

    // Back
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,0.5),glVertex3f(-0.5, 0.5,0.5);
		glVertex3f( 0.5, 0.5,0.5),glVertex3f( 0.5,-0.5,0.5);
    glEnd();

	glFlush();
}
//------------------------------------------------------------------------------
// Main function
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL Window");

	glutDisplayFunc(Display);
	glutMouseFunc(handleMouse);
	glutKeyboardFunc(handleKey);

	Init();
	glutMainLoop();
}
//------------------------------------------------------------------------------
