#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include "gtest/gtest.h"
#include "lab04include.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

TEST(BinaryTest, AddTest) {
    Op* two = new Op(2);
    Op* three = new Op(3);

    Add* add = new Add(two, three);
    
    Iterator* test = add->create_iterator();
         
    EXPECT_EQ(test->current()->evaluate(), 2);
    test->next();
    EXPECT_EQ(test->current()->evaluate(), 3);
    test->next();
    EXPECT_TRUE(test->is_done());

}

TEST(BinaryTest_Sub, SubTest) {
    Op* ten = new Op(10);
    Op* five = new Op(5);

    Sub* sub = new Sub(ten,five);

    Iterator* test = sub->create_iterator();
    
    EXPECT_EQ(test->current()->evaluate(), 10);
    test->next();
    EXPECT_EQ(test->current()->evaluate(), 5);
    test->next();
    EXPECT_TRUE(test->is_done());

}

TEST(BinaryTest_Mult, MultTest) {
    Op* six = new Op(6);
    Op* twelve = new Op(12);

    Mult* mult = new Mult(six,twelve);

    Iterator* test = mult->create_iterator();

    EXPECT_EQ(test->current()->evaluate(), 6);
    test->next();
    EXPECT_EQ(test->current()->evaluate(),12);
    test->next();
    EXPECT_TRUE(test->is_done());
  

}

TEST(BinaryTest_Div, DivTest) {
    Op* ten = new Op(10);
    Op* five = new Op(5);

    Div* div = new Div(ten,five);

    Iterator* test = div->create_iterator();

    EXPECT_EQ(test->current()->evaluate(), 10);
    test->next();
    EXPECT_EQ(test->current()->evaluate(), 5);
    test->next();
    EXPECT_TRUE(test->is_done());

}



TEST(NullTest, OpTest) {
    Op* two = new Op(2);

    Iterator* test = two->create_iterator();
    EXPECT_TRUE(test->is_done());
    EXPECT_EQ(test->current(), nullptr);
}



 
   
#endif //__VISITOR_TEST_HPP__
