#include "Triangle.h"
#include <Novice.h>
#include "Plane.h"

bool IsCollision(const Triangle& triangle, const Segment& segment) {
	Plane plane{};
	plane.normal = Normalize(Cross(Subtract(triangle.vertices[1], triangle.vertices[0]),Subtract(triangle.vertices[2], triangle.vertices[1])));
	plane.distance = Dot(triangle.vertices[0], plane.normal);
	float dot = Dot(segment.diff, plane.normal);
	if (dot == 0.0f) {
		return false;
	}
	float t = (plane.distance - Dot(segment.origin, plane.normal)) / dot;
	if (t < 0 && 1 < t) {
		return false;
	}
	Vector3 p = Add(segment.origin, Multiply(t, segment.origin));
	Vector3 cross1 = Cross(Subtract(triangle.vertices[1], triangle.vertices[0]), Subtract(p, triangle.vertices[1]));
	Vector3 cross2 = Cross(Subtract(triangle.vertices[2], triangle.vertices[1]), Subtract(p, triangle.vertices[2]));
	Vector3 cross3 = Cross(Subtract(triangle.vertices[0], triangle.vertices[2]), Subtract(p, triangle.vertices[0]));
	if (Dot(cross1, plane.normal) >= 0.0f &&
		Dot(cross2, plane.normal) >= 0.0f &&
		Dot(cross3, plane.normal) >= 0.0f) {
		return true;
	}
	return false;
}

void DrawLine(const Segment& segment, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
	Vector3 start = Transform(Transform(segment.origin, viewProjectionMatrix), viewportMatrix);
	Vector3 end = Transform(Transform(Add(segment.origin, segment.diff), viewProjectionMatrix), viewportMatrix);
	Novice::DrawLine(int(start.x), int(start.y), int(end.x), int(end.y), color);
}

void DrawTriangle(const Triangle& triangle, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
	Segment line[3];
	line[0].origin = triangle.vertices[0];
	line[0].diff = Subtract(triangle.vertices[1], triangle.vertices[0]);

	line[1].origin = triangle.vertices[1];
	line[1].diff = Subtract(triangle.vertices[2], triangle.vertices[1]);

	line[2].origin = triangle.vertices[2];
	line[2].diff = Subtract(triangle.vertices[0], triangle.vertices[2]);

	for (int i = 0; i < 3; i++)
	{
		DrawLine(line[i], viewProjectionMatrix, viewportMatrix, color);
	}
}