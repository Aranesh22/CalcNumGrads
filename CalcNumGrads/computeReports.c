#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "defs.h"   

/*  
  Function: gradPercentage()
  Purpose:  To initialize the report types in the functions which is the list that holds 
  	    the data for the grad.dat file and a list that holds the data for report one.  
  	    Based on the requirements for report one that report 
  	    is made in the calcgradPercentage function. The function then prints out report one.
       out: Prints the head for report one 
*/

void gradPercentage() { 

	ReportType listOne; 
	listOne.head = NULL;  
	listOne.tail = NULL;  
	
	ReportType gradp;   
  	gradp.head = NULL;  
	gradp.tail = NULL;  
	  
  	readFile(&listOne);  
  	
  	printf("REPORT OF THE GRADUATE PERCENTAGE FOR ALL YEAR AND ALL GENDERS BY DEGREE\n"); 
  	calcGradPercentage(&listOne,&gradp,1);   
  	printf("%24s %22s %21s %22s %21s\n","Country Name","Bachelors","Master's","Doctorate","All Degrees");  
  	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  	loopList(&gradp,1);   

	cleanUpList(&listOne); 
	cleanUpList(&gradp); 

}   

/*  
  Function: femalePercentage()
  Purpose:  To initialize the report types in the functions which is the list that holds 
  	    the data for the grad.dat file and a list that holds the data of the report for female graduate percentage  
  	    Based on the requirements for report of female graduate percentage that report 
  	    is made in the calculateFemalePercentage function. The function then prints out report and clean the report types that were made.
       out: Prints the header for the table of report for female graduate percentage.
*/
void femalePercentage() { 

	ReportType listOne; 
	listOne.head = NULL;  
	listOne.tail = NULL; 
	
	ReportType femalePercentage; 
  	femalePercentage.head = NULL; 
  	femalePercentage.tail = NULL;
  	
  	readFile(&listOne);   
  	
  	
  	calculateFemalePercentage(&listOne,&femalePercentage,2);  
  	loopFemalePercentage(&femalePercentage);   
  	
  	cleanUpList(&listOne); 
	cleanUpList(&femalePercentage);   

} 

/*  
  Function: rangeReport() 
  Purpose:  To initialize the report types in the functions which is the list that holds 
  	    the data for the grad.dat file and a list that holds the data of the report for the range of 2014 to 2017  
  	    graduate students Based on the requirements for that report
  	    is made in the calculateRangePercentage function. The function then prints out the report and cleans 
  	    the report types that were made.
       out: Prints the header for the table of range Report,
*/
void rangeReport() { 

	ReportType listOne; 
	listOne.head = NULL;  
	listOne.tail = NULL;  
	
	ReportType rangeReport; 
  	rangeReport.head = NULL; 
  	rangeReport.tail = NULL;  
  	
  	readFile(&listOne);  
  	
  	printf("REPORT OF THE GRADUATE PERCENTAGE FROM YEAR 2014 TO 2017\n"); 
  	printf("%24s %20s %21s %21s %21s\n","Country Name","2014","2015","2016","2017");  
  	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  	calculateRangePercentage(&listOne,&rangeReport,3); 
  	loopList(&rangeReport,3);  

	cleanUpList(&listOne); 
	cleanUpList(&rangeReport); 

}

/*  
  Function: highestDegReport()
  Purpose:  To initialize the report types in the functions which is the list that holds 
  	    the data for the grad.dat file and a list that holds the data of the report of 
  	    of the year of the highest number of grads for each degree for each country. That report 
  	    is made in the calculateHighestDegReport function. The function then prints out the report and cleans 
  	    the report types that were made. 
       out: Prints the header for the table of the highest degree report,
*/
void highestDegReport() { 

	ReportType listOne; 
	listOne.head = NULL;  
	listOne.tail = NULL;   
	
	ReportType highestDegReport; 
  	highestDegReport.head = NULL; 
  	highestDegReport.tail = NULL;  
  	
  	readFile(&listOne);     
	
	printf("REPORT OF THE YEAR OF THE HIGHEST GRADUATE PERCENTAGE WITHIN THE COUNTRY FOR EVERY DEGREE\n"); 
	printf("%24s %25s %27s %27s \n","Country Name","Bachelors","Master's","Doctorate");  
  	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	calculateHighestDegReport(&listOne,&highestDegReport,4);   
  	loopList(&highestDegReport,4); 
  	
	cleanUpList(&listOne); 
	cleanUpList(&highestDegReport); 

} 

