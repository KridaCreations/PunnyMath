# `pum` Namespace Functions

This library provides mathematical functions and utilities related to vectors and geometry. It includes operations such as dot product, cross product, projection of points and polygons, distance calculations, and unit conversions between degrees and radians.

## Functions

### `long double dotpro(vector2d a, vector2d b)`
Calculates the **dot product** of two 2D vectors.

**Parameters:**
- `a`: The first 2D vector (`vector2d`).
- `b`: The second 2D vector (`vector2d`).

**Returns:**
- The dot product of the two vectors as a `long double`.

---

### `long double crosspro(vector2d a, vector2d b)`
Calculates the **cross product** of two 2D vectors. In 2D, the cross product is a scalar that represents the magnitude of the vector perpendicular to the plane defined by `a` and `b`.

**Parameters:**
- `a`: The first 2D vector (`vector2d`).
- `b`: The second 2D vector (`vector2d`).

**Returns:**
- The cross product as a `long double`.

---

### `template<typename T> bool nearlyequal(T a, T b, long double thr)`
Checks whether two values `a` and `b` are approximately equal within a given threshold (`thr`).

**Parameters:**
- `a`: The first value.
- `b`: The second value.
- `thr`: The threshold value to compare the absolute difference between `a` and `b`.

**Returns:**
- `true` if the absolute difference between `a` and `b` is less than or equal to the threshold `thr`.
- `false` otherwise.

---

### `bool nearlyequal(vector2d a, vector2d b, long double thr)`
Checks whether two 2D vectors `a` and `b` are approximately equal within a given threshold (`thr`).

**Parameters:**
- `a`: The first 2D vector (`vector2d`).
- `b`: The second 2D vector (`vector2d`).
- `thr`: The threshold distance for the comparison.

**Returns:**
- `true` if the distance between the two vectors is less than or equal to `thr`.
- `false` otherwise.

---

### `std::pair<long double, long double> projectcircle(pum::vector2d line, pum::vector2d point, double radius)`
Projects a point onto a line and returns the scalar values representing the range where a circle (of given `radius`) intersects the line.

**Parameters:**
- `line`: The direction vector (`vector2d`) representing the line.
- `point`: The point (`vector2d`) from which the circle will be projected.
- `radius`: The radius of the circle to project.

**Returns:**
- A `std::pair` of `long double` values representing the left and right projections of the circle along the line.

---

### `std::pair<double, double> projectpolygon(pum::vector2d line, std::vector<pum::vector2d>& points)`
Projects a polygon onto a line and returns the scalar values representing the minimum and maximum projections of the polygon along the line.

**Parameters:**
- `line`: The direction vector (`vector2d`) representing the line.
- `points`: A vector of `vector2d` representing the vertices of the polygon.

**Returns:**
- A `std::pair` of `double` values representing the minimum and maximum projections of the polygon along the line.

---

### `pointlineprojectresult distanceFromLinesegment(pum::vector2d a, pum::vector2d b, pum::vector2d p)`
Calculates the perpendicular distance from a point `p` to a line segment defined by two points `a` and `b`, and also provides the projection point.

**Parameters:**
- `a`: The first point (`vector2d`) of the line segment.
- `b`: The second point (`vector2d`) of the line segment.
- `p`: The point (`vector2d`) from which the distance is calculated.

**Returns:**
- A `pointlineprojectresult` structure containing:
  - `distance`: The shortest distance between the point and the line segment.
  - `projectionpoint`: The point on the line segment closest to `p`.

---

### `long double deg2rad(long double deg)`
Converts an angle from **degrees** to **radians**.

**Parameters:**
- `deg`: The angle in degrees.

**Returns:**
- The angle in radians (`long double`).

---

### `long double rad2deg(long double rad)`
Converts an angle from **radians** to **degrees**.

**Parameters:**
- `rad`: The angle in radians.

**Returns:**
- The angle in degrees (`long double`).

---

## Additional Notes:
- **Vector2D Operations**: The functions assume you have a `vector2d` type defined with `x` and `y` as members representing the 2D vector coordinates.
- **Threshold (`thr`)**: In functions like `nearlyequal()`, a threshold value is used to determine if the difference between two values (either scalars or vectors) is small enough to be considered "equal."

## Example Usage

```cpp
#include "pch.h"
#include "pum.h"

int main()
{
    pum::vector2d a = {1.0, 2.0};
    pum::vector2d b = {3.0, 4.0};
    
    // Calculate dot product
    long double dot = pum::dotpro(a, b);
    std::cout << "Dot Product: " << dot << std::endl;
    
    // Calculate cross product
    long double cross = pum::crosspro(a, b);
    std::cout << "Cross Product: " << cross << std::endl;
    
    // Check if vectors are nearly equal
    bool equal = pum::nearlyequal(a, b, 0.1);
    std::cout << "Are vectors nearly equal? " << (equal ? "Yes" : "No") << std::endl;
    
    return 0;
}
