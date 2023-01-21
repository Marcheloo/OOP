#include "gtest/gtest.h"
#include "Rpn/rpn.h"
#include "Stack/stack.h"
using namespace std;

TEST(ch, value)
{
    char ch1 = '8';
    char ch2 = '3';
    EXPECT_EQ(Num_scan(ch1), 8);
    EXPECT_EQ(Num_scan(ch2), 3);
}

TEST(oper, znach) {
    EXPECT_EQ(oper(2, 2, '+'), 4);
    EXPECT_EQ(oper(2, 3, '*'), 6);
}

TEST(String, Answer) {
    string s1 = "5324+*+7+";
    string s2 = "2222+*+22*+22*2++";
    string s3 = "12+35*+";
    string s4 = "12+35*+8+233*++";
    EXPECT_EQ(Rpn(s1), 30);
    EXPECT_EQ(Rpn(s2), 20);
    EXPECT_EQ(Rpn(s3), 18);
    EXPECT_EQ(Rpn(s4), 37);
}