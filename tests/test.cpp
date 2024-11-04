#include "pch.h"
#include "pum.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(TestCaseName, TestName) {
  EXPECT_FLOAT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Vector2DTest, vector2dtests) {
	pum::vector2d vec = pum::vector2d(10, 10);
	int len = vec.lengthsquare();
	EXPECT_FLOAT_EQ(len, 200);

	vec.normalize();
	EXPECT_FLOAT_EQ(vec.length(),1);

	EXPECT_NE(vec, pum::vector2d());

	vec.makelen(10);
	vec.makelen(20);
	len = vec.length();

	EXPECT_FLOAT_EQ(len, 20);

	vec = vec * 0;
	EXPECT_EQ(vec, pum::vector2d());
	vec = vec + pum::vector2d(20, 10);

	EXPECT_EQ(vec, pum::vector2d(20,10));

	vec = vec - pum::vector2d(10, 20);
	EXPECT_EQ(vec, pum::vector2d(10,-10));

	vec = vec / 2;
	EXPECT_EQ(vec, pum::vector2d(5, -5));

}

TEST(Vector2DTest, DotProduct) {
    // Test case 1: Orthogonal vectors (should be 0)
    pum::vector2d vec1(1, 0);
    pum::vector2d vec2(0, 1);
    EXPECT_FLOAT_EQ(pum::dotpro(vec1, vec2), 0); // 1*0 + 0*1 = 0

    // Test case 2: Same vectors (should be the square of the length)
    pum::vector2d vec3(3, 4);
    EXPECT_FLOAT_EQ(pum::dotpro(vec3, vec3), 25); // 3*3 + 4*4 = 9 + 16 = 25

    // Test case 3: Opposite vectors (should be negative of the square of the length)
    pum::vector2d vec4(-3, -4);
    EXPECT_FLOAT_EQ(pum::dotpro(vec3, vec4), -25); // 3*(-3) + 4*(-4) = -9 - 16 = -25

    // Test case 4: Mixed values
    pum::vector2d vec5(2, 3);
    pum::vector2d vec6(4, 1);
    EXPECT_FLOAT_EQ(pum::dotpro(vec5, vec6), 11); // 2*4 + 3*1 = 8 + 3 = 11

    // Test case 5: Zero vector
    pum::vector2d vec7(0, 0);
    EXPECT_FLOAT_EQ(pum::dotpro(vec5, vec7), 0); // Any vector dot zero vector should be 0

    // Test case 6: Unit vectors
    pum::vector2d vec8(1, 0);
    pum::vector2d vec9(0, 1);
    EXPECT_FLOAT_EQ(pum::dotpro(vec8, vec9), 0); // Unit vectors in different directions

    // Test case 7: Negative and positive vectors
    pum::vector2d vec10(-1, -2);
    pum::vector2d vec11(1, 2);
    EXPECT_FLOAT_EQ(pum::dotpro(vec10, vec11), -5); // (-1)*1 + (-2)*2 = -1 - 4 = -5
}

// Test suite for cross product
TEST(Vector2DTest, CrossProduct) {
    // Test case 1: Orthogonal vectors (should be positive)
    pum::vector2d vec1(1, 0);
    pum::vector2d vec2(0, 1);
    EXPECT_FLOAT_EQ(pum::crosspro(vec1, vec2), 1); // 1*1 - 0*0 = 1

    // Test case 2: Opposite vectors (should be negative)
    pum::vector2d vec3(-1, 0);
    pum::vector2d vec4(0, -1);
    EXPECT_FLOAT_EQ(pum::crosspro(vec3, vec4), 1); // -1*(-1) - 0*0 = 1

    // Test case 3: Collinear vectors (should be 0)
    pum::vector2d vec5(2, 4);
    pum::vector2d vec6(1, 2);
    EXPECT_FLOAT_EQ(pum::crosspro(vec5, vec6), 0); // 2*2 - 4*1 = 0

    // Test case 4: Mixed values
    pum::vector2d vec7(3, 2);
    pum::vector2d vec8(1, 5);
    EXPECT_FLOAT_EQ(pum::crosspro(vec7, vec8), 13); // 3*5 - 2*1 = 15 - 2 = 13

    // Test case 5: Zero vector
    pum::vector2d vec9(0, 0);
    pum::vector2d vec10(1, 1);
    EXPECT_FLOAT_EQ(pum::crosspro(vec9, vec10), 0); // 0*1 - 0*1 = 0

    // Test case 6: Negative vectors
    pum::vector2d vec11(-1, -1);
    pum::vector2d vec12(1, 2);
    EXPECT_FLOAT_EQ(pum::crosspro(vec11, vec12), -1); // -1*2 - (-1)*1 = -2 + 1 = -1
}


