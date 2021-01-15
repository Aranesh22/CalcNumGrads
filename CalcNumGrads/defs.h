#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_STR 32 
#define MIN_YR 2010 
#define MAX_YR 2017
/*  
  struct: OECD
  Purpose:  This structs hold all data for all the reports in the lists 
  	    and where the same varaibles are used for differnt reports making it 
  	    convienent. 
*/   

typedef struct { 
 
	char  countryCode[MAX_STR];
  	char  countryName[MAX_STR]; 
  	char  gender[MAX_STR]; 
  	char degree[MAX_STR]; 
  	int year;  
  	int topL6Yr,topL7Yr,topL8Yr; 
  	float numGrads;  
  	float L6,L7,L8; 
  	float totalGradsCount; 
  	float ft;   
  	float tY14,tY15,tY16,tY17;  
  	float growPer; 
  	char growName[MAX_STR]; 
  	 
}OECD;  
 
/*  
  struct: NodeType
  Purpose:  This structs allows the usage of pointing to 
  	    previous and next nodes in the list by creating structs of the node. 
*/   
typedef struct Node { 

	OECD *data; 
  	struct Node *prev;
  	struct Node *next; 
  	
}NodeType;  

 
/*  
  struct: ReportType
  Purpose:  This structs allows the usage of pointing to 
  	    to head and tail of a doubly linked list by making instances 
  	    of it. 
*/   
typedef struct List{ 

 	NodeType *head;
  	NodeType *tail;
}ReportType;  

void loopList(ReportType *list,int RNUM);
void growthOfDegReport();
void highestDegReport();
void rangeReport();
void femalePercentage();
void gradPercentage();
void printGrowthOfDegReport(const OECD *cGpr);
void printHighestDegReport(const OECD *hpr);
void initCalculateGrowthOfDegReport(char *cn, float growthPer, char *change, OECD **changePtr); 
void calculateGrowthOfDegReport(ReportType *listOne,ReportType *growthOfDegReport,char *deg,int yearFirst,int yearSecond,int rNum);
void initHighestDegReport(char *cn, float pHL6, float pHL7,float pHL8,int l6Yr, int l7Yr, int l8Yr,OECD **highYr); 
void calculateHighestDegReport(ReportType *listOne, ReportType *highestDegReport,int rNum);
void printRRPercentage(const OECD *rp);
void initRangePercentage(char *cn, float totalY14, float totalY15,float totalY16,float totalY17, OECD **rp);
void calculateRangePercentage(ReportType *listOne,ReportType *rangeReport,int rNum); 
void readFile(ReportType *listOne); 
void intitList(char *cc, char *cn, char *gen, char *deg, int y, float g, OECD **o); 
void addtoList(ReportType *list, OECD *o,int rNum); 
void initGradPercentList(char *cn, float valL6,float valL7, float valL8,float totalGrads,OECD **cpoint); 
void calcGradPercentage(ReportType *listOne,ReportType *gradp, int rNum);
void printGradPercentage(const OECD *cp);
void printFemalePercentage(const OECD *cp);
void loopFemalePercentage(ReportType *list);
void calculateFemalePercentage(ReportType *listOne,ReportType *femalePercentage,int rNum); 
void initfemalePercentage(char *cn, float femalecountPercent, OECD **fp);
void cleanUpList(ReportType* list);
