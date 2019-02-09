#pragma once

#include <KrumbEngine/GL.h>

#include "Krumb/world/Chunk.h"

namespace Krumb
{
    struct ChunkMeshData
    {
        GLuint chunkVAO = 0;
        GLuint chunkVertexBuffer = 0;

        int numVertices = 0;

        bool init = false;
        bool needsRebuild = false;
    };

    struct ChunkVertex
    {
        float xyz[3];
        float texCoord[3];

        ChunkVertex(float _x, float _y, float _z, float _tx, float _ty, float _tw)
        {
            xyz[0] = _x;
            xyz[1] = _y;
            xyz[2] = _z;
            texCoord[0] = _tx;
            texCoord[1] = _ty;
            texCoord[2] = _tw;
        }
    };

    class ChunkMesh
    {
    private:
        ChunkMeshData _chunkMeshData{};
        std::vector<ChunkVertex> _chunkVertices;
    public:
        inline void addFace(Block block, BlockFace face, uint16_t x, uint16_t y, uint16_t z)
        {
            if (face == BLOCK_FACE_NX)
            {
                int textureLayer = block.getBlockData().textureLayers.nx;

                _chunkVertices.emplace_back(x + 0, y + 1, z + 0, 1, 1, textureLayer);
                _chunkVertices.emplace_back(x + 0, y + 0, z + 1, 0, 0, textureLayer);
                _chunkVertices.emplace_back(x + 0, y + 0, z + 0, 1, 0, textureLayer);

                _chunkVertices.emplace_back(x + 0, y + 1, z + 0, 1, 1, textureLayer);
                _chunkVertices.emplace_back(x + 0, y + 1, z + 1, 0, 1, textureLayer);
                _chunkVertices.emplace_back(x + 0, y + 0, z + 1, 1, 0, textureLayer);
            }
            else if (face == BLOCK_FACE_PX)
            {
                int textureLayer = block.getBlockData().textureLayers.px;

                _chunkVertices.emplace_back(x + 1, y + 1, z + 1, 1, 0, textureLayer);
                _chunkVertices.emplace_back(x + 1, y + 0, z + 0, 0, 1, textureLayer);
                _chunkVertices.emplace_back(x + 1, y + 0, z + 1, 0, 0, textureLayer);

                _chunkVertices.emplace_back(x + 1, y + 1, z + 1, 1, 0, textureLayer);
                _chunkVertices.emplace_back(x + 1, y + 1, z + 0, 1, 1, textureLayer);
                _chunkVertices.emplace_back(x + 1, y + 0, z + 0, 0, 1, textureLayer);
            }
        }

        inline void setupMesh()
        {
            if (!_chunkMeshData.init)
                glGenVertexArrays(1, &(_chunkMeshData.chunkVAO));
            glBindVertexArray(_chunkMeshData.chunkVAO);

            if (!_chunkMeshData.init)
                glGenBuffers(1, &(_chunkMeshData.chunkVertexBuffer));

            _chunkMeshData.numVertices = _chunkVertices.size();

            glBindBuffer(GL_ARRAY_BUFFER, _chunkMeshData.chunkVertexBuffer);
            glBufferData(GL_ARRAY_BUFFER, _chunkMeshData.numVertices * sizeof(ChunkVertex), getRawVertexData(), GL_STATIC_DRAW);

            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ChunkVertex), (GLvoid*)offsetof(ChunkVertex, xyz));

            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ChunkVertex), (GLvoid*)(offsetof(ChunkVertex, texCoord)));

            _chunkVertices.clear();

            _chunkMeshData.init = true;
        }

        inline ChunkMeshData& getData() { return _chunkMeshData; }

        inline int getNumVertices() const { if (!_chunkVertices.empty()) return static_cast<int>(_chunkVertices.size()); else return _chunkMeshData.numVertices; }

        void* getRawVertexData() { return &_chunkVertices[0]; }
    };
}
