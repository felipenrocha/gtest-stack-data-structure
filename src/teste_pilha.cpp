#include "../include/pilha_lista.hpp"
// #include "../include/pilha_vetor.hpp"
#include <gtest/gtest.h>

/*
OBS.: Comentar e descomentar os header files na hora de compilaçã 
de acordo com o teste a ser realizado.
*/

int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(PilhaTeste, TopPushAndPop)
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
    pilha.destroyStack();
}
TEST(PilhaTeste, sizeAndsetSizePilha)
{
    Pilha pilha(5); // Tamanho 5
    ASSERT_EQ(5, pilha.size());
    pilha.setSize(3); // Novo tamanho: 3
    ASSERT_EQ(3, pilha.size());
    pilha.destroyStack();

    Pilha pilha1(1); // Tamanho 1
    ASSERT_EQ(1, pilha1.size());
    pilha1.setSize(9); // Novo tamanho: 9
    ASSERT_EQ(9, pilha1.size());
    pilha1.destroyStack();

    Pilha pilha2(2); // Tamanho 2
    ASSERT_EQ(2, pilha2.size());
    pilha2.destroyStack();
}
TEST(PilhaTeste, isEmpty)
{
    Pilha pilha(10); // Pilha vazia ao inicializar:
    ASSERT_EQ(true, pilha.isEmpty());
    Elemento elemento(2);
    pilha.push(&elemento); // Pilha não está mais vazia. 1 elemento.
    ASSERT_EQ(false, pilha.isEmpty());
    pilha.pop(); // Vazia após pop:0 elementos e quantidade 0
    ASSERT_EQ(true, pilha.isEmpty());
    pilha.destroyStack();
}
TEST(PilhaTeste, isFull)
{
    Pilha pilha(1); // Tamanho 1
    Elemento elemento(10);
    ASSERT_EQ(false, pilha.isFull());
    pilha.push(&elemento); // Primeiro push a pilha ja está cheia.
    ASSERT_EQ(true, pilha.isFull());
    pilha.pop();
    ASSERT_EQ(false, pilha.isFull());
    pilha.destroyStack();

    Pilha pilha2(3); // Tamanho 3
    Elemento elemento1(1);
    Elemento elemento2(2);
    Elemento elemento3(3);
    ASSERT_EQ(false, pilha2.isFull());
    pilha2.push(&elemento1); // 1 Elemento
    ASSERT_EQ(false, pilha2.isFull());
    pilha2.push(&elemento2); // 2 Elementos
    ASSERT_EQ(false, pilha2.isFull());
    pilha2.push(&elemento3); // 3 elementos = Pilha cheia
    ASSERT_EQ(true, pilha2.isFull());
    pilha2.pop();
    ASSERT_EQ(false, pilha2.isFull());
    pilha2.destroyStack();
}

TEST(PilhaTeste, DestroyPilha)
{
    Pilha pilha(5); //(PilhaVazia)
    ASSERT_EQ(true, pilha.isEmpty());

    Elemento elemento1(1);
    pilha.push(&elemento1);
    Elemento elemento2(5);
    pilha.push(&elemento2);
    Elemento elemento3(10);
    pilha.push(&elemento3);

    pilha.destroyStack();
    ASSERT_EQ(true, pilha.isEmpty());
    pilha.push(&elemento1);
    ASSERT_EQ(false, pilha.isEmpty());
    pilha.destroyStack();
}

TEST(PilhaException, ExceptionPilhaVazia)
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
    pilha.destroyStack();
}

TEST(PilhaException, ExceptionPilhaCheia)
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
    pilha.destroyStack();
}

TEST(PilhaException, ExceptionTamanhoZero)
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

TEST(PilhaException, ExceptionSetSize)
{
    Pilha pilha(2);
    Elemento elemento1(1);
    Elemento elemento2(2);
    pilha.push(&elemento1);
    pilha.push(&elemento2);

    EXPECT_THROW({
        try
        {
            pilha.setSize(1); // Pilha set size com nº < que nº d elementos da pilha
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Impossível mudar o tamanho pois já existe mais mais elementos, tente mudar para no mínimo a quantidade de elementos da pilha!", e.what());
            throw;
        }
    },
                 invalid_argument);
    pilha.destroyStack();
}
