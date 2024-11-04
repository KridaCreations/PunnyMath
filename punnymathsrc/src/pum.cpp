#include "pch.h"
#include "pum.h"
#include "punnymath.h"


namespace pum {
	long double dotpro(vector2d a, vector2d b)
	{
		long double result = (a.x * b.x) + (a.y * b.y);
		return result;
	}

	long double crosspro(vector2d a, vector2d b)
	{
		long double result = a.x * b.y - a.y * b.x;
		return result;
	}

	template<typename T>
	bool nearlyequal(T a, T b, long double thr)
	{
		std::cout << "int " << std::endl;
		long double diff = a - b;
		return std::abs(diff) <= thr;
	}


	bool nearlyequal(vector2d a, vector2d b, long double thr)
	{
		vector2d diff = a - b;
		long double mag = diff.length();
		return mag <= thr;
	}


	std::pair<long double, long double> projectcircle(pum::vector2d line, pum::vector2d point, double radius)
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

	std::pair<double, double> projectpolygon(pum::vector2d line, std::vector<pum::vector2d>& points)
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

	pointlineprojectresult distanceFromLinesegment(pum::vector2d a, pum::vector2d b, pum::vector2d p)
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
	long double deg2rad(long double deg)
	{
		long double ans = (3.14159 * deg) / 180.000;
		return ans;
	}
	long double rad2deg(long double rad)
	{
		long double ans = (rad * 180.0000) / 3.14159;
		return ans;
	}
}