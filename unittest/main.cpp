#include <iostream>

 #include "gtest/gtest.h"
 #include "../lab/configuration.h"

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
   Configuration s1;
   Configuration s2;

 };

 TEST(general, TESTSIMPLE) {

     /** replace with your own **/
     Configuration s1;
     Configuration s2("test");
     ASSERT_EQ(s1.get_filename(), s2.get_filename()) << s1.get_filename()
                                                     << " and "
                                                     << s2.get_filename()
                                                     << " should match!";
 }

 TEST_F(FooTest, TESTFIXTURE) {

     /** replace with your own **/
     ASSERT_EQ(s1.get_filename(), s2.get_filename()) << "These should match!";
 }

 int main(int argc, char **argv) {

     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
 }
