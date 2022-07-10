#include "Laptop.h"

Laptop::Laptop(int id,string cpubrand,string cpumodel,string gcardbrand,string gcardmodel,int memory,string hdtype,int hdcap,string os,int price,string manufacturer,double screensize,int ncpu,int ngc) :Computer(id,cpubrand,cpumodel,gcardbrand,gcardmodel,memory,hdtype,hdcap,os,price){
	this -> manufacturer = manufacturer;
	this -> screensize = screensize;
	this -> ncpu = ncpu;
	this -> ngc = ngc;
}

Laptop::~Laptop(){};

string Laptop::getmanufacturer(){return manufacturer;}
double Laptop::getscreensize(){return screensize;}
int Laptop::getncpu(){return ncpu;}
int Laptop::getngc(){return ngc;}

void Laptop::setmanufacturer(string m){manufacturer = m;}
void Laptop::setscreensize(double s){screensize=s;};
void Laptop::setncpu(int c){ncpu=c;};
void Laptop::setngc(int g){ngc=g;};
double Laptop::checkscreensize(double c){
	if(c != 11.1 && c != 12 && c != 13.3 && c != 14 && c != 15.6 && c != 17.3){//check whether user entered valid number
		do{
			cout<<"Enter valid screensize(11.1/12/13.3/14/15.6): ";//do until user enters valid number
			cin >> c;
		}while(c != 11.1 && c != 12 && c != 13.3 && c != 14 && c != 15.6 && c != 17.3);
	}return c;
}
int Laptop::checkngcandncpu(int c){
		if(c>1){//check whether user entered valid number
				do{
					cout<<"Enter valid number(Max 1): ";//do until user enters valid number
					cin >> c;
				}while(c>1);
		}
	return c;
}
