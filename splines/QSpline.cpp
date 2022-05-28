#include "QSpline.h"
#include<GLFW/glfw3.h>
#include<iostream>


QSpline::QSpline()
{
}

void QSpline::CreateQSpline(Dados dados, std::vector<double> h)
{
    _nodes = dados;
    size_t n = dados.size() - 1;

    _a2.clear(); _b2.clear(); _c2.clear();

    for (size_t i = 0; i < n; i++)
        h.push_back(dados[i + 1].x - dados[i].x); // h

    for (size_t i = 0; i < n; i++)
        _c2.push_back(dados[i].y);// c


    _b2.push_back((dados[1].y - dados[0].y) / h[0]);// bo
    _a2.push_back(0.f);// ao


    for (size_t i = 1; i < n; i++) {
        double val_b = 2 * _a2[i - 1] * h[i - 1] + _b2[i - 1];
        _b2.push_back(val_b);

        double val_a = (dados[i + 1].y - dados[i].y - _b2[i] * h[i]) / (h[i] * h[i]);
        _a2.push_back(val_a);
    }
}

double QSpline::Calcula(double x)
{
    double result = 0.f;
    for (size_t i = 0; i < _nodes.size() - 1; i++) {
        if (_nodes[i].x <= x && x <= _nodes[i + 1].x) {
            /*if (_data[i].x == _data[_data.size() - 2].x) {
                int foo = 0;
            }*/
            double xi = _nodes[i].x;
            result = _a2[i] * (x - xi) * (x - xi) + _b2[i] * (x - xi) + _c2[i];
            break;
        }
    }
    return result;
}

void QSpline::PlotQSpline(glm::vec3 cor, int n)
{
    double xmin = _nodes[0].x;
    double xmax = _nodes.back().x;
    double incr = (xmax - xmin) / (n - 1.0);
    glLineWidth(1.5f);
    glColor3fv(&cor.r);
    glBegin(GL_LINE_STRIP);
    for (double x = xmin; x <= xmax; x = x + incr) {
        double y = Calcula(x);
        glVertex2d(x, y);
    }
    glEnd();
}

