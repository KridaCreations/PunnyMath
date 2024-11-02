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

	inline long double dotpro(vector2d a, vector2d b)
	{
		long double result = (a.x * b.x) + (a.y * b.y);
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

	
	inline bool nearlyequal(vector2d a, vector2d b, long double thr)
	{
		vector2d diff = a - b;
		long double mag = diff.length();
		return mag <= thr;
	}

	
	inline std::pair<long double, long double> projectcircle(pum::vector2d line, pum::vector2d point, double radius)
	{
		line.normalize();

		pum::vector2d temp = (line * radius);
		pum::vector2d left = point - line * radius;
		pum::vector2d right = point + line * radius;
		double dotleft = dotpro(line, left);
		double dotright = dotpro(line, right);
		if (dotleft < dotright)
			return std::pair<double, double>(dotleft, dotright);
		return std::pair<double, double>(dotright, dotleft);
	}

	inline std::pair<double, double> projectpolygon(pum::vector2d line, std::vector<pum::vector2d>& points)
	{
		double minim = LLONG_MAX;
		double maxim = LLONG_MIN;
		for (int point = 0; point < points.size(); point++)
		{
			pum::vector2d p = points[point];
			double val = dotpro(line, p);
			minim = std::min(minim, val);
			maxim = std::max(maxim, val);
		}
		return std::pair<double, double>(minim, maxim);
	}

	inline pointlineprojectresult distanceFromLinesegment(pum::vector2d a, pum::vector2d b, pum::vector2d p)
	{

		pointlineprojectresult result;

		pum::vector2d ab = b - a;
		pum::vector2d ap = p - a;
		double dot = pum::dotpro(ab, ap);

		double d = dot / ab.lengthsquare();
		pum::vector2d cp;
		if (d <= 0.0)
		{
			cp = a;
		}
		else if (d >= 1.0)
		{
			cp = b;
		}
		else
		{
			cp = a + (ab * d);
		}

		double dis = (cp - p).length();
		result.distance = dis;
		result.projectionpoint = cp;
		return result;

	}
	
}

