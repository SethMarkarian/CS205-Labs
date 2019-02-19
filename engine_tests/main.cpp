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

     //r1.movePlayer("n");
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

 TEST(general, TESTROBOTMOVEMENT1) {

     /** replace with your own **/
     Robots r1;
     std::pair<int, int> x;

     r1.movePlayerN();
     r1.moveRobots();
     x.first = 1;
     x.second = 2;

     ASSERT_EQ(r1.robots[0], x);
 }

 TEST(general, TESTROBOTMOVEMENT2) {

     /** replace with your own **/
     Robots r1;
     std::pair<int, int> x;

     r1.movePlayerN();
     r1.moveRobots();
     x.first = 1;
     x.second = 2;

     ASSERT_EQ(r1.robots[1], x);
 }

 TEST(general, TESTRANDOMTELEPORT) {

     /** replace with your own **/
     Robots r1;
     Robots r2;

     r1.randomTeleport();
     r2.randomTeleport();

     bool isAns = r1.player != r2.player;

     ASSERT_EQ(isAns, true);
 }

 TEST(general, TESTROBOTCOLLISIONS) {

     /** replace with your own **/
     Robots r1;

     r1.movePlayerN();
     r1.moveRobots();
     bool isAns = r1.isDead();

     ASSERT_EQ(isAns, true);

}

 TEST(general, TESTROBOTWIN) {

     /** replace with your own **/
     Robots r1;

     r1.robots[0].first = -1;
     r1.robots[0].second = -1;
     r1.robots[1].first = -1;
     r1.robots[1].second = -1;
     r1.robots[2].first = -1;
     r1.robots[2].second = -1;

     bool isAns = r1.win();

     ASSERT_EQ(isAns, true);

}


 TEST(general, TESTRIGHTWORM)
 {
     Worm w(17);
     w.right();
     std::pair<int, int> s1;
     std::pair<int, int> s2;
     std::vector<std::pair<int, int>> truth;
     s1.first = 2;
     s1.second = 3;
     s2.first = 2;
     s2.second = 2;
     truth.push_back(s1);
     truth.push_back(s2);
     ASSERT_EQ(w.get_worm(), truth);
 }

 TEST(general, TESTDOWNWORM)
 {
     Worm w(17);
     w.down();
     std::pair<int, int> s1;
     std::pair<int, int> s2;
     std::vector<std::pair<int, int>> truth;
     s1.first = 3;
     s1.second = 2;
     s2.first = 2;
     s2.second = 2;
     truth.push_back(s1);
     truth.push_back(s2);
     ASSERT_EQ(w.get_worm(), truth);
 }

 TEST(general, TESTUPWORM)
 {
     Worm w(17);
     w.up();
     std::pair<int, int> s1;
     std::pair<int, int> s2;
     std::vector<std::pair<int, int>> truth;
     s1.first = 1;
     s1.second = 2;
     s2.first = 2;
     s2.second = 2;
     truth.push_back(s1);
     truth.push_back(s2);
     ASSERT_EQ(w.get_worm(), truth);
 }

 TEST(general, TESTINTOBODYWORM)
 {
     Worm w(17);
     w.left();
     ASSERT_EQ(w.lost_yet, true);
 }

 TEST(general, TESTLEFTWORM)
 {
     Worm w(17);
     w.down();
     w.left();
     std::pair<int, int> s1;
     std::pair<int, int> s2;
     std::vector<std::pair<int, int>> truth;
     s1.first = 3;
     s1.second = 1;
     s2.first = 3;
     s2.second = 2;
     truth.push_back(s1);
     truth.push_back(s2);
     ASSERT_EQ(w.get_worm(), truth);
 }

 TEST(general, TESTSCOREWORM)
 {
     Worm w(17);
     w.up();
     w.left();
     ASSERT_EQ(w.score, 1);
 }

 TEST(general, TESTGETWORM)
 {
     Worm w(17);
     char c = w.get(0, 0);
     ASSERT_EQ(c, '*');
 }

 TEST(general, TESTINSERTWORM)
 {
     Worm w(17);
     w.insert(1, 2, 'c');
     char c = w.get(1, 2);
     ASSERT_EQ(c, 'c');
 }

 TEST(general, TESTREMOVEWORM)
 {
     Worm w(17);
     w.insert(1, 2, 'c');
     w.remove(1, 2);
     char c = w.get(1, 2);
     ASSERT_EQ(c, ' ');
 }
 TEST(general, TESTGETWORMWORM)
 {
     Worm w(17);
     std::pair<int, int> s1;
     std::pair<int, int> s2;
     std::vector<std::pair<int, int>> truth;
     s1.first = 2;
     s1.second = 2;
     s2.first = 2;
     s2.second = 1;
     truth.push_back(s1);
     truth.push_back(s2);
     ASSERT_EQ(w.get_worm(), truth);
 }

 int main(int argc, char **argv) {

     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
 }
