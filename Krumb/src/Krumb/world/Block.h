#pragma once

#include <cstdint>

#include <KrumbEngine.h>

#define BLOCK_FACE_NX		0
#define BLOCK_FACE_PX		1
#define BLOCK_FACE_NY		2
#define BLOCK_FACE_PY		3
#define BLOCK_FACE_NZ		4
#define BLOCK_FACE_PZ		5
#define BLOCK_FACE_SIDES	6
#define BLOCK_FACE_ALL		7

namespace Krumb
{
	typedef int BlockFaceLayer;

	struct BlockFaceLayers
	{
		uint8_t nx;
		uint8_t px;
		uint8_t ny;
		uint8_t py;
		uint8_t nz;
		uint8_t pz;
	};

	struct BlockData
	{
		BlockFaceLayers textureLayers;
	};
}