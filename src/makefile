IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm -Wall -g -pthread -lgtest_main -lgtest -lpthread
## ARQUIVO PARA RODAR OS TESTES:
MAIN = teste_pilha.cpp

_DEPS = lista.hpp pilha.hpp 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = lista.o pilha.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


make:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(MAIN)


.PHONY: clean

testePilhaLista:
	g++ -Wall -g -pthread -o teste_pilha teste_pilha.cpp -lgtest_main -lgtest -lpthread
	./teste_pilha

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 