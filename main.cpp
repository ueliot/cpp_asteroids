
// https://www.youtube.com/watch?v=HCWghQtxlos&list=PLDD6B727E5B6B5E33
#include "miniwin.h"
using namespace miniwin;
//#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

void rotar(float& x,float& y, float cx, float cy, float da){
  // componentes rectangulares del vector; recibimos los puntos cartesianos del centro y el punto x referencia para asi cambiarlos directamente
   float dx = x - cx;
   float dy = y - cy;
   //magnitud del vector
   float r = sqrt(dx*dx + dy*dy);
   //angulo del vector
   float a = atan2(dy,dx);  //atan2 respeta los negativos bien controla bien el pi atan solo trabaja bien en el 1er cuadrante
   a -= da/180 * M_PI;  //en radianes  /lo restamos por que en miniwing el y aumenta de arriba hacia abajo
   //devolvemos los puntos cartesianos
   x= cx+r*cos(a);
   y= cy+r*sin(a);

}
//pinta un rectagulo centrada en x e y con una rotacion del angulo a)
void pinta_nave(float x, float y, float a){
   float x1 = x, y1 = y - 40;
   float x2 = x - 15, y2 = y + 10;
   float x3 = x + 15, y3 = y + 10;
   rotar(x1,y1,x,y,a);
   rotar(x2,y2,x,y,a);
   rotar(x3,y3,x,y,a);
   
   

   linea(x1, y1, x2, y2);
   linea(x2, y2, x3, y3);
   linea(x3, y3, x1, y1);
}

int main() {
   vredimensiona(500, 500);
   float a=0;
   for (float y = 500.0; y > -50.0; y-=2.0)
   {
      /* code */
      borra();
      pinta_nave(250,y,a);
      //printf("El valor y: %5.2f.  y deal angulo: %5.2f. \n", y,a);
      a+=2.0;
      refresca();
      espera(5);
   } 
   
   return 0;
}
