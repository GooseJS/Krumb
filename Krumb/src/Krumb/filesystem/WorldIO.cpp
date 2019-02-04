#include "WorldIO.h"

namespace Krumb
{
	// TODO: Look into possibly adding an "editor" that allows us to write \
	// the block JSON files automatically by just filling in the data

	BlockLoader::BlockLoader()
	{

	}

	BlockLoader::BlockLoader(KrumbEngine::Texture::TextureArray textureArray)
	{
		_textureArray = textureArray;
		_init = true;
	}

	BlockData BlockLoader::loadBlockData(const char* blockName)
	{
		BlockData retVal;

		std::ifstream blockIFStream(blockName);
		json file;
		blockIFStream >> file;

		if (DOES_JSON_EXIST(file, "textures"))
		{
			json textureLayers = file["textures"];
			int nx = -1;
			int px = -1;
			int ny = -1;
			int py = -1;
			int nz = -1;
			int pz = -1;

			if (DOES_JSON_EXIST(textureLayers, "nx"))
				nx = _textureArray.getEntry(textureLayers["nx"].get<std::string>());

			if (DOES_JSON_EXIST(textureLayers, "px"))
				px = _textureArray.getEntry(textureLayers["px"].get<std::string>());

			if (DOES_JSON_EXIST(textureLayers, "ny"))
				ny = _textureArray.getEntry(textureLayers["ny"].get<std::string>());

			if (DOES_JSON_EXIST(textureLayers, "py"))
				py = _textureArray.getEntry(textureLayers["py"].get<std::string>());

			if (DOES_JSON_EXIST(textureLayers, "nz"))
				nz = _textureArray.getEntry(textureLayers["nz"].get<std::string>());

			if (DOES_JSON_EXIST(textureLayers, "pz"))
				pz = _textureArray.getEntry(textureLayers["pz"].get<std::string>());

			if (DOES_JSON_EXIST(textureLayers, "sides"))
			{
				int texture = _textureArray.getEntry(textureLayers["sides"].get<std::string>());
				nx = texture;
				px = texture;
				nz = texture;
				pz = texture;
			}

			if (DOES_JSON_EXIST(textureLayers, "all"))
			{
				int texture = _textureArray.getEntry(textureLayers["all"].get<std::string>());
				nx = texture;
				px = texture;
				nz = texture;
				pz = texture;
				ny = texture;
				py = texture;
			}

			if (nx == -1) KRUMB_ERROR("Negative X texture not found for block {}.", blockName);
			if (px == -1) KRUMB_ERROR("Positive X texture not found for block {}.", blockName);
			if (ny == -1) KRUMB_ERROR("Negative Y texture not found for block {}.", blockName);
			if (py == -1) KRUMB_ERROR("Positive Y texture not found for block {}.", blockName);
			if (nz == -1) KRUMB_ERROR("Negative Z texture not found for block {}.", blockName);
			if (pz == -1) KRUMB_ERROR("Positive Z texture not found for block {}.", blockName);

			retVal.textureLayers.nx = nx;
			retVal.textureLayers.px = px;
			retVal.textureLayers.ny = ny;
			retVal.textureLayers.py = py;
			retVal.textureLayers.nz = nz;
			retVal.textureLayers.pz = pz;
		}
		else
		{
			KRUMB_ERROR("No texture layers found for block {}.", blockName);
		}

		return retVal;
	}
}