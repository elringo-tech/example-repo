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



/*

NOTA: El el lenguage c++ no esta optimizado para trabajar con strings, por lo 
que la inclusion de los nombres es bastante complicada y escapa de el alcance 
de esta materia en esta etapa. Por lo que se procede a realizar todo lo 
solicitado en el enunciado sin utilizar nombres...


*/
#include <iostream>
using namespace std;

#define N 2
#define M 3
int main(int argc, char *argv[]) {
	int mat[N][M]={};     //Matriz de N alumnos y M columnas (una para indice y la otra para notas)
	float promedios[N]={};//creo un vector para guardar los promedios de N alumnos
	int i=0, j=0; 		  //variables enteras para control de for's
	int alumno; 		  //indice para referirse a cada alumno 
	float acum = 0; 	  //acumulador
	float promedio = 0;	  //variable de punto flotante para calculo de promedio
	int p1, max, pmax, min, pmin; 
	int pares[M-1]={},impares[M-1]={};     //vectores pares e impares
	int asc[N*(M-1)]={}, desc[N*(M-1)]={}; //ascendente y descendente tienen que tener el tamaño
										   //"N*(M-1)" ya que tienen que estar todas las notas
										   //se pone "M-1" porque una de las columnas es de indices
	int ban, aux, k,l;
	char opc; //variable tipo caracter para usar en estructura switch
	
	//****CARGA MATRIZ INDICE 
	for(i=0;i<N;i++){
		
		mat[i][0]=i+1;   //la columna "0" almacena los indices
		//cout<<mat[i][0]<<endl;
	}
	//***CARGA MATRIZ NOMBRE Y NOTAS
	for(i=0;i<N;i++){
		
		for(j=1;j<M;j++){//j arranca en 1 porque la primer columna es de indices
		cout<<endl<<"ingrese nota "<<j<<" del alumno "<<i+1<<": ";
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
	
	//creo dos vectores desordenados que contienen todas las notas cargadas
	k=0; //inicializo en 0 la variable que hara de indice para los vectores
	for(i=0;i<N;i++){
		for(j=1;j<M;j++){
			asc[k]=mat[i][j];
			desc[k] = asc[k]; //en este caso los vectores van a ser iguales al principío, despues se ordenan.
			k++;
		}
	}
	//Ordenamos y guardamos en vector ascendente METODO BURBUJA CON BANDERA
	do{
		ban = 0;
	for(i=0;i<N*(M-1)-1;i++){
		if(asc[i]>asc[i+1]){
		aux = asc[i];
		asc[i] = asc[i+1];
		asc[i+1]= aux;
		ban = 1;
		}
	}
	}while(ban==1);
	
	//Ordenamos y guardamos en vector descendente METODO BURBUJA CON BANDERA
	do{
		ban = 0;
		for(i=0;i<N*(M-1)-1;i++){
			if(desc[i]<desc[i+1]){
				aux = desc[i];
				desc[i] = desc[i+1];
				desc[i+1]= aux;
				ban = 1;
			}
		}
	}while(ban==1);
	
	//******MOSTRAMOS NOTAS EN FORMA ASCENDENTE*******
	cout<<"Se muestran las notas en forma ascendente"<<endl;
	for(i=0;i<(N*(M-1));i++){
		
		cout<<asc[i]<<" ";
	}
	cout<<endl;
	
	//*****MOSTRAMOS NOTAS EN FORMA DESCENDENTE*******
	cout<<"Se muestran las notas en forma descendente"<<endl;
	for(i=0;i<(N*(M-1));i++){
		
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
		case '1':{ 		//-OPCION PROMEDIOS
						do{//pequeño submenu 
						cout<<"Desea ver todos los promedios?? "<<endl; 
						cout<<"presione 1 para ver todos"<<endl;
						cout<<"presione 2 para ver uno solo"<<endl;
						cin>>p1;//pido ingreso opcion de submenu
							if(p1<1||p1>2){ //valido el rango de la opcion ingresada
								cout<<"debe ingresar 1 o 2 como opcion!!!!"<<endl;
							}
							
						}while(p1<1||p1>2);				//mientras no se cumpla mi condicion deseada pido reingreso
						if(p1==1){						//opcion de mostrar todos los promedios (los guardo en un vector)
						for(i=0;i<N;i++){
							acum = 0; 					//debo reiniciar mi acumulador porque puede estar cargado con suma de notas de alumnos anteriores
							for(j=1;j<M;j++){			//j siempre arranca en 1 para no tomar la columna que contiene indices
						acum = acum + mat[i][j];}
						promedio = acum/(M-1);			//va hasta M-1 porque la primer columna es de indices
						promedios[i] = promedio;
						}
						//******MUESTRO TODOS LOS PROMEDIOS******
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
					acum = acum + mat[alumno-1][j];}
					cout<<"mat[alumno][j] :"<<acum<<endl;
					promedio = acum/(M-1);
					
					//*****MUESTRO EL PROMEDIO DEL ALUMNO CUYO INDICE FUE INGRESADO*****
					cout<<"El promedio del alumno "<<alumno<<" es: "<<promedio<<endl;}
					break;}
		
		case '2':{			//***OPCION NOTA MAS ALTA******
							j=1; //inicio j para recorrer sin considerar los indices que se corresponden con cada alumno
							for(i=0;i<N;i++){
								if(i==0 && j==1){ 
									max = mat[i][j];//guardo el primer elemento de la matriz como maximo antes de recorrer
									pmax = i;       //guardo la posicion del elemento maximo al principio
								}
								for(j=1;j<M;j++){
									if(mat[i][j]>max){ //verifico si cada elemento de la matriz es mayor al maximo encontrado
										max=mat[i][j]; //CARGO EL MAXIMO EN MI VARIABLE "max" 
										pmax = i;      //guardo el indice del alumno con maxima nota
									}
									}
							}		//*******MUESTRO LA NOTA MAS ALTA*********
							cout<<"La nota mas alta es: "<<max<<" y se corresponde con el alumno "<<pmax+1<<endl;
							break;}
		
			
		case '3':{   		//******OPCION NOTA MAS BAJA*******
							j=1; //inicio j para recorrer sin considerar los indices que se corresponden con cada alumno
							for(i=0;i<N;i++){
								if(i==0 && j==1){ 
								min = mat[i][j];  //guardo el primer elemento de la matriz como minimo antes de recorrer
								pmin = i;         //guardo la posicion del primer elemento que considero como minimo
								}
							for(j=1;j<M;j++){
								if(mat[i][j]<min){  //verifico si cada elemento de la matriz es menor al minimo encontrado
								min=mat[i][j];		//CARGO MI VARIABLE "min"
								pmin = i; 			//guardo el indice del alumno con menor nota
								}
							}
							}		//****MUESTRO  LA NOTA MAS BAJA*****
							cout<<"La nota mas baja es: "<<min<<" y se corresponde con el alumno "<<pmin+1<<endl;
							break;}
							
		case '4':{ 
					k=0; //utilizo variables para recorrer mis vectores de pares e impares
					l=0;
					for(i=0;i<N;i++){ //inicio recorrido de matriz
			
					for(j=1;j<M;j++){
						
						if(mat[i][j]%2==0){    //si el resto de dividir el elemento por 2 es cero => "par"
							pares[k]=mat[i][j];
							k++; //incremento el indice de mi vector de pares
						}else					//si el resto !=0 => "impar"
							{impares[l]=mat[i][j];
								l++;  //incremento el indice de mi vector de impares
						}
						
					}
		}			//***********MUESTRO LAS NOTAS PARES************
		cout<<"A continuacion se muestran las notas pares: "<<endl;
		for(i=0;i<M-1;i++){
			cout<<pares[i]<<" ";
		}
		cout<<endl;
					//********MUESTRO LAS NOTAS IMPARES*************
		cout<<"A continuacion se muestran las notas impares: "<<endl;
		for(i=0;i<M-1;i++){
			cout<<impares[i]<<" ";
		}
		cout<<endl;
		break;}
					
	    case 's':{ cout<<"***FIN DE PROGRAMA****"; break;}
		default: cout<<"opcion incorrecta, reingrese"<<endl;
		}
	}while(opc!='s');
	
	return 0;
}

