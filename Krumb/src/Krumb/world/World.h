#pragma once

#include <memory>
#include <unordered_map>

#include "Krumb/world/WorldDefines.h"

#include "Krumb/world/Block.h"
#include "Krumb/world/Chunk.h"

namespace Krumb
{
    typedef std::shared_ptr<Chunk> ChunkPtr;
    typedef std::unordered_map<ChunkPos, ChunkPtr> ChunkMap;

    class WorldProvider
    {
    private:
        ChunkMap _loadedChunks;
    public:
        WorldProvider();
        ~WorldProvider();

        ChunkPtr getChunkAt(ChunkPos chunkPos);

        inline ChunkMap getLoadedChunks() { return _loadedChunks;}
    };

    class World
    {
    private:
        WorldProvider _worldProvider;
    public:
        ChunkPtr getChunkAt(ChunkPos pos);

        Block getBlockAt(BlockPos pos);
        void setBlockAt(BlockPos pos, Block block);

        // TODO: See if I want to handle this better
        inline ChunkMap getLoadedChunks() { return _worldProvider.getLoadedChunks(); }
    };
}