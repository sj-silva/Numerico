#include"main.hpp"
#include<string>

double g(double x) {
    return cos(x);
 //   return 8.f / (1.f + x * x);
   // return 4 * sin(2 * x) * cos(x / 2.f);
}

QSpline interpola(g, XMIN,XMAX);

int main()
{

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(900, 600, "Quadratic Spline", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);

    init_OPENGL(window);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    
    ImGuiIO& io = ImGui::GetIO();
    std::string fontPath = "font/Roboto-Medium.ttf";
    ImFont* pFont = io.Fonts->AddFontFromFileTTF(fontPath.c_str(), 14.0f);
  
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        /* Poll for and process events */
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
       
        Menu::Theme();
        {
            Menu::Render(interpola);
           
        }


        /* Render here */
        glClearColor(0.0, 0.15, 0.25, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(0, 0, 600, 600);
        desenha();
        ImGui::Render();
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
        /* Swap front and back buffers */
        glfwSwapBuffers(window);


    }


    // Cleanup
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}

void init_OPENGL(GLFWwindow* window)
{

    glfwSetKeyCallback(window, teclado_callback);
    glClearColor(0.0, 0.15, 0.25, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(XMIN - 0.5, XMAX + 0.5, YMIN - 0.5, YMAX + 0.5, 1.0, -1.0);

    interpola.CreateQSpline(SpacingType::EQUALLY);
    
}

void desenha()
{

    // AXIS
    glLineWidth(2.f);
    glColor3f(0.f, 0.f, 1.f);
    glBegin(GL_LINES);
    glVertex2f(XMIN, 0.f);
    glVertex2f(XMAX, 0.f);
    glVertex2f(0.f, YMIN);
    glVertex2f(0.f, YMAX);
    glEnd();


    // FUNCTION
    if (show_function) {
        glm::vec3 functionColor(0.f, 1.f, 0.f);
        interpola.PlotFunc(functionColor);
    }
        
     // QUADRATIC SPLINE  
    if (show_quad_spline) {
        glEnable(GL_LINE_STIPPLE);
        short padrao = 0x5555;
        glLineStipple(3, padrao);
        glm::vec3 qsplineColor(0.819, 0.968, 0.094);
        interpola.PlotQSpline(qsplineColor);
        glDisable(GL_LINE_STIPPLE);
    }

    // PLOT POINTS
    if (show_points) {
        interpola.PlotPoints();
    }
}

void teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

}

