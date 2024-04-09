/*
 * OGL02Animation.cpp: 3D Shapes with animation
 */
#include "cone.h"
#include "cube.h"
#include "pyramid.h"
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <SOIL/SOIL.h>
/* Global variables */
char title[] = "3D Shapes with animation";
GLfloat anglePyramid = 0.0f; // Rotational angle for pyramid [NEW]
GLfloat angleCube = 0.0f;    // Rotational angle for cube [NEW]
int refreshMills = 15;       // refresh interval in milliseconds [NEW]
/* Initialize OpenGL Graphics */
void initGL() {
  glClearColor(0.0f, 0.0f, 0.0f,
               1.0f);      // Set background color to black and opaque
  glClearDepth(1.0f);      // Set background depth to farthest
  glEnable(GL_DEPTH_TEST); // Enable depth testing for z-culling
  glDepthFunc(GL_LEQUAL);  // Set the type of depth-test
  glShadeModel(GL_SMOOTH); // Enable smooth shading
  glHint(GL_PERSPECTIVE_CORRECTION_HINT,
         GL_NICEST); // Nice perspective corrections
}

GLuint texture[1];   // Storage For One Texture ( NEW )
int loadGLTextures() // Load Bitmaps And Convert To Textures
{
  /* load an image file directly as a new OpenGL texture */
  texture[0] = SOIL_load_OGL_texture("resource/sample.png", SOIL_LOAD_AUTO,
                                     SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  if (texture[0] == 0)
    return false;
  // Typical Texture Generation Using Data From The Bitmap
  glBindTexture(GL_TEXTURE_2D, texture[0]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  return true;
}

/* Handler for window-repaint event. Called back when the window first appears
and whenever the window needs to be re-painted. */
void display() {
  glClear(GL_COLOR_BUFFER_BIT |
          GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
  glMatrixMode(GL_MODELVIEW);   // To operate on model-view matrix

  glBindTexture(GL_TEXTURE_2D, texture[0]); // Map your texture here
  glBegin(GL_QUADS);
  // Front Face
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  // Back Face
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
  // Top Face
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);
  // Bottom Face
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  // Right face
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  // Left Face
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glEnd();
  Pyramid pyramid;
  pyramid.moveTo(-1.5f, 0.0f, -6.0f);
  pyramid.rotateTo(anglePyramid, 0.0f, 1.0f, 0.0f);
  pyramid.draw(texture[0]);

  // Cone cone;
  // cone.moveTo(0.0f, 0.0f, -5.0f);
  // cone.rotateTo(anglePyramid, 0.0f, 1.0f, 0.0f);
  // cone.draw();

  glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)

  // Update the rotational angle after each refresh [NEW]
  anglePyramid += 0.2f;
  angleCube -= 0.15f;
}
/* Called back when timer expired [NEW] */
void timer(int value) {
  glutPostRedisplay(); // Post re-paint request to activate display()
  glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}
/* Handler for window re-size event. Called back when the window first appears
and whenever the window is re-sized with its new width and height */
void reshape(GLsizei width,
             GLsizei height) { // GLsizei for non-negative integer
  // Compute aspect ratio of the new window
  if (height == 0)
    height = 1; // To prevent divide by 0
  GLfloat aspect = (GLfloat)width / (GLfloat)height;
  // Set the viewport to cover the new window
  glViewport(0, 0, width, height);
  // Set the aspect ratio of the clipping volume to match the viewport
  glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
  glLoadIdentity();            // Reset
  // Enable perspective projection with fovy, aspect, zNear and zFar
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char **argv) {
  glutInit(&argc, argv);            // Initialize GLUT
  glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
  glutInitWindowSize(640, 480);     // Set the window's initial width & height
  glutInitWindowPosition(50,
                         50); // Position the window's initial top-left corner
  glutCreateWindow(title);    // Create window with the given title
  glutDisplayFunc(
      display); // Register callback handler for window re-paint event
  glutReshapeFunc(
      reshape); // Register callback handler for window re-size event
  initGL();     // Our own OpenGL initialization
  loadGLTextures();
  glutTimerFunc(0, timer, 0); // First timer call immediately [NEW]
  glutMainLoop();             // Enter the infinite event-processing loop
  return 0;
}
