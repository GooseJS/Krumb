#pragma once

#include <cstdint>
#include <vector>

#include <KrumbEngine.h>

#define BLOCK_FACE_NX		0
#define BLOCK_FACE_PX		1
#define BLOCK_FACE_NY		2
#define BLOCK_FACE_PY		3
#define BLOCK_FACE_NZ		4
#define BLOCK_FACE_PZ		5
#define BLOCK_FACE_SIDES	6
#define BLOCK_FACE_ALL		7

namespace Krumb
{
	typedef int BlockFace;

	struct BlockFaceLayers
	{
		uint8_t nx;
		uint8_t px;
		uint8_t ny;
		uint8_t py;
		uint8_t nz;
		uint8_t pz;
	};

	struct BlockData
	{
		uint8_t blockID;
		BlockFaceLayers textureLayers;

		bool shouldRenderWithWorld;
	};

	class Block
	{
	private:
		friend class BlockManager;
		int _blockID;
		const char* _name;
		BlockData _data;
	public:
		Block(const char* name, BlockData blockData);
		int getBlockID() const { return _blockID; }
		const char* getName() const { return _name; }
		BlockData& getBlockData() { return _data; }
	};

	class BlockManager
	{
	private:
		std::vector<Block> _registeredBlocks;
	public:
		static BlockManager* getInstance()
		{
			static BlockManager instance;
			return &instance;
		}

		int registerBlock(Block& block);
		Block getBlock(int blockID);
		Block getBlock(const char* blockName);
		int getLastBlockID();
	};
}