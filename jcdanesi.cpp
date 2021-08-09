#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio2.h>
#include <cstdio>
#include <windows.h>
using namespace std;

//cambie el nombre de la variable ya que auto es una palabra reservada de c++

class car {
protected:
	int matriz[5][4];
	int color[5][4]; 
	int ancho,alto,pasoX,pasoY,xnueva,ynueva,maxLimitX,maxLimitY,minLimitX,minLimitY,x,y,velocidad;
	clock_t tempo; 
	clock_t paso; 
public:
	void dibujar();
	void borrar(); 
	car(int v, int x0,int y0);
	void setLimit(int, int,int, int);
	car(int vel);
	car();
	bool update();
	int gettempo();
	int getX();
	int getY();
};
car::car(){}

car::car(int vel, int x0,int y0) {
	velocidad = vel;
	paso=CLOCKS_PER_SEC/velocidad;
	tempo=clock(); 
	int Color = (rand()%15)+1;
	matriz[0][0]=0;  color[0][0] = 8;
	matriz[0][1]=219; color[0][1] = 15;
	matriz[0][2]=0; color[0][2] = 8;
	matriz[0][3]=219; color[0][3] = 15;
	matriz[1][0]=0;  color[1][0] = Color;
	matriz[1][1]=61; color[1][1] = 8;
	matriz[1][2]=47; color[1][2] = Color;
	matriz[1][3]=61; color[1][3] = 8;
	matriz[2][0]=30; color[2][0] = Color;
	matriz[2][1]=61; color[2][1] = 8;
	matriz[2][2]=0;  color[2][2] = Color;
	matriz[2][3]=61; color[2][3] = 8;
	matriz[3][0]=0;  color[3][0] = Color;
	matriz[3][1]=61; color[3][1] = 8;
	matriz[3][2]=92; color[3][2] = Color;
	matriz[3][3]=61; color[3][3] = 8;
	matriz[4][0]=0;  color[4][0] = 8;
	matriz[4][1]=219; color[4][1] = 15;
	matriz[4][2]=0; color[4][2] = 8;
	matriz[4][3]=219; color[4][3] = 15;
	ancho = 5;
	alto = 4;
	pasoX = 3;
	pasoY = 3;
	x = x0;
	y = y0;
	xnueva = x0;
	ynueva = y0;
	dibujar();
}
int car::getX()
{
	return x;
}
int car::getY()
{
	return y;
}
int car::gettempo()
{
	return tempo;
}
void car::dibujar()
{
	for (int i= 0; i<ancho; i++)
	{
		for (int k= 0; k<alto; k++)
		{
			textcolor(color[i][k]);
			gotoxy(x+i,y+k);
			cout<<(char) matriz[i][k];
		}
	}
}
void car::borrar()
{
	
	for (int i= 0; i<ancho+1; i++)
	{
		for (int k= 0; k<alto+1; k++)
		{
			textcolor(color[i][k]);	
			gotoxy(x+i,y+k);
			cout<<" ";
		}
	}
}
class car_1: public car {
public:
	car_1(int v, int x0,int y0);
	car_1();
	void setLimit(int x0, int x1,int y0, int y1);
	void update();
};
car_1::car_1(){}

car_1::car_1(int vel, int x0, int y0): car( vel,  x0, y0){
	velocidad = vel;
	paso=CLOCKS_PER_SEC/velocidad; 
	tempo=clock(); 
	int Color = (rand()%15)+1;
	matriz[0][0]=0;  color[0][0] = 8;
	matriz[0][1]=219; color[0][1] = 15;
	matriz[0][2]=0; color[0][2] = 8;
	matriz[0][3]=219; color[0][3] = 15;
	matriz[1][0]=0;  color[1][0] = Color;
	matriz[1][1]=61; color[1][1] = 8;
	matriz[1][2]=47; color[1][2] = Color;
	matriz[1][3]=61; color[1][3] = 8;
	matriz[2][0]=30; color[2][0] = Color;
	matriz[2][1]=61; color[2][1] = 8;
	matriz[2][2]=0;  color[2][2] = Color;
	matriz[2][3]=61; color[2][3] = 8;
	matriz[3][0]=0;  color[3][0] = Color;
	matriz[3][1]=61; color[3][1] = 8;
	matriz[3][2]=92; color[3][2] = Color;
	matriz[3][3]=61; color[3][3] = 8;
	matriz[4][0]=0;  color[4][0] = 8;
	matriz[4][1]=219; color[4][1] = 15;
	matriz[4][2]=0; color[4][2] = 8;
	matriz[4][3]=219; color[4][3] = 15;
	ancho = 5;
	alto = 4;
	pasoX = 3;
	pasoY = 3;
	x = x0;
	y = y0;
	xnueva = x0;
	ynueva = y0;
	dibujar();
}
void car_1::update()
{
	if (_kbhit())
	{
		int tecla = getch();
		bool moves = false;
		
		switch(tecla)
		{
			case (119): 
			{//w
				if (y - alto > minLimitY )
				{
					borrar(); y = y - pasoY; moves = true;
				} break;
			}
			case (115):
			{ //a
				if (y < maxLimitY)
				{
					borrar(); y = y + pasoY; moves = true;
				} break;
			}
			case (100):
			{ //d
				if (x + ancho < maxLimitX)
				{
					borrar(); x = x + pasoX; moves = true;
				} break;
			}
			case (97):
			{//s
				if (x - ancho > minLimitX)
				{
					borrar(); x = x - pasoX; moves = true;
				} break;
			}
			if(moves) 
			{
				dibujar();
			}
		}	
	}
}
void car_1::setLimit(int x0, int x1,int y0, int y1){
	maxLimitX = x1;
	maxLimitY = y1;
	minLimitX = x0;
	minLimitY = y0;
}

