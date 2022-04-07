
/* https://www.youtube.com/watch?v=pf3D-kkDKHU&list=PLDD6B727E5B6B5E33&index=4
//Refactorizando el programa
//Agrupamos variables con una struct  (hacemos una tupla N)
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

void pinta_nave( const NAVE& N){   //recibe un const por que esto no lo modifica pero es la misma NAVE ya que es x referencia
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


//mueve_nave no sera const ya que se pudrá modif x refeencia
//de este modo ya me olvido de como se movia la nave que podría ser tan complicado como sea
void mueve_nave(NAVE& N){
   N.x+= N.vx;   
   N.y+=N.vy;
   //controlar límites
   if (N.x > 500){
      N.x-=500;
   } else if (N.x <0){
      N.x +=500;
   }
    if (N.y > 500){
      N.y-=500;
   } else if (N.y <0){
      N.y +=500;
   }
}

//Acelera Nave simplificando lo que se hacia muy grande en el main
//(mas de 25 lineas ya hay que empezar a pensar a arreglar algo separando x funciones)
void acelera_nave(NAVE& N){
    float ax=0.0, ay= -0.5;
         rotar(ax,ay,0.0,0.0,N.a);
         N.vx=N.vx+ax;
         N.vy=N.vy+ay;
}

//Rota Nave
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
