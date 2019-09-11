IDIR =../include
CC=g++
CFLAGS_PILHA_VETOR=-I$(IDIR)
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib
#LIBS DO GTEST
LIBS=-lm -Wall -g -pthread -lgtest_main -lgtest -lpthread
## ARQUIVO PARA RODAR OS TESTES:
MAIN = teste_pilha.cpp



## Para compilar com a pilha vetor ou lista basta comentar/descomentar as bibiliotecas que serão utilizadas no arquivo teste_pilha.
#  Regras para vetor:


_DEPS_PILHA_VETOR = pilha_vetor.hpp # ou pilha_lista.hpp
DEPS_PILHA_VETOR = $(patsubst %,$(IDIR)/%,$(_DEPS_PILHA_VETOR))

_OBJ_PILHA_VETOR =  pilha_vetor.o # ou pilha_lista.o
OBJ_PILHA_VETOR = $(patsubst %,$(ODIR)/%,$(_OBJ_PILHA_VETOR))

$(ODIR)/%.o: %.cpp $(DEPS_PILHA_VETOR)
	$(CC) -c -o $@ $< $(CFLAGS_PILHA_VETOR)

## Regras para Pilha Lista:

_DEPS_PILHA_LISTA = pilha_lista.hpp # ou pilha_lista.hpp
DEPS_PILHA_LISTA = $(patsubst %,$(IDIR)/%,$(_DEPS_PILHA_LISTA))

_OBJ_PILHA_LISTA =  pilha_lista.o # ou pilha_lista.o
OBJ_PILHA_LISTA = $(patsubst %,$(ODIR)/%,$(_OBJ_PILHA_LISTA))

$(ODIR)/%.o: %.cpp $(DEPS_PILHA_LISTA)
	$(CC) -c -o $@ $< $(CFLAGS_PILHA_VETOR)


## default: make vetor
Vetor:$(OBJ_PILHA_VETOR)
	$(CC) -o $@ $^ $(CFLAGS_PILHA_VETOR) $(MAIN) $(LIBS)


Lista:$(OBJ_PILHA_LISTA)
	$(CC) -o $@ $^ $(CFLAGS_PILHA_LISTA) $(MAIN) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 