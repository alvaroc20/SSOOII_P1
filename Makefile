DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/
DIRSTU := data/
DIRBCKUP := backup/
LOGTXT := log.txt
LDLIBS := -pthread -lrt -lm

CFLAGS := -I$(DIRHEA) -c -Wall -ansi
IFLAGS :=  -c -Wall -ansi -g
CC := gcc

all: dirs manager pa pb pc pd demon
dirs:
	mkdir -p $(DIROBJ) $(DIREXE) $(DIRBCKUP)

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

demon: $(DIROBJ)demon.o 
	$(CC) -o $(DIREXE)$@ $^ 


$(DIROBJ)%.o: $(DIRSRC)%.c
	$(CC) $(CFLAGS) $^ -o $@ 

run:
	./$(DIREXE)manager ; ./$(DIREXE)demon &

clean : 
	rm -rf *~ core $(DIROBJ) $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~ $(DIRSTU) $(LOGTXT) $(DIRBCKUP)