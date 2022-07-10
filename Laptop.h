#ifndef LAPTOP_H
#define LAPTOP_H
#include "Computer.h"
class Laptop : public Computer{
public:
	Laptop();
	Laptop(string manufacturer,int screensize,int ncpu,int ngc);
	Laptop(int id,string cpubrand,string cpumodel,string gcardbrand,string gcardmodel,int memory,string hdtype,int hdcap,string os,int price,string manufacturer,double screensize,int ncpu,int ngc);
	~Laptop();

	string getmanufacturer();
	double getscreensize();
	int getncpu();
	int getngc();

	void setmanufacturer(string m);
	void setscreensize(double s);
	void setncpu(int c);
	void setngc(int g);
	double checkscreensize(double c);
	int checkngcandncpu(int c);
private:
	string manufacturer;
	double screensize;
	int ncpu;
	int ngc;
};
#endif
