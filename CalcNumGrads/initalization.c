#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "defs.h"  

/*  
  Function: initCalculateGrowthOfDegReport()
  Purpose:  The purpose of this function of the function is to store the data of the Growth degree report into 
  	    the data types for everytime theres a new country that needs to be stored in the list 
      in:   the country name, the percent of growth or decesase, a char indicating the year change increased or decreased and an a double pointer to the OECD struct
      out:  a pointer of the new OECD struct is returned out
*/ 

void initCalculateGrowthOfDegReport(char *cn, float gPer, char *changeG, OECD **changePtr) { 

	OECD *cPtr = calloc(1,sizeof(OECD)); 
	strcpy((cPtr)->countryName, cn);  
	(cPtr)-> growPer = gPer; 
	strcpy((cPtr)->growName, changeG);  
	(*changePtr) = cPtr;  

}  

/*  
  Function: initHighestDegReport()
  Purpose:  The purpose of this function is to store the data of the Highest Year degree report  
  	    into the data types for every new country that is passed in.
      in:   the country name, each percentage for each degree andthe coresponding year and a double pointer 
      out:  a pointer of the new OECD struct is returned out
*/ 
void initHighestDegReport(char *cn, float pHL6, float pHL7,float pHL8,int l6Yr, int l7Yr, int l8Yr,OECD **highYr) { 

	OECD *highestYrPtr = calloc(1,sizeof(OECD));  
	strcpy((highestYrPtr)->countryName, cn); 
	(highestYrPtr)->L6 = pHL6;  
	(highestYrPtr)->L7 = pHL7; 
	(highestYrPtr)->L8 = pHL8; 
	(highestYrPtr)->topL6Yr = l6Yr; 
	(highestYrPtr)->topL7Yr = l7Yr;  
	(highestYrPtr)->topL8Yr = l8Yr; 
	(*highYr) = highestYrPtr;  

} 

/*  
  Function: initRangePercentage()
  Purpose:  The purpose of this function is to store the data into the RangeReport for the years of 2014 to 2017  
  	    into the data types for every new country that is passed in.
      in:   the country name, each percentage of each year from 2014 to 2017, and a double pointer of OECD data 
     out:  a pointer of the new OECD struct is returned out
*/  
void initRangePercentage(char *cn, float totalY14, float totalY15,float totalY16,float totalY17, OECD **rp) { 

	OECD *rangePer = calloc(1,sizeof(OECD)); 
	strcpy((rangePer)->countryName, cn);   
	(rangePer)->tY14 = totalY14; 
	(rangePer)->tY15 = totalY15; 
	(rangePer)->tY16 = totalY16; 
	(rangePer)->tY17 = totalY17; 
	(*rp)= rangePer;

} 

/*  
  Function: initfemalePercentage()
  Purpose:  The purpose of this function is to store the data of the female perentage report 
  	    into the the data types for every new country thats passed in.
      in:   the country name, each percentage, and a double pointer of OECD data 
      out:  a pointer of the new OECD struct is returned out
*/  
void initfemalePercentage(char *cn, float femalecountPercent, OECD **fp) { 

	OECD *femalePer = calloc(1,sizeof(OECD)); 
	strcpy((femalePer)->countryName, cn);  
	(femalePer) ->ft = femalecountPercent;   	  
	(*fp)= femalePer;

}  

/*  
  Function: initgradpercentList()
  Purpose:  The purpose of this function is to store the data of the gradpercentList report 
  	    into the data types for every new country thats passed in. 
      in:   the country name, the percentage for bachelors, the percentage for Master's, the percentage of Doctorate, 
      	    the percentage of the total degrees and a double pointer of the OECD data struct
      out:  a pointer of the new OECD struct is returned out
*/  
void initGradPercentList(char *cn, float valL6,float valL7, float valL8, float tGrads, OECD **cpoint) { 

	OECD *cp = calloc(1,sizeof(OECD)); 
	strcpy((cp)->countryName, cn);  
	(cp) ->L6 = valL6;  
	(cp) ->L7 = valL7;   
	(cp) ->L8 = valL8;   
	(cp) ->totalGradsCount = tGrads;
	(*cpoint) = cp; 

}  

/*  
  Function: intitList()
  Purpose:  The purpose of this function is to store the new data of the graduate data from 
  	    the grad.data file into the data types for every new line that has data is 
  	    when this function will be called. 
      in:   the country code, the country name, the gender, the degree, the year, the number of grades, and a double pointer of OECD
      out:  a pointer of the new OECD struct is returned out
*/  
void intitList(char *cc, char *cn, char *gen, char *deg, int y, float g, OECD **o) { 

	OECD *new_O = calloc(1,sizeof(OECD));  
	strcpy((new_O)->countryCode, cc);   
	strcpy((new_O)->countryName, cn);   
	strcpy((new_O)->gender, gen);   
	strcpy((new_O)->degree, deg);  
	(new_O) ->year = y;  
	(new_O) ->numGrads = g; 
	
	(*o) = new_O; 

} 

/*  
  Function: addtoList()
  Purpose:  This function is a reused function that is used by all the reports  
  	    .This function adds the data that was saved in those init functions 
  	    for that particular report for each country into a doubly linked list. 
       in:  The report list, that data that will be added to the report and the repot number 
      out:  Initalizes data into the linked list 
*/   
void addtoList(ReportType *list, OECD *o,int rNum) {  

	NodeType *currNode;
	NodeType *prevNode;
  	NodeType *newNode; 
   
  	currNode = list->head;
        prevNode = NULL; 
        
  	while(currNode!=NULL) { 
  	
  		if (rNum == 2 && currNode->data->ft > o->ft) { 
  		
  			break; 
  		
  		} 
  		
  		if(rNum == 5 && currNode->data->growPer < o->growPer) {  
  		
  			break;
  		
  		}

		prevNode = currNode;
    		currNode = currNode->next;
	
 	} 
 	
  	newNode = malloc(sizeof(NodeType));
  	newNode->data = o;
  	newNode->prev = NULL;
 	newNode->next = NULL;
  	
  	if(prevNode == NULL){ 

        	list->head = newNode;
  	}
 	else{
        	prevNode->next = newNode;
  	} 
  	
 
 	newNode->next = currNode;
  	newNode->prev = prevNode; 
  	
  	if(currNode!=NULL){
    		currNode->prev = newNode;
  	} 
  	
  	while(currNode!=NULL) { 

		prevNode = currNode;
    		currNode = currNode->next; 
	
 	} 
 
 	list->tail = prevNode;  

}  
