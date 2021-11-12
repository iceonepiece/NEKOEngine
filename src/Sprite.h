#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"
#include "Texture.h"

class Sprite
{
public:
  Sprite(const Shader &shader);
  ~Sprite();

  void Draw(Texture &texture, glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));

private:
  Shader m_shader;
  unsigned int m_VAO;
};
