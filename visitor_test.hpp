#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include "gtest/gtest.h"
#include "lab04include.hpp"



//------------------Op------------------
TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(2.34);
    EXPECT_EQ(test->evaluate(), 2.34);
    EXPECT_EQ(test->stringify(), "2.340000");
}


//------------------Rand------------------
TEST(RandTest, RandEvaluateNonZero) {
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(), 100);
}

//------------------Mult------------------
TEST(MultTest, MultEvaluationNonZero) {
    Op* a = new Op(4.321);
    Op* b = new Op(2.231);

    Mult* test = new Mult(a,b);
    EXPECT_EQ(test->evaluate(), 9.640151);
    EXPECT_EQ(test->stringify(), "4.321000 * 2.231000");
}

//------------------Div------------------
TEST(DivTest, DivEvaluationNonZero) {
    Op* a = new Op(6.321);
    Op* b = new Op(2.345);

    Div* test = new Div(a,b);
    EXPECT_NEAR(test->evaluate(), 2.69552238806, 0.000001);
    EXPECT_EQ(test->stringify(), "6.321000 / 2.345000");

//------------------ADD------------------
TEST(AddTest, AddEvaluateNonZero) {
    Op* a = new Op(2.466);
    Op* b = new Op(3.98722);
    
    Add* test = new Add(a,b);
    EXPECT_EQ(test->evaluate(), 6.45322);
    EXPECT_EQ("2.466000 + 3.987220", test->stringify());
}
//------------------POW------------------
TEST(PowTest, PowEvaluateNonZero) {
    Op* a = new Op(2.14);
    Op* b = new Op(3.5222);
    Pow* test = new Pow(a, b);
    EXPECT_NEAR(test->evaluate(), 14.58086847543, 0.000001);
    EXPECT_EQ("2.140000 ** 3.522200", test->stringify());
}
//------------------SUB------------------
TEST(SubTest, SubEvaluateNonZero) {
    Op* a = new Op(4.323);
    Op* b = new Op(2.4433);
    Sub* test = new Sub(a, b);
    EXPECT_NEAR(test->evaluate(), 1.8797, 0.000001);
    EXPECT_EQ("4.323000 - 2.443300", test->stringify());
}

#endif //__VISITOR_TEST_HPP__