// Test suite for projectcircle
TEST(ProjectCircleTest, BasicProjection) {
    pum::vector2d line(1, 0);    // Horizontal line along x-axis
    pum::vector2d point(5, 5);   // Point above the line
    double radius = 3;

    auto result = projectcircle(line, point, radius);
    EXPECT_FLOAT_EQ(result.first, 2);  // Expected values based on calculations
    EXPECT_FLOAT_EQ(result.second, 8);  // Expected values based on calculations
}

TEST(ProjectCircleTest, VerticalLine) {
    pum::vector2d line(0, 1);    // Vertical line along y-axis
    pum::vector2d point(5, 5);   // Point to the right of the line
    double radius = 4;

    auto result = projectcircle(line, point, radius);
    EXPECT_FLOAT_EQ(result.first, 1);   // Expected values based on calculations
    EXPECT_FLOAT_EQ(result.second, 9);   // Expected values based on calculations
}

TEST(ProjectCircleTest, ZeroRadius) {
    pum::vector2d line(1, 0);     // Horizontal line
    pum::vector2d point(2, 2);    // Point above the line
    double radius = 0;

    auto result = projectcircle(line, point, radius);
    EXPECT_FLOAT_EQ(result.first, 2);    // The point itself should be the projection
    EXPECT_FLOAT_EQ(result.second, 2);    // Same, since radius is zero
}

TEST(ProjectCircleTest, NegativeRadius) {
    pum::vector2d line(0, -1);    // Line pointing down
    pum::vector2d point(2, 2);    // Point above the line
    double radius = -3;

    auto result = projectcircle(line, point, radius);
    EXPECT_FLOAT_EQ(result.first, -5);   // Depending on implementation, check expected values
    EXPECT_FLOAT_EQ(result.second, 1);  // Depending on implementation, check expected values
}

TEST(ProjectCircleTest, EdgeCasePointOnLine) {
    pum::vector2d line(1, 1);     // Diagonal line
    pum::vector2d point(3, 3);    // Point on the line
    double radius = 2;

    auto result = projectcircle(line, point, radius);
    EXPECT_FLOAT_EQ(result.first, 2.24264);    // Expected values based on calculations
    EXPECT_FLOAT_EQ(result.second, 6.24264);    // Expected values based on calculations
}

TEST(ProjectCircleTest, CollinearPointAndLine) {
    pum::vector2d line(1, 1);     // Diagonal line
    pum::vector2d point(4, 4);    // Point that is far away but collinear
    double radius = 5;

    auto result = projectcircle(line, point, radius);
    EXPECT_FLOAT_EQ(result.first, 0.65685427);    // Expected values based on calculations
    EXPECT_FLOAT_EQ(result.second, 10.65685427);   // Expected values based on calculations
}


// Test suite for projectpolygon
TEST(ProjectPolygonTest, BasicProjection) {
    pum::vector2d line(1, 0); // Horizontal line
    std::vector<pum::vector2d> points = {
        pum::vector2d(1, 1),
        pum::vector2d(2, 2),
        pum::vector2d(3, 3)
    };

    auto result = projectpolygon(line, points);
    EXPECT_EQ(result.first, 1);  // Minimum projection should be at (1, 1)
    EXPECT_EQ(result.second, 3);  // Maximum projection should be at (3, 3)
}

TEST(ProjectPolygonTest, VerticalLine) {
    pum::vector2d line(0, 1); // Vertical line
    std::vector<pum::vector2d> points = {
        pum::vector2d(1, 1),
        pum::vector2d(2, 2),
        pum::vector2d(3, 3)
    };

    auto result = projectpolygon(line, points);
    EXPECT_EQ(result.first, 1);  // Minimum projection
    EXPECT_EQ(result.second, 3);  // Maximum projection
}

TEST(ProjectPolygonTest, MixedCoordinates) {
    pum::vector2d line(1, 1); // Diagonal line
    std::vector<pum::vector2d> points = {
        pum::vector2d(1, 2),
        pum::vector2d(2, 1),
        pum::vector2d(-1, -1),
        pum::vector2d(0, 0)
    };

    auto result = projectpolygon(line, points);
    EXPECT_DOUBLE_EQ(result.first, -2); // Expect minimum projection
    EXPECT_DOUBLE_EQ(result.second, 3); // Expect maximum projection
}

