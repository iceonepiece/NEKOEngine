#include "GUIShader.h"
#include "../ResourceManager.h"
#include "../Shader.h"

void GUIShader::Draw()
{
	ImGui::Begin("Shader");
	
	Shader shader = ResourceManager::GetShader("sprite");

	std::string vertexSource = shader.GetVertexSource();
	char text[1000];
	strcpy_s(text, vertexSource.c_str());

	ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 50), ImGuiInputTextFlags_AllowTabInput);
	
	ImGui::End();
}