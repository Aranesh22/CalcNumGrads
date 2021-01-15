#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "defs.h" 


/*  
  Function: main()
  Purpose:  The purpose of this program is to provide the user with reports of graduate data 
  	    where these reports display data of main percetnages of certain factual reports. 
  Author:  Aranesh Athavan 
*/   
int main() { 

	char userC[MAX_STR];  
   	 
	while(1) { 
	
		printf("~~~~~WELCOME TO OECD REPORTS PLEASE SELECT NUMBERS ONE TO FIVE INCLUSIVELY FOR A REPORT THAT  WILL TO BE DISPLAYED~~~~~\n\n"); 
		printf("INPUT 1 -> The graduate percentage for all years and all genders by degree.\n\n");
		printf("INPUT 2 -> The graudate percentage of females graduates of top 5 and bottom 5 for each country for all years and all degrees.\n\n"); 
		printf("INPUT 3 -> The graduate percentage from year 2014 to 2017 for each country, for all degrees and all genders\n\n");  
		printf("INPUT 4 -> The year highest graduate percent within the country and within there degree for all genders\n\n");  
		printf("INPUT 5 -> The growth percentage of a degree within the country from a year to the following year, where the user inputs the years and degree \n\n"); 
	
		printf("INPUT A NUMBER AND ENTER -1 TO EXIT-> "); 
		scanf("%s",userC); 
		  
		if (strcmp(userC,"1") == 0 || strcmp(userC,"2") == 0 || strcmp(userC,"3") == 0 || strcmp(userC,"4") == 0 || strcmp(userC,"5") == 0)  { 
		
			if(strcmp(userC,"1") == 0 ) { 
			
				gradPercentage(); 
				
			} 
			
			else if(strcmp(userC,"2") == 0 ) { 
			
				femalePercentage(); 
			} 
			
			else if( strcmp(userC,"3") == 0 ) { 
			
				rangeReport();
			} 
			
			else if (strcmp(userC,"4") == 0 ) { 
			
				highestDegReport(); 
			}
			
			else if (strcmp(userC,"5") == 0 ) { 
			
				growthOfDegReport(); 
				
			}
		
	      } 
	      
	      else if(strcmp(userC,"-1") == 0) { 
	      
	      		break;      
	      } 
	      else  { 
		
			printf("Wrong input Please Try Again\n"); 
		
	      } 
	 	
	} 
		
}    

/*  
  Function: cleanUpList()
  Purpose:  The purpose of this function is to clearn up the dynamically allocated memory  
  	    and de allocate it. 
  	in: The lists that need to be de allocated
*/   
void cleanUpList(ReportType* list){ 

	NodeType *currNode;
  	NodeType *nextNode;

  	currNode = list->head;

  	while (currNode != NULL) { 
  	
    		nextNode = currNode->next;
    		free(currNode->data);
    		free(currNode);
    		currNode = nextNode;
 	}


}  

/*  
  Function: readFile()
  Purpose:  The purpose of this function is to read the grad.data 
  	    file and input each record into a list that can hold 
  	    all the record. 
 	in: The list that will hold the record data 
 	out: initatlizaing and adding the list
*/   
void readFile(ReportType *listOne) { 
	
  	FILE *infile;  
  	char  cc[MAX_STR];
  	char  cn[MAX_STR]; 
  	char  gen[MAX_STR]; 
  	char deg[MAX_STR]; 
  	int year; 
  	float numGrads;  
  
  	OECD *o;

  	infile = fopen("grad.dat", "r"); 	 
  
  	if (!infile) {
    		printf("Error: could not open file\n");
    		exit(1);
  	} 
  
  	while (1) { 
  
    		fscanf(infile, "%s %s %s %s %d %f", cc, cn, gen, deg, &year, &numGrads); 
    
    		if (feof(infile)) 
      			break; 
      
    		intitList(cc,cn,gen,deg,year,numGrads,&o);   
    
    		addtoList(listOne,o,1); 
 
  	}  
  
  	fclose(infile);   
}

