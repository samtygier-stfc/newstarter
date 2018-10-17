//
// Created by dolica on 16/10/18.
//

#include <gtest/gtest.h>
#include "../src/Triangle.h"

class TriangleTests : public ::testing::Test {

public:
  double triangleBase = 3.8;
  double triangleHeight = 5.3;
  Triangle myTriangle = Triangle(triangleBase,triangleHeight);
};

TEST_F(TriangleTests, first_test)
{
  EXPECT_FLOAT_EQ(myTriangle.GetBase(), triangleBase);
  EXPECT_FLOAT_EQ(myTriangle.GetHeight(), triangleHeight);
  EXPECT_FLOAT_EQ(myTriangle.GetArea(), triangleBase * 0.5 * triangleHeight);
  EXPECT_FLOAT_EQ(myTriangle.GetPerimeter(), triangleBase + 2 * std::sqrt(triangleBase * triangleBase * 0.25 + triangleHeight * triangleHeight));

  EXPECT_EQ(myTriangle.GetNumSides(),3);

  EXPECT_TRUE("Triangle" == myTriangle.GetType());
}
