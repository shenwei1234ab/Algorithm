#ifndef _AC_H
#define _AC_H
#include <string>
#include "acsmx.h"
#include <list>
//http://blog.csdn.net/joylnwang/article/details/6793192
// http://www.hankcs.com/program/algorithm/implementation-and-analysis-of-aho-corasick-algorithm-in-java.html
/*
*  Text Data Buffer
*/
unsigned char text[MAXLEN];
extern int nline;
using namespace std;
int acTest(int argc, char **argv)
{
	int i, nocase = 0;
	FILE *fd;
	char filename[20];
	ACSM_STRUCT * acsm;
	/*if (argc < 3)
	{
	fprintf(stderr, "Usage: acsmx filename pattern1 pattern2 ...  -nocase\n");
	exit(0);
	}*/
	acsm = acsmNew();
	//strcpy(filename, argv[1]);
	fd = fopen("actext", "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Open file error!\n");
		exit(1);
	}
	//for (i = 1; i < argc; i++)
	//	if (strcmp(argv[i], "-nocase") == 0)
	nocase = 1;
	/*for (i = 2; i < argc; i++)
	{
	if (argv[i][0] == '-')
	continue;
	acsmAddPattern(acsm, argv[i], strlen(argv[i]), nocase, argv[i]);
	}*/
	std::list<std::string> patterList;

	patterList.push_back("hers");
	patterList.push_back("his");
	patterList.push_back("she");
	patterList.push_back("he");
	for (auto it = patterList.begin(); it != patterList.end(); ++it){
		acsmAddPattern(acsm, (unsigned char *)it->c_str(), it->length(), nocase);
	}
	/* Generate GtoTo Table and Fail Table */
	acsmCompile(acsm);

	/*Search Pattern*/
	while (fgets((char *)text, MAXLEN, fd))
	{
		acsmSearch(acsm, text, strlen((char *)text), PrintMatch);
		nline++;
	}

	PrintSummary(acsm->acsmPatterns);

	acsmFree(acsm);

	printf("\n### AC Match Finished ###\n");
	system("pause");

	return (0);
}






#endif