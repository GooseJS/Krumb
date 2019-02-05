#include "Krumb/world/Block.h"

namespace Krumb
{
	Block::Block(const char * name, BlockData blockData) : _blockID(BlockManager::getInstance()->getLastBlockID()), _name(name), _data(blockData)
	{

	}

	int BlockManager::registerBlock(Block& block)
	{
		int blockID = _registeredBlocks.size();
		block._blockID = blockID;
		_registeredBlocks.push_back(block);
		return _registeredBlocks.size() - 1;
	}
	
	Block BlockManager::getBlock(int blockID)
	{
		return _registeredBlocks[blockID];
	}

	Block BlockManager::getBlock(const char * blockName)
	{
		for (const auto& block : _registeredBlocks)
		{
			if (block.getName() == blockName)
				return block;
		}

		return Block("Air", BlockData());
	}

	int BlockManager::getLastBlockID()
	{
		return _registeredBlocks.size() - 1;
	}
}