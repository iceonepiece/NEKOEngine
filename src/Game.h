#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "ResourceManager.h"
#include "Sprite.h"
#include "GUI.h"

class Game
{
public:
  Game(unsigned int width = 1280, unsigned int height = 720);
  ~Game();

  void Init();
  void Run();

  GLFWwindow* GetWindow() { return m_window; }

private:
  GLFWwindow* m_window;
  GUI m_gui;

  unsigned int m_width;
  unsigned int m_height;
};
