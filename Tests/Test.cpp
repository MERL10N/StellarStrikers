#include <gtest/gtest.h>
#include "../Source/health.h"
#include "../Source/player.h"
#include "../Source/powerup.h"
#include "../Source/healthPowerUp.h"
#include "../Source/rapidFirePowerup.h"
#include "../Source/Enemy.h"
#include "../Source/gameManager.h"
#include "../Source/rocket.h"


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(HealthTest, NoinputConstructor)
{
    auto* h = new Health();
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
    h.receiveDamage(20);
    EXPECT_EQ(h.getHealth(), 30);
    h.receiveDamage(30);
    EXPECT_EQ(h.getHealth(), 0);
}

TEST(HealthTest, ReceiveHealth) {
    Health h(50);
    h.receiveHealth(30); 
    EXPECT_EQ(h.getHealth(), 50); 

    h.receiveDamage(10); 
    h.receiveDamage(10); 
    h.receiveDamage(10); 
    EXPECT_EQ(h.getHealth(), 20); 
    h.receiveHealth(50); 
    EXPECT_EQ(h.getHealth(), 50); 
}

TEST(HealthTest, BoundaryValues)
{
    Health h(100);
    for(int i = 0; i<11; i++){
        h.receiveDamage(10);
    }
    EXPECT_EQ(h.getHealth(), 0);

    h.receiveHealth(200);
    EXPECT_EQ(h.getHealth(), 100);
}

TEST(PlayerTest, CanGetPlayerPositionX)
{
    auto p = Player();
    EXPECT_EQ(p.getPosition().x, 100);
}

TEST(PlayerTest, CanGetPlayerPositionY)
{
    auto p = Player();
    EXPECT_EQ(p.getPosition().y, 250);
}

TEST(PlayerTest, CanCallConstructor)
{
    const auto* p = new Player();
    EXPECT_TRUE(p != nullptr);
    delete p;
    p = nullptr;
}

TEST(PlayerTest, CanCallDestructor)
{
    const auto* p = new Player();
    delete p;
    p = nullptr;
    EXPECT_TRUE(p == nullptr);
}

TEST(PlayerTest, PlayerHealthInitialised)
{
    auto* p = new Player();
    p->getHealth();
    EXPECT_EQ(p->getHealth(), 100);
    delete p;
    p = nullptr;
}

TEST(PlayerTest, PlayerHealthDamage)
{
    auto* p = new Player();
    p->receiveDamage(10);
    EXPECT_EQ(p->getHealth(), 90);
    delete p;
    p = nullptr;
}



TEST(EnemyTest, CanCallConstructor)
{
    const auto* p = new Enemy();
    EXPECT_TRUE(p != nullptr);
    delete p;
    p = nullptr;
}

TEST(EnemyTest, CanCallDestructor)
{
    const auto* p = new Enemy();
    delete p;
    p = nullptr;
    EXPECT_TRUE(p == nullptr);
}

TEST(EnemyTest, IsEnemyAlive)
{
    const auto* p = new Enemy();
    EXPECT_TRUE(!p->IsAlive());
    delete p;
    p = nullptr;
}

TEST(EnemyTest, TestForEmptyBullets)
{
    auto* p = new Enemy();
    EXPECT_TRUE(p->getBullets().empty());
    delete p;
    p = nullptr;
}

TEST(EnemyTest, TestForEnemyShootState)
{
    auto* p = new Enemy();
    p->setState(Enemy::State::SHOOT);
    EXPECT_EQ(p->getState(), Enemy::State::SHOOT);
    delete p;
    p = nullptr;
}

TEST(EnemyTest, TestForEnemyChaseState)
{
    auto* p = new Enemy();
    p->setState(Enemy::State::CHASE);
    EXPECT_EQ(p->getState(), Enemy::State::CHASE);
    delete p;
    p = nullptr;
}

TEST(EnemyTest, TestForEnemyDieState)
{
    auto* p = new Enemy();
    p->setState(Enemy::State::DIE);
    EXPECT_EQ(p->getState(), Enemy::State::DIE);
    delete p;
    p = nullptr;
}


TEST(HealthPowerupTest, TestForConstructor)
{
    Powerup* powerup = new HealthPowerUp();
    EXPECT_TRUE(powerup != nullptr);
    delete powerup;
    powerup = nullptr;
}

TEST(HealthPowerupTest, TestForDestructor)
{
    Powerup* powerup = new HealthPowerUp();

    delete powerup;
    powerup = nullptr;
    EXPECT_TRUE(powerup == nullptr);
}

TEST(HealthPowerupTest, TestForActivePowerup)
{
    Powerup* powerup = new HealthPowerUp();
    EXPECT_TRUE(powerup->getActive());
    delete powerup;
    powerup = nullptr;
}

TEST(RapidFirePowerupTest, CanCallConstructor)
{
    auto* powerup = new RapidFirePowerup(Vector2{100, 200}, 1.0f, ASSETS_PATH"playerbullet.png");
    EXPECT_TRUE(powerup != nullptr);
    delete powerup;
}

TEST(RapidFirePowerupTest, CanCallDestructor)
{
    auto* powerup = new RapidFirePowerup(Vector2{100, 200}, 1.0f, ASSETS_PATH"playerbullet.png");
    delete powerup;
    powerup = nullptr;
    EXPECT_TRUE(powerup == nullptr);
}

TEST(RapidFirePowerupTest, IsPowerupActive)
{
    auto* powerup = new RapidFirePowerup(Vector2{100, 200}, 1.0f, ASSETS_PATH"rapidfirepowerup.png");
    auto player = Player();
    powerup->activatePowerup(player);
    EXPECT_TRUE(powerup->getActive());
}

TEST(RapidFirePowerupTest, IsPowerupInactive)
{
    auto* powerup = new RapidFirePowerup(Vector2{100, 200}, 1.0f, ASSETS_PATH"rapidfirepowerup.png");
    auto player = Player();
    powerup->activatePowerup(player);
    powerup->deactivatePowerup(player);
    EXPECT_FALSE(powerup->getActive());
}

TEST(GameTest, CanCallConstructor)
{
    auto* game = new Game();
    EXPECT_FALSE(game == nullptr);
    delete game;
    game = nullptr;
}

TEST(GameTest, CanCallDestructor)
{
    auto* game = new Game();
    delete game;
    game = nullptr;
    EXPECT_TRUE(game == nullptr);
}

TEST(BulletTest, CanCallBulletConstructor)
{
    auto* bullet = new Bullet(Vector2{100, 200}, 0.0f);
    EXPECT_TRUE(bullet != nullptr);
    delete bullet;
    bullet = nullptr;
}

TEST(BulletTest, CanCallBulletDestructor)
{
    auto* bullet = new Bullet(Vector2{100, 200}, 0.0f);
    delete bullet;
    bullet = nullptr;
    EXPECT_TRUE(bullet == nullptr);
}

TEST(RocketTest, CanCallRocketConstructor)
{
    auto* rocket = new Rocket(Vector2{100, 200}, 0.0f);
    EXPECT_TRUE(rocket != nullptr);
    delete rocket;
    rocket = nullptr;
}

TEST(RocketTest, CanCallRocketDestructor)
{
    const auto* rocket = new Rocket(Vector2{100, 200}, 0.0f);
    delete rocket;
    rocket = nullptr;
    EXPECT_TRUE(rocket == nullptr);
}