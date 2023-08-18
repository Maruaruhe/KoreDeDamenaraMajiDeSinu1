#pragma once
#include "Matrix.h"
#include "Vec3.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Triangle.h"

struct AABB {
	Vector3 min;
	Vector3 max;
};

void DrawAABB(const AABB& aabb, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
bool IsCollision(const AABB& a, const AABB& b);