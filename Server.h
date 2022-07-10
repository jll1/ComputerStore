#ifndef SERVER_H
#define SERVER_H
#include "Computer.h"
class Server : public Computer{
public:
	Server();
	Server(int screen,string manufacturer,int ncpu,int ngc);
	Server(int id,string cpubrand,string cpumodel,string gcardbrand,string gcardmodel,int memory,string hdtype,int hdcap,string os,int price,int screenn,string manufacturer,int ncpu,int ngc);
	~Server();

	int getscreenn();
	string getmanufacturer();
	int getncpu();
	int getngc();

	void setmanufacturer(string m);
	void setncpu(int c);
	void setngc(int g);
	int checkngcandncpu(int c);
private:
	const int screenn = 0;
	string manufacturer;
	int ncpu;
	int ngc;
};
#endif
