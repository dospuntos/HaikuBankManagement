#ifndef ACCOUNTQUERY_H
#define ACCOUNTQUERY_H

#include <iostream>
#include <fstream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;

class account_query
{
private:
		char account_number[20];
		char firstName[10];
		char lastName[10];
		float total_Balance;
		
public:
		void read_data();
		void show_data();
		void write_rec();
		void read_rec();
		void search_rec();
		void edit_rec();
		void delete_rec();	
};

#endif
