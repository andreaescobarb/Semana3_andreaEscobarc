#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>

using namespace std;


//provisiona una matriz de tamano n x n
char** createMatrix(int);

//libera la memoria de una matriz n x n
void deleteMatrix(char**, int);

//imprime matriz
void printMatrix(char**, int);

int main(){
	srand(time(NULL));

	int ran = rand()%255;
	cout<<ran<<endl;

	char** charMatrix;
	int size;
	cout<<"Ingrese el tamano de la matriz:";
	cin>>size;

	charMatrix = createMatrix(size);
	deleteMatrix(charMatrix, size);
	return 0;
} 
void printMatrix(char** matrix, int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<10;j++){
			cout<<" "<<matrix[i][j];
		}
		cout<<endl;
	}
}

void deleteMatrix(char** matrix, int size){
	for(int i=0;i<size;i++){
		delete[] matrix[i];
		matrix[i] = NULL;
	}
	delete[] matrix;
}

char** createMatrix(int size){
	char** retVal = new char*[size];

	for(int i=0;i<size;i++){
		retVal[i] = new char[size];
	}

	return retVal;
}
