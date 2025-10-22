#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;


double f1(double x, double y, double z){
	double f = (pow(x,2)+pow(y,2)+pow(z,2))*exp(-pow(x,2)-pow(y,2)-pow(z,2));
return f;
}

double f2(double x, double y, double z){
	double f = exp(-pow(x,2)-pow(y,2)-pow(z,2));
return f;
}


double integrar (int b, int a, int N, double (*funcion) (double,double,double)){

srand(time(NULL));

	double sum=0;
	double x;
	double aux = (b - a)/(1.*N);
	
	for(int i=1; i<=N; i++){
		//x = rand() % (b+1);
		x = (rand()/double(RAND_MAX))*(1.*b);
		sum = sum + funcion(x,0,0);
	}
	sum = aux * sum;

return sum;
}

double integrar_doble (int b, int a, int N, double (*funcion) (double,double,double)){

srand(time(NULL));

	double sum=0;
	double x, y;
	double aux = pow((b - a),2.)/(1.*N);
	
	for(int i=1; i<=N; i++){
		//x = rand() % (b+1);
		x = (rand()/double(RAND_MAX))*(1.*b);
		y = (rand()/double(RAND_MAX))*(1.*b);
		sum = sum + funcion(x,y,0);
	}
	sum = aux * sum;

return sum;
}

double integrar_triple (int b, int a, int N, double (*funcion) (double,double,double)){

srand(time(NULL));

	double sum=0;
	double x, y, z;
	double aux = pow((b - a),3.)/(1.*N);
	
	for(int i=1; i<=N; i++){
		//x = rand() % (b+1);
		x = (rand()/double(RAND_MAX))*(1.*b);
		y = (rand()/double(RAND_MAX))*(1.*b);
		z = (rand()/double(RAND_MAX))*(1.*b);
		sum = sum + funcion(x,y,z);
	}
	sum = aux * sum;

return sum;
}

double integrar_quintuple(int b, int a, int N, double (*funcion) (double,double,double,double,double)){

srand(time(NULL));

	double sum=0;
	double x, y, z, u, v;
	double aux = pow((b - a),5.)/(1.*N);
	
	for(int i=1; i<=N; i++){
		x = (rand()/double(RAND_MAX))*(1.*b);
		y = (rand()/double(RAND_MAX))*(1.*b);
		z = (rand()/double(RAND_MAX))*(1.*b);
		u = (rand()/double(RAND_MAX))*(1.*b);
		v = (rand()/double(RAND_MAX))*(1.*b);
		sum = sum + funcion(x,y,z,u,v);
	}
	sum = aux * sum;

return sum;
}

double j1_5 (double x,double y,double z,double u,double v){

	double f = (pow(x,2)+pow(y,2)+pow(z,2)+pow(u,2)+pow(v,2))*exp(-pow(x,2)-pow(y,2)-pow(z,2)-pow(u,2)-pow(v,2));
return f;
}

double j2_5 (double x,double y,double z,double u,double v){

	double f = exp(-pow(x,2)-pow(y,2)-pow(z,2)-pow(u,2)-pow(v,2));
return f;
}




int main(){

//srand(time(NULL));

double j1[4];
double j2[4];
int b, a, N;

cout<<"Defina el límite inferior:"<<endl;
cin>>a;
cout<<"Defina el límite superior"<<endl;
cin>>b;
cout<<"defina la cantidad de pasos:"<<endl;
cin>>N;

ofstream j11; j11.open("j11.dat");
ofstream j21; j21.open("j21.dat");

ofstream j12; j12.open("j12.dat");
ofstream j22; j22.open("j22.dat");

ofstream j13; j13.open("j13.dat");
ofstream j23; j23.open("j23.dat");

ofstream j15; j15.open("j15.dat");
ofstream j25; j25.open("j25.dat");


for(int i=0; i<1000; i++){
	j1[0] = integrar(b, a, N, f1); j11<<j1[0]<<endl;
	j1[1] = integrar_doble(b, a, N, f1); j12<<j1[1]<<endl;
	j1[2] = integrar_triple(b, a, N, f1); j13<<j1[2]<<endl;
	j1[3] = integrar_quintuple(b, a, N, j1_5); j15<<j1[3]<<endl;


	j2[0] = integrar(b, a, N, f2); j21<<j2[0]<<endl;
	j2[1] = integrar_doble(b, a, N, f2); j22<<j2[1]<<endl;
	j2[2] = integrar_triple(b, a, N, f2); j23<<j2[2]<<endl;
	j2[3] = integrar_quintuple(b, a, N, j2_5); j25<<j2[3]<<endl;
}

j11.close();
j21.close();

j12.close();
j22.close();

j13.close();
j23.close();

j15.close();
j25.close();





return 0;
}