TEST(ProjectPolygonTest, ZeroLengthLine) {
    pum::vector2d line(0, 0); // Zero vector as line
    std::vector<pum::vector2d> points = {
        pum::vector2d(1, 1),
        pum::vector2d(2, 2),
        pum::vector2d(3, 3)
    };

    auto result = projectpolygon(line, points);
    EXPECT_EQ(result.first, 0); // Minimum projection should remain at max
    EXPECT_EQ(result.second, 0); // Maximum projection should remain at min
}

TEST(ProjectPolygonTest, EmptyPoints) {
    pum::vector2d line(1, 0); // Any line
    std::vector<pum::vector2d> points; // Empty vector

    auto result = projectpolygon(line, points);
    EXPECT_EQ(result.first, LLONG_MAX); // Minimum should still be max
    EXPECT_EQ(result.second, LLONG_MIN); // Maximum should still be min
}

TEST(ProjectPolygonTest, NegativeCoordinates) {
    pum::vector2d line(1, 1); // Diagonal line
    std::vector<pum::vector2d> points = {
        pum::vector2d(-1, -2),
        pum::vector2d(-2, -1),
        pum::vector2d(-3, -3)
    };

    auto result = projectpolygon(line, points);
    EXPECT_DOUBLE_EQ(result.first, -6); // Expect minimum projection
    EXPECT_DOUBLE_EQ(result.second, -3); // Expect maximum projection
}


// test cases for DistanceFromLineSegmentTest///////////////////////////////////////////
TEST(DistanceFromLineSegmentTest, PointOnSegment) {
    pum::vector2d a(0, 0);
    pum::vector2d b(4, 4);
    pum::vector2d p(2, 2); // Point on the line segment

    pum::pointlineprojectresult result = distanceFromLinesegment(a, b, p);
    EXPECT_DOUBLE_EQ(result.distance, 0); // Distance should be 0
    EXPECT_EQ(result.projectionpoint, p); // Projection point should be the same as p
}

TEST(DistanceFromLineSegmentTest, PointCloseToSegment) {
    pum::vector2d a(0, 0);
    pum::vector2d b(4, 4);
    pum::vector2d p(2, 3); // Point close to the line segment

    pum::pointlineprojectresult result = distanceFromLinesegment(a, b, p);
    EXPECT_NEAR(result.distance, 0.7071, 1e-5); // Check the distance is approximately 1
}

TEST(DistanceFromLineSegmentTest, PointAboveSegment) {
    pum::vector2d a(0, 0);
    pum::vector2d b(4, 4);
    pum::vector2d p(2, 5); // Point above the line segment

    pum::pointlineprojectresult result = distanceFromLinesegment(a, b, p);
    EXPECT_NEAR(result.distance, 2.1213,0.0001); // Expected distance to be √2
}

TEST(DistanceFromLineSegmentTest, PointBelowSegment) {
    pum::vector2d a(0, 0);
    pum::vector2d b(4, 4);
    pum::vector2d p(2, -1); // Point below the line segment

    pum::pointlineprojectresult result = distanceFromLinesegment(a, b, p);
    EXPECT_NEAR(result.distance, 2.1213, 0.0001); // Expected distance to be √2
}

TEST(DistanceFromLineSegmentTest, PointLeftOfSegment) {
    pum::vector2d a(0, 0);
    pum::vector2d b(4, 4);
    pum::vector2d p(-1, 2); // Point to the left of the line segment

    pum::pointlineprojectresult result = distanceFromLinesegment(a, b, p);
    EXPECT_NEAR(result.distance, 2.1213, 0.0001); // Expected distance to be √2
}

TEST(DistanceFromLineSegmentTest, PointRightOfSegment) {
    pum::vector2d a(0, 0);
    pum::vector2d b(4, 4);
    pum::vector2d p(5, 2); // Point to the right of the line segment

    pum::pointlineprojectresult result = distanceFromLinesegment(a, b, p);
    EXPECT_NEAR(result.distance, 2.1213,0.0001); // Expected distance to be √2
}

TEST(DistanceFromLineSegmentTest, EndpointA) {
    pum::vector2d a(0, 0);
    pum::vector2d b(4, 4);
    pum::vector2d p(0, 0); // Point at endpoint A

    pum::pointlineprojectresult result = distanceFromLinesegment(a, b, p);
    EXPECT_DOUBLE_EQ(result.distance, 0); // Distance should be 0
    EXPECT_EQ(result.projectionpoint, p); // Projection point should be A
}

TEST(DistanceFromLineSegmentTest, EndpointB) {
    pum::vector2d a(0, 0);
    pum::vector2d b(4, 4);
    pum::vector2d p(4, 4); // Point at endpoint B

    pum::pointlineprojectresult result = distanceFromLinesegment(a, b, p);
    EXPECT_DOUBLE_EQ(result.distance, 0); // Distance should be 0
    EXPECT_EQ(result.projectionpoint, p); // Projection point should be B
}

