#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "defs.h"    

/*  
  Function: calculateGrowthOfDegReport()
  Purpose:  The purpose of this function is to calculate the percentage growth of the function  
  	    based on the users input of degree and years for all genders. Then populating everything in the  
  	    into the list for this report. 
       in:  records list, the list that will be populated for the report of the growth percentge, the degree, the two years and the report number 
      out:  initalization of the growth perceentage list
*/
void calculateGrowthOfDegReport(ReportType *listOne,ReportType *growthOfDegReport,char *deg,int yearFirst,int yearSecond,int rNum) { 

	NodeType *currNode = listOne->head;
  	NodeType *prevNode = NULL;  
  	
  	float valuYrFirst =0, valuYrSec =0, growthPer =0;  
  	char change[MAX_STR]; 
  	
  	char temp_n[MAX_STR];  
  	strcpy(temp_n,currNode->data->countryName);    
  	
  	OECD *growthChangePer; 
 	while (currNode != NULL) {   
 	
 		if(strcmp(temp_n,currNode->data->countryName) == 0) {   
 		
  			if ((strcmp(currNode->data->degree,deg) == 0) &&  (strcmp(currNode->data->gender,"T") == 0) && (currNode->data->year == yearFirst) ) { 
  				 valuYrFirst = currNode->data->numGrads; 
  			} 
  	
  			else if ((strcmp(currNode->data->degree,deg) == 0) && (strcmp(currNode->data->gender,"T") == 0) && (currNode->data->year == yearSecond) )  { 		
  				valuYrSec  = currNode->data->numGrads; 
  			} 
  			
 		} 
 		
 		else if (strcmp(temp_n,currNode->data->countryName) != 0)  {  
 		
 			if( valuYrFirst==0 || valuYrSec ==0) { 
 			
 				strcpy(change,"NO DATA");  
 				growthPer = 0; 
 			
 			} 
 			else if ( valuYrFirst > 0 && valuYrSec >0) {  
 		  		
 				if ((valuYrSec -valuYrFirst) > 0) { 
 			
 					growthPer = ((valuYrSec -valuYrFirst)/valuYrFirst) *100; 
 					strcpy(change,"INCREASED");     		
 			
 				} 
 			
 				else if ((valuYrSec -valuYrFirst) < 0) {   
 				
 					growthPer = (((valuYrFirst -valuYrSec)/valuYrFirst) *-100); 
 					strcpy(change,"DECREASED");     
 			
 				} 
 				
 			} 
 			
 			initCalculateGrowthOfDegReport(temp_n,growthPer,change,&growthChangePer); 
 			addtoList(growthOfDegReport,growthChangePer,rNum);  
 			strcpy(temp_n,currNode->data->countryName);   
 			
  			if ((strcmp(currNode->data->degree,deg) == 0) && (strcmp(currNode->data->gender,"T") == 0) && (currNode->data->year == yearFirst) ) { 
  			
  				 valuYrFirst = currNode->data->numGrads; 
  			} 
  			
  			else if ((strcmp(currNode->data->degree,deg) == 0) && (strcmp(currNode->data->gender,"T") == 0) && (currNode->data->year == yearSecond) ) { 
  			
  				valuYrSec  = currNode->data->numGrads; 
  			
  			}  
 		}  
 		
 		prevNode = currNode;
    		currNode = currNode->next;
 		 		
 	}

	if( valuYrFirst==0 || valuYrSec ==0) { 
 			
 		strcpy(change,"NO DATA");  
 		growthPer = 0; 
 			
 	} 
 	else if ( valuYrFirst > 0 && valuYrSec >0) {  
 			
 		if ((valuYrSec -valuYrFirst) > 0) { 
 			
 			growthPer = ((valuYrSec -valuYrFirst)/valuYrFirst) *100; 
 			strcpy(change,"INCREASED");     	
 			
 		} 
 			
 		else if ((valuYrSec -valuYrFirst) < 0) {   
 				
 			growthPer = (((valuYrFirst -valuYrSec)/valuYrFirst) *-100); 
 			strcpy(change,"DECREASED");     
 			
 		} 
 					
 	}
 	
 	initCalculateGrowthOfDegReport(temp_n,growthPer,change,&growthChangePer); 
 	addtoList(growthOfDegReport,growthChangePer,rNum);  
	 			
} 

