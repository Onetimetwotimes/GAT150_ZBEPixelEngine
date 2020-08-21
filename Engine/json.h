#pragma once
#include <string>
#include "document.h"
#include "Vector2.h"
#include "color.h"

namespace zbe {
	namespace IO {
		bool LoadJSON(const std::string filename, rapidjson::Document& document);

		bool GetJSON(const rapidjson::Value& value, const std::string name, bool& data);
		bool GetJSON(const rapidjson::Value& value, const std::string name, int& data);
		bool GetJSON(const rapidjson::Value& value, const std::string name, float& data);
		bool GetJSON(const rapidjson::Value& value, const std::string name, std::string& data);
		bool GetJSON(const rapidjson::Value& value, const std::string name, zbe::math::Vector2& data);
		bool GetJSON(const rapidjson::Value& value, const std::string name, zbe::Graphics::Color& data);
	}
}