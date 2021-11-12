#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"

class Texture
{
public:
  Texture(const char* filename, bool alpha = false);
  ~Texture();

  void Bind();

private:
  unsigned int m_ID;
};
