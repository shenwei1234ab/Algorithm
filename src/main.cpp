//============================================================================
// Name        : thread2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <iostream>
#include "KMP.h"
#include "AC.h"
using namespace  std;

int kmpTest(int argc,char *argv[])
{
	//char s[] = "DABCDABDE";
	char s[] = "DABCDABDE";
	int length = strlen(s);
	int *p = new int[length];
	GetNext(s, p);
	for (int i = 0; i < length; ++i){
		std::cout << p[i] << ",";
	}
	getchar();
	return 0;
}


int main(int argc, char **argv)
{
	acTest(argc, argv);
	system("pause");
}

