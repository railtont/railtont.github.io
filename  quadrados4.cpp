#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

void display(void);
void timer(int);
void keyboard(unsigned char key, int x, int y);


int main(int argc, char** argv){
  srand (time(NULL));
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow (argv[0]);
  glClearColor(1.0, 1.0, 1.0, 0.0);  
  glOrtho (0, 1, 0, 1, -1 ,1);    
  glutDisplayFunc(display);
  glutMainLoop();  
  return 0;
}

void mudacor(){	
	double r=(rand()%101)/100.0;
	double g=(rand()%101)/100.0;
	double b=(rand()%101)/100.0;
	glColor3f(r,g,b);
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT); //limpa tela

	double x[4]={0.1,0.1,0.5,0.5}; //vertices
	double y[4]={0.1,0.5,0.5,0.1};
	double dx=0;
  
	for(int j=0; j<4; j++){		
	  mudacor(); //altera a cor
	  
	  glBegin(GL_POLYGON);    	  
	  for(int i=0; i<4; i++) //desenha poligono
		  glVertex2f(x[i]+dx,y[i]+dx);		  	
	  glEnd(); 
	  
	  dx+=0.125;	//aumenta o deslocamento
	}
		
	glFlush();
}
