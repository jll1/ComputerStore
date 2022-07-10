#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
using namespace std;
class Inventory{
public:
string strword(int index, string line);
void entercontinue();
void searchhdtype();
void searchss();
void searchngcpu();
void searchprice();
void searchos();
void searchid();
void searchcomputer();
void removecomputer();
void addcomputer();
void showcomputersfromfile();
void start();
};
#endif