/*  
  Function: calculateHighestDegReport()
  Purpose:  The purpose of this function is to find the year of the highest number of grads  
  	    for each degree and to calculate the percentage of that highest degree compared that specific degree of 
  	    that country. 
  	    The functions also populates the list of the highest degree report.
       in:  grad.dat list, the list that will be populated for the report of the years pf Highest Degree, the degree, the report number  
      out:  initalization of the list highest degree report. 
*/
void calculateHighestDegReport(ReportType *listOne, ReportType *highestDegReport,int rNum) { 

	NodeType *currNode = listOne->head;
  	NodeType *prevNode = NULL;  
  	
  	char temp_n[MAX_STR];  
  	strcpy(temp_n,currNode->data->countryName);   
 		
 	float temp_L6 =0,temp_L7 =0,temp_L8 =0; 
 	int l6Yr =0,l7Yr =0,l8Yr =0;   
 	float total6C =0,total7C =0,total8C =0;  
 	float pHL6 =0, pHL7 =0, pHL8 =0;
 	OECD *highYr;  
 	
 	while (currNode != NULL) {  
 	
 		if(strcmp(temp_n,currNode->data->countryName) == 0) {   
  		
  			if ((strcmp(currNode->data->degree,"L6") == 0) && (strcmp(currNode->data->gender,"T") == 0) && (currNode->data->numGrads !=0) ) {  
			
				if(temp_L6 < (currNode->data->numGrads) ) {  
		
					temp_L6 = currNode->data->numGrads; 
					l6Yr = currNode->data->year; 
								
				} 
				
				total6C += currNode->data->numGrads;   
		
			} 
			
			else if ((strcmp(currNode->data->degree,"L7") == 0) && (strcmp(currNode->data->gender,"T") == 0) && (currNode->data->numGrads !=0) ) {  
			
				if(temp_L7 < (currNode->data->numGrads) ) {   

				
					temp_L7 = currNode->data->numGrads; 
					l7Yr = currNode->data->year; 
								
				} 
				
				total7C += currNode->data->numGrads;   
					
			} 
			
			
			else if ((strcmp(currNode->data->degree,"L8") == 0) && (strcmp(currNode->data->gender,"T") == 0) && (currNode->data->numGrads !=0) ) {  
			
				if(temp_L8 < (currNode->data->numGrads) ) {  
				

					temp_L8 = currNode->data->numGrads; 
					l8Yr = currNode->data->year; 
								
				} 
				
				total8C += currNode->data->numGrads;   
					
			} 	 	 		
  		} 
  		
  		else if (strcmp(temp_n,currNode->data->countryName) != 0)  { 
  		
			if(temp_L6 ==0 || total6C == 0) { 
			
				pHL6 =0; 
				l6Yr = 0; 
			}   
			else { 
			
				pHL6 =  (temp_L6/total6C)*100;  
			
			
			}
			
			if (temp_L7 ==0 || total7C == 0) { 
			
				pHL7 =0; 
				l7Yr = 0;  
			
			} 
			else { 
			
				pHL7 =  (temp_L7/total7C)*100;
			
			}
 				
 			if (temp_L8 ==0 || total8C == 0) { 
 			
 				pHL8 =0; 
 				l8Yr = 0;  
 			
 			} 
 			else { 
 			
 				pHL8 =  (temp_L8/total8C)*100; 
 			
 			} 
 						
  			initHighestDegReport(temp_n,pHL6,pHL7,pHL8,l6Yr,l7Yr,l8Yr,&highYr);  
  			addtoList(highestDegReport,highYr,rNum);  
  			strcpy(temp_n,currNode->data->countryName);   
 
 	 		total6C =0,
 	 		total7C =0,
 	 		total8C =0;   
 	 		temp_L6 = 0; 
 	 		temp_L7 =0;
 	 		temp_L8 =0;
 	 		pHL6 = 0; 
 	 		pHL7 = 0;
 	 		pHL8 =0;
  			
  			if ((strcmp(currNode->data->degree,"L6") == 0) && (strcmp(currNode->data->gender,"T") == 0) ) {  
			
				if(temp_L6 < (currNode->data->numGrads) ) {  
				
					temp_L6 = currNode->data->numGrads; 
					l6Yr = currNode->data->year; 
								
				} 
				
				total6C += currNode->data->numGrads;   
		
			} 
			
			else if ((strcmp(currNode->data->degree,"L7") == 0) && (strcmp(currNode->data->gender,"T") == 0) ) {  
			
				if(temp_L7 < (currNode->data->numGrads) ) {  
				
					temp_L7 = currNode->data->numGrads; 
					l7Yr = currNode->data->year; 
								
				} 
				
				total7C += currNode->data->numGrads;   
					
			} 
			
			
			else if ((strcmp(currNode->data->degree,"L8") == 0) && (strcmp(currNode->data->gender,"T") == 0) ) {  
			
				if(temp_L8 < (currNode->data->numGrads) ) {  
				
					temp_L8 = currNode->data->numGrads; 
					l8Yr = currNode->data->year; 
								
				} 
				
				total8C += currNode->data->numGrads;   
					
			} 	
  			
  		} 
  	  			
		prevNode = currNode;
    		currNode = currNode->next;
  		
 	}
		
	if(temp_L6 ==0 || total6C == 0) { 
			
		pHL6 =0; 
		l6Yr = 0; 
	}   
	else { 
			
		pHL6 =  (temp_L6/total6C)*100;  
					
	}
			
	if (temp_L7 ==0 || total7C == 0) { 
			
		pHL7 =0; 
		l7Yr = 0;  
			
	} 
	else { 
			
		pHL7 =  (temp_L7/total7C)*100;
			
	}
 				
 	if (temp_L8 ==0 || total8C == 0) { 
 			
 		pHL8 =0; 
 		l8Yr = 0;  
 			
 	} 
 	else { 
 			
 		pHL8 =  (temp_L8/total8C)*100; 
 			
 	} 
 						
  	initHighestDegReport(temp_n,pHL6,pHL7,pHL8,l6Yr,l7Yr,l8Yr,&highYr);  
  	addtoList(highestDegReport,highYr,rNum);  

}

