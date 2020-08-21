#include "pch.h"
#include "json.h"
#include "document.h"
#include <fstream>
#include <istreamwrapper.h>
namespace zbe {
	namespace IO {
		bool LoadJSON(const std::string filename, rapidjson::Document& document) {
			std::ifstream file(filename);

			if (file.is_open()) {
				rapidjson::IStreamWrapper istream(file);
				document.ParseStream(istream);
				return document.IsObject();
			}
			else
				return false;
		}

		bool GetJSON(const rapidjson::Value& value, const std::string name, bool& data)
		{
			auto iter = value.FindMember(name.c_str());

			if (iter == value.MemberEnd())
				return false;

			auto& prop = iter->value;

			if (!prop.IsBool())
				return false;

			data = prop.GetBool();
			return true;
		}

		bool GetJSON(const rapidjson::Value& value, const std::string name, int& data) {
			auto iter = value.FindMember(name.c_str());

			if (iter == value.MemberEnd())
				return false;

			auto& prop = iter->value;

			if (!prop.IsInt())
				return false;

			data = prop.GetInt();
			return true;
		}

		bool GetJSON(const rapidjson::Value& value, const std::string name, float& data)
		{
			auto iter = value.FindMember(name.c_str());

			if (iter == value.MemberEnd())
				return false;

			auto& prop = iter->value;

			if (!prop.IsFloat())
				return false;

			data = prop.GetFloat();
			return true;
		}

		bool GetJSON(const rapidjson::Value& value, const std::string name, std::string& data)
		{
			auto iter = value.FindMember(name.c_str());

			if (iter == value.MemberEnd())
				return false;

			auto& prop = iter->value;

			if (!prop.IsString())
				return false;

			data = prop.GetString();
			return true;
		}

		bool GetJSON(const rapidjson::Value& value, const std::string name, zbe::math::Vector2& data)
		{
			auto iter = value.FindMember(name.c_str());

			if (iter == value.MemberEnd())
				return false;

			auto& prop = iter->value;

			if (!prop.IsArray() || prop.Size() != 2)
				return false;

			if (!(prop[0].IsNumber() && prop[1].IsNumber()))
				return false;

			data.x = prop[0].GetFloat();
			data.y = prop[1].GetFloat();
			return true;
		}

		bool GetJSON(const rapidjson::Value& value, const std::string name, zbe::Graphics::Color& data)
		{
			auto iter = value.FindMember(name.c_str());

			if (iter == value.MemberEnd())
				return false;

			auto& prop = iter->value;

			if (!prop.IsArray() || prop.Size() < 3 || prop.Size() > 4)
				return false;

			if (!(
				prop[0].IsNumber() &&
				prop[1].IsNumber() &&
				prop[2].IsNumber() &&
				(prop[3].IsNumber() || prop[3].IsNull())
				))
				return false;

			data.SetRGBA(
				prop[0].GetFloat(),
				prop[1].GetFloat(),
				prop[2].GetFloat());
			if (prop.Size() == 4)
				data.a = prop[3].GetFloat();

			return true;
		}
	}
}