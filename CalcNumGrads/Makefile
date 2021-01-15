run:    main.o intialization.o calculate.o print.o compute.o traverseReports.o  
	gcc -o run main.c initalization.c calculate.c printLists.c computeReports.c traverseReports.c 

main.o: main.c defs.h 
	gcc -c  main.c 

intialization.o: initalization.c defs.h 
	gcc -c initalization.c

calculate.o: calculate.c defs.h
	gcc -c calculate.c 

print.o: printLists.c defs.h 
	gcc -c printLists.c 

compute.o: computeReports.c defs.h
	   gcc -c computeReports.c 

traverseReports.o: traverseReports.c defs.h 
		   gcc -c traverseReports.c 

clean: 
	rm -f main.o intialization.o calculate.o print.o compute.o traverseReports.o run

