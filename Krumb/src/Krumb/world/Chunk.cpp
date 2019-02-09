#include "Krumb/world/Chunk.h"

namespace Krumb
{
    Chunk::Chunk() : _pos(0, 0, 0), _data(KRUMB_CHUNK_VOLUME)
    {

    }

	Chunk::Chunk(ChunkPos pos) : _pos(pos), _data(KRUMB_CHUNK_VOLUME)
	{
        _pos.y = 0;
	}

	void Chunk::init()
	{
		_chunkColumn[0] = shared_from_this();
		for(int y = 1; y < KRUMB_CHUNK_HEIGHT; y++)
		{
			_chunkColumn[y] = std::make_shared<Chunk>(ChunkPos(_pos.x, y, _pos.z));
			_chunkColumn[y]->_pos.x = _pos.x;
			_chunkColumn[y]->_pos.y = y;
			_chunkColumn[y]->_pos.z = _pos.z;
			_chunkColumn[y]->_chunkColumn = _chunkColumn;
		}
	}

	bool Chunk::withinYBounds(int y)
	{
		int bottomY = KRUMB_CHUNK_LENGTH * _pos.y;
		int topY = bottomY + KRUMB_CHUNK_LENGTH - 1;
		return bottomY <= y && y <= topY;
	}

	Block Chunk::getBlockAt(int index)
	{
		// TODO: Debug checking if greater than chunk volume?
		return BlockManager::getInstance()->getBlock(_data.getDataAt(index));
	}

	Block Chunk::getBlockAt(ChunkBlockPos pos)
	{
		if (withinYBounds(pos.y))
			return getBlockAt(pos.index());
		else
			return _chunkColumn[(pos.y >> 4)]->getBlockAt(pos);
	}

	void Chunk::setBlockAt(int index, Block block)
	{
		_data.setDataAt(index, block.getBlockID());
	}

	void Chunk::setBlockAt(ChunkBlockPos pos, Block block)
	{
		if (withinYBounds(pos.y))
        {
            setBlockAt(pos.index(), block);
            _chunkLayers[pos.y].addBlock(block);
        }
		else
        {
            _chunkColumn[pos.y >> 4]->setBlockAt(pos.index(), block);
            _chunkColumn[pos.y >> 4]->_chunkLayers[pos.y & 15].addBlock(block);
        }
	}

	Chunk::ChunkLayer Chunk::getLayerAt(int y)
	{
		// TODO: Debug checking that this is less than chunk height * length
		if (withinYBounds(y))
			return _chunkLayers[y & 15];
		else
			return _chunkColumn[y >> 4]->getLayerAt(y);

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