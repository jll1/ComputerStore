#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <fstream>
//#include <vector>
//#include <array>
//#include <string.h>
//#include <cstdlib>
using namespace std;
class Computer{
public:
	Computer();
	Computer(int id,string cpubrand,string cpumodel,string gcardbrand,string gcardmodel,int memory,string hdtype,int hdcap,string os,double price);
	virtual ~Computer();

	int getid();
	string getcpubrand();
	string getcpumodel();
	string getgcbrand();
	string getgcmodel();
	int getmemory();
	string gethdtype();
	int gethdcap();
	string getos();
	double getprice();

	void setid(int i);
	void setcpubrand(string b);
	void setcpumodel(string m);
	void setgcbrand(string b);
	void setgcmodel(string m);
	void setmemory(int m);
	void sethdtype(string h);
	void sethdcap(int h);
	void setos(string o);
	void setprice(double p);
	string strword(int index, string line);

	int checkid(int c);
	double checkprice(double p);
	virtual int checkngcandncpu(int c);
	string checkhdtype(string c);
	string checkos(string c);
private:
	int id;
	string cpubrand;
	string cpumodel;
	string gcardbrand;
	string gcardmodel;
	int memory;
	string hdtype;
	int hdcap;
	string os;
	double price;
};
#endif
