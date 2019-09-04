IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = lista.hpp pilha_lista.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = lista.o pilha_lista.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


make:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

testePilhaLista:
	g++ -Wall -g -pthread -o teste_pilha_lista teste_pilha_lista.cpp -lgtest_main -lgtest -lpthread
	./teste_pilha_lista

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 