CC = gcc 
CFLAGS = -std=c11 -Wall -g -O0 
INCLUDE = -I../src 
EXEC = test 
OBJ = tester.o getMegaMimeTypeTest.o  MegaMimes.o main.o getMegaMimeExtensionstest.o getMegaMimeFileInformationTest.o

$(EXEC):$(OBJ)
	$(CC)  -o $(EXEC) $(OBJ)

getMegaMimeFileInformationTest.o:getMegaMimeFileInformationTest.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $< 

getMegaMimeTypeTest.o:getMegaMimeTypeTest.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $< 

getMegaMimeExtensionstest.o:getMegaMimeExtensionstest.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $< 

main.o:main.c 
	$(CC) -c $(CFLAGS) $(INCLUDE) $< 

MegaMimes.c:../src/MegaMimes.c
	cp  $< $@

MegaMimes.o:MegaMimes.c
		$(CC) -c $(CFLAGS) $(INCLUDE) -fprofile-arcs -ftest-coverage $< 

