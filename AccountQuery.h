#ifndef ACCOUNTQUERY_H
#define ACCOUNTQUERY_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <String.h>

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
		status_t show_data(BString &target);
		void write_rec();
		status_t read_rec(BString &target);
		void search_rec();
		void edit_rec();
		void delete_rec();	
};

#endif
