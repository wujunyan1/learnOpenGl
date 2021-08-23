#pragma once
class Vector3
{
public:
	Vector3() {
		Vector3(0.0f, 0.0f, 0.0f);
	}

	Vector3(float _x, float _y, float _z):x(_x),y(_y), z(_z)
	{
	}

public:
	float x;
	float y;
	float z;
};

