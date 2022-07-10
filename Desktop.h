#ifndef DESKTOP_H
#define DESKTOP_H
#include "Computer.h"
class Desktop : public Computer{
public:
	Desktop();
	Desktop(int screen,int ncpu,int ngc);
	Desktop(int id,string cpubrand,string cpumodel,string gcardbrand,string gcardmodel,int memory,string hdtype,int hdcap,string os,int price,int screenn,int ncpu,int ngc);
	~Desktop();

	int getscreenn();
	int getncpu();
	int getngc();

	void setncpu(int c);
	void setngc(int g);
	int checkngcandncpu(int c);
private:
	const int screenn = 0;
	int ncpu;
	int ngc;
};
#endif
