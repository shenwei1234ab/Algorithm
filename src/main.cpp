//============================================================================
// Name        : thread2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "KMP.h"
#include "AC.h"
#include "stateTest.h"
#include <iostream>
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

void test_fsm() {
	char input_string[80];
	printf("Enter input expression: ");
	scanf("%s", input_string);

	Fsm fsm;
	fsm.Reset();
	int index = 0;
	fsm.Advance(input_string[index++]);

	while (!fsm.EndState() && !fsm.DoomState())
		fsm.Advance(input_string[index++]);

	if (fsm.EndState())
		printf("\nValid input expression");
	else
		printf("\nInvalid input expression");
}

int main(int argc, char **argv)
{
	
	system("pause");
}

