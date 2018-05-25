#include<iostream>

#include<iostream.h>

#include<conio.h>

#include<math.h>

using namespace std;

const float g=9.86;

const float PI=3.1416;

//Programa que calcula la distancia de recorrida en linea recta recorrida por un Misil

// "Estructura"Separamos un espacio de Memoria el cual se va a llamar proyectil y tiene

seis//partes que son

//espacios cada uno de tipo flotante con un respectivo nombre

struct proyectil{

float j;

float h;

float posh; //Por si acaso

float pos_j;

float VelocidadInicial;

float angulo;

float PosX;

float PosY;

float Tiempo; //se agrego 2 datos tiempo y distancia para guardar en la estructura proyectil

float Distancia;

float am;

};

float Cambio_grado_rad(proyectil m1){

float radianes;

radianes=m1.angulo*PI/180;

return(radianes);

}

float Tiempo_Aire(proyectil m1){

float Ta;

float r;

r=Cambio_grado_rad(m1);

Ta=(2*m1.VelocidadInicial*sin(r))/g;

return(Ta);

}

float Distancia(proyectil m1, float ta){

float distancia;

float r;

r=Cambio_grado_rad(m1);

distancia = (m1.VelocidadInicial*m1.VelocidadInicial)*sin(2*(r))/g;

return(distancia);

}

float PosX (proyectil m1, float ta){

float posh;

float j;

float h;

float r;

r=Cambio_grado_rad (m1);

posh=m1.j+(m1.VelocidadInicial*(cos(r))*((m1.VelocidadInicial*(sin(r))))+((sqrt

(m1.VelocidadInicial*m1.VelocidadInicial)*((sin(r)*sin(r)))+(2*g*j)))/g);

return (posh);}

float PosY(proyectil m1){

float j;

float pos_j;

float r;

r=Cambio_grado_rad (m1);

pos_j=m1.j+(((m1.VelocidadInicial*m1.VelocidadInicial)*((sin (r)) * (sin (r))))/(2*9.86));

return (pos_j);}

void Imprimir(proyectil m1[], int i); //procedimiento que imprime los datos y resultados de los 10

proyectiles

int main(int argv, char *argc[] )

{

proyectil misil[9]; //se crea un arreglo de la estructura proyectil

float d, ta, f, gh;

int x=0;

float h;

float posh;

float j; //altura máxima

float pos_j;

cout<<"*************Instrucciones del programa************"<<endl;

cout<<"1. El programa calcula la distancia, en linea recta,en la que cae un proyectil"<<endl;

cout<<"2. Para ejecutar el programa escriba la velocidad inicial para lanzar cada proyectil y el

angulo de lanzamiento"<<endl;

for(int i=1; i<11; i++){ //con el for se pide al usuario que ingrese los datos y los

guarda para cada

cout<<"Proyectil No. "<<i<<" "<<endl<<"Angulo en grados: "; // uno de los 10 misiles.

cin>>misil[i].angulo;

cout<<"Velocidad inicial en metros/segundo: ";

cin>>misil[i].VelocidadInicial;

cout<<"Digite la posición en x"<<endl; //modif

cin>>misil[i].h;

cout<<"Digite la posición en y"<<endl; //modif

cin>>misil[i].j;

ta=Tiempo_Aire(misil[i]);

misil[i].Tiempo=ta;

//misil[i].PosX=misil[i].PosY=0;

d=Distancia(misil[i], ta);

misil[i].Distancia=d;

cout<<endl;

//modificaciones

f=PosX (misil[i],ta);

misil[i].PosX =f;

gh=PosY(misil[i]);

misil[i].PosY =gh;

//misil[i].h=h;

//misil[i].j=j;

}

Imprimir (misil, x);

system("PAUSE");

return EXIT_SUCCESS;

}

void Imprimir(proyectil m1[], int i){ //imprime mediante un for los datos de los 10

proyectiles

cout<<" Estos son los datos de los 10 proyectiles: "<<endl;

cout<<"Proy.No.--Angulo--Vel.--PosX0--PosY0-- t vuelo--distancia --PosXf--H.MAX "<<endl;

for( i=1; i<11; i++){

cout<<"

*************************************************************************"<<endl;

cout<<" | "<<i<<" | "<<m1[i].angulo<<" | "<<m1[i].VelocidadInicial<<" | "<< m1[i].h<<" |

"<< m1[i].j<<" | "<<m1[i].Tiempo<<"|"<<m1[i].Distancia<<"|"<<m1[i].PosX<< "|"<<m1[i].PosY<<

"|"<<endl;

cout<<endl;

}

} 
