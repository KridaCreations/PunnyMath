#pragma once
#include <iostream>
#include<math.h>
#include<algorithm>
#include<vector>


// Sometimes libraries define max as a macro, which can lead to conflicts. You might find something like:
//#define max ...
//below lines are to remove this conflicts
#ifdef max
#undef max
#endif
//doing same for min
#ifdef min
#undef min
#endif


#ifdef punnymath_EXPORTS
#define punnymath_API __declspec(dllexport)
#else
#define punnymath_API __declspec(dllimport)
#endif

namespace pum {

	class vector2d
	{
	public:
		double x, y;

		vector2d(long double x, long double y)
		{
			this->x = x;
			this->y = y;
		}

		vector2d()
		{
			this->x = 0;
			this->y = 0;
		}

		[[nodiscard]] vector2d operator+(const vector2d& other) {
			return vector2d(this->x + other.x, this->y + other.y);
		}

		[[nodiscard]] vector2d operator-(const vector2d& other) {
			return vector2d(this->x - other.x, this->y - other.y);
		}

		template<typename T>
		[[nodiscard]] vector2d operator*(const T& mult) {
			return vector2d(this->x * (long double)mult, this->y * (long double)mult);
		}

		template<typename T>
		[[nodiscard]]  vector2d operator/(const T& div) {
			return vector2d(this->x / (long double)div, this->y / (long double)div);
		}

		template<typename T>
		vector2d operator=(vector2d &other)
		{
			other.x = this->x;
			other.y = this->y;
			return vector2d(this->x, this->y);
		}

		[[nodiscard]] bool operator==(const vector2d& second) const
		{
			return ((this->x == second.x) && (this->y == second.y));
		}

		[[nodiscard]] bool operator!=(const vector2d& second) const
		{
			return ((this->x != second.x) || (this->y != second.y));
		}

		double lengthsquare()
		{
			return (this->x * this->x) + (this->y * this->y);
		}

		double length()
		{
			return sqrt((this->x * this->x) + (this->y * this->y));
		}

		void normalize()
		{
			long double len = this->length();
			this->x = this->x / (long double)len;
			this->y = this->y / (long double)len;
		}

		void makelen(double newlen)
		{
			long double len = this->length();
			this->x = (this->x / len) * newlen;
			this->y = (this->y / len) * newlen;
		}

	};

	struct pointlineprojectresult {
		pum::vector2d projectionpoint = pum::vector2d(0, 0);
		double distance = 0;
	};

	punnymath_API long double dotpro(vector2d a, vector2d b);

	punnymath_API long double crosspro(vector2d a, vector2d b);
	
	template<typename T>
	punnymath_API bool nearlyequal(T a, T b, long double thr);
	
	punnymath_API bool nearlyequal(vector2d a, vector2d b, long double thr);

	punnymath_API std::pair<long double, long double> projectcircle(pum::vector2d line, pum::vector2d point, double radius);

	punnymath_API std::pair<double, double> projectpolygon(pum::vector2d line, std::vector<pum::vector2d>& points);

	punnymath_API pointlineprojectresult distanceFromLinesegment(pum::vector2d a, pum::vector2d b, pum::vector2d p);
	
	punnymath_API long double deg2rad(long double deg);
	
	punnymath_API long double rad2deg(long double rad);



}

