#include <iostream>
#include "../src/xstring.h"
#include <gtest/gtest.h>
//#define _DEBUG_


class sample : public ::testing::Test
{
public:
    void reset()
    {
        data = "Hello, World!";
    }
protected:
    void SetUp() override
    {
        data = "Hello,1 World!";
        first = "Hello,";
        second = " World!";
    }
    
    void TearDown() override
    {
        data = "";
    }
    string data;
    string first;
    string second;
};

TEST_F(sample,length_calculation)
{
    ASSERT_EQ(data.length(),14);
}

TEST_F(sample,concat)
{
    std::cout << data << std::endl;
    ASSERT_EQ(data,"Hello, World!");
}

TEST_F(sample,assignment)
{
    ASSERT_EQ(data,"Hello, World!");
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