/*  
  Function: calculateRangePercentage()
  Purpose:  The purpose of this function is to calculate the graduate percent for each year of 2014 
  	    to 2017 compared to all the countries, for all genders all degrees and for each country.  
  	    Then poplate that list report with the calculations made.
       in:  The gradiate data list, the list that will be populated for the report of graduates for year 2014 to 2017, the degree, and the report number   
      out:  initalization of the Range Percentage report list. 
*/

void calculateRangePercentage(ReportType *listOne,ReportType *rangeReport,int rNum) { 

	float yTFourteen = 0;  
	float yTFifteen = 0;  
	float yTSixteen = 0; 
	float yTSeventeen = 0;

	NodeType *currNode = listOne->head;
  	NodeType *prevNode = NULL;  
  	
 	while (currNode != NULL) {  
 	
   		if (strcmp(currNode->data->gender,"T") == 0 && currNode->data->year == 2014) { 
  			
  				yTFourteen += currNode->data->numGrads; 
  			
  		} 
  		else if  (strcmp(currNode->data->gender,"T") == 0 && currNode->data->year == 2015) { 
  				
  				yTFifteen += currNode->data->numGrads;  
  		
  			
  		} 
  		else if (strcmp(currNode->data->gender,"T") == 0 && currNode->data->year == 2016) { 
  			
  				yTSixteen += currNode->data->numGrads;  
  			
  		}
  		
  		else if (strcmp(currNode->data->gender,"T") == 0 && currNode->data->year == 2017) { 
  			
  				yTSeventeen += currNode->data->numGrads; 
  			
  		}
   		
   		
    		prevNode = currNode;
    		currNode = currNode->next; 
  	}   

	float tFourteen = 0, tFifteen = 0, tSixteen = 0, tSeventeen =0, p14 =0, p15 = 0, p16 =0, p17 =0;  
 	currNode = listOne->head;
  	prevNode = NULL;  
  	
  	char temp_n[MAX_STR];  
  	 
  	strcpy(temp_n,currNode->data->countryName);   
  	
  	OECD *rp; 

	while (currNode != NULL) {  
  	
  		if(strcmp(temp_n,currNode->data->countryName) == 0) {   
  			
  			if (strcmp(currNode->data->gender,"T") == 0 && currNode->data->year == 2014) { 
  			
  				tFourteen +=  currNode->data->numGrads; 
  			
  			} 
  			else if  (strcmp(currNode->data->gender,"T") == 0 && currNode->data->year == 2015) { 
  				
  				tFifteen += currNode->data->numGrads;  
  			
  			} 
  			else if (strcmp(currNode->data->gender,"T") == 0 && currNode->data->year == 2016) { 
  			
  				tSixteen += currNode->data->numGrads;  
  			
  			}
  		
  			else if (strcmp(currNode->data->gender,"T") == 0 && currNode->data->year == 2017) { 
  			
  				 tSeventeen += currNode->data->numGrads; 
  			
  			}
  		
  		} 

		else if (strcmp(temp_n,currNode->data->countryName) != 0) {  
		
			p14 = (tFourteen/yTFourteen) *100; 
			p15 = (tFifteen/yTFifteen) *100;  
			p16 = (tSixteen/yTSixteen) *100;  
			p17 = (tSeventeen/yTSeventeen) *100; 
			
			initRangePercentage(temp_n, p14,p15,p16,p17,&rp); 
			addtoList(rangeReport,rp,rNum);   
			
			tFourteen = 0; 
			tFifteen = 0; 
			tSixteen = 0; 
			tSeventeen =0;  
			
			strcpy(temp_n,currNode->data->countryName);  
			
  			if (strcmp(currNode->data->gender,"T") == 0 && currNode->data->year == 2014) { 
  			
  				tFourteen +=  currNode->data->numGrads; 
  			
  			} 
  			else if  (strcmp(currNode->data->gender,"T") == 0 && currNode->data->year == 2015) { 
  				
  				tFifteen += currNode->data->numGrads;  
  			
  			} 
  			else if (strcmp(currNode->data->gender,"T") == 0 && currNode->data->year == 2016) { 
  			
  				tSixteen += currNode->data->numGrads;  
  			
  			}
  		
  			else if (strcmp(currNode->data->gender,"T") == 0 && currNode->data->year == 2017) { 
  			
  				 tSeventeen += currNode->data->numGrads; 
  				 
  			} 
		
		} 
		
		prevNode = currNode;
    		currNode = currNode->next;

	} 

	p14 = (tFourteen/yTFourteen) *100; 
	p15 = (tFifteen/yTFifteen) *100;  
	p16 = (tSixteen/yTSixteen) *100;  
	p17 = (tSeventeen/yTSeventeen) *100; 
			
	initRangePercentage(temp_n, p14,p15,p16,p17,&rp); 
	addtoList(rangeReport,rp,rNum);   
			
}

