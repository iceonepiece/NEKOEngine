#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Shader
{
public:
  Shader(const char* vertexSource, const char* fragmentSource);
  ~Shader();

  void Use();

  void SetInt(const char* name, int value);
  void SetVector3f(const char* name, glm::vec3& value);
  void SetMatrix4(const char* name, glm::mat4& value);

private:
  unsigned int m_ID;
};
