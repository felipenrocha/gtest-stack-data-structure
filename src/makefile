IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm -Wall -g -pthread -lgtest_main -lgtest -lpthread

_DEPS = lista.hpp pilha.hpp menu.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = lista.o pilha.o menu.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


hellomake:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

testePilhaLista:
	g++ -Wall -g -pthread -o teste_pilha_lista teste_pilha_lista.cpp -lgtest_main -lgtest -lpthread
	./teste_pilha_lista

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 