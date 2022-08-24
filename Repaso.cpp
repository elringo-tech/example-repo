/*
Escribir un programa en el que se defina una matriz de NxM. Cada fila de la 
matriz se corresponde con un número de identificación y dos notas. 

Las notas deben ser cargadas por teclado y tienen que estar comprendidas entre 1 y 100. 
Se debe validar el correcto ingreso de las notas. 
En un vector aparte asociar cada número de identificación y notas a un nombre. 

Estas notas se deberán mostrar luego en forma ascendente y en forma descendente siempre con el 
nombre de a quien le corresponden. 

Luego se deberá pedir al usuario que elija las operaciones que desea realizar 
con los datos creados. 

Una de las operaciones es que se obtenga el promedio de las notas asociadas a cada
nombre, este promedio deberá ser guardado. El usuario deberá optar por ver
el promedio de cada usuario o de todos. 

Otra operación es la de buscar la nota más alta y a qué nombre se corresponde. 

Otra opción es buscar la menor nota y a qué nombre se corresponde. 

Otra opción es buscar un nombre por número de identificación. 

Crear también una opción que permita mostrar las 
notas pares y las notas impares en dos vectores separados. */

#include <iostream>
using namespace std;

#define N 2
#define M 3
int main(int argc, char *argv[]) {
	int mat[N][M]={};//Matriz de N alumnos y M columnas (una para indice y la otra para notas)
	float promedios[N]={};//creo un vector para guardar los promedios de N alumnos
	int i=0, j=0; //variables enteras para control de for's
	int alumno; //indice para referirse a cada alumno 
	float acum = 0; 
	float promedio = 0;
	int p1, max, pmax, min, pmin;
	int pares[M-1]={},impares[M-1]={};
	int asc[N*(M-1)], desc[N*[M-1];
	int ban, aux;
	char opc; //variable tipo caracter para usar en estructura switch
	
	//****CARGA MATRIZ INDICE 
	for(i=0;i<N;i++){
		
		mat[i][0]=i+1;
		//cout<<mat[i][0]<<endl;
	}
	//***CARGA MATRIZ NOMBRE Y NOTAS
	for(i=0;i<N;i++){
		
		for(j=1;j<M;j++){//j arranca en 1 porque la primer columna es de indices
		//cout<<"ingrese nombre "<<i+1<<": ";
		//cin>>nombre[i];
		
		cout<<endl<<"ingrese nota "<<j<<" del alumno "<<i+1<<endl;
		do{
		cin>>mat[i][j];
		if(mat[i][j]>100 || mat[i][j]<1){//si nota incorrecta => msj de error
			cout<<"incorrecto, debe ingresar una nota comprendida entre 1 y 100"<<endl;
			cout<<"reingrese la nota: ";
		}
		}while(mat[i][j]>100 || mat[i][j]<1);	//validamos las notas
		
		}
		
	}
	
	//****MUESTRA MATRIZ INDICE Y NOMBRE
	for(i=0;i<N;i++){
		
		for(j=1;j<M;j++){
			cout<<"Alumno "<<i+1<<" nota "<<j<<": ";
			cout<<mat[i][j]<<endl;
			
		}
		
	}
	//Ordenamos y guardamos en vector ascendente
	do{
		ban = 0;
	for(i=0;i<(N*M-1)-2;i++){
		if(asc[i]>asc[i+1]){
		aux = asc[i];
		asc[i] = asc[i+1];
		asc[i+1]= aux;
		ban = 1;
		}
	}
	}while(ban==1);
	//Ordenamos y guardamos en vector descendente
	do{
		ban = 0;
		for(i=0;i>(N*M-1)-2;i++){
			if(desc[i]>desc[i+1]){
				aux = desc[i];
				desc[i] = desc[i+1];
				desc[i+1]= aux;
				ban = 1;
			}
		}
	}while(ban==1);
	
	//******MOSTRAMOS NOTAS EN FORMA ASCENDENTE*******
	for(i=0;i<(N*(M-1));i++){
		cout<<"Se muestran las notas en forma ascendente"<<endl;
		cout<<asc[i]<<" ";
	}
	cout<<endl;
	//*****MOSTRAMOS NOTAS EN FORMA DESCENDENTE*******
	for(i=0;i<(N*(M-1));i++){
		cout<<"Se muestran las notas en forma descendente"<<endl;
		cout<<desc[i]<<" ";
	}
	cout<<endl;
	//****DESPLEGAMOS MENU****************************
	do{
		cout<<"***********Menu************"<<endl;
		cout<<"*****ingrese una opcion****"<<endl;
		cout<<"1-PROMEDIOS"<<endl;
		cout<<"2-NOTA MAS ALTA"<<endl;
		cout<<"3-NOTA MAS BAJA"<<endl;
		cout<<"4-NOTAS PARES E IMPARES"<<endl;
		cout<<"'s'-SALIR"<<endl;
		cin>>opc;
		
		switch(opc){
		case '1':{ 
						do{//pequeño menu 
						cout<<"Desea ver todos los promedios?? "<<endl; 
						cout<<"presione 1 para ver todos"<<endl;
						cout<<"presione 2 para ver uno solo"<<endl;
						cin>>p1;
							if(p1<1||p1>2){ //valido el rango de la opcion ingresada
								cout<<"debe ingresar 1 o 2 como opcion!!!!"<<endl;
							}
							
						}while(p1<1||p1>2);				//mientras no se cumpla mi condicion deseada pido reingreso
						if(p1==1){							//opcion de mostrar todos los promedios (los guardo en un vector)
						for(i=0;i<N;i++){
							acum = 0; 					//debo reiniciar mi acumulador porque puede estar cargado con suma de notas de alumnos anteriores
							for(j=1;j<M;j++){			//j siempre arranca en 1 para no tomar la columna que contiene indices
						acum = acum + mat[i][j];}
						promedio = acum/(M-1);			//va hasta M-1 porque la primer columna es de indices
						promedios[i] = promedio;
						}
						
					cout<<"A continuacion se muestran los promedios: "<<endl;
					
					for(i=0;i<N;i++){
						cout<<"Promedio del alumno "<<i+1<<": "<<promedios[i]<<endl;
							}		
					}
					
					//aqui abajo si p=2 entonces se pide ver promedio de un solo alumno
						if(p1==2){
					cout<<"ingrese el numero de alumno: ";
						
					do{
					cin>>alumno;
					if(alumno<1 || alumno > N)
					cout<<"debe ingresar un numero de alumno valido entre ";
					cout<<1<<" y "<<N<<endl;
					}while(alumno<1 || alumno > N);
					
					acum = 0; //reseteo mi acumulador por si fue utilizado anteriormente
					for(j=1;j<M;j++){
					acum = acum + mat[alumno][j];}
					cout<<"mat[alumno][j] :"<<acum<<endl;
					promedio = acum/(M-1);
					
					cout<<"El promedio del alumno "<<alumno<<" es: "<<promedio<<endl;}
					
		break;}
		case '2':{			j=1; //inicio j para recorrer sin considerar los indices que se corresponden con cada alumno
							for(i=0;i<N;i++){
								if(i==0 && j==1){ //guardo el primer elemento de la matriz como maximo antes de recorrer
									max = mat[i][j];
								}
								for(j=1;j<M;j++){
									if(mat[i][j]>max){ //verifico si cada elemento de la matriz es mayor al maximo encontrado
										max=mat[i][j];
										pmax = i; //guardo el indice del alumno con maxima nota
									}
									}
							}	
							cout<<"La nota mas alta es: "<<max<<" y se corresponde con el alumno "<<pmax<<endl;
							break;}
		case '3':{ 
			j=1; //inicio j para recorrer sin considerar los indices que se corresponden con cada alumno
			for(i=0;i<N;i++){
				if(i==0 && j==1){ //guardo el primer elemento de la matriz como minimo antes de recorrer
					min = mat[i][j];
				}
				for(j=1;j<M;j++){
					if(mat[i][j]<min){ //verifico si cada elemento de la matriz es menor al minimo encontrado
						min=mat[i][j];
						pmin = i; //guardo el indice del alumno con menor nota
					}
				}
			}	
			cout<<"La nota mas baja es: "<<min<<" y se corresponde con el alumno "<<pmin<<endl;
			
			break;}
		case '4':{ for(i=0;i<N;i++){
			
					for(j=1;j<M;j++){
						
						if(mat[i][j]%2==0){
							pares[j]=mat[i][j];
						}else
							{impares[j]=mat[i][j];}
						for(i=0;i<N;i++){
							cout<<"Acontinuacion se muestran las notas pares: "<<pares[i]<<endl;
							cout<<"Acontinuacion se muestran las notas impares: "<<impares[i]<<endl;
							
						}
						
					}
		}
				
				
				
				
				break;}
	    case 's':{ cout<<"***FIN DE PROGRAMA****"; break;}
		default: cout<<"opcion incorrecta, reingrese"<<endl;
		}
	}while(opc!='s');
	
	return 0;
}

