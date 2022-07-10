#include "Computer.h"
Computer::Computer(int id,string cpubrand,string cpumodel,string gcardbrand,string gcardmodel,int memory,string hdtype,int hdcap,string os,double price){
	this -> id = id;
	this -> cpubrand = cpubrand;
	this -> cpumodel = cpumodel;
	this -> gcardbrand = gcardbrand;
	this -> gcardmodel = gcardmodel;
	this -> memory = memory;
	this -> hdtype = hdtype;
	this -> hdcap = hdcap;
	this -> os = os;
	this -> price = price;
}

Computer::~Computer(){}

int Computer::getid(){return id;}
string Computer::getcpubrand(){return cpubrand;}
string Computer::getcpumodel(){return cpumodel;}
string Computer::getgcbrand(){return gcardbrand;}
string Computer::getgcmodel(){return gcardmodel;}
int Computer::getmemory(){return memory;}
string Computer::gethdtype(){return hdtype;}
int Computer::gethdcap(){return hdcap;}
string Computer::getos(){return os;}
double Computer::getprice(){return price;}

void Computer::setid(int i){id = i;}
void Computer::setcpubrand(string b){cpubrand=b;}
void Computer::setcpumodel(string m){cpumodel=m;}
void Computer::setgcbrand(string b){gcardbrand = b;}
void Computer::setgcmodel(string m){gcardmodel = m;}
void Computer::setmemory(int m){memory=m;}
void Computer::sethdtype(string h){h = hdtype;}
void Computer::sethdcap(int h){hdcap = h;}
void Computer::setos(string o){os = o;}
void Computer::setprice(double p){price = p;}

string Computer::strword(int index, string line)
{
    int count = 1; // number of read words
    string word; // the resulting word
    for (unsigned int i = 0 ; i < line.length(); i++) { // iterate over all characters in 'line'
        if (line[i] == ',') { // if this character is a comma we might be done reading a word from 'line'
            if (line[i+1] != ',') { // next character is not a comma, so we are done reading a word
                count++;
                if (count == index) {
                    return word; // yes so return it
                }
                word =""; // no reset word and start over with the next one in 'line'
            }
        }
        else { // not a space .. so append the character to 'word'
           word += line[i];
        }
    }return word;
}

int Computer::checkid(int c){
	string line;
	ifstream file("data.txt");
	while(getline(file,line)) {
	if (strword(3, line) == to_string(c))
		do{
			cout<<"ID not unique, try again: ";//do until user enters valid number
			cin >> c;
		}while(strword(3, line) == to_string(c));
	}return c;
}

double Computer::checkprice(double c){
	if(c<100.0){//check whether user entered valid number
			do{
				cout<<"Enter valid price(Over 100): ";//do until user enters valid number
				cin >> c;
			}while(c<100.0);
	}return c;
}

int Computer::checkngcandncpu(int c){return c;}

string Computer::checkhdtype(string c){
	for(unsigned int i = 0; i < c.length(); i++){c[i] = toupper(c[i]);}
	if(c != "SSD" && c != "HDD" && c != "SSHD"){//check whether user entered valid number
			do{
				cout<<"Enter valid Hard Disk Type: ";//do until user enters valid number
				cin >> c;
				for(unsigned int i = 0; i < c.length(); i++){c[i] = toupper(c[i]);}
			}while(c != "SSD" && c != "HDD" && c != "SSHD");
	}
	return c;
}

string Computer::checkos(string c){
	c[0] = toupper(c[0]);
	if(c != "Win" && c != "Linux" && c != "Mac"){//check whether user entered valid number
			do{
				cout<<"Enter valid Operating System: ";//do until user enters valid number
				cin >> c;
				c[0] = toupper(c[0]);
			}while(c != "Win" && c != "Linux" && c != "Mac");
	}
	return c;
}
