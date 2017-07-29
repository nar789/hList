/*
*-- Copyright 2017 all rights reserved by (c)HUME
*-- Written by Junghun,Lee
*-- HList
*-- July 29, 2017
*/
#include "hList.h"

int main(int argc,char* argv[])
{
	if (argc > 0) {
		string k = argv[0];
		string title = k.substr(k.find_last_of('\\') + 1, k.size());
		cout<<endl<<"\t"<<"["<< title.c_str() << "]"<<endl<<endl;
	}
	
	hList list;
	for (int i = 1; i <= 7; i++) {list + D(i, i);}
	cout << list << endl;

	list--;
	cout << list << endl;

	--list;
	cout << list << endl;

	for (E i : list) {
		cout << i << endl;
	}
	return 0;
}







