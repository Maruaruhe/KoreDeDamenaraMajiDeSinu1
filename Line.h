#pragma once
#include "Vec3.h"

struct Vector3;

//直線
struct Line {
	Vector3 origin;
	Vector3 diff;
};

//半直線
struct Ray {
	Vector3 origin;
	Vector3 diff;
};

//線分
struct Segment {
	Vector3 origin;
	Vector3 diff;
};