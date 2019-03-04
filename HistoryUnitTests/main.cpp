#include <iostream>

 #include "../gtest/gtest.h"
 #include "../History/game.h"
 #include "../History/player.h"
 #include "../History/playergamehistory.h"
 #include "../History/gamehistory.h"

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

 TEST(general, TESTGAMEFINALSCORE) {
     char c = 'w';
     Game g(new Player(), &c, 250);
     ASSERT_EQ(250, g.getFinalScore());
 }

 TEST(general, TESTGAMENAME) {
     char c = 'w';
     Game g(new Player(), &c, 250);
     ASSERT_EQ(&c, g.getName());
 }

 TEST(general, TESTGAMEHISTORYNUMBEROFGAMES) {
     GameHistory gh;
     gh.addGame(new Game());
     ASSERT_EQ(1, gh.getTotalGames());
 }

 TEST(general, TESTPLAYERFN) {
     char c = 'w';
     char r = 'r';
     char s = 'e';
     Player p(new Game(), &c, &r, &s);
     ASSERT_EQ(&c, p.getFirstName());
 }

 TEST(general, TESTPLAYERLN) {
     char c = 'w';
     char r = 'r';
     char s = 'e';
     Player p(new Game(), &c, &r, &s);
     ASSERT_EQ(&r, p.getLastName());
 }

 TEST(general, TESTPLAYERAD) {
     char c = 'w';
     char r = 'r';
     char s = 'e';
     Player p(new Game(), &c, &r, &s);
     ASSERT_EQ(&s, p.getAddress());
 }

 TEST(general, TESTPLAYERADDGAME) {
     char c = 'w';
     char r = 'r';
     char s = 'e';
     Player p(new Game(), &c, &r, &s);
     p.addToGameHistory(new Game());
     ASSERT_EQ(1, p.getGameHistory()->getTotalGames());
 }

 TEST(general, TESTPLAYERGAMEHISTORYNUMGAMES) {
     PlayerGameHistory pgh;
     pgh.addGame(new Game());
     ASSERT_EQ(1, pgh.numGamesPlayed());
 }

 TEST(general, TESTPLAYERGAMEHISTORYNUMPLAYERS) {
     PlayerGameHistory pgh;
     pgh.addPlayer(new Player());
     ASSERT_EQ(1, pgh.numPlayers());
 }

 int main(int argc, char **argv) {

     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
 }
