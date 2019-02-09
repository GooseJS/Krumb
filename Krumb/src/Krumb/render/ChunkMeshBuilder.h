#pragma once

#include "Krumb/world/World.h"
#include "Krumb/render/ChunkMesh.h"

namespace Krumb
{
    typedef bool* VisibleBlockFaces;

    class ChunkMeshBuilder
    {
    private:
        World* _world;

        VisibleBlockFaces checkForVisibleFaces(BlockPos pos);
    public:
        explicit ChunkMeshBuilder(World* world);
        void buildChunk(ChunkPos pos);
    };
}