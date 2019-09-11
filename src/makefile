IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib
#LIBS DO GTEST
LIBS=-lm -Wall -g -pthread -lgtest_main -lgtest -lpthread
## ARQUIVO PARA RODAR OS TESTES:
MAIN = teste_pilha.cpp

## Para compilar com a pilha vetor ou lista basta mudar o nome de _DEPS para pilha_lista.hpp ou pilha_vetro.hpp,
## o _OBJ para pilha_lista.o ou pilha_vetor.o
## e comentar/descomentar as bibiliotecas que serão utilizadas no arquivo teste_pilha.

_DEPS = pilha_vetor.hpp # ou pilha_lista.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ =  pilha_vetor.o # ou pilha_lista.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


make:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(MAIN) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 