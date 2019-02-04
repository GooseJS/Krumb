#pragma once

#define KRUMB_CHUNK_LENGTH	16
#define KRUMB_CHUNK_AREA	KRUMB_CHUNK_LENGTH * KRUMB_CHUNK_LENGTH
#define KRUMB_CHUNK_VOLUME	KRUMB_CHUNK_AREA * KRUMB_CHUNK_LENGTH

#define KRUMB_CHUNK_HEIGHT	16

#include <cstdint>

struct BlockPos
{
	int x;
	int y;
	int z;

	BlockPos() {}
	BlockPos(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}

	operator ChunkBlockPos()
	{
		ChunkBlockPos retVal;
		retVal.x = x & KRUMB_CHUNK_LENGTH - 1;
		retVal.z = z & KRUMB_CHUNK_LENGTH - 1;
		retVal.y = y;
		retVal.chunkX = x >> 4;
		retVal.chunkZ = z >> 4;
	}
};

struct ChunkBlockPos : public BlockPos
{
	int chunkX;
	int chunkZ;

	ChunkBlockPos() {}
	ChunkBlockPos(int _x, int _y, int _z, int _chunkX, int _chunkZ) : BlockPos(_x, _y, _z), chunkX(_chunkX), chunkZ(_chunkZ) {}

	int index() { return x | y << 4 | z << 8; }

	operator BlockPos()
	{
		BlockPos retVal;
		retVal.x = x + (chunkX * KRUMB_CHUNK_LENGTH);
		retVal.z = z + (chunkZ * KRUMB_CHUNK_LENGTH);
		retVal.y = y;
		return retVal;
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

	ChunkPos(uint64_t _value) : value(_value) {}
	ChunkPos(int _x, int _z) : x(_x), z(_z) {}
};