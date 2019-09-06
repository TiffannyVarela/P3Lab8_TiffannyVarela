#include <iostream>
#include <stdlib.h>
#include <sqlite3.h>

using namespace std;

int menu();

int main(int argc, char** argv) {
	sqlite3 *conn;
	sqlite3_stmt *res;
	int error=0;
	int rec_count =0;
	const char *tail;
	
		
	int opc =0;
	int resp =0;
	
	int deptno;
	string dname, loc;
	
	int empno;
	string ename, job, hiredate;
	int mgr, sal, comm, depto;
	
	do{
		switch(opc=menu()){
			case 1:
				cout<<"Que desea agregar?: ";
				switch(resp=menu()){
					
					case 1:
						cout<<"Empleado"<<endl;
						cout<<"Numero ";
						cin>>empno;
						cout<<"Nombre ";
						cin>>ename;
						cout<<"Trabajo ";
						cin>>job;
						cout<<"Jefe " ;
						cin>>mgr;
						cout<<"Fecha ";
						cin>>hiredate;
						cout<<"Salario ";
						cin>>sal;
						cout<<"Comision";
						cin>>comm;
						cout<<"Numero de Departamento ";
						cin>>depto;
						break;
						
					case 2:
						break;
						
				}
				break;
				
			case 2:
				break;
				
			case 3:
				break;
				
			case 4:
				break;
				
			case 5:
				break;
				
			case 6:
				break;	
		}
	}while(resp!=6);
	
	return 0;
}

int menu(){
	int opc=0;
	while (true){
		cout<<"MENU"<<endl
			<<"1.-Nota 1"<<endl
			<<"2.-Nota 2"<<endl
			<<"3.-Nota 3"<<endl
			<<"4.-Nota 4"<<endl
			<<"5.-Nota 5"<<endl
			<<"6.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=6){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}

int menu2(){
	int opc=0;
	while (true){
		cout<<"MENU"<<endl
			<<"1.-Empleado"<<endl
			<<"2.-Departamento"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=2){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}
