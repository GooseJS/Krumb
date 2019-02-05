#pragma once

#include <memory>
#include <cstdint>

#include <KrumbEngine/Logger.h>

#include "Krumb/world/WorldDefines.h"
#include "Krumb/world/Block.h"

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

	class Chunk
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
		ChunkLayer _chunkLayers[KRUMB_CHUNK_LENGTH];
	public:
		Chunk(ChunkPos pos);

		Block getBlockAt(int index);
		Block getBlockAt(ChunkBlockPos pos);

		void setBlockAt(int index, Block block);
		void setBlockAt(ChunkBlockPos pos, Block block);

		ChunkLayer getLayerAt(int y);

		inline ChunkPos getChunkPos() { return _pos; }
	};
}