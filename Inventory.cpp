#ifndef COMPUTER_H
#include "Computer.h"
#endif
#ifndef LAPTOP_H
#include "Laptop.h"
#endif
#ifndef DESKTOP_H
#include "Desktop.h"
#endif
#ifndef SERVER_H
#include "Server.h"
#endif
#ifndef INVENTORY_H
#include "Inventory.h"
#endif

void Inventory::entercontinue(){
	cout<<"Press enter to continue!";
	cin.clear(); //clears the stream
	cin.ignore(200,'\n'); //ignores next line(enter)
	cin.get();
}

void Inventory::showcomputersfromfile(){
    string line;
    ifstream file("data.txt");
    while(getline(file, line)) {
     cout << line << endl;
    }
    file.close();entercontinue();start();
}

string Inventory::strword(int index, string line)
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

void Inventory::searchhdtype(){
    string line,a;
    cout<<"Hard disk type(SSD/HDD/SSHD): ";cin>>a;
    for(unsigned int i=0; i<a.length(); i++){a[i]=toupper(a[i]);}
	ifstream file("data.txt");
    while(getline(file, line)) {
    	if(strword(9, line) == a){
    	cout << line << endl;
    }}file.close();entercontinue();start();
}

void Inventory::searchss(){
    string line;
	int a,b;
    cout<<"Min Screensize: ";cin>>a;
    cout<<"Max Screensize: ";cin>>b;
	ifstream file("data.txt");
    while(getline(file, line)) {
    	if(strword(2, line) == "Laptop" && strword(14, line) > to_string(a) && strword(15, line) < to_string(b)){
    	cout << line << endl;
    }}file.close();entercontinue();start();
}

void Inventory::searchngcpu(){
    string line;
	int a,b;
    cout<<"Min GPU/CPU: ";cin>>a;
    cout<<"Max GPU/CPU: ";cin>>b;
	ifstream file("data.txt");
    while(getline(file, line)) {
    	if(strword(15, line) > to_string(a) && strword(15, line) < to_string(b)){
    	cout << line << endl;
    }}file.close();entercontinue();start();
}

void Inventory::searchprice(){
    string line;
	double a,b;
    cout<<"From Price: ";cin>>a;
    if(a<100.0){//check whether user entered valid number
    			do{
    				cout<<"Enter valid from price(Over 100): ";//do until user enters valid number
    				cin >> a;
    			}while(a<100.0);
    	}
    cout<<"To Price: ";cin>>b;
    if(b<a){//check whether user entered valid number
    			do{
    				cout<<"Enter valid price(More than To Price): ";//do until user enters valid number
    				cin >> b;
    			}while(b<a);
    	}
	ifstream file("data.txt");
    while(getline(file, line)) {
    	if(strword(12, line) > to_string(a) && strword(12, line) < to_string(b)){
    	cout << line << endl;
    }}file.close();entercontinue();start();
}

void Inventory::searchos(){
    string line;
	string os;
    cout<<"Enter Operating System(Win/Linux/Mac): ";
    cin>>os;
    os[0]=toupper(os[0]);
	ifstream file("data.txt");
    while(getline(file, line)) {
    	if(strword(11, line) == os){
    	cout << line << endl;
    }}file.close();entercontinue();start();
}

void Inventory::searchid(){
    string line;
	int id;
    cout<<"Enter ID: ";cin>>id;
	ifstream file("data.txt");
    while(getline(file, line)) {
    	if(strword(3, line) == to_string(id)){
    	cout << line << endl;
    }}file.close();entercontinue();start();
}
void Inventory::searchcomputer(){
	int c;
	cout<<"Search By:"
		<<"\n1. ID"
		<<"\n2. Hard disk type"
		<<"\n3. OS"
		<<"\n4. Price range"
		<<"\n5. Screensize"
		<<"\n6. Number of CPU/GPU"
		<<"\nEnter selection(1 - 6): ";
	cin >> c;
	if(c < 1 || c > 6){//check whether user entered valid number
		do{
			cout<<"Enter valid selection(1 - 6): ";//do until user enters valid number
			cin >> c;
		}while(c < 1 || c > 6);
	}
	switch(c) {
		case 1: searchid();break;
		case 2: searchhdtype();break;
		case 3: searchos();break;
		case 4: searchprice();break;
		case 5: searchss();break;
		case 6: searchngcpu();break;
		default:break;
	}entercontinue();start();
}

