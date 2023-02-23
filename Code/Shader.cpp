#include "Shader.h"

void Shader::Compile(const char* vertexSource, const char* fragmentSource)
{
	m_vertexSource = vertexSource;
	m_fragmentSource = fragmentSource;
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexSource, NULL);
  glCompileShader(vertexShader);

  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
  glCompileShader(fragmentShader);

  m_ID = glCreateProgram();
  glAttachShader(m_ID, vertexShader);
  glAttachShader(m_ID, fragmentShader);
  glLinkProgram(m_ID);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

Shader::~Shader()
{

}

std::string Shader::GetVertexSource()
{
	return m_vertexSource;
}

std::string Shader::GetFragmentSource()
{
	return m_fragmentSource;
}

void Shader::SetInt(const char* name, int value)
{
  glUniform1i(glGetUniformLocation(m_ID, name), value);
}

void Shader::SetVector3f(const char* name, glm::vec3& value)
{
  glUniform3f(glGetUniformLocation(m_ID, name), value.x, value.y, value.z);
}

void Shader::SetMatrix4(const char* name, glm::mat4& value)
{
  glUniformMatrix4fv(glGetUniformLocation(m_ID, name), 1, GL_FALSE, &value[0][0]);
}

void Shader::Use()
{
  glUseProgram(m_ID);
}
