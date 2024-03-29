#pragma once

#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include "GUIs/GUIShader.h"

class GUI
{
public:
  GUI();
  ~GUI();

  void Init(GLFWwindow* window, const char* glslVersion);
  void Destroy();

  void NewFrame();
  void Draw();

private:
	GUIShader m_guiShader;
};
