#pragma once

//int RandomNum(int min, int max);

template<class T>
T RandomNum(T min, T max)
{
	random_device rd;
	mt19937 mt(rd());

	uniform_real_distribution<T> rand(min, max);

	return rand(mt);
}

float LinerInterpolation(float start, float end, float s);