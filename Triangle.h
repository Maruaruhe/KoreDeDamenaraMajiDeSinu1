#pragma once
#include "Matrix.h"
#include "Vec3.h"
#define _USE_MATH_DEFINES
#include <math.h>

//ŽOŠpŒ`
struct Triangle {
	Vector3 vertices[3];
};

bool IsCollision(const Triangle& triangle, const Segment& segment);


void DrawLine(const Segment& segment, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
void DrawTriangle(const Triangle& triangle, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);