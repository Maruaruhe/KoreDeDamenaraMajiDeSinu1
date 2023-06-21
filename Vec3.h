#pragma once
#include "Matrix.h"
#include "assert.h"
#include "main.h"
#include <Novice.h>

struct Matrix4x4;

struct Vector3
{
	float x;
	float y;
	float z;
};

Vector3 Add(Vector3 v1, Vector3 v2);
Vector3 Subtract(Vector3 v1, Vector3 v2);

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

Vector3 Cross(const Vector3& vector1, const Vector3& vector2);

void VectorScreenPrint(int x, int y, const Vector3& vector, const char* label);