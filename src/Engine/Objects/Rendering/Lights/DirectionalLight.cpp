#include "DirectionalLight.h"

using namespace gbe;
using namespace gbe::gfx;

gfx::Light* gbe::DirectionalLight::GetData()
{
    if (this->mLight == nullptr)
        this->mLight = new DirLight();

    auto dir_light = (DirLight*)this->mLight;

    dir_light->color = this->Color;
    dir_light->intensity = this->intensity;
    dir_light->dir = this->World().GetForward();
    dir_light->pos = this->World().position.Get();

    return this->mLight;
}
