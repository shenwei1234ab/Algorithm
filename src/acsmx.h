/*
**   ACSMX.H
**
**
*/
#ifndef ACSMX_H
#define ACSMX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//snort中的入侵检测
/*
*   Prototypes
*/
#define ALPHABET_SIZE    256     
#define MAXLEN 256

#define ACSM_FAIL_STATE   -1     

typedef struct _acsm_pattern {

	struct  _acsm_pattern *next;
	unsigned char         *patrn;
	unsigned char         *casepatrn;
	int      n;
	int      nocase;
	void   * id;
	int         nmatch;

} ACSM_PATTERN;


typedef struct  {

	/* Next state - based on input character */
	int      NextState[ALPHABET_SIZE];

	/* Failure state - used while building NFA & DFA  */
	int      FailState;

	/* List of patterns that end here, if any */
	ACSM_PATTERN *MatchList;

}ACSM_STATETABLE;


/*
* State machine Struct
*/
typedef struct {

	int acsmMaxStates;
	int acsmNumStates;

	ACSM_PATTERN    * acsmPatterns;				//原始的数据链表 
	ACSM_STATETABLE * acsmStateTable;

}ACSM_STRUCT;

/*
*   Prototypes
*/
ACSM_STRUCT * acsmNew();
int acsmAddPattern(ACSM_STRUCT * p, unsigned char * pat, int n, int nocase);
int acsmCompile(ACSM_STRUCT * acsm);
int acsmSearch(ACSM_STRUCT * acsm, unsigned char *Tx, int n, void(*PrintMatch) (ACSM_PATTERN * pattern, ACSM_PATTERN * mlist, int nline, int index));
void acsmFree(ACSM_STRUCT * acsm);
void PrintMatch(ACSM_PATTERN * pattern, ACSM_PATTERN * mlist, int nline, int index);
void PrintSummary(ACSM_PATTERN * pattern);

#endif