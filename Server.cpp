#include "Server.h"

Server::Server(int id,string cpubrand,string cpumodel,string gcardbrand,string gcardmodel,int memory,string hdtype,int hdcap,string os,int price,int screenn,string manufacturer,int ncpu,int ngc) :Computer(id,cpubrand,cpumodel,gcardbrand,gcardmodel,memory,hdtype,hdcap,os,price){
	this -> manufacturer = manufacturer;
	this -> ncpu = ncpu;
	this -> ngc = ngc;
}

Server::~Server(){};

int Server::getscreenn(){return screenn;}
string Server::getmanufacturer(){return manufacturer;}
int Server::getncpu(){return ncpu;}
int Server::getngc(){return ngc;}

void Server::setmanufacturer(string m){manufacturer = m;}
void Server::setncpu(int c){ncpu=c;};
void Server::setngc(int g){ngc=g;};
int Server::checkngcandncpu(int c){
		if(c>4){//check whether user entered valid number
				do{
					cout<<"Enter valid number(Max 4): ";//do until user enters valid number
					cin >> c;
				}while(c>4);
		}
	return c;
}
