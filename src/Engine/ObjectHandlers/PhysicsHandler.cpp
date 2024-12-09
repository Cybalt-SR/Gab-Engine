#include "PhysicsHandler.h"

#include <iostream>

gbe::PhysicsHandler::PhysicsHandler()
{
	this->subhandlers.push_back(&this->forcevolume_handler);
	this->mPipeline = nullptr;
}

void gbe::PhysicsHandler::SetPipeline(physics::PhysicsPipeline* pipeline)
{
	this->mPipeline = pipeline;
}

void gbe::PhysicsHandler::Update()
{
	for (auto ro : this->object_list) {
		auto scale = ro->Local()->scale;
		auto matrix = Matrix4();
		ro->body.GetCalculatedMatrix(&matrix);
		ro->SetMatrix(matrix);
		//ro->Scale(scale);
	}
}

void gbe::PhysicsHandler::OnAdd(RigidObject* ro)
{
	this->mPipeline->RegisterBody(&ro->body);
}

void gbe::PhysicsHandler::OnRemove(RigidObject* ro)
{
	this->mPipeline->UnRegisterBody(&ro->body);
}