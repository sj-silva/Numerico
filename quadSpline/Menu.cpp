#include "Menu.h"

extern bool  show_function, show_quad_spline, show_points;
extern int nNodesAux, nNodes;

int MIN_NODES = 5;
int MAX_NODES = 50;

bool ButtonCenteredOnLine(const char* label, float alignment = 0.5f)
{
    ImGuiStyle& style = ImGui::GetStyle();

    float size = ImGui::CalcTextSize(label).x + style.FramePadding.x * 2.0f;
    float avail = ImGui::GetContentRegionAvail().x;

    float off = (avail - size) * alignment;
    if (off > 0.0f)
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);

    return ImGui::Button(label);
}

void Menu::Theme()
{

    ImVec2 menuWindowSize(250, 430);
    ImVec2 menuWindowPos(625, 20);
    ImGui::SetNextWindowSize(menuWindowSize);
    ImGui::SetNextWindowPos(menuWindowPos);

    ImGuiStyle* style = &ImGui::GetStyle();
    style->WindowTitleAlign = ImVec2(0.5, 0.5);
    style->WindowPadding = ImVec2(8, 8);
    style->FramePadding = ImVec2(8, 6);
    style->WindowRounding = 10.f;

    // Colors
    ImVec4* colors = style->Colors;
    ImColor primaryColor(92, 107, 192, 255);
    ImColor darkColor(38, 65, 143, 255);
    ImColor textColor(200, 200, 200, 255);

    colors[ImGuiCol_WindowBg] = primaryColor;
    colors[ImGuiCol_TitleBgActive] = darkColor;
    colors[ImGuiCol_Header] = darkColor;

    colors[ImGuiCol_Text] = textColor;


}

void Menu::Render(QSpline& interp)
{
    static int spacingType = interp.getSpacingType();
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;
    ImGui::Begin("Quadratic Spline Interpolation", nullptr, flags);

    ImGui::Dummy(ImVec2(0.0f, 10.0f));
    if (ImGui::CollapsingHeader("Draw", ImGuiTreeNodeFlags_DefaultOpen)) {
        ImGui::Checkbox("Function", &show_function);
        ImGui::Checkbox("Quadratic Spline", &show_quad_spline);
    }
    ImGui::Dummy(ImVec2(0.0f, 5.0f));
    ImGui::Separator();

    // Points Spacing Type
    ImGui::Dummy(ImVec2(0.0f, 10.0f));
    if (ImGui::CollapsingHeader("Point Spacing Method", ImGuiTreeNodeFlags_DefaultOpen)) {
        
        ImGui::RadioButton("Equally", &spacingType, (int)SpacingType::EQUALLY);
        ImGui::RadioButton("Chebyshev", &spacingType, (int)SpacingType::CHEBYSHEV);
    }
    ImGui::Dummy(ImVec2(0.0f, 5.0f));
    ImGui::Separator();

    // Header Nodes
    ImGui::Dummy(ImVec2(0.0f, 10.0f));
    if (ImGui::CollapsingHeader("Number of Nodes", ImGuiTreeNodeFlags_DefaultOpen)) {
        ImGui::Dummy(ImVec2(0.0f, 2.5f));
        ImGui::InputInt("Total", &nNodesAux);
        if (nNodesAux <= MIN_NODES) nNodesAux = MIN_NODES;
        if (nNodesAux >= MAX_NODES) nNodesAux = MAX_NODES;
    }

    ImGui::Dummy(ImVec2(0.0f, 5.0f));
    ImGui::Separator();

    // Botão para Interpolar
    ImGui::Dummy(ImVec2(0.0f, 10.0f));
    
    if (ButtonCenteredOnLine("Update Draw")) {
        interp.ResetData();
        nNodes = nNodesAux;
        SpacingType sp = (SpacingType)spacingType;
        interp.CreateQSpline(sp,nNodes);
    }

    ImGui::End();
}
  