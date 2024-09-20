#include <iostream>
#include "../src/xstring.h"
#include <gtest/gtest.h>

class sample : public ::testing::Test
{
public:
    void reset()
    {
        //data = "Hello, World!";
    }
protected:
    void SetUp() override
    {
        data = "Hello, World!";
        hello = "Hello ";
        world = "World!";
    }
    
    void TearDown() override
    {
        data = "";
    }
    string data;
    string hello;
    string world;
};

TEST_F(sample,concat)
{
    string hello_World = hello + world;
    ASSERT_EQ(hello_World,"Hello, World!");
}

TEST_F(sample,assignment)
{
    ASSERT_EQ(data,"Hello, World!");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
