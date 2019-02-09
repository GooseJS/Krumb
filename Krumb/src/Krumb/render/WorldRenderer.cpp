#include "Krumb/render/WorldRenderer.h"

namespace Krumb
{
    WorldRenderer::WorldRenderer(World* world)
    {
        _world = world;
    }

    void WorldRenderer::initRenderer(KrumbEngine::Texture::TextureArray textureAtlas)
    {
        _shader.initFromFile("shader.vert", "shader.frag");
        _textureAtlas = textureAtlas;

    }

    void WorldRenderer::render()
    {
        glEnable(GL_DEPTH_TEST);
        //
        _worldRenderCam->generateMatrices();
        glm::mat4 transformedMatrix = _worldRenderCam->getProjectionMatrix() * _worldRenderCam->getViewMatrix();

        _shader.use();

        glUniformMatrix4fv(_shader.uniform("projectionViewMatrix"), 1, GL_FALSE, &transformedMatrix[0][0]);
        glUniform3f(_shader.uniform("lightPos"), 0.0f, 64.0f, 0.0f);
        
        glm::mat4 translation(1.0f);

        glBindTexture(GL_TEXTURE_2D_ARRAY, _textureAtlas.textureID);
        glActiveTexture(GL_TEXTURE0);

        for (auto chunk : _world->getLoadedChunks())
        {
            for (int y = 0; y < KRUMB_CHUNK_HEIGHT; y++)
            {
                if (chunk.second->getChunkMesh(y).getData().init)
                {
                    translation = glm::translate(glm::vec3(chunk.first.x * KRUMB_CHUNK_LENGTH, y * KRUMB_CHUNK_LENGTH, chunk.first.z * KRUMB_CHUNK_LENGTH));
                    glUniformMatrix4fv(_shader.uniform("translationMatrix"), 1, GL_FALSE, &translation[0][0]);
                    glBindVertexArray(chunk.second->getChunkMesh(y).getData().chunkVAO);
                    glDrawArrays(GL_TRIANGLES, chunk.second->getChunkMesh(y).getData().numVertices, GL_FLOAT);
                }
            }
        }
    }
}
