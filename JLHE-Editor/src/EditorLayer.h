#pragma once

#include <JLHE.h>

namespace JLHE {

	class EditorLayer : public Layer {
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;
	private:
		OrthographicCameraController m_CameraController;

		// TEMPORARY
		Ref<VertexArray> m_SquareVA;
		Ref<Texture2D> m_CheckerboardTexture;
		Ref<SubTexture2D> m_SubTexture;
		Ref<Framebuffer> m_Framebuffer;
		EntitySystem m_EntitySystem;

		bool m_ViewportFocused = false;
		bool m_ViewportHovered = false;

		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
	};
}