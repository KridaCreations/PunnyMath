# pum namespace

## vector2d
This is a class defined under pum namespace.
For detailed documentation of the `vector2d` class, including methods and usage examples, please refer to the following file:

- [vector2d Class Documentation](/docs/vector2d.md)

### Features

- Operations for 2D vector math including addition, subtraction, scalar multiplication, division, and comparison.
- Functions for calculating the length, normalizing, and changing the length of vectors.
- Utility methods like `dotpro`, `crosspro`, and more.

### Example Usage

Refer to the code and examples in the documentation for a complete guide on how to use the `vector2d` class and associated functions.

## List of other Functions

1. `long double dotpro(vector2d a, vector2d b)`
2. `long double crosspro(vector2d a, vector2d b)`
3. `template<typename T> bool nearlyequal(T a, T b, long double thr)`
4. `bool nearlyequal(vector2d a, vector2d b, long double thr)`
5. `std::pair<long double, long double> projectcircle(pum::vector2d line, pum::vector2d point, double radius)`
6. `std::pair<double, double> projectpolygon(pum::vector2d line, std::vector<pum::vector2d>& points)`
7. `pointlineprojectresult distanceFromLinesegment(pum::vector2d a, pum::vector2d b, pum::vector2d p)`
8. `long double deg2rad(long double deg)`
9. `long double rad2deg(long double rad)`

You can find detailed documentation for other functions here
- [pumnamespace](/docs/pumnamespace.md).
