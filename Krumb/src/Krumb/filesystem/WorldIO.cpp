#include "WorldIO.h"

namespace Krumb
{
	// TODO: Look into possibly adding an "editor" that allows us to write \
	// the block JSON files automatically by just filling in the data

	int BlockLoader::getLayerForBlock(BlockFaceLayer layer, const char* blockName)
	{
		std::ifstream blockIFStream(blockName);
		json file;
		blockIFStream >> file;

		if (DOES_JSON_EXIST(file, "textures"))
		{
			json textureLayers = file["textures"];
			std::string nx;
			std::string px;
			std::string ny;
			std::string py;
			std::string nz;
			std::string pz;

			if (DOES_JSON_EXIST(textureLayers, "nx"))
				nx = textureLayers["nx"].get<std::string>();

			if (DOES_JSON_EXIST(textureLayers, "px"))
				px = textureLayers["px"].get<std::string>();
			
			if (DOES_JSON_EXIST(textureLayers, "ny"))
				ny = textureLayers["ny"].get<std::string>();
			
			if (DOES_JSON_EXIST(textureLayers, "py"))
				py = textureLayers["py"].get<std::string>();
			
			if (DOES_JSON_EXIST(textureLayers, "nz"))
				nz = textureLayers["nz"].get<std::string>();
			
			if (DOES_JSON_EXIST(textureLayers, "pz"))
				pz = textureLayers["pz"].get<std::string>();
			
			if (DOES_JSON_EXIST(textureLayers, "sides"))
			{
				std::string texture = textureLayers["sides"].get<std::string>();
				nx = texture;
				px = texture;
				nz = texture;
				pz = texture;
			}
			
			if (DOES_JSON_EXIST(textureLayers, "all"))
			{
				std::string texture = textureLayers["all"].get<std::string>();
				nx = texture;
				px = texture;
				nz = texture;
				pz = texture;
				ny = texture;
				py = texture;
			}
			
			if (nx.empty()) KRUMB_ERROR("Negative X texture not found for block {}.", blockName);
			if (px.empty()) KRUMB_ERROR("Positive X texture not found for block {}.", blockName);
			if (ny.empty()) KRUMB_ERROR("Negative Y texture not found for block {}.", blockName);
			if (py.empty()) KRUMB_ERROR("Positive Y texture not found for block {}.", blockName);
			if (nz.empty()) KRUMB_ERROR("Negative Z texture not found for block {}.", blockName);
			if (pz.empty()) KRUMB_ERROR("Positive Z texture not found for block {}.", blockName);
		}
		else
		{
			KRUMB_ERROR("No texture layers found for block {}.", blockName);
		}

		return 0;
	}

	BlockData BlockLoader::getBlockDataForBlock(const char* blockName)
	{
		BlockData retVal;

		retVal.textureLayers.nx = getLayerForBlock(BLOCK_FACE_NX, blockName);

		return retVal;
	}
}