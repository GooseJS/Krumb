#pragma once

#define KRUMB_CHUNK_LENGTH	16
#define KRUMB_CHUNK_AREA	KRUMB_CHUNK_LENGTH * KRUMB_CHUNK_LENGTH
#define KRUMB_CHUNK_VOLUME	KRUMB_CHUNK_AREA * KRUMB_CHUNK_LENGTH

#define KRUMB_CHUNK_HEIGHT	16

#include <cstdint>
#include <functional>

namespace Krumb
{
	struct BlockPos
	{
		int x;
		int y;
		int z;

		BlockPos()
		{}

		BlockPos(int _x, int _y, int _z) : x(_x), y(_y), z(_z)
		{}

		BlockPos(struct ChunkBlockPos pos);
	};

	struct ChunkBlockPos : public BlockPos
	{
		int chunkX;
		int chunkZ;

		ChunkBlockPos()
		{}

		ChunkBlockPos(int _x, int _y, int _z, int _chunkX, int _chunkZ) : BlockPos(_x, _y, _z), chunkX(_chunkX), chunkZ(_chunkZ)
		{}

		int index()
		{ return x | y << 4 | z << 8; }

		ChunkBlockPos(BlockPos pos)
		{
			x = pos.x & 15;
			z = pos.z & 15;
			y = pos.y;

			chunkX = pos.x >> 4;
			chunkZ = pos.z >> 4;
		}
	};

	struct ChunkPos
	{
		union
		{
			struct
			{
				int32_t x;
				int32_t z;
			};
			uint64_t value;
		};

		explicit ChunkPos(uint64_t _value) : value(_value)
		{}

		ChunkPos(int _x, int _z) : x(_x), z(_z)
		{}

		bool operator==(const ChunkPos &other) const
		{
			return value == other.value;
		}

		bool operator==(ChunkPos &other)
		{
			return value == other.value;
		}

		ChunkPos(BlockPos pos)
		{
			x = pos.x >> 4;
			z = pos.z >> 4;
		}

		ChunkPos(ChunkBlockPos pos)
		{
			x = pos.chunkX;
			z = pos.chunkZ;
		}
	};

	inline BlockPos::BlockPos(ChunkBlockPos pos)
	{
		x = pos.x + (pos.chunkX * KRUMB_CHUNK_LENGTH);
		z = pos.z + (pos.chunkZ * KRUMB_CHUNK_LENGTH);
		y = pos.y;
	}

	struct ChunkPosHasher
	{
		std::size_t operator()(const ChunkPos chunkPos) const noexcept
		{
			return chunkPos.value; // or use boost::hash_combine (see Discussion)
		}
	};
}

namespace std
{

	template<>
	struct hash<Krumb::ChunkPos>
	{
		std::size_t operator()(const Krumb::ChunkPos &chunkPos) const
		{
			return chunkPos.value;
		}
	};
}