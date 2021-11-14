
all: con	

																							
con :   con.c
		gcc con.c -Wall -ansi -pedantic 	
		-./a.out		
		

clean:
		rm -rf *o con.o

