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
    
#endif //__VISITOR_TEST_HPP__
