DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/
DIRSTU := data/
LOGTXT := log.txt
LDLIBS := -pthread -lrt -lm

CFLAGS := -I$(DIRHEA) -c -Wall -ansi
IFLAGS :=  -c -Wall -ansi -g
CC := gcc

all: dirs manager pa pb pc
dirs:
	mkdir -p $(DIROBJ) $(DIREXE)

manager: $(DIROBJ)manager.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS) 

pa: $(DIROBJ)pa.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS) 

pb: $(DIROBJ)pb.o 
	$(CC) -o  $(DIREXE)$@ $^ $(LDLIBS) 

pc: $(DIROBJ)pc.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS) 

pd: $(DIROBJ)pd.o 
	$(CC) -o $(DIREXE)$@ $^ 


$(DIROBJ)%.o: $(DIRSRC)%.c
	$(CC) $(CFLAGS) $^ -o $@ 

test:
	./$(DIREXE)manager

clean : 
	rm -rf *~ core $(DIROBJ) $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~ $(DIRSTU) $(LOGTXT)