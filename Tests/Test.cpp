#include <gtest/gtest.h>
#include "../Source/health.h"
#include "../Source/player.h"
#include "../Source/healthPowerUp.h"
#include "../Source/rapidFirePowerup.h"

// Sample test
TEST(SampleTest, BasicAssertions)
{
    EXPECT_EQ(1, 1);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(HealthTest, NoinputConstructor) {
    Health* h = new Health();
    EXPECT_TRUE(h != nullptr);

    delete h;
    h = nullptr;
}

TEST(HealthTest,InputConstructor) {
    Health h(50);
    EXPECT_EQ(h.getHealth(), 50);
}

TEST(HealthTest, ReceiveDamage) {
    Health h(50);
    h.receiveDamage();
    EXPECT_EQ(h.getHealth(), 30);
    h.receiveDamage();
    EXPECT_EQ(h.getHealth(), 0);
}

TEST(HealthTest, ReceiveHealth) {
    Health h(50);
    h.receiveHealth(30);
    EXPECT_EQ(h.getHealth(), 80); //should fail as max health is 50

    h.receiveDamage();
    h.receiveDamage();
    h.receiveDamage();
    h.receiveDamage();
    h.receiveDamage();
    h.receiveHealth(50);
    EXPECT_EQ(h.getHealth(), 100);
}

TEST(HealthTest, BoundaryValues) {
    Health h(100);
    for(int i = 0; i<11; i++){
        h.receiveDamage();
    }
    EXPECT_EQ(h.getHealth(), 0);

    h.receiveHealth(200);
    EXPECT_EQ(h.getHealth(), 100);
}

TEST(PlayerTest, CanCallConstructor)
{
    Player *p = new Player();

    EXPECT_TRUE(p != nullptr);

    delete p;
    p = nullptr;
}

TEST(PlayerTest, )
