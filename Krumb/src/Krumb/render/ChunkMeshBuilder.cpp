#include "Krumb/render/ChunkMeshBuilder.h"

namespace Krumb
{
    ChunkMeshBuilder::ChunkMeshBuilder(Krumb::World* world) : _world(world)
    {

    }

    VisibleBlockFaces ChunkMeshBuilder::checkForVisibleFaces(Krumb::BlockPos pos)
    {
        VisibleBlockFaces visibleFaces = new bool[6];

        visibleFaces[BLOCK_FACE_NX] = _world->getBlockAt(pos.changeX(-1)).getBlockData().shouldRenderWithWorld;
        visibleFaces[BLOCK_FACE_NY] = _world->getBlockAt(pos.changeY(-1)).getBlockData().shouldRenderWithWorld;
        visibleFaces[BLOCK_FACE_NZ] = _world->getBlockAt(pos.changeZ(-1)).getBlockData().shouldRenderWithWorld;
        visibleFaces[BLOCK_FACE_PX] = _world->getBlockAt(pos.changeX(1)).getBlockData().shouldRenderWithWorld;
        visibleFaces[BLOCK_FACE_PY] = _world->getBlockAt(pos.changeY(1)).getBlockData().shouldRenderWithWorld;
        visibleFaces[BLOCK_FACE_PZ] = _world->getBlockAt(pos.changeZ(1)).getBlockData().shouldRenderWithWorld;

        return visibleFaces;
    }

    void ChunkMeshBuilder::buildChunk(ChunkPos pos)
    {
        ChunkPtr chunk = _world->getChunkAt(pos);
        ChunkMesh& chunkMesh = chunk->getChunkMesh(pos.y);

        for (int y = 0; y < (KRUMB_CHUNK_LENGTH * KRUMB_CHUNK_HEIGHT); y++)
        {
            if (y % 16 == 0)
                chunkMesh = chunk->getChunkMesh(pos.y >> 4);
            Chunk::ChunkLayer layer = chunk->getLayerAt(y);

            if (!layer.shouldDraw())
                continue;
            else if (layer.isAllSolid())
            {
                bool botPos;
                if (y == 0) botPos = true;
                else botPos = chunk->getLayerAt(y - 1).isAllSolid();
                bool topPos;
                if (y == KRUMB_CHUNK_LENGTH * KRUMB_CHUNK_HEIGHT) topPos = true;
                else topPos = chunk->getLayerAt(y + 1).isAllSolid();

                if (botPos && topPos)
                {
                    // TODO: See how many times this actually happens and skips rendering
                    continue;
                }
            }

            for (int x = 0; x < KRUMB_CHUNK_LENGTH; x++)
            {
                for (int z = 0; z < KRUMB_CHUNK_LENGTH; z++)
                {
                    Block currentBlock = chunk->getBlockAt(ChunkBlockPos(x, y, z, pos.x, pos.z));
                    if (currentBlock.getBlockData().shouldRenderWithWorld)
                    {
                        VisibleBlockFaces visibleFaces = checkForVisibleFaces(ChunkBlockPos(x, y, z, pos.x, pos.z));

                        if (visibleFaces[BLOCK_FACE_NX])
                            chunkMesh.addFace(currentBlock, BLOCK_FACE_NX, x, y, z);
                        else if (visibleFaces[BLOCK_FACE_PX])
                            chunkMesh.addFace(currentBlock, BLOCK_FACE_PX, x, y, z);
                        else if (visibleFaces[BLOCK_FACE_NY])
                            chunkMesh.addFace(currentBlock, BLOCK_FACE_NY, x, y, z);
                        else if (visibleFaces[BLOCK_FACE_PY])
                            chunkMesh.addFace(currentBlock, BLOCK_FACE_PY, x, y, z);
                        else if (visibleFaces[BLOCK_FACE_NZ])
                            chunkMesh.addFace(currentBlock, BLOCK_FACE_NZ, x, y, z);
                        else if (visibleFaces[BLOCK_FACE_PZ])
                            chunkMesh.addFace(currentBlock, BLOCK_FACE_PZ, x, y, z);
                    }
                }
            }
        }
    }
}