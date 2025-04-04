/*
 ******************************************************************************
 * @file           : test/ExampleTests.cpp
 * @brief          : Main program body
 ******************************************************************************
 * @author         : Jabed-Akhtar (Github)
 * @date           : 22.08.2022
 ******************************************************************************
 * --
 ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "../Example.hpp"
#include <gtest/gtest.h>

int sideEffect = 42;

struct ExampleTests
    : public ::testing::Test
{
    int* x;
    int GetX(){
        return *x;
    }
    virtual void SetUp() override{
        fprintf(stderr, "Hello from struct-ExampleTests-SetUp!\n");
        x = new int(42); // allocating some memory
    }
    virtual void TearDown() override{
        delete x;
    }
};

bool f(){
    sideEffect = 16;
    return false;
}

// Test->1.1. ExampleTests > DemonstrateGTestMacros
TEST_F(ExampleTests, DemonstrateGTestMacros){
    EXPECT_TRUE(true);

    const bool result = f();
    EXPECT_EQ(true, result) << "--->> sideEffect = " << sideEffect;
}

// Test->1.2. ExampleTests > MAC
TEST_F(ExampleTests, MAC){
    int y = 16;
    int sum = 100;
    int oldSum = sum;
    int expectedNewSum = oldSum + GetX() * y;

    EXPECT_EQ(
        expectedNewSum,
        MAC(GetX(), y, sum)
    );
    EXPECT_EQ(
        expectedNewSum,
        sum
    );
}

// Test->2. ExampleTest_2 > Square
TEST(ExampleTest_2, Square){
    int x = 5;
    int expectedSquare = x*x;
    EXPECT_EQ(
        expectedSquare,
        Square(x)
    );
}

// ================================= END OF FILE =================================