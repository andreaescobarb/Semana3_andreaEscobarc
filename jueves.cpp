#include <iostream>
#include<fstream>
using namespace std;

char** createMatrix(int);
void deleteMatrix(char**, int);
void printMatrix(char**, int);

int main(){
	//abrir el archivo
	ifstream file("laberinto.txt");
	int size = 0;
	char** labMatrix = NULL;
	//si el archivo existe 
	if(file.is_open()){
		//leer el tamano
		file>>size;
		
		//inicializar la matriz del archivo
		labMatrix = createMatrix(size);

		//leer la matriz del archivo
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				file>>labMatrix[i][j];
			}
		}

		file.close();

		printMatrix(labMatrix, size);
		deleteMatrix(labMatrix, size);
	}

	return 0;
}

void printMatrix(char** matrix, int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
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
	char** retVal = new char* [size];
	for(int i=0;i<size;i++){
		retVal[i] = new char [size];
	}
	return retVal;
}

