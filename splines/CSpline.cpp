#include "CSpline.h"
#include"Mat.h"
#include<GLFW/glfw3.h>


CSpline::CSpline()
{
}

double CSpline::Calcula(double x)
{
    double result = 0.f;
    for (size_t i = 0; i < _nodes.size() - 1; i++) {
        if (_nodes[i].x <= x && x <= _nodes[i + 1].x) {
            double xi = _nodes[i].x;
            result = _a[i] * (x - xi) * (x - xi) * (x - xi);
            result += _b[i] * (x - xi) * (x - xi) + _c[i] * (x - xi) + _d[i];
            break;
        }
    }
    return result;

}

void CSpline::CreateCSpline(Dados dados, std::vector<double> h)
{
    _nodes = dados;
    size_t n = dados.size() - 1;//n=4 para total 5 pontos

    _a.clear(); _b.clear(); _c.clear(); _d.clear();


    // Calculo dos di's 
    for (int i = 0; i < n; i++)
        _d.push_back(dados[i].y);// d=(y0, y1, y2, y3)

    Mat z(n - 1, 1);
    for (size_t i = 0; i < n - 1; i++) {
        double z2 = (dados[i + 2].y - dados[i + 1].y) / h[i + 1];
        double z1 = (dados[i + 1].y - dados[i].y) / h[i];
        z(i, 0) = 6.0 * (z2 - z1);
    }
    Mat A(n - 1, n - 1);
    A(0, 0) = 2 * (h[0] + h[1]);
    A(0, 1) = h[1];
    A(n - 2, n - 3) = h[n - 2];
    A(n - 2, n - 2) = 2 * (h[n - 2] + h[n - 1]);

    for (size_t i = 1; i < n - 2; i++) {
        A(i, i - 1) = h[i];
        A(i, i) = 2.0 * (static_cast<double>(h[i]) + h[i + 1]);
        A(i, i + 1) = h[i + 1];
    }

    Mat M = Mat::merge(A, z);
    M = Mat::rref(M);

    unsigned last_col = M.cols() - 1;//indice da última coluna
                                        // = total de colunas de M - 1
    std::vector<double> g;
    // Cria vetor g
    g.push_back(0.0);
    for (int i = 0; i < M.rows(); i++) {
        g.push_back(M(i, last_col));
    }
    g.push_back(0.0);

    // Calcula ai,bi,ci
    for (size_t i = 0; i < n; i++) {
        _b.push_back(g[i] / 2.0);
        _a.push_back((g[i + 1] - g[i]) / (6.0 * h[i]));
        _c.push_back((dados[i + 1].y - dados[i].y) / h[i] - h[i] / 6.0 * (g[i + 1] + 2 * g[i]));
    }
}

void CSpline::PlotCSpline(glm::vec3 cor, int n)
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

