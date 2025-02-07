#include <iostream>
#include <string>

#ifndef CHARSTRTONUMBER_H
#define CHARSTRTONUMBER_H

using namespace std;

int charToNumber(char c) {
    return c - '0';
}

int stringToNumber(string palabra){
	int total=0;
	for(char i: palabra){
		total+=charToNumber(i);
	}
	return total;
}


#endif
