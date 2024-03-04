#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Thermostat.hpp"

class MockHeater : public Heater {
public:
    MOCK_METHOD(void, start, (), (override));
};

class MockCooler : public Cooler {
public:
    MOCK_METHOD(void, start, (), (override));
};

class MockThermostat : public Thermostat {
public:
    MockHeater heater;
    MockCooler cooler;
    MockThermostat(int minTemp, int maxTemp) : Thermostat(minTemp, maxTemp, &heater, &cooler) {}
    MOCK_METHOD(int, getCurrentTemp, (), (override, const));
};

class ThermostatTests : public ::testing::Test {
protected:
    std::unique_ptr<MockThermostat> t;
    void SetUp() override {
        t = std::make_unique<MockThermostat>(15, 20);
    }
    // No need to explicitly call reset() in TearDown() thanks to smart pointers
    void TearDown() override {}

    
};

TEST_F(ThermostatTests, Increase)
{
    EXPECT_CALL(*t, getCurrentTemp()).WillOnce(testing::Return(7));
    EXPECT_CALL(t->heater, start()).Times(1);
    t->adjustTemp();
}

TEST_F(ThermostatTests, Decrease)
{
    EXPECT_CALL(*t, getCurrentTemp()).WillOnce(testing::Return(23));
    EXPECT_CALL(t->cooler, start()).Times(1);
    t->adjustTemp();
}

TEST_F(ThermostatTests, NoChange)
{
    EXPECT_CALL(*t, getCurrentTemp()).WillOnce(testing::Return(17));
    EXPECT_CALL(t->heater, start()).Times(0);
    EXPECT_CALL(t->cooler, start()).Times(0);
    t->adjustTemp();
}