class car_2: public car {
protected:
	bool cambio;
	int colorAuto;
public:
	car_2(int v, int x0,int y0);
	car_2();
	void Cambio();
	void update();
	void setLimit(int x0, int x1,int y0, int y1);
};

car_2:: car_2(){}

car_2::  car_2(int v, int x0,int y0): car( v, x0, y0){
	cambio = true;
	colorAuto = 10;
	matriz[0][0]=0;  color[0][0] = 8;
	matriz[0][1]=219; color[0][1] = 15;
	matriz[0][2]=0; color[0][2] = 8;
	matriz[0][3]=219; color[0][3] = 15;
	matriz[1][0]=0;  color[1][0] = colorAuto;
	matriz[1][1]=61; color[1][1] = 8;
	matriz[1][2]=47; color[1][2] = colorAuto;
	matriz[1][3]=61; color[1][3] = 8;
	matriz[2][0]=30; color[2][0] = colorAuto;
	matriz[2][1]=61; color[2][1] = 8;
	matriz[2][2]=0;  color[2][2] = colorAuto;
	matriz[2][3]=61; color[2][3] = 8;
	matriz[3][0]=0;  color[3][0] = colorAuto;
	matriz[3][1]=61; color[3][1] = 8;
	matriz[3][2]=92; color[3][2] = colorAuto;
	matriz[3][3]=61; color[3][3] = 8;
	matriz[4][0]=0;  color[4][0] = 8;
	matriz[4][1]=219; color[4][1] = 15;
	matriz[4][2]=0; color[4][2] = 8;
	matriz[4][3]=219; color[4][3] = 15;
	dibujar();
}

void  car_2::Cambio(){
	if (cambio){
		matriz[4][0]=219;  color[4][0] = 15;
		matriz[4][1]=0; color[4][1] = 8;
		matriz[4][2]=219; color[4][2] = 15;
		matriz[4][3]=0; color[4][3] = 8;
		matriz[3][0]=61;  color[1][0] = 8;
		matriz[3][1]=47; color[1][1] = colorAuto;
		matriz[3][2]=61; color[1][2] = 8;
		matriz[3][3]=0; color[1][3] = 8;
		matriz[2][0]=61; color[2][0] = 8;
		matriz[2][1]=0; color[2][1] = colorAuto;
		matriz[2][2]=61;  color[2][2] = 8;
		matriz[2][3]=31; color[2][3] = colorAuto;
		matriz[1][0]=61;  color[3][0] = 8;
		matriz[1][1]=92; color[3][1] = colorAuto;
		matriz[1][2]=61; color[3][2] = 8;
		matriz[1][3]=0; color[3][3] = 8;
		matriz[0][0]=219;  color[0][0] = 15;
		matriz[0][1]=0; color[0][1] = 8;
		matriz[0][2]=219; color[0][2] = 15;
		matriz[0][3]=0; color[0][3] = 8;
	}
	else 
	{
		matriz[0][0]=0;  color[0][0] = 8;
		matriz[0][1]=219; color[0][1] = 15;
		matriz[0][2]=0; color[0][2] = 8;
		matriz[0][3]=219; color[0][3] = 15;
		matriz[1][0]=0;  color[1][0] = colorAuto;
		matriz[1][1]=61; color[1][1] = 8;
		matriz[1][2]=47; color[1][2] = colorAuto;
		matriz[1][3]=61; color[1][3] = 8;
		matriz[2][0]=30; color[2][0] = colorAuto;
		matriz[2][1]=61; color[2][1] = 8;
		matriz[2][2]=0;  color[2][2] = colorAuto;
		matriz[2][3]=61; color[2][3] = 8;
		matriz[3][0]=0;  color[3][0] = colorAuto;
		matriz[3][1]=61; color[3][1] = 8;
		matriz[3][2]=92; color[3][2] = colorAuto;
		matriz[3][3]=61; color[3][3] = 8;
		matriz[4][0]=0;  color[4][0] = 8;
		matriz[4][1]=219; color[4][1] = 15;
		matriz[4][2]=0; color[4][2] = 8;
		matriz[4][3]=219; color[4][3] = 15;
	}
	cambio = !cambio;
	
}

