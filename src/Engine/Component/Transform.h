#pragma once

#include "Math/gbe_math.h"
#include "TransformChangeType.h"
#include <functional>

namespace gbe {
	class Transform {
	private:
		Matrix4 updated_matrix_without_scale;
		Matrix4 updated_matrix_with_scale;

		std::function<void(TransformChangeType)> onChange;

		void UpdateAxisVectors();
		void OnComponentChange(TransformChangeType type);

		//AXIS VECTORS
		Vector3 Right;
		Vector3 Up;
		Vector3 Forward;
	public:

		const Vector3& GetRight();
		const Vector3& GetUp();
		const Vector3& GetForward();

		TrackedVariable<Vector3> position = TrackedVariable<Vector3>([this](auto var) {this->OnComponentChange(TransformChangeType::TRANSLATION); });
		TrackedVariable<Vector3> scale = TrackedVariable<Vector3>([this](auto var) {this->OnComponentChange(TransformChangeType::SCALE); });
		TrackedVariable<Quaternion> rotation = TrackedVariable<Quaternion>([this](auto var) {
			this->OnComponentChange(TransformChangeType::ROTATION);
			this->UpdateAxisVectors();
			});

		Transform();
		Transform(std::function<void(TransformChangeType)> onChange);
		Matrix4 GetMatrix(bool include_scale = true);
	};
}