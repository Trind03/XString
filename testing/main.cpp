#include <iostream>
#include "../src/xstring.h"
#include <gtest/gtest.h>

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
        data = "Hello, World!";
    }

    void TearDown() override
    {
        data = "";
    }
    string data;
};

TEST_F(sample,concat)
{
    ASSERT_EQ(data,"Hello, World!");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