void  car_2::update()
{
	if(tempo+paso<clock())
	{
		dibujar();
		tempo=clock(); 
	}
}

void  car_2::setLimit(int x0, int x1,int y0, int y1){
	maxLimitX = x1;
	maxLimitY = y1;
	minLimitX = x0;
	minLimitY = y0;
}
class car_3 : public car_2 {
public:
	car_3(int v, int x0,int y0);
	car_3();
	void setLimit(int x0, int x1,int y0, int y1);
	void Colorear();
	void update();
};
car_3::car_3(){}

car_3::car_3(int v, int x0,int y0): car_2( v, x0, y0){
	cambio = true;
	colorAuto = (rand()%15)+1;
	matriz[0][0]=0;  color[0][0] = 8;
	matriz[0][1]=219; color[0][1] = 15;
	matriz[0][2]=0; color[0][2] = 8;
	matriz[0][3]=219; color[0][3] = 15;
	matriz[1][0]=0;  color[1][0] = colorAuto;
	matriz[1][1]=61; color[1][1] = 8;
	matriz[1][2]=47; color[1][2] = colorAuto;
	matriz[1][3]=61; color[1][3] = 8;
	matriz[2][0]=30; color[2][0] = colorAuto;
	matriz[2][1]=61; color[2][1] = 8;
	matriz[2][2]=0;  color[2][2] = colorAuto;
	matriz[2][3]=61; color[2][3] = 8;
	matriz[3][0]=0;  color[3][0] = colorAuto;
	matriz[3][1]=61; color[3][1] = 8;
	matriz[3][2]=92; color[3][2] = colorAuto;
	matriz[3][3]=61; color[3][3] = 8;
	matriz[4][0]=0;  color[4][0] = 8;
	matriz[4][1]=219; color[4][1] = 15;
	matriz[4][2]=0; color[4][2] = 8;
	matriz[4][3]=219; color[4][3] = 15;
}
void car_3::Colorear(){
	colorAuto = (rand()%15)+1;
	color[1][0] = colorAuto;
	color[1][2] = colorAuto;
	color[2][0] = colorAuto;
	color[2][2] = colorAuto;
	color[3][0] = colorAuto;
	color[3][2] = colorAuto;
}
void car_3::update(){
	if(tempo+paso<clock()){
		dibujar();
		tempo=clock();
	}
}
void car_3::setLimit(int x0, int x1,int y0, int y1){
	maxLimitX = x1;
	maxLimitY = y1;
	minLimitX = x0;
	minLimitY = y0;
}
class Juego{
	int teclas[4];
	car_1 automovil_1;
	car_2 automovil_2;
	car_3 automovil_3;
	int checkCollision();
public:
	Juego();
	void play();
};
Juego::Juego(){
	automovil_1 = car_1(4,4,4);
	automovil_1.setLimit(0,130,0,45);
	automovil_2 = car_2(10,14,14);
	automovil_2.setLimit(0,130,0,45);
	automovil_3 = car_3(10,30,30);
	automovil_3.setLimit(0,130,0,45);
}
int Juego::checkCollision(){
	int x1 = automovil_1.getX();
	int y1 = automovil_1.getY();
	int x2 = automovil_2.getX();
	int y2 = automovil_2.getY();
	int x3 = automovil_3.getX();
	int y3 = automovil_3.getY();
	int ancho = 3;
	int alto = 4;
	if(x1 > (x2 - ancho) && x1 < (x2 + ancho) && 
	   y1 > (y2 - alto) && y1 < (y2 + alto))
	{
		return 2;
	}
	   if(x1 > (x3 - ancho) && x1 < (x3 + ancho) && 
		  y1 > (y3 - alto) && y1 < (y3 + alto))
	   {
		   return 3;
	   }
		  return 0;
}
void Juego::play(){
	bool flag = true;
	while(flag) 
	{
		automovil_1.update();
		automovil_1.dibujar();
		automovil_2.update();
		automovil_3.update();
		if (checkCollision() == 2){
			automovil_2.Cambio();
			flag=false;
			cout<<"Chocaste, fin del juego."<<endl;
		}
		if (checkCollision() == 3){
			automovil_3.Colorear();
			flag=false;
			cout<<"Chocaste, fin del juego."<<endl;
		}	
	}
}
int main(int argc, char *argv[]) {
	srand(time(NULL));
	Juego J;
	J.play();
	return 0;
}
