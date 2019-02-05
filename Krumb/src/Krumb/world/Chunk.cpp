#include "Krumb/world/Chunk.h"

namespace Krumb
{
	Chunk::Chunk(ChunkPos pos) : _pos(pos), _data(KRUMB_CHUNK_VOLUME)
	{

	}

	Block Chunk::getBlockAt(int index)
	{
		// TODO: Debug checking if greater than chunk volume?
		return BlockManager::getInstance()->getBlock(_data.getDataAt(index));
	}

	Block Chunk::getBlockAt(ChunkBlockPos pos)
	{
		return getBlockAt(pos.index());
	}

	void Chunk::setBlockAt(int index, Block block)
	{
		_data.setDataAt(index, block.getBlockID());
	}

	void Chunk::setBlockAt(ChunkBlockPos pos, Block block)
	{
		setBlockAt(pos.index(), block);
	}

	Chunk::ChunkLayer Chunk::getLayerAt(int y)
	{
		// TODO: Debug checking that this is less than chunk length
		return _chunkLayers[y];
	}

//	template<typename Pos, typename>
//	inline int Chunk::getBlockAt(Pos pos)
//	{
//		if (std::is_same<Pos, BlockPos>::value)
//		{
//
//		}
//		else
//		{
//			// NOTE: Means that it's a ChunkBlockPos
//		}
//		return 0;
//	}
}