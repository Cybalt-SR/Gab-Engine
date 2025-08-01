#pragma once

#include "ColliderData.h"

#include <vector>
#include "Math/gbe_math.h"

namespace gbe {
	namespace physics {
		class MeshColliderData : public ColliderData{
		private:
			btBvhTriangleMeshShape* trimeshShape;
		public:
			MeshColliderData(std::vector<std::vector<Vector3>>, Collider* related_engine_wrapper);
			virtual btCollisionShape* GetShape() override;
		};
	}
}