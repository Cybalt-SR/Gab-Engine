#include "Vector3.h"

#include <glm/gtc/type_ptr.hpp>

gbe::Vector3::Vector3() : glm::vec3(0)
{
}

gbe::Vector3::Vector3(float x, float y, float z) : glm::vec3(x, y, z)
{

}

gbe::Vector3::Vector3(float u) : glm::vec3(u)
{

}

gbe::Vector3::Vector3(const glm::vec3& glmvec) : glm::vec3(glmvec)
{
	
}

float gbe::Vector3::SqrMagnitude() {
	return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
}

gbe::Vector3& gbe::Vector3::Cross(gbe::Vector3 b) {
	return Vector3((this->y * b.z) - (this->z * b.y), (this->x * b.z) - (this->z * b.x), (this->x * b.y) - (this->y * b.x));
}

gbe::Vector3 gbe::Vector3::Normalize() {
	return (glm::vec3)*this * (1.0f / this->Magnitude());
}

float gbe::Vector3::Dot(Vector3 b)
{
	return (this->x * b.x) + (this->y * b.y) + (this->z * b.z);
}

float gbe::Vector3::Magnitude()
{
	return sqrt(this->SqrMagnitude());
}

gbe::Vector3& gbe::Vector3::operator+=(const gbe::Vector3& b) {
	return (gbe::Vector3)glm::vec3::operator+=((glm::vec3)b);
}

gbe::Vector3& gbe::Vector3::operator-=(const gbe::Vector3& b) {
	return (gbe::Vector3)glm::vec3::operator-=((glm::vec3)b);
}

gbe::Vector3::operator glm::vec3() const
{
	return glm::vec3(this->x, this->y, this->z);
}

const float* gbe::Vector3::Get_Ptr() {
	return &((*this).x);
}


const gbe::Vector3 gbe::Vector3::zero = gbe::Vector3(0, 0, 0);