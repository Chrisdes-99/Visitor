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

TEST(BinaryTest, SubTest) {
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

TEST(BinaryTest, MultTest) {
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

TEST(BinaryTest, DivTest) {
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


TEST(VisitorTest, MultTest) {
    Base* num1 = new Op(3);
    Base* num2 = new Op(7);

    Mult* temp = new Mult(num1, num2);

    Base* dummy = new Add(temp, num1);

    Iterator* it = new PreorderIterator(dummy); //dummy->create_iterator();
    CountVisitor* visit = new CountVisitor();

    it->first();
    while (!it->is_done()) {
        it->current()->accept(visit);
        it->next();
    }
    EXPECT_EQ(visit->op_count(), 3);
    EXPECT_EQ(visit->mult_count(), 1);
    EXPECT_EQ(visit->sub_count(), 0);
    EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, AddTest) {
    Base* num1 = new Op(3);
    Base* num2 = new Op(7);

    Add* temp = new Add(num1, num2);

    Base* dummy = new Add(temp, num1);

    Iterator* it = new PreorderIterator(dummy); //dummy->create_iterator();
    CountVisitor* visit = new CountVisitor();

    it->first();
    while (!it->is_done()) {
        it->current()->accept(visit);
        it->next();
    }
    EXPECT_EQ(visit->op_count(), 3);
    EXPECT_EQ(visit->mult_count(), 0);
    EXPECT_EQ(visit->sub_count(), 0);
    EXPECT_EQ(visit->add_count(), 1);
}

TEST(VisitorTest, SubTest) {
    Base* num1 = new Op(3);
    Base* num2 = new Op(7);

    Sub* temp = new Sub(num1, num2);

    Base* dummy = new Add(temp, num1);

    Iterator* it = new PreorderIterator(dummy); //dummy->create_iterator();
    CountVisitor* visit = new CountVisitor();

    it->first();
    while (!it->is_done()) {
        it->current()->accept(visit);
        it->next();
    }
    EXPECT_EQ(visit->op_count(), 3);
    EXPECT_EQ(visit->mult_count(), 0);
    EXPECT_EQ(visit->sub_count(), 1);
    EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, DivTest) {
    Base* num1 = new Op(3);
    Base* num2 = new Op(7);

    Div* temp = new Div(num1, num2);

    Base* dummy = new Add(temp, num1);

    Iterator* it = new PreorderIterator(dummy); //dummy->create_iterator();
    CountVisitor* visit = new CountVisitor();

    it->first();
    while (!it->is_done()) {
        it->current()->accept(visit);
        it->next();
    }
    EXPECT_EQ(visit->op_count(), 3);
    EXPECT_EQ(visit->div_count(), 1);
    EXPECT_EQ(visit->sub_count(), 0);
    EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, PowTest) {
    Base* num1 = new Op(3);
    Base* num2 = new Op(7);

    Pow* temp = new Pow(num1, num2);

    Base* dummy = new Add(temp, num1);

    Iterator* it = new PreorderIterator(dummy); // dummy->create_iterator();
    CountVisitor* visit = new CountVisitor();

    it->first();
    while (!it->is_done()) {
        it->current()->accept(visit);
        it->next();
    }
    EXPECT_EQ(visit->op_count(), 3);
    EXPECT_EQ(visit->pow_count(), 1);
    EXPECT_EQ(visit->sub_count(), 0);
    EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, BigTreeTest) {
    Base* num1 = new Op(3);
    Base* num2 = new Op(7);

    Pow* pow = new Pow(num1, num2);
    Mult* mult = new Mult(pow, num1);
    Add* add = new Add(mult, num2);
    Sub* test = new Sub(add, num1);

    Base* dummy = new Add(test, num1);

    Iterator* it = new PreorderIterator(dummy);
    CountVisitor* visit = new CountVisitor();

    it->first();
    while (!it->is_done())  {
        it->current()->accept(visit);
        it->next();
    }

    EXPECT_EQ(visit->op_count(), 6);
    EXPECT_EQ(visit->pow_count(), 1);
    EXPECT_EQ(visit->mult_count(), 1);
    EXPECT_EQ(visit->add_count(), 1);
    EXPECT_EQ(visit->sub_count(), 1);
    EXPECT_EQ(visit->div_count(), 0);
}











   
#endif //__VISITOR_TEST_HPP__
