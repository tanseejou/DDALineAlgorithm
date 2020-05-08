// Lab 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <GL/glut.h> // Include the GLUT header file  
#include <math.h>

#define ROUND(a) ((int)(a+0.5))

void PlotPixel(float x, float y)
{
	glColor3f(1.0f, 0.6f, 0.71f);
	glPointSize(15.0f);	
	glBegin(GL_POINTS);	// start drawing a point primitive
	glVertex2f(x, y);					// The bottom left corner
	glEnd();
}

void lineDDA(float xa, float ya, float xb, float yb)
{
	float dx = xb - xa;
	float dy = yb - ya;
	int steps, k;
	float xIncrement, yIncrement, x = xa, y = ya;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	xIncrement = dx / float(steps);
	yIncrement = dy / float(steps);

	PlotPixel(ROUND(x), ROUND(y));
	for (k = 0; k < steps; k++)
	{
		x += xIncrement;
		y += yIncrement;
		PlotPixel(ROUND(x), ROUND(y));
	}
}


void display(void) {
	glClearColor(1.0f, 0.87f, 0.6f, 1.0f); // Clear the background of our window to blue  
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)  
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations  
	
	glTranslatef(0.0f, 0.0f, -5.0f);

	//PlotPixel(10.0f, 10.0f);

	lineDDA(-12.0f, -10.0f, 25.0f, 12.0f);

	glFlush(); // Flush the OpenGL buffers to the window  
}

void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window  
	glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed  
	glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)  
	gluPerspective(140, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes  
	glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly  
}

int main(int argc, char **argv) {
	glutInit(&argc, argv); // Initialize GLUT  
	glutInitDisplayMode(GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)  
	glutInitWindowSize(500, 500); // Set the width and height of the window  
	glutInitWindowPosition(100, 100); // Set the position of the window  
	glutCreateWindow("Your first OpenGL Window"); // Set the title for the window  
	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering  
	glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for rendering  
	glutMainLoop(); // Enter GLUT's main loop  
}