
#include "Vector2.h"
#include <glm/gtc/type_ptr.hpp>

gbe::Vector2::Vector2(float x, float y) : glm::vec2(x, y)
{

}

gbe::Vector2::Vector2() : glm::vec2(0)
{
}

gbe::Vector2::Vector2(const glm::vec2& glmvec) : glm::vec2(glmvec)
{

}

gbe::Vector2& gbe::Vector2::operator+=(const gbe::Vector2& b) {
	(glm::vec2)*this += (glm::vec2)b;

	return *this;
}

gbe::Vector2& gbe::Vector2::operator-=(const gbe::Vector2& b) {
	(glm::vec2)*this -= (glm::vec2)b;

	return *this;
}

const float* gbe::Vector2::Get_Ptr() {
	return &((*this).x);
}

const gbe::Vector2 gbe::Vector2::zero = gbe::Vector2(0, 0);