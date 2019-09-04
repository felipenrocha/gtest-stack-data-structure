#include "pilha.cpp"
#include "lista.cpp"
#include <gtest/gtest.h>

int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(PilhaLista, PushAndTop)
{
    Pilha pilha;
    pilha.push(2);
    ASSERT_EQ(2, pilha.top()->getValue());
    pilha.push(-1);
    ASSERT_EQ(-1, pilha.top()->getValue());
}