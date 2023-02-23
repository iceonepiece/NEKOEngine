#include "GUI.h"
#include <string>
#include <vector>

static std::vector<std::string> entities;


GUI::GUI()
{
}

GUI::~GUI()
{
}

void GUI::Destroy()
{
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

void GUI::Init(GLFWwindow* window, const char* glslVersion)
{
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  ImGui::StyleColorsDark();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(glslVersion);

  entities.push_back("abc");
  entities.push_back("def");

  //io.Fonts->AddFontFromFileTTF("fonts/ProggyClean.ttf", 20);
  //io.Fonts->AddFontFromFileTTF("fonts/DroidSans.ttf", 20);
  io.Fonts->AddFontFromFileTTF("Assets/Fonts/Cousine-Regular.ttf", 18);
  //io.Fonts->AddFontFromFileTTF("fonts/Roboto-Medium.ttf", 18);

}


void GUI::NewFrame()
{
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  bool show_demo_window = true;

  if (show_demo_window)
      ImGui::ShowDemoWindow(&show_demo_window);

    //m_guiShader.Draw();

    ImGui::Begin("Entities");
    static int selected = -1;
    for (int n = 0; n < entities.size(); n++)
    {
        if (ImGui::Selectable(entities[n].c_str(), selected == n))
            selected = n;
    }
    ImGui::End();

    ImGui::Begin("Inspector");
    static int i0 = 123;
    ImGui::InputInt("input int", &i0);
    ImGui::End();


  ImGui::Render();
}

void GUI::Draw()
{
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
