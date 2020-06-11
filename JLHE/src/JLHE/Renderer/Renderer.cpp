#include "jlhepch.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace JLHE {

	Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;

	void Renderer::Init() {
		RenderCommand::Init();
	}

	void Renderer::BeginScene(OrthographicCamera& camera) {
		m_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene() {

	}

	void Renderer::Submit(const JLHE::Ref<VertexArray>& vertexArray, const JLHE::Ref<Shader>& shader, const glm::mat4& transform) {
		shader->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_ViewProjectionMatrix", m_SceneData->ViewProjectionMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_Transform", transform);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}

}