TEST(DistanceFromLineSegmentTest, PointOutsideSegment) {
    pum::vector2d a(0, 0);
    pum::vector2d b(4, 4);
    pum::vector2d p(5, 5); // Point outside the line segment

    pum::pointlineprojectresult result = distanceFromLinesegment(a, b, p);
    EXPECT_NEAR(result.distance, sqrt(2), 1e-5); // Expected distance to be √2
}

TEST(DegreeToRadianTest, ZeroDegrees) {
    EXPECT_DOUBLE_EQ(pum::deg2rad(0), 0);
}

TEST(DegreeToRadianTest, NinetyDegrees) {
    EXPECT_DOUBLE_EQ(pum::deg2rad(90), 3.14159 / 2);
}

TEST(DegreeToRadianTest, OneEightyDegrees) {
    EXPECT_DOUBLE_EQ(pum::deg2rad(180), 3.14159);
}

TEST(DegreeToRadianTest, TwoSeventyDegrees) {
    EXPECT_DOUBLE_EQ(pum::deg2rad(270), 3 * 3.14159 / 2);
}

TEST(DegreeToRadianTest, ThreeSixtyDegrees) {
    EXPECT_DOUBLE_EQ(pum::deg2rad(360), 2 * 3.14159);
}

TEST(DegreeToRadianTest, FortyFiveDegrees) {
    EXPECT_DOUBLE_EQ(pum::deg2rad(45), 3.14159 / 4);
}

TEST(DegreeToRadianTest, ThirtyDegrees) {
    EXPECT_DOUBLE_EQ(pum::deg2rad(30), 3.14159 / 6);
}

TEST(DegreeToRadianTest, NegativeNinetyDegrees) {
    EXPECT_DOUBLE_EQ(pum::deg2rad(-90), -3.14159 / 2);
}

TEST(DegreeToRadianTest, OneDegree) {
    EXPECT_DOUBLE_EQ(pum::deg2rad(1), 3.14159 / 180);
}

TEST(DegreeToRadianTest, LargeAngle) {
    EXPECT_DOUBLE_EQ(pum::deg2rad(1800), 10 * 3.14159);
}

TEST(DegreeToRadianTest, LargeNonStandardAngle) {
    EXPECT_NEAR(pum::deg2rad(1000), 1000 * 3.14159 / 180, 1e-5); // Using EXPECT_NEAR for floating-point comparison
}


TEST(RadianToDegreeTest, ZeroRadians) {
    EXPECT_DOUBLE_EQ(pum::rad2deg(0), 0);
}

TEST(RadianToDegreeTest, PiOverTwoRadians) {
    EXPECT_DOUBLE_EQ(pum::rad2deg(3.14159 / 2), 90);
}

TEST(RadianToDegreeTest, PiRadians) {
    EXPECT_DOUBLE_EQ(pum::rad2deg(3.14159), 180);
}

TEST(RadianToDegreeTest, ThreePiOverTwoRadians) {
    EXPECT_DOUBLE_EQ(pum::rad2deg(3 * 3.14159 / 2), 270);
}

TEST(RadianToDegreeTest, TwoPiRadians) {
    EXPECT_DOUBLE_EQ(pum::rad2deg(2 * 3.14159), 360);
}

TEST(RadianToDegreeTest, PiOverFourRadians) {
    EXPECT_DOUBLE_EQ(pum::rad2deg(3.14159 / 4), 45);
}

TEST(RadianToDegreeTest, PiOverSixRadians) {
    EXPECT_DOUBLE_EQ(pum::rad2deg(3.14159 / 6), 30);
}

TEST(RadianToDegreeTest, NegativePiOverTwoRadians) {
    EXPECT_DOUBLE_EQ(pum::rad2deg(-3.14159 / 2), -90);
}

TEST(RadianToDegreeTest, OneRadian) {
    EXPECT_NEAR(pum::rad2deg(1), 1 * (180.0 / 3.14159), 1e-5); // Using EXPECT_NEAR for floating-point comparison
}

TEST(RadianToDegreeTest, LargeAngle) {
    EXPECT_DOUBLE_EQ(pum::rad2deg(10 * 3.14159), 10 * 180); // 10π radians
}

TEST(RadianToDegreeTest, LargeNonStandardAngle) {
    EXPECT_NEAR(pum::rad2deg(1000), 1000 * (180.0 / 3.14159), 1e-5); // Using EXPECT_NEAR for floating-point comparison
}
