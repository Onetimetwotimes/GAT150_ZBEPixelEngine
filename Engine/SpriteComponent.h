#pragma once
#include "RenderComponent.h"
#include "Sprite.h"

namespace zbe {
	class SpriteComponent : public RenderComponent {
		virtual void Create(void* data) override;
		virtual void Destroy() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Read(const rapidjson::Value& value);

	protected:
		zbe::Graphics::Sprite* sprite;
		std::string imgPath;
	};
}