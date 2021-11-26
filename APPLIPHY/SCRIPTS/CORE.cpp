#include<glut.h>
#include<math.h>
#include<iostream>

using namespace std;

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glutSwapBuffers();
}

void KeyDown(unsigned char key, int x, int y)
{

}

void ChangeSize(int w, int h) {
	if (h == 0)
		h = 1;
	float ratio = 1.0 * w / h;
	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);
	// Reset Matrix
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	// Set the correct perspective.
	gluPerspective(45, ratio, 1, 1000);
	// Set the camera's position
	gluLookAt(
		0.0f, 0.0f, 500.0f, //camera position
		0.0f, 0.0f, 1.0f, //camera look direction
		0.0f, 1.0f, 0.0f //direction of up vector
	);
	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{

	// Initialize GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1920, 1080);
	glutCreateWindow("OpenGLWindow");

	// Register callbacks
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutIdleFunc(RenderScene);

	// Keyboard callbacks
	glutKeyboardFunc(KeyDown);

	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	/* for blending colors */
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}