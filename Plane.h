#pragma once
#include "Vec3.h"
#include "Matrix.h"
#include <Novice.h>
#include "GridSphere.h"

struct Plane {
	Vector3 normal; //ñ@ê¸
	float distance;//ãóó£
};

Vector3 Perpendicular(const Vector3& vector);
void DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

bool IsCollision(const Sphere& sphere, const Plane& plane);