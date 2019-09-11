IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib
#LIBS DO GTEST
LIBS=-lm -Wall -g -pthread -lgtest_main -lgtest -lpthread
## ARQUIVO PARA RODAR OS TESTES:
MAIN = teste_pilha.cpp

_DEPS = pilha_vetor.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ =  pilha_vetor.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


make:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(MAIN) $(LIBS) 


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 