#pragma once
#include<cmath>
#include<glm/glm.hpp>
#include<vector>

typedef double (*Function)(double);

typedef std::vector<glm::dvec2> Dados;
enum class SpacingType{ EQUALLY, CHEBYSHEV };

const double  M_PI = 3.14159265358979323846;  /* pi */

class QSpline
{
private:
	double _xmin, _xmax;
	Dados _data;
	Function _f;
	
	std::vector<double> _h, _a2, _b2, _c2;
	double Calcula_Quad_Spline(double x);
	void CreateData(SpacingType space, int n);
	SpacingType _space;

public:
	
	// -- Construtor --
  	QSpline(Function f, double xmin, double xmax) :
		_f(f), _xmin(xmin), _xmax(xmax), _space(SpacingType::EQUALLY) { }
		
	void PlotPoints();
	
	void PlotFunc(glm::vec3 cor, int n = 200);

	void PlotQSpline(
		glm::vec3 cor = glm::vec3(0.f, 1.f, 0.f), 
		int n = 200);
		
	void CreateQSpline(
		SpacingType space = SpacingType::CHEBYSHEV,
		int n = 5);
	
	void ResetData(); 

	inline int getSpacingType() { return (int)_space; }
	inline void setSpacingType(int value) { _space = (SpacingType)value; }
};

