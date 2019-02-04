#pragma once

#include <fstream>
#include <nlohmann/json.hpp>
#include "Krumb/world/Block.h"

using json = nlohmann::json;

#define DOES_JSON_EXIST(x, y) (x.find(y) != x.end())

namespace Krumb
{
	class BlockLoader
	{
	private:
		int getLayerForBlock(BlockFaceLayer layer, const char* blockName);
	public:
		BlockData getBlockDataForBlock(const char* blockName);
	};
}