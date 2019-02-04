#pragma once

#include <memory>
#include <fstream>
#include <nlohmann/json.hpp>
#include <KrumbEngine/render/Texture.h>

#include "Krumb/world/Block.h"

using json = nlohmann::json;

#define DOES_JSON_EXIST(x, y) (x.find(y) != x.end())

namespace Krumb
{
	class BlockLoader
	{
	private:
		bool _init = false;

		KrumbEngine::Texture::TextureArray _textureArray;

	public:
		BlockLoader();
		BlockLoader(KrumbEngine::Texture::TextureArray textureArray);

		BlockData loadBlockData(const char* blockName);

		inline void setTextureArray(KrumbEngine::Texture::TextureArray textureArray) { _textureArray = textureArray; }
	};
}