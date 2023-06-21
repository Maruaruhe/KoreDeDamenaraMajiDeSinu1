#pragma once
#include "Matrix.h"
#include "Vec3.h"

struct Sphere {
	Vector3 center;
	float radius;
};


void DrawGrid(const Matrix4x4& worldViewProjectionMatrix, const Matrix4x4& viewportMatrix);

void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
