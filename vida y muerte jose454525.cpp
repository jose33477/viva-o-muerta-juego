#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int filas, columnas, num_generaciones;
	cout<<"ingrese filas: ";
	cin>> filas ;
	cout<<"ingrese columnas: ";
	cin>> columnas;
	cout<<"ingrese num_generaciones: ";
	cin>> num_generaciones;
	num_generaciones++;
	int matriz[filas][columnas]={};
	 ifstream archivo("archivo.txt");
	 if(archivo.fail()){
	 	cout <<"error abrir archivo txt "<<endl;
	 	exit(0);
	 }	
	 else {
	 	for(int i=0;i<filas;i++){
	 		for(int j=0;j<columnas;j++){
	 				archivo>>matriz[i][j];
			 }
		 }
	 }
	archivo.close();
	for(int k=0;k<num_generaciones;k++){
		if(k==0){
			cout<<"Inicial:"<<endl;
		}
		else{
			cout<<"Generacion "<<k<<"."<<endl;
		}
		int vivas=0;
		int matriz2[filas][columnas]={};
		for(int i=0;i<filas;i++){
	 		for(int j=0;j<columnas;j++){
	 				cout<<matriz[i][j]<<' ';	
					 matriz2[i][j]=matriz[i][j];
					 if(matriz[i][j]==1){
					 	vivas++;
					 }
			 }
			 cout<<endl;
		 }
		 
		 cout<<"Las cantidad de celulas vivas son "<<vivas<<endl;
		 cout<<endl;
		 
		 for(int i=0;i<filas;i++){
	 		for(int j=0;j<columnas;j++){
	 				int contador0=0, contador1=0;
	 				for(int alr_filas=i-1;alr_filas<=i+1;alr_filas++){
	 						for(int alr_col=j-1;alr_col<=j+1;alr_col++){
	 							if(alr_filas>=0 && alr_filas<filas && alr_col>=0 && alr_col<columnas){
	 								if(alr_filas!=i || alr_col!=j){
		 								if(matriz2[alr_filas][alr_col]==1){
		 									contador1++;
										 }
										 else{
										 	contador0++;
										 }
								 	}
								 }
							 }
					 }	
				if(matriz2[i][j]==1){
					if(contador1!=2 && contador1!=3){
						matriz[i][j]=0;
					}
				}	
				else{
					if(contador1==3){
						matriz[i][j]=1;
					}
				}		
			 }
		 }
		 
	}
	return 0;
}


 
 