/*  
  Function: growthOfDegReport()
  Purpose:  To initialize the report types in the functions which is the list that holds 
  	    the data for the grad.dat file and a list that holds the data of the report of 
  	    for each country growth percentage of number of grads of two of a following year. That report 
  	    is made in the calculateGrowthOfDegReport function. The function then prints out the report and cleans 
  	    the report types that were made.  
    input:  The user weather they want to see a bachelors, a Masters or a declorate degree choice. The user then has to input  
    	    the an inital year and a following year. 
      out:  Prints the header for the table of the growth of degree report. 
*/
void growthOfDegReport() { 

	ReportType listOne; 
	listOne.head = NULL;  
	listOne.tail = NULL;    
	
	ReportType growthOfDegReport; 
  	growthOfDegReport.head = NULL; 
  	growthOfDegReport.tail = NULL; 
  	
  	readFile(&listOne); 
  	
  	int degC =0; 
  	char degreeChoice[MAX_STR]; 
  	char outDeg[MAX_STR];  
	printf("INPUT-->1 for Bachelor\nINPUT 2--> for Master's\nINPUT 3--> for Doctorate\n"); 
	while(1) { 
	
		printf("INPUT YOUR CHOICE from 1 to 3 inclusively-> "); 
		scanf(" %d", &degC);  
		
		if ( 1<= degC <=3) {  
			
			if(degC ==1) { 
			
				strcpy(degreeChoice,"L6");  
				strcpy(outDeg,"BACHELOR");
				break;  
			
			}
			else if(degC ==2) {  
			
				strcpy(degreeChoice,"L7");  
				strcpy(outDeg,"MASTERS");
				break; 
			} 
			else if(degC ==3) {  
			
				strcpy(degreeChoice,"L8"); 
				strcpy(outDeg,"DOCTORATE");  
				break; 
			}
			
		} 
		else { 
		
			printf("INPUT WAS NOT IN THE RANGE OF 1 TO 3 INCLUSEIVELY TRY AGAIN!\n"); 
		
		}
	} 
	
	
	int yearF =0, yearS =0,count =0;  
	int yearIn =0; 
	printf("INPUT 2 years from 2010 to 2017, where the second year is ONE AFTER the first year\n"); 
	while(1) { 
	
		if(count ==0) { 
		
			printf("INPUT YOUR CHOICE-> "); 
			scanf(" %d", &yearIn);    
		
		}  
		if (count >0 ) { 
		
		
			printf("INPUT YOUR SECOND CHOICE-> ");  
			scanf(" %d", &yearIn);
		}
		
		if (MIN_YR <= yearIn &&  yearIn <= MAX_YR) {  
			

			if(count ==0) {  
			
				yearF = yearIn; 
				printf("yes\n");  
				printf("%d\n",count);
				 
			}   
			
			else if (count >0) {  
			
				
				if((yearF+1) == yearIn) {  
				
					yearS = yearIn;  
					break; 
				
				} 
				else { 
				
					printf("%d\n",count);
					printf("Second year is not one year after the first year PlEASE TRY AGAIN\n"); 
					
				}
			} 
			count++;
				
		}   
		
		else if ( yearIn < 2010 || yearIn > 2017){ 
		
			printf("INPUT WAS NOT IN THE RANGE OF 2010 TO 2017 INCLUSEIVELY TRY AGAIN!\n"); 
		} 
			
	} 
  	
  	printf("%45s %s %s %d %s %d\n","REPORT OF THE GROWTH PERCENTAGE FOR",outDeg,"DEGREE FROM",yearF,"to",yearS);   
 	printf("%24s %29s %27s\n","Country Name","Growth Percentage","Increased/Decreased");  
  	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  	calculateGrowthOfDegReport(&listOne,&growthOfDegReport,degreeChoice,yearF,yearS,5);  
  	loopList(&growthOfDegReport,5); 

	cleanUpList(&listOne); 
	cleanUpList(&growthOfDegReport); 

}
