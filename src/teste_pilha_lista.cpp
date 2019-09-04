#include "pilha_lista.cpp"
#include "lista.cpp"
#include <gtest/gtest.h>

//compile: g++ -Wall -g -pthread -o teste_pilha_lista teste_pilha_lista.cpp -lgtest_main -lgtest -lpthread
int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(PilhaLista, TopPushAndPop)
{
    Pilha pilha;
    pilha.push(2);
    /*Pilha:
            [ 2 ]   <- Topo  
    */
    ASSERT_EQ(2, pilha.top()->getValue());
    pilha.push(-1);
    /*Pilha:
            [ -1]  <- Topo   
            [ 2 ]  
    */
    ASSERT_EQ(-1, pilha.top()->getValue());
    pilha.push(1000);
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
TEST(PilhaLista, TamanhoPilha)
{
    Pilha pilha; // Tamanho 0
    ASSERT_EQ(0, pilha.size());

    pilha.push(1); // Tamanho 1
    ASSERT_EQ(1, pilha.size());

    pilha.push(5); // Tamanho 2
    ASSERT_EQ(2, pilha.size());

    pilha.push(10); // Tamanho 3
    ASSERT_EQ(3, pilha.size());

    pilha.pop(); // Tamanho 2
    ASSERT_EQ(2, pilha.size());
}
TEST(PilhaLista, isEmpty)
{
    Pilha pilha; // Pilha vazia ao inicializar:
    ASSERT_EQ(true, pilha.isEmpty());
    pilha.push(2); // Pilha não está mais vazia. 1 elemento.
    ASSERT_EQ(false, pilha.isEmpty());
    pilha.pop(); // Vazia após pop:0 elementos e tamanho 0
    ASSERT_EQ(true, pilha.isEmpty());
}

TEST(PilhaLista, DestroyPilha)
{
    Pilha pilha; // PILHA DESTRUIDA TOPO == NULL e tamanho = 0; (PilhaVazia)
    ASSERT_EQ(NULL, pilha.top());

    pilha.push(1);
    pilha.push(5);
    pilha.push(10);

    pilha.destroyStack();
    ASSERT_EQ(NULL, pilha.top());
    ASSERT_EQ(0, pilha.size());
}

TEST(PilhaLista, Exception)
{
    Pilha pilha;
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