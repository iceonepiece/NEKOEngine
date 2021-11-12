#pragma once

#include <GLFW/glfw3.h>
#include "External/imgui/imgui.h"
#include "External/imgui/imgui_impl_glfw.h"
#include "External/imgui/imgui_impl_opengl3.h"

class GUI
{
public:
  GUI();
  ~GUI();

  void Init(GLFWwindow* window, const char* glslVersion);
  void Destroy();

  void NewFrame();
  void Draw();
};
