#pragma once

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <glm/gtx/matrix_decompose.hpp>

#include <vector>
#include <algorithm>
#include "Shader.h"
#include "Texture.h"
#include "DrawCall.h"
#include "Skybox.h"
#include "Light.h"
#include "Framebuffer.h"

#include <functional>

#include "../Datatypes/Vector3.h"
#include "../Datatypes/Matrix4.h"

namespace gbe {
	using namespace rendering;

	class RenderPipeline {
	private:
		Shader* depthShader;

		Framebuffer* mFrameBuffer;
		Framebuffer* mDepthFrameBuffer;

		Vector2 resolution;
		Shader* postprocess;

		std::vector<DrawCall*> drawcalls;

		std::list<rendering::Light*> lights_this_frame;
		int maxlights = 10;

		Skybox* mSkybox;

		void SetRequiredAttribs();
	public:
		RenderPipeline(void*(*procaddressfunc)(const char*), Vector2);
		void RegisterDrawCall(DrawCall*);

		void SetMaximumLights(int maxlights);
		void SetSkybox(Skybox*);
		void SetPostProcessing(Shader* postprocess);
		bool TryPushLight(rendering::Light* data, bool priority = false);

		void RenderFrame(Vector3& from, Vector3& forward, Matrix4& frustrum, float& nearclip, float& farclip);

		void CleanUp();
	};
}