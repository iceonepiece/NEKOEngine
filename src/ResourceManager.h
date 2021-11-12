#pragma once

#include <map>
#include <string>
#include <glad/glad.h>

#include "Texture.h"
#include "Shader.h"

class ResourceManager
{
public:
  static std::map<std::string, Shader> shaders;
  static std::map<std::string, Texture> textures;

  static Shader LoadShader(std::string name, const char* vertexShaderSource, const char* fragmentShaderSource);
  static Shader GetShader(std::string name);

  static Texture LoadTexture(std::string name, const char *filename, bool alpha = false);

private:
  ResourceManager() {}

};
