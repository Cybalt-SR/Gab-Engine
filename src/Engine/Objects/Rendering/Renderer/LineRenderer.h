#pragma once

#include "Engine/Objects/Rendering/RenderObject.h"
#include "Engine/ObjectFunctions/EarlyUpdate.h"

namespace gbe {
	class LineRenderer : public RenderObject{
	private:
		Object* a;
		Object* b;
		Object* camera;
	
	public:
		LineRenderer(rendering::DrawCall* drawcall, Object* Camera, Object* a, Object* b);

		Vector3 GetPos(int which);
		virtual void InvokeEarlyUpdate();
	};
}