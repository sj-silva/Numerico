#include<iostream>
#include<GLFW/glfw3.h>
#include"Spline.h"
#include"Mat.h"

Spline::Spline() :
    _xmin(0), _xmax(0),
    _f(nullptr), _spacingType(EQUALLY)
{
}

void Spline::CreateNodes(
    Function f,
    double xmin, double xmax,
    int spacingType,
    size_t totalPoints)
{
    _f = f;
    _spacingType = spacingType;
    _xmin = xmin; _xmax = xmax;

    double x = xmin;
    double y = f(x);
 
    switch (spacingType)
    {
    case CHEBYSHEV:
    {
        double delta_theta = M_PI / (totalPoints - 1.0);
        double xc = (xmin + xmax) / 2.f;
        double raio = (xmax - xmin) / 2.f;
        for (size_t i = 0; i < totalPoints; i++) {
            double theta = M_PI - i * delta_theta;
            x = xc + raio * cos(theta);
            y = f(x);
            glm::dvec2 p(x, y);
            _nodes.push_back(p);
        }
        break;
    }
    case EQUALLY:
    {
        glm::dvec2 p(x, y);
        _nodes.push_back(p);
        double incr = (xmax - xmin) / (totalPoints - 1.0);
        for (int i = 1; i < totalPoints; i++) {
            x += incr;
            y = _f(x);
            p = glm::dvec2(x, y);
            _nodes.push_back(p);
        }
        break;
    }
    default:
        std::cerr << "ERROR:: Espacing type must be CHEBYSHEV or EQUALLY!\n";
        break;
    }

    for (size_t i = 0; i < totalPoints-1; i++)
        _h.push_back(_nodes[i + 1].x - _nodes[i].x); // h

}



void Spline::Update(int spacingType, size_t totalPoints)
{
    _nodes.clear(); _h.clear();
    CreateNodes(_f, _xmin, _xmax, spacingType, totalPoints);
}

void Spline::PlotFunc(glm::vec3 cor, int n)
{
    double xmin = _nodes[0].x;
    double xmax = _nodes.back().x;
   
    double incr = (xmax - xmin) / (n - 1.0);
    glLineWidth(1.5f);
    glColor3fv(&cor.r);
    glBegin(GL_LINE_STRIP);
    for (double x = xmin; x <= xmax; x = x + incr) {
        double y = _f(x);
        glVertex2d(x, y);
    }
    glEnd();
}

void Spline::PlotPoints(glm::vec3 cor)
{
    // PONTOS
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glPointSize(4.5f);
    glColor3fv(&cor.r);
    glBegin(GL_POINTS);
    for (unsigned i = 0; i < _nodes.size(); i++) {
        double x = _nodes[i].x;
        double y = _nodes[i].y;
        glVertex2d(x, y);
    }
    glEnd();

}


