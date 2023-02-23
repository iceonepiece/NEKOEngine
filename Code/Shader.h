#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Shader
{
public:
  Shader() {}
  ~Shader();

  void Compile(const char* vertexSource, const char* fragmentSource);
  void Use();

  void SetInt(const char* name, int value);
  void SetVector3f(const char* name, glm::vec3& value);
  void SetMatrix4(const char* name, glm::mat4& value);

  std::string GetVertexSource();
  std::string GetFragmentSource();

private:
  unsigned int m_ID;
  std::string m_vertexSource;
  std::string m_fragmentSource;
};
