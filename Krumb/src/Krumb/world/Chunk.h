#pragma once

#include <memory>
#include <cstdint>
#include <stdlib.h>
#include <array>

#include <KrumbEngine/Logger.h>

#include "Krumb/world/Block.h"
#include "Krumb/render/ChunkMesh.h"
#include "Krumb/world/WorldDefines.h"

namespace Krumb
{
	class ChunkData
	{
	private:
		int* _data;
	public:
		ChunkData(int dataSize)
		{
			_data = new int[dataSize] {};
		}
		~ChunkData() { delete[] _data; }

		const int getDataAt(int index) const { return _data[index]; }
		void setDataAt(int index, int data) { _data[index] = data; }
	};

	class Chunk : public std::enable_shared_from_this<Chunk>
	{
	public:
		struct ChunkLayer
		{
		private:
			int _solidBlockCount = 0;
		public:
			void addBlock(Block block)
			{
				if (block.getBlockData().shouldRenderWithWorld)
					_solidBlockCount++;
			}

			void removeBlock(Block block)
			{
				if (block.getBlockData().shouldRenderWithWorld)
					_solidBlockCount--;
			}

			bool isAllSolid() const
			{
				return _solidBlockCount == KRUMB_CHUNK_AREA;
			}

			bool shouldDraw() const
			{
				return _solidBlockCount != 0;
			}
		};
	private:
		ChunkPos _pos;
		ChunkData _data;
        ChunkMesh _chunkMesh {};
		ChunkLayer _chunkLayers[KRUMB_CHUNK_LENGTH];

		std::array<std::shared_ptr<Chunk>, KRUMB_CHUNK_HEIGHT> _chunkColumn;

		bool withinYBounds(int y);

	public:
		Chunk();
		Chunk(ChunkPos pos);

		void init();

		Block getBlockAt(int index);
		Block getBlockAt(ChunkBlockPos pos);

		void setBlockAt(int index, Block block);
		void setBlockAt(ChunkBlockPos pos, Block block);

		ChunkLayer getLayerAt(int y);

		inline ChunkPos getChunkPos() { return _pos; }
		inline ChunkMesh& getChunkMesh(int chunkY) { if (_pos.y == chunkY) return _chunkMesh; else return _chunkColumn[chunkY]->getChunkMesh(chunkY); }
	};
}