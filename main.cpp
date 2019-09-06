#include <iostream>
#include <stdlib.h>
#include <sqlite3.h>
#include <vector>
using namespace std;

int menu();
int menu2();

int main(int argc, char** argv) {
	sqlite3 *conn;
	sqlite3_stmt *res;
	int error=0;
	int rec_count =0;
	const char *tail;
	
		
	int opc =0;
	int resp =0;
	
	vector <int> ndep;
	
	string deptno,dname, loc;
	string val;
	string empno,ename, job, hiredate,mgr, sal, comm, depto;
	string query;
	bool re=false;
	string var;
	
	
	do{
		switch(opc=menu()){
			case 1:
				cout<<"Que desea listar?: ";
				switch(resp=menu2()){
					
					case 1:
						error = sqlite3_open("oracle-sample.db", &conn);
						error = sqlite3_prepare_v2(conn, "select * from emp", 1000, &res, &tail);
						if(error!=SQLITE_OK){
							cout<<"ERROR EN EL QUERY"<<endl;
							break;
						}
						while(sqlite3_step(res) == SQLITE_ROW){
							cout<<endl;
							cout<<"Numero de Empleado: ";
							cout<<sqlite3_column_text(res,0)<<endl;
							cout<<"Nombre de Empleado: ";
							cout<<sqlite3_column_text(res,1)<<endl;
							cout<<"Trabajo: ";
							cout<<sqlite3_column_text(res,2)<<endl;
							cout<<"Numero Manager: ";
							cout<<sqlite3_column_text(res,3)<<endl;
							cout<<"Fecha: ";
							cout<<sqlite3_column_text(res,4)<<endl;
							cout<<"Salario: ";
							cout<<sqlite3_column_text(res,5)<<endl;
							cout<<"Comision: ";
							cout<<sqlite3_column_text(res,6)<<endl;
							cout<<"Numero de Departamento: ";
							cout<<sqlite3_column_text(res,7)<<endl;
							cout<<endl;
						}	
						sqlite3_close(conn);
						break;
						
					case 2:
						error = sqlite3_open("oracle-sample.db", &conn);
						error = sqlite3_prepare_v2(conn, "select * from dept", 1000, &res, &tail);
						if(error!=SQLITE_OK){
							cout<<"ERROR EN EL QUERY"<<endl;
							break;
						}
						while(sqlite3_step(res) == SQLITE_ROW){
							cout<<endl;
							cout<<"Numero de Departamento: ";
							cout<<sqlite3_column_text(res,0)<<endl;
							cout<<"Nombre de Departamento: ";
							cout<<sqlite3_column_text(res,1)<<endl;
							cout<<"Locacion: ";
							cout<<sqlite3_column_text(res,2)<<endl;
							cout<<endl;
						}	
						sqlite3_close(conn);
						break;
						
				}
				break;
				
			case 2:
				cout<<"Que desea Agregar?: ";
				switch(resp=menu2()){
					
					case 1:
						error=sqlite3_open("oracle-sample.db",&conn);
						cout<<"Empleado"<<endl;
						cout<<"Numero: ";
						cin>>empno;
						cout<<"Nombre: ";
						cin>>ename;
						cout<<"Trabajo: ";
						cin>>job;
						cout<<"Jefe: " ;
						cin>>mgr;
						cout<<"Fecha: ";
						cin>>hiredate;
						cout<<"Salario: ";
						cin>>sal;
						cout<<"Comision: ";
						cin>>comm;
						cout<<"Numero de Departamento: ";
						cin>>depto;
						
						query = "select * from dept where deptno = '"+depto+"'";
						sqlite3_prepare_v2(conn, query.c_str(), query.length()+1, &res,	&tail);
						
						if(error!=SQLITE_OK){
							cout<<"ERROR EN EL QUERY"<<endl;
							break;
						}
						
						if(sqlite3_step(res) == SQLITE_ROW){
							query = "insert into emp values('"+empno+"','"+ename+"','"+job+"','"+mgr+"','"+hiredate+"','"+sal+"','"+comm+"','"+depto+"')";
							error=sqlite3_exec(conn,query.c_str(),0,0,0);
						}
						
						sqlite3_close(conn);
						break;
						
					case 2:
						error=sqlite3_open("oracle-sample.db",&conn);
						cout<<"Departamento"<<endl;
						cout<<"Numero: ";
						cin>>deptno;
						cout<<"Nombre: ";
						cin>>dname;
						cout<<"Locacion: ";
						cin>>loc;
						query = "insert into dept values('"+deptno+"','"+dname+"','"+loc+"')";
						error=sqlite3_exec(conn,query.c_str(),0,0,0);
						if(error!=SQLITE_OK){
							cout<<"ERROR EN EL QUERY"<<endl;
							break;
						}
						sqlite3_close(conn);
						break;
						
				}
				break;
				
			case 3:
				error=sqlite3_open("oracle-sample.db",&conn);
				cout<<"Numero de Empleado a Eliminar: ";
				cin>>empno;
				query = "delete from emp where empno = '"+empno+"'";
				error=sqlite3_exec(conn,query.c_str(),0,0,0);
				if(error!=SQLITE_OK){
					cout<<"ERROR EN EL QUERY"<<endl;
					break;
				}
				sqlite3_close(conn);
				break;
				
			case 4:
				error=sqlite3_open("oracle-sample.db",&conn);
				cout<<"Numero de Empleado: ";
				cin>>empno;
				query = "select	mgr from emp where empno = '"+empno+"'";
				error=sqlite3_prepare_v2(conn,query.c_str(),query.length()+1,&res,&tail);
				if(error!=SQLITE_OK){
					cout<<"ERROR EN EL QUERY"<<endl;
					break;
				}
				if(sqlite3_step(res) == SQLITE_ROW){
					val=(char*)sqlite3_column_text(res,0);
				}
				query = "select * from emp where empno= '"+val+"'";
				error = sqlite3_prepare_v2(conn,query.c_str(), query.length()+1, &res, &tail );
				while(sqlite3_step(res) == SQLITE_ROW){
					cout<<endl;
					cout<<"MANAGER"<<endl;
					cout<<"Numero de Empleado: ";
					cout<<sqlite3_column_text(res,0)<<endl;
					cout<<"Nombre de Empleado: ";
					cout<<sqlite3_column_text(res,1)<<endl;
					cout<<"Trabajo: ";
					cout<<sqlite3_column_text(res,2)<<endl;
					cout<<"Numero Manager: ";
					cout<<sqlite3_column_text(res,3)<<endl;
					cout<<"Fecha: ";
					cout<<sqlite3_column_text(res,4)<<endl;
					cout<<"Salario: ";
					cout<<sqlite3_column_text(res,5)<<endl;
					cout<<"Comision: ";
					cout<<sqlite3_column_text(res,6)<<endl;
					cout<<"Numero de Departamento: ";
					cout<<sqlite3_column_text(res,7)<<endl;
					cout<<endl;
				}	
				query = "select * from emp where mgr= '"+val+"'";
				error = sqlite3_prepare_v2(conn,query.c_str(), query.length()+1, &res, &tail );
				if(error!=SQLITE_OK){
					cout<<"ERROR EN EL QUERY"<<endl;
					break;
				}
				while(sqlite3_step(res) == SQLITE_ROW){
					cout<<endl;
					cout<<"EMPLEADO"<<endl;
					cout<<"Numero de Empleado: ";
					cout<<sqlite3_column_text(res,0)<<endl;
					cout<<"Nombre de Empleado: ";
					cout<<sqlite3_column_text(res,1)<<endl;
					cout<<"Trabajo: ";
					cout<<sqlite3_column_text(res,2)<<endl;
					cout<<"Numero Manager: ";
					cout<<sqlite3_column_text(res,3)<<endl;
					cout<<"Fecha: ";
					cout<<sqlite3_column_text(res,4)<<endl;
					cout<<"Salario: ";
					cout<<sqlite3_column_text(res,5)<<endl;
					cout<<"Comision: ";
					cout<<sqlite3_column_text(res,6)<<endl;
					cout<<"Numero de Departamento: ";
					cout<<sqlite3_column_text(res,7)<<endl;
					cout<<endl;
				}	
				sqlite3_close(conn);
				break;
				
			case 5:
				break;
				
			case 6:
				break;	
				
			case 7:
				break;	
		}
	}while(opc!=7);
	
	return 0;
}

int menu(){
	int opc=0;
	while (true){
		cout<<"MENU"<<endl
			<<"1.-Listar"<<endl
			<<"2.-Agregar"<<endl
			<<"3.-Eliminar"<<endl
			<<"4.-Listar Jefe y Empleado"<<endl
			<<"5.-Actualizar Salario Empleado"<<endl
			<<"6.-Empleados de Departamento"<<endl
			<<"7.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=7){
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
		cout<<endl;
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
