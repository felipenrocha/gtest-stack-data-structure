#include "../include/pilha_lista.hpp"
#include "../include/lista.hpp"
#include "../include/pilha_vetor.hpp"
#include <gtest/gtest.h>

//compile: g++ -Wall -g -pthread -o teste_pilha teste_pilha.cpp -lgtest_main -lgtest -lpthread
int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(PilhaListaTeste, TopPushAndPop)
{
    Pilha pilha(3);
    Elemento elemento(2);
    pilha.push(&elemento);
    /*Pilha:
            [ 2 ]   <- Topo  
    */
    ASSERT_EQ(2, pilha.top()->getValue());
    Elemento elemento1(-1);
    pilha.push(&elemento1);
    /*Pilha:
            [ -1]  <- Topo   
            [ 2 ]  
    */
    ASSERT_EQ(-1, pilha.top()->getValue());
    Elemento elemento2(1000);
    pilha.push(&elemento2);
    /*Pilha :
        [1000]    <- Topo   
        [ -1]
        [ 2 ]
    */
    ASSERT_EQ(1000, pilha.top()->getValue());
    pilha.pop();
    /*Pilha:
            [ -1]  <- Topo   
            [ 2 ]  
    */
    ASSERT_EQ(-1, pilha.top()->getValue());
    pilha.pop();
    /*Pilha:
            [ 2 ]   <- Topo  
    */
    ASSERT_EQ(2, pilha.top()->getValue());
}
TEST(PilhaListaTeste, TamanhoPilha)
{
    Pilha pilha(5); // Tamanho 5
    ASSERT_EQ(5, pilha.size());

    Pilha pilha1(1); // Tamanho 1
    ASSERT_EQ(1, pilha1.size());

    Pilha pilha2(2); // Tamanho 2
    ASSERT_EQ(2, pilha2.size());
}
TEST(PilhaListaTeste, isEmpty)
{
    Pilha pilha(10); // Pilha vazia ao inicializar:
    ASSERT_EQ(true, pilha.isEmpty());
    Elemento elemento(2);
    pilha.push(&elemento); // Pilha não está mais vazia. 1 elemento.
    ASSERT_EQ(false, pilha.isEmpty());
    pilha.pop(); // Vazia após pop:0 elementos e quantidade 0
    ASSERT_EQ(true, pilha.isEmpty());
}

