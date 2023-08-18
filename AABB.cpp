#include "AABB.h"
#include <algorithm>

void DrawAABB(const AABB& aabb, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
    Vector3 point[8];

    point[0] = { aabb.min.x, aabb.min.y, aabb.min.z };

    point[1] = { aabb.max.x, aabb.min.y, aabb.min.z };

    point[2] = { aabb.min.x, aabb.max.y, aabb.min.z };

    point[3] = { aabb.min.x, aabb.min.y, aabb.max.z };

    point[4] = { aabb.max.x, aabb.max.y, aabb.min.z };

    point[5] = { aabb.max.x, aabb.min.y, aabb.max.z };

    point[6] = { aabb.min.x, aabb.max.y, aabb.max.z };

    point[7] = { aabb.max.x, aabb.max.y, aabb.max.z };

    Segment segment[12] = { 0 };
    segment[0].origin = point[0];
    segment[0].diff = Subtract(point[1], point[0]);
    segment[1].origin = point[2];
    segment[1].diff = Subtract(point[4], point[2]);
    segment[2].origin = point[3];
    segment[2].diff = Subtract(point[5], point[3]);
    segment[3].origin = point[6];
    segment[3].diff = Subtract(point[7], point[6]);

    segment[4].origin = point[0];
    segment[4].diff = Subtract(point[3], point[0]);
    segment[5].origin = point[1];
    segment[5].diff = Subtract(point[5], point[1]);
    segment[6].origin = point[2];
    segment[6].diff = Subtract(point[6], point[2]);
    segment[7].origin = point[4];
    segment[7].diff = Subtract(point[7], point[4]);

    segment[8].origin = point[0];
    segment[8].diff = Subtract(point[2], point[0]);
    segment[9].origin = point[1];
    segment[9].diff = Subtract(point[4], point[1]);
    segment[10].origin = point[3];
    segment[10].diff = Subtract(point[6], point[3]);
    segment[11].origin = point[5];
    segment[11].diff = Subtract(point[7], point[5]);

    for (int i = 0; i < 12; i++) {
        DrawLine(segment[i], viewProjectionMatrix, viewportMatrix, color);
    }
}

bool IsCollision(const AABB& a, const AABB& b) {
    if ((a.min.x <= b.max.x && a.max.x >= b.min.x) &&
        (a.min.y <= b.max.y && a.max.y >= b.min.y) &&
        (a.min.z <= b.max.z && a.max.z >= b.min.z)) {
        return true;
    }
    return false;
}

bool IsCollision(const AABB& a, const Sphere& sphere) {
    Vector3 clossestPoint{
        std::clamp(sphere.center.x,a.min.x,a.max.x),
        std::clamp(sphere.center.y,a.min.x,a.max.y),
        std::clamp(sphere.center.z,a.min.x,a.max.z),
    };
    float distance = Length(Subtract(clossestPoint, sphere.center));

    if (distance <= sphere.radius) {
        return true;
    }
    return false;
}