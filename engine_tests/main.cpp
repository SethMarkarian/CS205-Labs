#include <iostream>

 #include "gtest/gtest.h"
 #include "../Engines/robots.h"
 #include "../Engines/worm.h"

 // The fixture for testing class Foo.
 class FooTest : public ::testing::Test {
  protected:
   // You can remove any or all of the following functions if its body
   // is empty.

   FooTest() {
     // You can do set-up work for each test here.
   }

   virtual ~FooTest() {
     // You can do clean-up work that doesn't throw exceptions here.
   }

   // If the constructor and destructor are not enough for setting up
   // and cleaning up each test, you can define the following methods:

   virtual void SetUp() {
     // Code here will be called immediately after the constructor (right
     // before each test).
   }

   virtual void TearDown() {
     // Code here will be called immediately after each test (right
     // before the destructor).
   }

   // Objects declared here can be used by all tests in the test case for Foo.

   /** replace with your own **/
   Robots r1;
   Robots r2;

   Worm w1;
   Worm w2;

 };

 TEST(general, TESTSIMPLE) {

     /** replace with your own **/
     Robots r1;
     std::pair<int, int> x;

     r1.movePlayer("n");
     x.first = 2;
     x.second = 1;

     ASSERT_EQ(r1.player, x);
 }
 int main(int argc, char **argv) {

     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
 }
