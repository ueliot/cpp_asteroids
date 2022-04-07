
/* https://www.youtube.com/watch?v=pf3D-kkDKHU&list=PLDD6B727E5B6B5E33&index=4
Refactorizando el programa
*/

#include "miniwin.h"
using namespace miniwin;
#include <cmath>
using namespace std;

struct NAVE
{
   float x,y,a,vx,vy; 
};

void rotar(float& x,float& y, float cx, float cy, float da){  
   float dx = x - cx;
   float dy = y - cy;  
   float r = sqrt(dx*dx + dy*dy);   
   float a = atan2(dy,dx);  
   a -= da/180 * M_PI;    
   x= cx+r*cos(a);
   y= cy+r*sin(a);
}

void pinta_nave( const NAVE& N){   
   float x1 = N.x, y1 = N.y - 40;
   float x2 = N.x - 15, y2 = N.y + 10;
   float x3 = N.x + 15, y3 = N.y + 10;
   rotar(x1,y1,N.x,N.y,N.a);
   rotar(x2,y2,N.x,N.y,N.a);
   rotar(x3,y3,N.x,N.y,N.a);
   linea(x1, y1, x2, y2);
   linea(x2, y2, x3, y3);
   linea(x3, y3, x1, y1);
}

void limites (float& f, float max) {
   if (f> max){
      f -=max;
   } else if (f < 0){
      f +=max;
   }
}

void mueve_nave(NAVE& N){
   N.x+= N.vx;   
   N.y+=N.vy;
   //controlar límites
   limites(N.x, 500);
   limites(N.y, 500);
}

void acelera_nave(NAVE& N){
    float ax=0.0, ay= -0.5;
         rotar(ax,ay,0.0,0.0,N.a);
         N.vx=N.vx+ax;
         N.vy=N.vy+ay;
}

void rota_nave(NAVE& N, double da){
   N.a += da;

}

int main() {
   vredimensiona(500, 500);  

   NAVE N={ 250,250,0,0.0,0.0}; 
   
   int t= tecla();
   while (t != ESCAPE){
       mueve_nave(N);

      if(t==DERECHA){
         rota_nave(N, -10);   
      } else if (t==IZQUIERDA){
         rota_nave(N, 10);
      } else if (t==ARRIBA) {
        acelera_nave(N);
      }
      //refrescar la pantall      
      borra();
      pinta_nave(N);   
      refresca();
      espera(10); 
      t=tecla();
   }
   vcierra();   
   return 0;
}
