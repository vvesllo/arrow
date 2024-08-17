#pragma once
#define M_PI 3.14159265358979323846

#include "Utilities.h"

namespace Easing
{
	float ease_in(float x, float k);
	float ease_out(float x, float k);
	float ease_in_out(float x, float k);

	float elastic_in(float x, float k);
	float elastic_out(float x, float k);
	float elastic_in_out(float x, float k);

	float back_in(float x);
	float back_out(float x);
	float back_in_out(float x);
}