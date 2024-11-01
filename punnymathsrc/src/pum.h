#pragma once
#include <iostream>
#include<math.h>

extern "C++" namespace pum {

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

		[[nodiscard]] bool operator==( vector2d& second)
		{
			return ((this->x == second.x) && (this->y == second.y));
		}

		[[nodiscard]] bool operator!=(vector2d& second)
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
			this->x = this->x / len;
			this->y = this->y / len;
		}

		void makelen(double newlen)
		{
			long double len = this->length();
			this->x = (this->x / len) * newlen;
			this->y = (this->y / len) * newlen;
		}

	};

	inline long double dotpro(vector2d a, vector2d b)
	{
		long double result = (a.x * a.y) + (b.x + b.y);
		return result;
	}

	inline long double crosspro(vector2d a, vector2d b)
	{
		long double result = a.x * b.y - a.y * b.x;
		return result;
	}

	template<typename T>
	inline bool nearlyequal(T a, T b,long double thr)
	{
		std::cout << "int " << std::endl;
		long double diff = a - b;
		return std::abs(diff) <= thr;
	}

	bool nearlyequal(vector2d a, vector2d b, long double thr);

	inline bool nearlyequal(vector2d a, vector2d b, long double thr)
	{
		vector2d diff = a - b;
		long double mag = diff.length();
		return mag <= thr;
	}
	
}

