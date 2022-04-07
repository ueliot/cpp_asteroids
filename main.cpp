
// https://www.youtube.com/watch?v=B4LDrD-UedE&list=PLDD6B727E5B6B5E33&index=3
// Suma de vectores para conseguir el vector resultante en la posicion de la direccion  de velocidad
//aceleracion con tecla arriba
//debe haber un cambio de posicion permanente  que es el de la velocidad
//la velocidad se conserva
//y cuando damos a la flecha de arriba a la velocidad se le suma un vector 
//luego de esto se rota vector  y se suma luego el vector rotado con el anterior.

#include "miniwin.h"
using namespace miniwin;
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
//pinta un rectagulo centrada en x e y con una rotacion del angulo a
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
   float x=250, y=250, a=0;  //posicion de la nave
   float vx = 0.5, vy=0.0; //velocidad inicial
   int t= tecla();
   while (t != ESCAPE){
      x+= vx;   //desplazamiento horizontal 20 pixeles x seg
      y+=vy;   //desplazamiento vertical  30 pixeles x seg (nave va para abajo)

      if(t==DERECHA){
         a-=8;   //restamos 5 grados si se presiona derecha
      } else if (t==IZQUIERDA){
         a+=8;
      } else if (t==ARRIBA) {

         float ax=0.0, ay= -0.5;
         rotar(ax,ay,0.0,0.0,a);
         vx=vx+ax;
         vy=vy+ay;
      }
      //refrescar la pantall      
      borra();
      pinta_nave(x,y,a);   //refresca la nave 100 veces x seg
      refresca();
      espera(10); //solo pedimos 100 teclas x segundo  (esperamos 10 mms)
      t=tecla();
   }
   vcierra();

   
   
   return 0;
}
