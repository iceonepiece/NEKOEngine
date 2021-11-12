#include "ResourceManager.h"

std::map<std::string, Texture> ResourceManager::textures;
std::map<std::string, Shader> ResourceManager::shaders;

Shader ResourceManager::LoadShader(std::string name, const char* vertexShaderSource, const char* fragmentShaderSource)
{
  Shader shader;
  shader.Compile(vertexShaderSource, fragmentShaderSource);

  shaders[name] = shader;

  return shaders[name];
}

Shader ResourceManager::GetShader(std::string name)
{
    return shaders[name];
}

Texture ResourceManager::LoadTexture(std::string name, const char *filename, bool alpha)
{
  Texture texture;
  texture.Generate(filename, alpha);

  textures[name] = texture;

  return textures[name];
}
