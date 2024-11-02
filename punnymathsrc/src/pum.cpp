#include "pch.h"
#include "pum.h"
#include "punnymath.h"


//namespace pum {
//
//	bool nearlyequal(vector2d a, vector2d b, long double thr)
//	{
//		vector2d diff = a - b;
//		long double mag = diff.length();
//		std::cout << "vector " << mag << std::endl;
//		return mag <= thr;
//	}
//}

//bool pum::nearlyequal(vector2d a, vector2d b, long double thr)
//{
//	return false;
//}

extern "C++" namespace pum {
//namespace pum{

	/*std::pair<long double, long double> projectcircle(pum::vector2d line, pum::vector2d point, double radius)
	{
		line.normalize();
		pum::vector2d left = point - line * radius;
		pum::vector2d right = point + line * radius;
		double dotleft = dotpro(line, left);
		double dotright = dotpro(line, right);
		if (dotleft < dotright)
			return std::pair<double, double>(dotleft, dotright);
		return std::pair<double, double>(dotright, dotleft);
	}*/

	/*inline std::pair<long double, long double> projectcircle(pum::vector2d line, pum::vector2d point, double radius)
	{
		line.normalize();
		pum::vector2d left = point - line * radius;
		pum::vector2d right = point + line * radius;
		double dotleft = dotpro(line, left);
		double dotright = dotpro(line, right);
		if (dotleft < dotright)
			return std::pair<double, double>(dotleft, dotright);
		return std::pair<double, double>(dotright, dotleft);
	}*/


	/*std::pair<double, double> projectpolygon(pum::vector2d line, std::vector<pum::vector2d>& points)
	{
		double minim = LLONG_MAX;
		double maxim = LLONG_MIN;
		for (int point = 0; point < points.size(); point++)
		{
			pum::vector2d p = points[point];
			double val = dotpro(line, p);
			minim = min(minim, val);
			maxim = max(maxim, val);
		}
		return std::pair<double, double>(minim, maxim);
	}*/

	//pointlineprojectresult distanceFromLinesegment(pum::vector2d a, pum::vector2d b, pum::vector2d p)
	//{
	//	pointlineprojectresult result;

	//	pum::vector2d ab = b - a;
	//	pum::vector2d ap = p - a;
	//	double dot = dotpro(ab, ap);

	//	double d = dot / ab.lengthsquare();
	//	pum::vector2d cp;
	//	if (d <= 0.0)
	//	{
	//		cp = a;
	//	}
	//	else if (d >= 1.0)
	//	{
	//		cp = b;
	//	}
	//	else
	//	{
	//		cp = a + (ab * d);
	//	}

	//	double dis = (cp - p).length();//; this->getmag(cp - p);
	//	result.distance = dis;
	//	result.projectionpoint = cp;
	//	return result;
	//}

}