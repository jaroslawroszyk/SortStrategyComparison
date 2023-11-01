#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace ::testing;

class Calculator
{
public:
    virtual ~Calculator() {}
    virtual int Add(int a, int b) = 0;
};

class MockCalculator : public Calculator
{
public:
    MOCK_METHOD(int, Add, (int a, int b), (override));
};

class MathUtility
{
public:
    MathUtility(Calculator *calc) : calculator_(calc) {}

    int AddTwoNumbers(int a, int b)
    {
        return calculator_->Add(a, b);
    }

private:
    Calculator *calculator_;
};

TEST(NiceMockCalculatorTest, AddTwoNumbers)
{
    NiceMock<MockCalculator> nice_mockCalculator;
    MathUtility mathUtility(&nice_mockCalculator);

    EXPECT_CALL(nice_mockCalculator, Add(2, 3)).WillOnce(testing::Return(5));
    EXPECT_CALL(nice_mockCalculator, Add(0, 0)).WillOnce(testing::Return(0));

    EXPECT_EQ(mathUtility.AddTwoNumbers(2, 3), 5);
    EXPECT_EQ(mathUtility.AddTwoNumbers(0, 0), 0);
}

TEST(NiceMockCalculatorTest, AddTwoNumbers2)
{
    NiceMock<MockCalculator> nice_mockCalculator;
    MathUtility mathUtility(&nice_mockCalculator);

    EXPECT_EQ(mathUtility.AddTwoNumbers(2, 3), 0);
    EXPECT_EQ(mathUtility.AddTwoNumbers(0, 0), 0);
}
