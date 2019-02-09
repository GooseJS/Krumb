#pragma once

#include <KrumbEngine.h>
#include <KrumbEngine/GL.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

#include "Krumb/world/World.h"
#include "Krumb/render/Camera.h"

namespace Krumb
{
    class WorldRenderer
    {
    private:
        World* _world;
        KrumbEngine::Shader _shader;
        KrumbEngine::Texture::TextureArray _textureAtlas;

        Camera* _worldRenderCam = nullptr;

    public:
        WorldRenderer(World* world);

        void initRenderer(KrumbEngine::Texture::TextureArray _textureAtlas);

        void render();

        inline void setWorldRenderCam(Camera* camera) { _worldRenderCam = camera; }
    };
}
