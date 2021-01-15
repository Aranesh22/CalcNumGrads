#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "defs.h"   

/*  
  Function: loopList()
  Purpose:  The purpose of this function based on the report number that is passed in the the while loop will traverse through 
  	    the list that is passed in and call the certain print function based on the report number that is passed in. 
      in:   A pointer to the Report type and an int of the report number 
      out:  print out the report data based on the report number
*/
void loopList(ReportType *list,int RNUM) {  

	NodeType *currNode = list->head;
  	NodeType *prevNode = NULL;  
  	
 	while (currNode != NULL) {  
 	
 		if(RNUM ==1) {  
 		
 			printGradPercentage(currNode ->data);
 		
 		} 
 		else if (RNUM ==3) { 
 		
 			 printRRPercentage(currNode->data); 
 		
 		} 
 		
 		else if (RNUM ==4) { 
 		
 			printHighestDegReport(currNode ->data); 
 		
 		} 
 		
 		else if (RNUM ==5){ 
 		
 			printGrowthOfDegReport(currNode ->data); 
 		
 		}
   		
   		//printf("-- %5s\n",currNode->data->countryCode);
   		prevNode = currNode;
    		currNode  = currNode->next;
  	} 

	

}

/*  
  Function: loopFemalePercentage()
  Purpose:  The purpose of this function of the function is traverse to  
  	    only the female graduate percentage report by printing the first bottom 5 of the list  
  	    and then the top five of the list.
      in:   A pointer to the Report type
      out:  Print out the header of each report and the data for the female graduate percentage list
*/

void loopFemalePercentage(ReportType *list) { 

	printf("Bottom FIVE OF FEMALE GRADUATES\n");  
	printf("%23s   %25s \n","Country","Female Graduates %");    
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
	NodeType *currNode = list->head;
  	NodeType *prevNode = NULL;   
  	
  	int count =0; 
  	
 	while (currNode != NULL) {  
 	
 		if(count <5) { 
 		
 			printFemalePercentage(currNode->data); 
 			
 		} 
 		
   		prevNode = currNode;
    		currNode = currNode->next; 
    		count++;
  	}  
  	
  	printf("\n");  
  	  	
  	printf("TOP FIVE OF FEMALE GRADUATES\n");  
	printf("%23s   %25s \n","Country","Female Graduates %");    
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
  	count =0; 
  	currNode = prevNode;  
  	
  	while (currNode != NULL) {  
 	
 		if(count <5) { 
 		
 			printFemalePercentage(currNode->data); 
 			
 		} 
 		else {
 		
 			break; 
 		}
   		
    		currNode = currNode->prev; 
    		count++;
  	}  

} 

