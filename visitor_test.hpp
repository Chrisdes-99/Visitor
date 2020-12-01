#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include "gtest/gtest.h"
#include "lab04include.hpp"
#include "iterator.hpp"


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

TEST(NullTest, OpTest) {
    Op* two = new Op(2);

    Iterator* test = two->create_iterator();
    EXPECT_TRUE(test->is_done());
    EXPECT_EQ(test->current(), nullptr);
}


//Count Testing

TEST(BinaryCount,AddSub){
    Base* four = new Op(4);
    Base* five = new Op(5);

    Add* value = new Add(four,five);

    Base* dummy_node = new sub(value,five);

    Iterator* test = dummy_node->create_iterator();
    CountVistor* count = new CountVisitor();

    test->first();
    
    while(!test->is_done(){
    Base* val = test->current();
    val->accept(count);
    }

    EXPECT_EQ(2,count->op_count());
    EXPECT_EQ(1,count->add_count());
    
}

TEST(Binary_Count,MultDiv){
    Base* value = new Op(20);
    Base* value2 = new Op(5);

    Mult* mult = new Mult(four,five);

    Base* dummy_node = new div(mult,value2);

    Iterator* test = dummy_node->create_iterator();
    CountVistor* count = new CountVisitor();

    test->first();

    while(!test->is_done(){
    Base* state = test->current();
    state->accept(count);
    }

    EXPECT_EQ(2,count->op_count());
    EXPECT_EQ(1,count->mult_count());

}

 


   
#endif //__VISITOR_TEST_HPP__
