# `vector2d` Class Documentation

The `vector2d` class is designed to represent and manipulate 2D vectors, offering various vector operations such as addition, subtraction, scalar multiplication, and more.

## Constructor

### `vector2d(long double x, long double y)`

- **Parameters:**
  - `x`: The x-coordinate of the vector.
  - `y`: The y-coordinate of the vector.

- **Description:**
  This constructor initializes the vector with the given `x` and `y` values.

### `vector2d()`

- **Description:**
  Default constructor, which initializes the vector to `(0, 0)`.

## Methods

### `vector2d operator+(const vector2d& other)`

- **Parameters:**
  - `other`: The vector to be added to the current vector.
  
- **Returns:** A new `vector2d` representing the sum of the two vectors.
  
- **Description:**
  Adds the current vector to another vector and returns the result.

### `vector2d operator-(const vector2d& other)`

- **Parameters:**
  - `other`: The vector to be subtracted from the current vector.

- **Returns:** A new `vector2d` representing the difference of the two vectors.

- **Description:**
  Subtracts the given vector from the current vector and returns the result.

### `template<typename T> vector2d operator*(const T& mult)`

- **Parameters:**
  - `mult`: The scalar value by which the vector is multiplied.

- **Returns:** A new `vector2d` with the result of the scalar multiplication.

- **Description:**
  Multiplies the vector by a scalar value.

### `template<typename T> vector2d operator/(const T& div)`

- **Parameters:**
  - `div`: The scalar value by which the vector is divided.

- **Returns:** A new `vector2d` with the result of the scalar division.

- **Description:**
  Divides the vector by a scalar value.

### `template<typename T> vector2d operator=(vector2d& other)`

- **Parameters:**
  - `other`: The vector whose values will be copied to the current vector.

- **Returns:** The current vector with the new values from `other`.

- **Description:**
  Assigns the values of another vector to the current vector.

### `bool operator==(const vector2d& second) const`

- **Parameters:**
  - `second`: The vector to be compared with the current vector.

- **Returns:** `true` if the vectors are equal, `false` otherwise.

- **Description:**
  Checks if the current vector is equal to another vector.

### `bool operator!=(const vector2d& second) const`

- **Parameters:**
  - `second`: The vector to be compared with the current vector.

- **Returns:** `true` if the vectors are not equal, `false` otherwise.

- **Description:**
  Checks if the current vector is not equal to another vector.

### `double lengthsquare()`

- **Returns:** The square of the vector's length.

- **Description:**
  Calculates the squared length (magnitude) of the vector without computing the square root.

### `double length()`

- **Returns:** The length (magnitude) of the vector.

- **Description:**
  Computes the length (magnitude) of the vector using the Euclidean distance formula.

### `void normalize()`

- **Description:**
  Normalizes the vector to a unit vector (magnitude = 1).

### `void makelen(double newlen)`

- **Parameters:**
  - `newlen`: The desired length for the vector.

- **Description:**
  Scales the vector to the specified length while maintaining its direction.

## Usage Example

```cpp
#include "vector2d.h"

// Create two vectors
vector2d v1(3.0, 4.0);
vector2d v2(1.0, 2.0);

// Add vectors
vector2d result = v1 + v2;  // result is (4.0, 6.0)

// Compute the length of a vector
double len = v1.length();  // len is 5.0

// Normalize the vector
v1.normalize();  // v1 becomes (0.6, 0.8) since its length is 1
