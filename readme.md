Trabalho 1 - Métodos em Programação - 201600

Aluno: Felipe Nascimento Rocha - 17/0050084

Professor: Jan Mendonça Correa

Sistema Operacional: Ubuntu 18.04

Compilador: gcc/g++ (7.4.0)

Linguagem: C++11

Framework de teste: gtest

    - Instruções para instalação do gtest:

        $ sudo apt-get install libgtest-dev

        $ sudo apt-get install cmake

        $ cd /usr/src/gtest

        $ sudo cmake CMakeLists.txt

        $ sudo make

        $ sudo cp *.a /usr/lib

    - Instruções makefile:

        - Compilar os testes:
            - Para compilar com a Pilha usando vetores ou Pilha usando lista encadeada:
                - Comentar/descomentar os header files que serão utilizadas no arquivo teste_pilha.cpp; (pilha_lista.hpp  ou pilha_vetor.hpp);

            - Dentro do diretório src no terminal:
             - $ make Vetor
                - Compilação passando os parâmetros do objeto Vetor
                - Para executar, basta utilizar o comando:
                    - $  ./Vetor
             - $ make Lista
                - Compilação passando os parâmetros do objeto Lista
                - Para executar, basta utilizar o comando:
                    - $  ./Lista

        - $ make .PHONY
            - Remove os objetos da compilação;

Executar com Valgrind: 

    - Após comipalação: rodar comando no terminal dentro do diretório src:
    
        $ valgrind ./Vetor
        $ valgrind ./Lista
        
    
   Trabalho 1 - Métodos em Programação - 201600
