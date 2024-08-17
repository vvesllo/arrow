#include "Easing.h"


float Easing::ease_in(float x, float k)		{ return 1 - std::cos((x * M_PI) / k); }
float Easing::ease_out(float x, float k)	{ return std::sin((x * M_PI) / k); }
float Easing::ease_in_out(float x, float k)	{ return -(std::cos(M_PI * x) - 1) / k; }

float Easing::elastic_in(float x, float k)
{
	const float c = (k * M_PI) / 3;

	return x == 0 ? 0
		: x == 1 ? 1
		: -std::pow(2, 10 * x - 10) * std::sin((x * 10 - 10.75) * c);
}

float Easing::elastic_out(float x, float k)
{
	const float c = (k * M_PI) / 3;

	return x == 0 ? 0
		: x == 1 ? 1
		: std::pow(2, -10 * x) * std::sin((x * 10 - 0.75) * c) + 1;
}

float Easing::elastic_in_out(float x, float k)
{
	const float c = (k * M_PI) / 4.5;

	return x == 0 ? 0
		: x == 1 ? 1
		: x < 0.5 ? -(std::pow(2, 20 * x - 10) * std::sin((20 * x - 11.125) * c)) / 2
		: (std::pow(2, -20 * x + 10) * std::sin((20 * x - 11.125) * c)) / 2 + 1;
}

float Easing::back_in(float x)
{
	const float c1 = 1.70158;
	const float c2 = c1 + 1;

	return c2 * x * x * x - c1 * x * x;
}
float Easing::back_out(float x)
{
	const float c1 = 1.70158;
	const float c2 = c1 + 1;

	return 1 + c2 * std::pow(x - 1, 3) + c1 * std::pow(x - 1, 2);
}
float Easing::back_in_out(float x)
{
	const float c1 = 1.70158;
	const float c2 = c1 * 1.525;

	return x < 0.5
		? (std::pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
		: (std::pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
}