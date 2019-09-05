#include "../src/pilha.cpp"
#include "../src/lista.cpp"
#include <gtest/gtest.h>

//compile: g++ -Wall -g -pthread -o teste_pilha teste_pilha.cpp -lgtest_main -lgtest -lpthread
int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(PilhaLista, TopPushAndPop)
{
    Pilha pilha;
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
TEST(PilhaLista, TamanhoPilha)
{
    Pilha pilha; // Tamanho 0
    ASSERT_EQ(0, pilha.size());

    Elemento elemento1(1);
    pilha.push(&elemento1); // Tamanho 1
    ASSERT_EQ(1, pilha.size());

    Elemento elemento2(5);
    pilha.push(&elemento2); // Tamanho 2
    ASSERT_EQ(2, pilha.size());

    Elemento elemento3(1000);
    pilha.push(&elemento3); // Tamanho 3
    ASSERT_EQ(3, pilha.size());

    pilha.pop(); // Tamanho 2
    ASSERT_EQ(2, pilha.size());
}
TEST(PilhaLista, isEmpty)
{
    Pilha pilha; // Pilha vazia ao inicializar:
    ASSERT_EQ(true, pilha.isEmpty());
    Elemento elemento(2);
    pilha.push(&elemento); // Pilha não está mais vazia. 1 elemento.
    ASSERT_EQ(false, pilha.isEmpty());
    pilha.pop(); // Vazia após pop:0 elementos e tamanho 0
    ASSERT_EQ(true, pilha.isEmpty());
}

TEST(PilhaLista, DestroyPilha)
{
    Pilha pilha; // PILHA DESTRUIDA TOPO == NULL e tamanho = 0; (PilhaVazia)
    ASSERT_EQ(NULL, pilha.top());

    Elemento elemento1(1);
    pilha.push(&elemento1);
    Elemento elemento2(5);
    pilha.push(&elemento2);
    Elemento elemento3(10);
    pilha.push(&elemento3);

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