/*  
  Function: calculateFemalePercentage()
  Purpose:  The purpose of this function is to calculate the female graduate percent of all the years and all  
            degrees compared to all the total graudates of all the degrees of that country.These calculaions are then populated  
            into the report of femalePercentage. 
       in:  The gradiate data list, the list that will be populated for the report of graduates of female percentage, the degree, and the report number   
      out:  initalization of the graduate percentge of females report list. 
*/

void calculateFemalePercentage(ReportType *listOne,ReportType *femalePercentage,int rNum) { 

	float countryT =0, femaleT =0,temp_h =0;
	NodeType *currNode = listOne->head;
  	NodeType *prevNode = NULL;  
  	int tempYear =0;  
  	char temp_n[MAX_STR],temp_deg[MAX_STR];  
  	 
  	strcpy(temp_n,currNode->data->countryName);  
  	
  	OECD *fp; 
  	
  	while (currNode != NULL) {  
  	
  		if(strcmp(temp_n,currNode->data->countryName) == 0) {   
  			
  			if (strcmp(currNode->data->gender,"F") == 0) { 	
  				
  				femaleT += currNode->data->numGrads;  
  				tempYear = currNode->data->year; 
  				strcpy(temp_deg,currNode->data->degree);
  				
  			} 
  			else if  (strcmp(currNode->data->gender,"T") == 0 && (currNode->data->year == tempYear) && (strcmp(currNode->data->degree,temp_deg) == 0) )  {  
  				
  				countryT += currNode->data->numGrads; 
  			
  			}
  		
  		}  
  		
  		else if (strcmp(temp_n,currNode->data->countryName) != 0) { 
  		
  			temp_h = (femaleT/countryT)*100;
  		
  			initfemalePercentage(temp_n,temp_h,&fp); 
			addtoList(femalePercentage,fp,rNum);  
  			
  			countryT =0; 
  			femaleT =0; 
  			temp_h =0;
  			
  			strcpy(temp_n,currNode->data->countryName);  
  			
  			if (strcmp(currNode->data->gender,"F") == 0) { 
  				
  				femaleT += currNode->data->numGrads;  
  				tempYear = currNode->data->year; 
  				strcpy(temp_deg,currNode->data->degree);
  				
  			} 
  			else if  (strcmp(currNode->data->gender,"T") == 0 && (currNode->data->year == tempYear) && (strcmp(currNode->data->degree,temp_deg) == 0) )  {  
  			
  				countryT += currNode->data->numGrads; 
  			
  			}
  			
  		} 
  		
  		prevNode = currNode;
    		currNode = currNode->next;
  	
  	}
	 
	temp_h = (femaleT/countryT)*100; 
	initfemalePercentage(temp_n,temp_h,&fp); 
	addtoList(femalePercentage,fp,rNum);  

} 
/*  
  Function: calcGradPercentage()
  Purpose:  The purpose of this function is to calculate the graduate percentage of all the years for each degree for all genders  
            for each country compared to the total of all genders of number of grads for all the years for that degree. This is data is then 
            porpulated into the 
       in:  The gradiate data list, the list that will be populated for the report of graduates of female percentage, the degree, and the report number   
      out:  initalization of the graduate percentge of each degree for gradPercentage List  
*/

