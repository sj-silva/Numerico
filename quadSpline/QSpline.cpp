#include "QSpline.h"
#include<GLFW/glfw3.h>
#include<iostream>

double QSpline::Calcula_Quad_Spline(double x)
{
    double result = 0.f;
    for (size_t i = 0; i < _data.size() - 1; i++) {
        if (_data[i].x <= x && x <= _data[i + 1].x) {
            /*if (_data[i].x == _data[_data.size() - 2].x) {
                int foo = 0;
            }*/
            double xi = _data[i].x;
            result = _a2[i] * (x - xi) * (x - xi) + _b2[i] * (x - xi) + _c2[i];
            break;
        }
    }
    return result;
}

void QSpline::CreateData(SpacingType space, int totalPoints)
{
    double x = _xmin;
    double y = _f(x);
    _space = space;

    switch (_space)
    {
    case SpacingType::CHEBYSHEV:
    {
        double delta_theta = M_PI / (totalPoints - 1.0);
        double xc = (_xmin + _xmax) / 2.f;
        double raio = (_xmax - _xmin) / 2.f;
        for (int i = 0; i < totalPoints; i++) {
            double theta = M_PI - i * delta_theta;
            x = xc + raio * cos(theta);
            y = _f(x);
            glm::dvec2 p(x, y);
            _data.push_back(p);
        }
        break;
    }
    case SpacingType::EQUALLY:
    {
        glm::dvec2 p(x, y);
        _data.push_back(p);
        double incr = (_xmax - _xmin) / (totalPoints - 1.0);
        for (int i = 0; i < totalPoints; i++) {
            x += incr;
            y = _f(x);
            p=glm::dvec2(x, y);
            _data.push_back(p);
        }
        break;
    }
    default:
        std::cerr << "ERROR:: Espacing type must be CHEBYSHEV or EQUALLY!\n";
        break;
    }
}

void QSpline::PlotPoints()
{
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glPointSize(4.5f);
    glColor3f(1.f, 0.f, 0.f);
    glBegin(GL_POINTS);
    for (unsigned i = 0; i < _data.size(); i++) {
        double x = _data[i].x;
        double y = _data[i].y;
        glVertex2d(x, y);
    }
    glEnd();
}

void QSpline::PlotFunc(glm::vec3 cor, int n)
{
    double incr = (_xmax - _xmin) / (n - 1.0);
    glLineWidth(1.5f);
    glColor3fv(&cor.r);
    glBegin(GL_LINE_STRIP);
    for (double x = _xmin; x <= _xmax; x = x + incr) {
        double y = _f(x);
        glVertex2d(x, y);
    }
    glEnd();
}

void QSpline::PlotQSpline(glm::vec3 cor, int n)
{
    double incr = (_xmax - _xmin) / (n - 1.0);
    glLineWidth(1.5f);
    glColor3fv(&cor.r);
    glBegin(GL_LINE_STRIP);
    for (double x = _xmin; x <= _xmax; x = x + incr) {
        double y = Calcula_Quad_Spline(x);
        glVertex2d(x, y);
    }
    glEnd();
}

void QSpline::CreateQSpline(SpacingType space, int totalPoints)
{

    this->CreateData(space, totalPoints);

    int n = _data.size() - 1;

    _h.clear(); _a2.clear(); _b2.clear(); _c2.clear();
  
    for (int i = 0; i < n; i++)
        _h.push_back(_data[i + 1].x - _data[i].x); // h

    for (int i = 0; i < n; i++)
        _c2.push_back(_data[i].y);// c


    _b2.push_back((_data[1].y - _data[0].y) / _h[0]);// bo
    _a2.push_back(0.f);// ao

    
    for (size_t i = 1; i < n; i++) {
        double val_b = 2 * _a2[i - 1] * _h[i - 1] + _b2[i - 1];
        _b2.push_back(val_b);

        double val_a = (_data[i + 1].y - _data[i].y - _b2[i] * _h[i]) / (_h[i] * _h[i]);
        _a2.push_back(val_a);
    }
}

void QSpline::ResetData()
{
	_data.clear();
}
