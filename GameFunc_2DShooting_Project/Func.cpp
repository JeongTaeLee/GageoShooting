#include "DXUT.h"
#include "Func.h"

//int RandomNum(int min, int max)
//{
//	random_device rd;
//	mt19937 mt(rd());
//
//	uniform_int_distribution<int> rand(min, max);
//
//	return rand(mt);
//}

float LinerInterpolation(float start, float end, float s)
{
	return start + ((end - start) * s);
}