void calcGradPercentage(ReportType *listOne,ReportType *gradp,int rNum) {   
	
	float L6T = 0;  
	float L7T = 0;  
	float L8T = 0; 
	float overallT = 0;
	
	NodeType *currNode = listOne->head;
  	NodeType *prevNode = NULL; 
 	while (currNode != NULL) {  
 
   		
   		if(strcmp(currNode->data->gender,"T") == 0 && strcmp(currNode->data->degree,"L6") == 0 ){ 
  
  			L6T +=(currNode->data->numGrads);    
  			overallT +=(currNode->data->numGrads);
  
 		 }  
 		 
 		 
 		 else if(strcmp(currNode->data->gender,"T") == 0 && strcmp(currNode->data->degree,"L7") == 0 ) { 
  
  			L7T +=(currNode->data->numGrads);    
  			overallT +=(currNode->data->numGrads);
  			
  		}  
  
  		else if (strcmp(currNode->data->gender,"T") == 0 && strcmp(currNode->data->degree,"L8") == 0 ) { 
  
  			L8T +=(currNode->data->numGrads);    
  			overallT +=(currNode->data->numGrads);
  
 		 }
   		
    		prevNode = currNode;
    		currNode = currNode->next; 
  	}  
  	

	float tempL6 = 0, tempL7 = 0, tempL8 = 0, totalGrads =0,pL6 =0, pL7 = 0, pL8 =0, pTotal =0;   

	currNode = listOne->head;
  	prevNode = NULL;  
  	
  	
	char temp_n[MAX_STR];   
	
	strcpy(temp_n,currNode->data->countryName);  
	
	OECD *cp; 
	
	while (currNode != NULL) {  


		if(strcmp(temp_n,currNode->data->countryName) == 0) {  
	
			if ((strcmp(currNode->data->degree,"L6") == 0) && (strcmp(currNode->data->gender,"T") == 0) ) {  
			
				tempL6+= currNode->data->numGrads;  
					
			} 
			else if (strcmp(currNode->data->degree,"L7") == 0 && (strcmp(currNode->data->gender,"T") == 0) ) { 
			
				tempL7+= currNode->data->numGrads;  
			
			} 
			else if (strcmp(currNode->data->degree,"L8") == 0 && (strcmp(currNode->data->gender,"T") == 0) ) {  
			
				tempL8+= currNode->data->numGrads;  
			
			}
		
		} 
		
		else if (strcmp(temp_n,currNode->data->countryName) != 0) { 
			
			totalGrads = tempL6 + tempL7 + tempL8;
			pL6 = (tempL6/L6T) *100; 
			pL7 = (tempL7/L7T) *100; 
			pL8 = (tempL8/L8T) *100; 
			pTotal = (totalGrads/overallT) *100;  
			 
			initGradPercentList(temp_n,pL6,pL7,pL8,pTotal,&cp); 
			addtoList(gradp,cp,rNum);  
			
			tempL6 = 0; 
			tempL7 = 0; 
			tempL8 = 0;  
			totalGrads = 0;

			strcpy(temp_n,currNode->data->countryName); 

			if ((strcmp(currNode->data->degree,"L6") == 0) && (strcmp(currNode->data->gender,"T") == 0) ) {  
			
				tempL6+= currNode->data->numGrads;  
					
			} 
			else if (strcmp(currNode->data->degree,"L7") == 0 && (strcmp(currNode->data->gender,"T") == 0) ) { 
			
				tempL7+= currNode->data->numGrads;  
			
			} 
			else if (strcmp(currNode->data->degree,"L8") == 0 && (strcmp(currNode->data->gender,"T") == 0) ) {  
			
				tempL8+= currNode->data->numGrads;  
			
			}
		}
   		
    		prevNode = currNode;
    		currNode = currNode->next;
  	}  
  	
  	totalGrads = tempL6 + tempL7 + tempL8; 
	pL6 = (tempL6/L6T) *100; 
	pL7 = (tempL7/L7T) *100; 
	pL8 = (tempL8/L8T) *100; 
	pTotal = (totalGrads/overallT) *100;  
			 
	initGradPercentList(temp_n,pL6,pL7,pL8,pTotal,&cp); 
	addtoList(gradp,cp,rNum);  
			
} 
