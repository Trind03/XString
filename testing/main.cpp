#include <iostream>
#include "../src/xstring.h"
#include <gtest/gtest.h>
//#define _DEBUG_


TEST(string,length_calculation)
{
    string hello_world = "Hello, World!";
    std::cout << hello_world << std::endl;
    EXPECT_EQ(hello_world.length(),13);
}

TEST(string,concat)
{
    string x = "Hello, ";
    string y = "World";
    string hello_world = x + y;
    EXPECT_EQ(hello_world,"test");
}

#ifndef _DEBUG_
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
#else 
int main()
{
    string data = "Hello, World!";
    std::cout << data.length() << std::endl;
    return EXIT_SUCCESS;
}
#endif