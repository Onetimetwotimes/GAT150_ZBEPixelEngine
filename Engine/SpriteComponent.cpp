#include "pch.h"
#include "SpriteComponent.h"
#include "GameObject.h"

namespace zbe {
void SpriteComponent::Create(void* data) {
	sprite = owner->engine->GetSystem<zbe::ResourceManager>()
		 ->Get<zbe::Graphics::Sprite>( imgPath, owner->engine->GetSystem<zbe::Graphics::Renderer>() );
}	

void SpriteComponent::Destroy() {
	
}	

void SpriteComponent::Update() {

}

void SpriteComponent::Draw() {
	sprite->Draw(owner->getTransform().position, owner->getTransform().scale, owner->getTransform().rotation);
}

void SpriteComponent::Read(const rapidjson::Value& value) {
	zbe::IO::GetJSON(value, "imgPath", imgPath);
}

}
