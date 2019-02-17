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

 };

 TEST(general, TESTNORTH) {

     /** replace with your own **/
     Robots r1;
     std::pair<int, int> x;

     r1.movePlayer("n");
     x.first = 3;
     r1.movePlayerN();
     x.first = 1;
     x.second = 1;


     ASSERT_EQ(r1.player, x);
 }

 TEST(general, TESTSOUTH) {

     /** replace with your own **/
     Robots r1;
     std::pair<int, int> x;

     r1.movePlayerS();
     x.first = 1;
     x.second = 3;


     ASSERT_EQ(r1.player, x);
 }

 TEST(general, TESTEAST) {

     /** replace with your own **/
     Robots r1;
     std::pair<int, int> x;

     r1.movePlayerE();
     x.first = 2;
     x.second = 2;


     ASSERT_EQ(r1.player, x);
 }

 TEST(general, TESTWEST) {

     /** replace with your own **/
     Robots r1;
     std::pair<int, int> x;

     r1.movePlayerW();
     x.first = 0;
     x.second = 2;

     ASSERT_EQ(r1.player, x);
 }

 TEST(general, TESTNORTHEAST) {

     /** replace with your own **/
     Robots r1;
     std::pair<int, int> x;

     r1.movePlayerNE();
     x.first = 0;
     x.second = 1;

     ASSERT_EQ(r1.player, x);
 }

 TEST(general, TESTNORTHWEST) {

     /** replace with your own **/
     Robots r1;
     std::pair<int, int> x;

     r1.movePlayerNW();
     x.first = 2;
>>>>>>> 265f09df1b41c1ddfea3c22ce1894ecd5942207a
     x.second = 1;

     ASSERT_EQ(r1.player, x);
 }

 TEST(general, TESTSOUTHEAST) {

     /** replace with your own **/
     Robots r1;
     std::pair<int, int> x;

     r1.movePlayerSE();
     x.first = 0;
     x.second = 3;

     ASSERT_EQ(r1.player, x);
 }

 TEST(general, TESTSOUTHWEST) {

     /** replace with your own **/
     Robots r1;
     std::pair<int, int> x;

     r1.movePlayerSW();
     x.first = 2;
     x.second = 3;

     ASSERT_EQ(r1.player, x);
 }


 int main(int argc, char **argv) {

     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
 }
