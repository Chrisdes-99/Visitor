CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

ADD_EXECUTABLE(test
   unit_test.cpp
   binary_iterator.cpp
   preorder_iterator.cpp
   visitor.cpp
)


ADD_EXECUTABLE(main
    main.cpp
    binary_iterator.cpp
    preorder_iterator.cpp
    visitor.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
