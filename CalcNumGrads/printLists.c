#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "defs.h"    

/*  
  Function: printFemalePercentage()
  Purpose:  This function prints out the graudate percentage of the female for every 
  	    country and the country name.
       in:  The current node of the female percentage report list
      out:  Print out the the percentage for country 
*/   
void printFemalePercentage(const OECD *cp) { 

	printf("-> %20s %20.2f%%\n",
          cp->countryName, (cp->ft));  

} 

/*  
  Function: printGradPercentage()
  Purpose:  This function prints out the graduate percentage for all
  	    the degrees and the total grad percent for each country  
            and the country name. 
       in:  The current node of the graduate percent report list
      out:  Print all the percentges that the current node stores and 
      	    the country name 
*/ 
void printGradPercentage(const OECD *cp) { 
	
	printf("-> %20s %20.2f%% %20.2f%% %20.2f%% %20.2f%%\n",
          cp->countryName,cp->L6,cp->L7,cp->L8,cp->totalGradsCount);  

} 
/*  
  Function: printGrowthOfDegReport()
  Purpose:  This function prints the gorwth percentage from one  
  	     year to the followying for each country
       in:  The current node of the growth report list
      out:  Print out all the content of the current node data
*/ 
void printGrowthOfDegReport(const OECD *cGpr) { 

	printf("-> %20s %25.2f%% %25s\n",
          cGpr->countryName, cGpr->growPer, cGpr->growName);  
	
}

/*  
  Function: printHighestDegReport()
  Purpose:  This function prints the the year of the highest graduate  
  	    percent within the country for every degree
       in:  The current node of the highest degree report list
      out:  Print out all the content of the current nodes data
*/ 
void printHighestDegReport(const OECD *hpr) { 

	printf("-> %20s %20.2f%%->%5d %20.2f%%->%5d %20.2f%%->%5d\n",
          hpr->countryName,(hpr->L6),(hpr->topL6Yr), (hpr->L7),(hpr->topL7Yr),(hpr->L8),(hpr->topL8Yr));   
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

} 

/*  
  Function: printRRPercentage()
  Purpose:  This function prints out the range report percentage 
  	    for each year for every country. 
       in:  The current node of the range report list
      out:  Print out all the content of the current node data
*/ 
void printRRPercentage(const OECD *rp) { 

	printf("--> %20s %20.2f%% %20.2f%% %20.2f%% %20.2f%%\n",
          rp->countryName,rp->tY14,rp->tY15,rp->tY16,rp->tY17);   

}
 	 	
