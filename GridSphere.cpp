#include "GridSphere.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

void DrawGrid(const Matrix4x4& worldViewProjectionMatrix, const Matrix4x4& viewportMatrix) {
	const float kGridHalfWidth = 2.0f;
	const uint32_t kSubdivision = 10;
	const float kGridEvery = (kGridHalfWidth * 2.0f) / float(kSubdivision);

	for (uint32_t xIndex = 0; xIndex <= kSubdivision; ++xIndex) {
		Vector3 screenVertices[11];
		Vector3 kLocalVertices[11];
		kLocalVertices[xIndex] = {1.0f + xIndex * kGridHalfWidth,1.0f + xIndex * kGridHalfWidth,0.0f};
		Vector3 ndcVertex = Transform(kLocalVertices[xIndex], worldViewProjectionMatrix);
		screenVertices[xIndex] = Transform(ndcVertex, viewportMatrix);
		Novice::DrawLine(screenVertices[xIndex].x, screenVertices[xIndex].y + xIndex * kGridEvery, screenVertices[xIndex].x + kGridEvery, screenVertices[xIndex].y + xIndex * kGridEvery, 0xAAAAAAFF);
	}

	for (uint32_t zIndex = 0; zIndex <= kSubdivision; ++zIndex) {
		Novice::DrawLine(0, zIndex * kGridHalfWidth, kGridEvery, zIndex * kGridHalfWidth, WHITE);
	}
}

//void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
//	const uint32_t kSubdivision = 10;
//	const float kLonEvery = ;
//	const float kLatEvery = ;
//
//	for (uint32_t latIndex = 0; latIndex < kSubdivision; ++latIndex) {
//		float lat = -pi / 2.0f + kLatEvery * latIndex;
//
//		for (uint32_t lonIndex = 0; lonIndex < kSubdivision; ++lonIndex) {
//			float lon = lonIndex * kLonEvery;
//
//			Vector3 a, b, c;
//
//			Novice::DrawLine();
//			Novice::DrawLine();
//		}
//	}
//}