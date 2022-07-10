#include "Desktop.h"

Desktop::Desktop(int id,string cpubrand,string cpumodel,string gcardbrand,string gcardmodel,int memory,string hdtype,int hdcap,string os,int price,int screenn,int ncpu,int ngc) :Computer(id,cpubrand,cpumodel,gcardbrand,gcardmodel,memory,hdtype,hdcap,os,price){
	this -> ncpu = ncpu;
	this -> ngc = ngc;
}

Desktop::~Desktop(){};

int Desktop::getscreenn(){return screenn;}
int Desktop::getncpu(){return ncpu;}
int Desktop::getngc(){return ngc;}

void Desktop::setncpu(int c){ncpu=c;};
void Desktop::setngc(int g){ngc=g;};
int Desktop::checkngcandncpu(int c){
	if(c>2){//check whether user entered valid number
				do{
					cout<<"Enter valid number(Max 2): ";//do until user enters valid number
					cin >> c;
				}while(c>2);
		}
	return c;
}
