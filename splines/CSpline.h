#pragma once
#include "Spline.h"
class CSpline :
    public Spline
{
private:
	std::vector<double> _a, _b, _c, _d;
	double Calcula(double x);

public:
	CSpline();
	void CreateCSpline(Dados dados, std::vector<double> h);
	void PlotCSpline(glm::vec3 cor, int n = 200);
};

