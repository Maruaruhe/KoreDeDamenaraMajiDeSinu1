#pragma once
#include "Vec3.h"

struct Vector3;

//����
struct Line {
	Vector3 origin;
	Vector3 diff;
};

//������
struct Ray {
	Vector3 origin;
	Vector3 diff;
};

//����
struct Segment {
	Vector3 origin;
	Vector3 diff;
};