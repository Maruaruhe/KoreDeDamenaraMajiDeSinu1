#include "GridSphere.h"
#include <Novice.h>

#define M_PI 3.14f

void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix) {
	const float kGridHalfWidth = 2.0f;											//Grid�̔����̕�
	const uint32_t kSubdivision = 10;											//������
	const float kGridEvery = (kGridHalfWidth * 2.0f) / float(kSubdivision);	//1���̒���

	//�������O�ւ̐������Ɉ����Ă���
	for (uint32_t xIndex = 0; xIndex <= kSubdivision; ++xIndex) {
		Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, float(5 - int(xIndex)) * kGridEvery });

		Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, viewProjectionMatrix);

		Vector3 localVertices[2] = { {-2, 0, 0}, {2, 0, 0} };
		Vector3 screenVertices[2]{};
		for (uint32_t i = 0; i < 2; ++i) {
			//NDC�܂ŕϊ��BTransform���g���Ɠ������W�n->�f�J���g���W�n�̏������s���A���ʓI��ZDvivide���s���邱�ƂɂȂ�
			Vector3 ndcVertex = Transform(localVertices[i], worldViewProjectionMatrix);
			//viewport�ϊ����g����Screen��Ԃ�
			screenVertices[i] = Transform(ndcVertex, viewportMatrix);
		}
		if (xIndex != 5) {
			Novice::DrawLine((int)screenVertices[0].x, (int)screenVertices[0].y, (int)screenVertices[1].x, (int)screenVertices[1].y, 0xAAAAAAFF);
		}
		else {
			Novice::DrawLine((int)screenVertices[0].x, (int)screenVertices[0].y, (int)screenVertices[1].x, (int)screenVertices[1].y, 0x222222FF);
		}
	}
	//����������������Ă���
	for (uint32_t zIndex = 0; zIndex <= kSubdivision; ++zIndex) {
		Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { float(5 - int(zIndex)) * kGridEvery, 0.0f, 0.0f });

		Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, viewProjectionMatrix);

		Vector3 localVertices[2] = { {0, 0, -2}, {0, 0, 2} };
		Vector3 screenVertices[2]{};
		for (uint32_t i = 0; i < 2; ++i) {
			//NDC�܂ŕϊ��BTransform���g���Ɠ������W�n->�f�J���g���W�n�̏������s���A���ʓI��ZDvivide���s���邱�ƂɂȂ�
			Vector3 ndcVertex = Transform(localVertices[i], worldViewProjectionMatrix);
			//viewport�ϊ����g����Screen��Ԃ�
			screenVertices[i] = Transform(ndcVertex, viewportMatrix);
		}
		if (zIndex != 5) {
			Novice::DrawLine((int)screenVertices[0].x, (int)screenVertices[0].y, (int)screenVertices[1].x, (int)screenVertices[1].y, 0xAAAAAAFF);
		}
		else {
			Novice::DrawLine((int)screenVertices[0].x, (int)screenVertices[0].y, (int)screenVertices[1].x, (int)screenVertices[1].y, 0x222222FF);
		}
	}
}



void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
	const uint32_t kSubdivision = 16;
	const float kLonEvery = (2 * M_PI) / kSubdivision;
	const float kLatEvery = (M_PI) / kSubdivision;
	//�ܓx�̕����ɕ��� -��/1 �` ��/2
	for (uint32_t latIndex = 0; latIndex < kSubdivision; ++latIndex) {
		float lat = -M_PI / 2.0f + kLatEvery * latIndex; //���݂̈ܓx
		//�o�x�̕����ɕ��� 0�`2��
		for (uint32_t lonIndex = 0; lonIndex < kSubdivision; ++lonIndex) {
			float lon = lonIndex * kLonEvery;
			//world���W�n�ł�a, b, c�����߂�
			Vector3 a, b, c;
			a = { std::cos(lat) * std::cos(lon),
				std::sin(lat),
				std::cos(lat) * std::sin(lon) };

			b = { std::cos(lat + kLatEvery) * std::cos(lon),
				std::sin(lat + kLatEvery),
				std::cos(lat + kLatEvery) * std::sin(lon) };

			c = { std::cos(lat) * std::cos(lon + kLonEvery),
				std::sin(lat),
				std::cos(lat) * std::sin(lon + kLonEvery) };

			a.x *= sphere.radius;
			a.y *= sphere.radius;
			a.z *= sphere.radius;

			b.x *= sphere.radius;
			b.y *= sphere.radius;
			b.z *= sphere.radius;

			c.x *= sphere.radius;
			c.y *= sphere.radius;
			c.z *= sphere.radius;

			a.x += sphere.center.x;
			a.y += sphere.center.y;
			a.z += sphere.center.z;

			b.x += sphere.center.x;
			b.y += sphere.center.y;
			b.z += sphere.center.z;

			c.x += sphere.center.x;
			c.y += sphere.center.y;
			c.z += sphere.center.z;

			Matrix4x4 worldMatrixA = MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, a);

			Matrix4x4 worldViewProjectionMatrixA = Multiply(worldMatrixA, viewProjectionMatrix);

			Matrix4x4 worldMatrixB = MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, b);

			Matrix4x4 worldViewProjectionMatrixB = Multiply(worldMatrixB, viewProjectionMatrix);

			Matrix4x4 worldMatrixC = MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, c);

			Matrix4x4 worldViewProjectionMatrixC = Multiply(worldMatrixC, viewProjectionMatrix);

			Vector3 screenVertices[3]{};

			//NDC�܂ŕϊ��BTransform���g���Ɠ������W�n->�f�J���g���W�n�̏������s���A���ʓI��ZDvivide���s���邱�ƂɂȂ�
			Vector3 ndcVertexA = Transform({ 0, 0, 0 }, worldViewProjectionMatrixA);
			//viewport�ϊ����g����Screen��Ԃ�
			screenVertices[0] = Transform(ndcVertexA, viewportMatrix);

			//NDC�܂ŕϊ��BTransform���g���Ɠ������W�n->�f�J���g���W�n�̏������s���A���ʓI��ZDvivide���s���邱�ƂɂȂ�
			Vector3 ndcVertexB = Transform({ 0, 0, 0 }, worldViewProjectionMatrixB);
			//viewport�ϊ����g����Screen��Ԃ�
			screenVertices[1] = Transform(ndcVertexB, viewportMatrix);

			//NDC�܂ŕϊ��BTransform���g���Ɠ������W�n->�f�J���g���W�n�̏������s���A���ʓI��ZDvivide���s���邱�ƂɂȂ�
			Vector3 ndcVertexC = Transform({ 0, 0, 0 }, worldViewProjectionMatrixC);
			//viewport�ϊ����g����Screen��Ԃ�
			screenVertices[2] = Transform(ndcVertexC, viewportMatrix);

			Novice::DrawLine(
				(int)screenVertices[0].x, (int)screenVertices[0].y,
				(int)screenVertices[1].x, (int)screenVertices[1].y,
				color);

			Novice::DrawLine(
				(int)screenVertices[0].x, (int)screenVertices[0].y,
				(int)screenVertices[2].x, (int)screenVertices[2].y,
				color);
		}
	}
}