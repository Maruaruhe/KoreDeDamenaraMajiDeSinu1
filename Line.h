#pragma once
#include "Vec3.h"

struct Vector3;

//’¼ü
struct Line {
	Vector3 origin;
	Vector3 diff;
};

//”¼’¼ü
struct Ray {
	Vector3 origin;
	Vector3 diff;
};

//ü•ª
struct Segment {
	Vector3 origin;
	Vector3 diff;
};