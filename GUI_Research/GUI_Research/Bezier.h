#ifndef __CURVE_BEZIER__
#define __CURVE_BEZIER__

#include "p2Point.h"
#include <vector>
#include <math.h>

#include "App.h"
#include "M_Render.h"

#define MAX_POINTS 100
#define ORIGIN_POINTS 4

enum cbezier_type
{
	CB_NO_TYPE = 0,
	CB_EASE_INOUT_BACK,
	CB_SLOW_MIDDLE,
	CB_LINEAL
};

class CBeizier
{
public:
	CBeizier();
	virtual ~CBeizier();

	void DrawBezierCurve(cbezier_type type);

	float GetActualPoint(const iPoint origin, const iPoint destination, int ms, int currentMs, cbezier_type type);
	float GetActualX(int ms, int currentMs, cbezier_type type);

	bool CalculatePivots(std::vector<fPoint>& points);
	void CPoints(fPoint x0, fPoint x1, fPoint x2, fPoint x3);
	void Bezier(std::vector<fPoint>& points, cbezier_type bType);

private:

	std::vector<float>* list = nullptr;
	std::vector<fPoint> pivotPoints;

	float speed = 0.0f;
	std::vector<float> easeInoutBack;
	std::vector<float> slowMiddle;
	std::vector<float> bLineal;

	std::vector<float> temp;
};

#endif // !__CURVE_BEZIER__