TEST(PilhaListaTeste, DestroyPilha)
{
    Pilha pilha(5); // PILHA DESTRUIDA TOPO == NULL e quantidade= 0; (PilhaVazia)
    ASSERT_EQ(NULL, pilha.top());

    Elemento elemento1(1);
    pilha.push(&elemento1);
    Elemento elemento2(5);
    pilha.push(&elemento2);
    Elemento elemento3(10);
    pilha.push(&elemento3);

    pilha.destroyStack();
    ASSERT_EQ(NULL, pilha.top());
    ASSERT_EQ(0, pilha.getQuantidade());
}
//TODO : setSize test
TEST(PilhaListaTeste, ExceptionPilhaVazia)
{
    Pilha pilha(5);
    // Pilha Vazia ao tentar realizar pop deve retornar uma exceção dizendo que a pilha está vazia.

    EXPECT_THROW({
        try
        {
            pilha.pop();
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Pilha Vazia!", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(PilhaListaTeste, ExceptionPilhaCheia)
{
    Pilha pilha(1); // Pilha somente com 1 elemento, ao tentar se dar push em um segundo numero, uma exceção é retornada.
    Elemento elemento(5);
    pilha.push(&elemento);
    Elemento elemento2(1);
    EXPECT_THROW({
        try
        {
            pilha.push(&elemento2);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Pilha Cheia!", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(PilhaListaTeste, ExceptionTamanhoZero)
{
    EXPECT_THROW({
        try
        {
            Pilha pilha(-1); // Pilha com tamanho <= 0 deve retornar mensagem de tratamento
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Pilha deve possuir tamanho maior que 0!", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(PilhaVetorTeste, TopPushAndPop)
{
    PilhaVetor pilha(3);
    TipoDeDado elemento;
    elemento.setValue(2);
    pilha.push(elemento);
    /*Pilha:
            [ 2 ]   <- Topo  
    */
    ASSERT_EQ(2, pilha.top().getValue());
    TipoDeDado elemento1;
    elemento1.setValue(-1);
    pilha.push(elemento1);
    /*Pilha:
            [ -1]  <- Topo   
            [ 2 ]  
    */
    ASSERT_EQ(-1, pilha.top().getValue());
    TipoDeDado elemento2;
    elemento2.setValue(1000);
    pilha.push(elemento2);
    /*Pilha :
        [1000]    <- Topo   
        [ -1]
        [ 2 ]
    */
    ASSERT_EQ(1000, pilha.top().getValue());
    pilha.pop();
    /*Pilha:
            [ -1]  <- Topo   
            [ 2 ]  
    */
    ASSERT_EQ(-1, pilha.top().getValue());
    pilha.pop();
    /*Pilha:
            [ 2 ]   <- Topo  
    */
    ASSERT_EQ(2, pilha.top().getValue());
}
TEST(PilhaVetorTeste, SizeAndResizePilha)
{
    Pilha pilha(5); // Tamanho 5
    ASSERT_EQ(5, pilha.size());
    pilha.setSize(3); // Novo tamanho 3
    ASSERT_EQ(3, pilha.size());

    Pilha pilha1(1); // Tamanho 1
    ASSERT_EQ(1, pilha1.size());
    pilha1.setSize(4); // Novo tamanho: 4
    ASSERT_EQ(4, pilha1.size());

    Pilha pilha2(2); // Tamanho 2
    ASSERT_EQ(2, pilha2.size());
    pilha2.setSize(10); // Novo tamanho: 10
    ASSERT_EQ(10, pilha2.size());
}

TEST(PilhaVetorTeste, isEmpty)
{
    PilhaVetor pilha(10); // Pilha vazia ao inicializar:
    ASSERT_EQ(true, pilha.isEmpty());
    TipoDeDado elemento;
    elemento.setValue(2);
    pilha.push(elemento); // Pilha não está mais vazia. 1 elemento.
    ASSERT_EQ(false, pilha.isEmpty());
    pilha.pop(); // Vazia após pop:0 elementos e quantidade 0
    ASSERT_EQ(true, pilha.isEmpty());
}

TEST(PilhaVetorTeste, DestroyPilha)
{
    PilhaVetor pilha(5); // quantidade= 0; (PilhaVazia)
    ASSERT_EQ(0, pilha.getQuantidade());

    TipoDeDado elemento1;
    elemento1.setValue(5);
    pilha.push(elemento1);
    TipoDeDado elemento2;
    elemento2.setValue(4);
    pilha.push(elemento2);
    TipoDeDado elemento3;
    elemento3.setValue(10);
    pilha.push(elemento3);

    pilha.destroyStack();
    ASSERT_EQ(0, pilha.getQuantidade());
}

TEST(PilhaVetorTeste, ExceptionPilhaVetorVazia)
{
    PilhaVetor pilha(5);
    // Pilha Vazia ao tentar realizar pop deve retornar uma exceção dizendo que a pilha está vazia.

    EXPECT_THROW({
        try
        {
            pilha.pop();
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Pilha Vazia!", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(PilhaVetorTeste, ExceptionTamanhoZero)
{
    EXPECT_THROW({
        try
        {
            PilhaVetor pilha(-1); // Pilha com tamanho <= 0 deve retornar mensagem de tratamento
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Pilha deve possuir tamanho maior que 0!", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(PilhaVetorTeste, ExceptionPilhaCheia)
{
    PilhaVetor pilha(1); // Pilha somente com 1 elemento, ao tentar se dar push em um segundo numero, uma exceção é retornada.
    TipoDeDado elemento;
    elemento.setValue(1);
    pilha.push(elemento);
    ASSERT_EQ(1, pilha.getQuantidade());
    TipoDeDado elemento2;
    ASSERT_EQ(true, pilha.isFull());
    EXPECT_THROW({
        try
        {
            pilha.push(elemento2);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Pilha Cheia!", e.what());
            throw;
        }
    },
                 invalid_argument);
}


