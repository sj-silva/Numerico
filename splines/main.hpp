#pragma once
#include<GLFW/glfw3.h>
#include"imgui/imgui.h"
#include"imgui/imgui_impl_glfw.h"
#include"imgui/imgui_impl_opengl2.h"
#include"QSpline.h"
#include"Menu.h"
#include"Splines.hpp"



void init_OPENGL(GLFWwindow* window);
void desenha();
void teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


bool show_function = true,
show_quad_spline = false,
show_cubic_spline=false,
show_points = true;

 double XMIN = -10.f;
 double XMAX = 10.f;
 double YMIN = -10.f;
 double YMAX = 10.f;