void Inventory::removecomputer(){
    string line;
    int cpumodel;
    cout<<"Computer ID to delete: ";
    cin>>cpumodel;
	ifstream file("data.txt");
	ofstream outfile("temp.txt", ofstream::out);
	while(getline(file, line)) {
	if (strword(3, line) != to_string(cpumodel)){
		outfile << line << "\n";
	}else if(strword(3, line) == to_string(cpumodel)){
		cout << line << "\n";
		cout << "This record was deleted.\n";
	}
	}
	outfile.close();
	file.close();
	remove("data.txt");
	rename("temp.txt", "data.txt");
	entercontinue();start();
}

void Inventory::addcomputer(){
	int c;
	cout<<"Choose Computer to add"
		<<"\n1. Laptop"
		<<"\n2. Desktop"
		<<"\n3. Server"
		<<"\nEnter selection(1 - 3): ";
	cin >> c;
	if(c < 1 || c > 3){//check whether user entered valid number
		do{
			cout<<"Enter valid selection(1 - 7): ";//do until user enters valid number
			cin >> c;
		}while(c < 1 || c > 3);
	}
	int id=0,hdcap=0,ncpu=0,ngc=0,memory=0;
	string cpu1,cpu2,gc1,gc2,hdtype,os,manufacturer;
	double screensize=0,price=0;
	Computer cc(id,cpu1,cpu2,gc1,gc2,memory,hdtype,hdcap,os,price);
	cout<<"Enter:\nID(numbers only): "<<flush;int i;cin >> i;id=cc.checkid(i);
	cout<<"CPU Brand: "<<flush;cin >> cpu1;cpu1[0] = toupper(cpu1[0]);
	cout<<"CPU Model: "<<flush;cin >> cpu2;cpu2[0] = toupper(cpu2[0]);
	cout<<"Graphics Card Brand: "<<flush;cin >> gc1;gc1[0] = toupper(gc1[0]);
	cout<<"Graphics Card Model: "<<flush;cin >> gc2;gc2[0] = toupper(gc2[0]);
	cout<<"Computer Memory(GB)(numbers only): "<<flush;cin >> memory;
	cout<<"Hard Disk Type(SSD/HDD/SSHD): "<<flush;string h;cin >> h;hdtype=cc.checkhdtype(h);
	cout<<"Hard Disk Capacity(GB)(numbers only): "<<flush;cin >> hdcap;
	cout<<"Operating System(Win/Linux/Mac): "<<flush;string o;cin >> o;os=cc.checkos(o);
	cout<<"Price(Over 100): "<<flush;double p;cin >> p;price=cc.checkprice(p);
	switch(c){
		case 1:{
			Laptop ll(id,cpu1,cpu2,gc1,gc2,memory,hdtype,hdcap,os,price,manufacturer,screensize,ncpu,ngc);
			cout<<"Manufacturer: "<<flush;cin >> manufacturer;manufacturer[0] = toupper(manufacturer[0]);
			cout<<"Screensize(11.1/12/13.3/14/15.6): "<<flush;double s;cin >> s;screensize=ll.checkscreensize(s);
			cout<<"Number of CPU's(Max 1): "<<flush;int r;cin >> r;ncpu=ll.checkngcandncpu(r);
			cout<<"Number of Graphic Cards(Max 1): "<<flush;int t;cin >> t;ngc=ll.checkngcandncpu(t);
			Laptop l(id,cpu1,cpu2,gc1,gc2,memory,hdtype,hdcap,os,price,manufacturer,screensize,ncpu,ngc);
			ofstream outfile("data.txt", ios_base::app);
			outfile << "Laptop,"<<l.getid()<<","<<l.getcpubrand()<<","<<l.getcpumodel()<<","<<l.getgcbrand()<<","<<l.getgcmodel()<<","<<l.getmemory()<<","<<l.gethdtype()<<","<<l.gethdcap()<<","<<l.getos()<<","<<l.getprice()<<","<<l.getmanufacturer()<<","<<l.getscreensize()<<","<<l.getncpu()<<","<<l.getngc()<<"\n";
			cout << "Record added!\n";outfile.close();
		break;}
		case 2:{
			Desktop dd(id,cpu1,cpu2,gc1,gc2,memory,hdtype,hdcap,os,price,0,ncpu,ngc);
			cout<<"Number of CPU's(Max 2): "<<flush;int r;cin >> r;ncpu=dd.checkngcandncpu(r);
			cout<<"Number of Graphic Cards(Max 2): "<<flush;int t;cin >> t;ngc=dd.checkngcandncpu(t);
			Desktop d(id,cpu1,cpu2,gc1,gc2,memory,hdtype,hdcap,os,price,0,ncpu,ngc);
			ofstream outfile("data.txt", ios_base::app);
			outfile << "Desktop,"<<d.getid()<<","<<d.getcpubrand()<<","<<d.getcpumodel()<<","<<d.getgcbrand()<<","<<d.getgcmodel()<<","<<d.getmemory()<<","<<d.gethdtype()<<","<<d.gethdcap()<<","<<d.getos()<<","<<d.getprice()<<","<<d.getscreenn()<<","<<d.getncpu()<<","<<d.getngc()<<"\n";
			cout << "Record added!\n";outfile.close();
		break;}
		case 3:{
			Server ss(id,cpu1,cpu2,gc1,gc2,memory,hdtype,hdcap,os,price,0,manufacturer,ncpu,ngc);
			cout<<"Manufacturer: "<<flush;cin >> manufacturer;manufacturer[0] = toupper(manufacturer[0]);
			cout<<"Number of CPU's(Max 4): "<<flush;int r;cin >> r;ncpu=ss.checkngcandncpu(r);
			cout<<"Number of Graphic Cards(Max 4): "<<flush;int t;cin >> t;ngc=ss.checkngcandncpu(t);
			Server s(id,cpu1,cpu2,gc1,gc2,memory,hdtype,hdcap,os,price,0,manufacturer,ncpu,ngc);
			ofstream outfile("data.txt", ios_base::app);
			outfile << "Server,"<<s.getid()<<","<<s.getcpubrand()<<","<<s.getcpumodel()<<","<<s.getgcbrand()<<","<<s.getgcmodel()<<","<<s.getmemory()<<","<<s.gethdtype()<<","<<s.gethdcap()<<","<<s.getos()<<","<<s.getprice()<<","<<s.getscreenn()<<","<<s.getmanufacturer()<<","<<s.getncpu()<<","<<s.getngc()<<"\n";
			cout << "Record added!\n";outfile.close();
		break;}}entercontinue();start();
}

void Inventory::start(){
	int c;
	cout<<"---------------------------------"
		<<"\n Computer Store Main Menu"
		<<"\n---------------------------------"
		<<"\n1. Search Computers"
		<<"\n2. Add Computer"
		<<"\n3. Remove Computer"
		<<"\n4. Display All Computers"
		<<"\n5. Exit"
		<<"\nEnter selection(1 - 6): ";
	cin >> c;
	if(c < 1 || c > 6){//check whether user entered valid number
		do{
			cout<<"Enter valid selection(1 - 6): ";//do until user enters valid number
			cin >> c;
		}while(c < 1 || c > 6);
	}
	switch(c) {
		case 1: searchcomputer();break;
		case 2: addcomputer();break;
		case 3: removecomputer();break;
		case 4: showcomputersfromfile();break;
		case 5: cout<<"Goodbye";_Exit(1);break;
		default:break;
	}
}
