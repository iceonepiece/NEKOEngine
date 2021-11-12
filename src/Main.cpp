#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Game.h"
#include "ResourceManager.h"
#include "GUI.h"
#include "Shader.h"
#include "Texture.h"
#include "Sprite.h"

const char* vertexShaderSource = R"(
  #version 330 core
  layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>

  out vec2 TexCoords;

  uniform mat4 model;
  uniform mat4 projection;

  void main()
  {
    TexCoords = vertex.zw;
    gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);
  }
)";

const char* fragmentShaderSource = R"(
  #version 330 core
  in vec2 TexCoords;
  out vec4 color;

  uniform sampler2D image;
  uniform vec3 spriteColor;

  void main()
  {
      color = vec4(spriteColor, 1.0) * texture(image, TexCoords);
  }
)";

int main()
{
  Game game;

  ResourceManager::LoadShader("sprite", vertexShaderSource, fragmentShaderSource);

  glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(800), static_cast<float>(600), 0.0f, -1.0f, 1.0f);

  ResourceManager::shaders["sprite"].Use();
  ResourceManager::shaders["sprite"].SetInt("image", 0);
  ResourceManager::shaders["sprite"].SetMatrix4("projection", projection);

  ResourceManager::LoadTexture("wooden", "container.jpeg");
  ResourceManager::LoadTexture("face", "awesomeface.png", true);

  game.Run();

  return 0;
}
