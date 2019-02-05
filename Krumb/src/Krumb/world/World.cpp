#include "Krumb/world/World.h"

namespace Krumb
{
    WorldProvider::WorldProvider()
    {

    }

    WorldProvider::~WorldProvider()
    {

    }

    ChunkPtr WorldProvider::getChunkAt(ChunkPos chunkPos)
    {
        auto chunkIter = _loadedChunks.find(chunkPos);
        ChunkPtr chunk;
        if (chunkIter == _loadedChunks.end())
        {
            // TODO: This is when we attempt to either load chunk from disk if it's been generated, or generate it if it hasn't
            chunk = std::make_shared<Chunk>(chunkPos);
            _loadedChunks.insert(std::pair<ChunkPos, ChunkPtr>(chunkPos, chunk));
        }
        else
        {
            chunk = chunkIter->second;
        }

        return chunk;
    }

    ChunkPtr World::getChunkAt(ChunkPos pos)
    {
        return _worldProvider.getChunkAt(pos);
    }

    Block World::getBlockAt(BlockPos pos)
    {
        return _worldProvider.getChunkAt(pos)->getBlockAt(pos);
    }

    void World::setBlockAt(BlockPos pos, Block block)
    {
        _worldProvider.getChunkAt(pos)->setBlockAt(pos, block);
    }
}