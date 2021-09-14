#pragma once
#include <cmath>

class Vector3
{
public:
	union
	{
		struct
		{
			float x, y, z;
		};

		float m[3];
	};

	Vector3() {
		Vector3(0.0f, 0.0f, 0.0f);
	}

	Vector3(float _x, float _y, float _z):x(_x),y(_y), z(_z)
	{
	}

	inline Vector3& operator = (const Vector3& rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}

	inline Vector3& operator += (const Vector3& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	inline Vector3& operator += (float f)
	{
		x += f;
		y += f;
		z += f;
		return *this;
	}

	inline Vector3& operator -= (const Vector3& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	inline Vector3& operator -= (float f)
	{
		x -= f;
		y -= f;
		z -= f;
		return *this;
	}

	inline Vector3& operator *= (const float value)
	{
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	inline Vector3& operator /= (const float value)
	{
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	inline const Vector3& operator + () const
	{
		return *this;
	}

	inline Vector3 operator - () const
	{
		return Vector3(-x, -y, -z);
	}

	inline bool operator == (const Vector3& rhs) const
	{
		return (x == rhs.x && y == rhs.y && z == rhs.z);
	}

	inline bool operator != (const Vector3& rhs) const
	{
		return (x != rhs.x || y != rhs.y || z != rhs.z);
	}

	inline Vector3 operator + (const Vector3& rhs) const
	{
		return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	inline Vector3 operator + (float f) const
	{
		return Vector3(x + f, y + f, z + f);
	}

	inline Vector3 operator - (const Vector3& rhs) const
	{
		return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	inline Vector3 operator - (float f) const
	{
		return Vector3(x - f, y - f, z - f);
	}

	inline Vector3 operator * (const Vector3& rhs) const
	{
		return Vector3(x * rhs.x, y * rhs.y, z * rhs.z);
	}

	inline Vector3 operator * (const float f) const
	{
		return Vector3(x * f, y * f, z * f);
	}

	inline friend Vector3 operator * (const float f, const Vector3& rkVec)
	{
		return Vector3(f * rkVec.x, f * rkVec.y, f * rkVec.z);
	}

	inline Vector3 operator / (const float f) const
	{
		return Vector3(x / f, y / f, z / f);
	}

	inline friend Vector3 operator / (const float f, const Vector3& rkVec)
	{
		return Vector3(f / rkVec.x, f / rkVec.y, f / rkVec.z);
	}

	inline Vector3 operator / (const Vector3& rhs) const
	{
		return Vector3(x / rhs.x, y / rhs.y, z / rhs.z);
	}

	inline float dot(const Vector3& rhs) const
	{
		return (x * rhs.x + y * rhs.y + z * rhs.z);
	}

	inline Vector3 cross(const Vector3& rhs) const
	{
		Vector3 vec;

		vec.x = y * rhs.z - z * rhs.y;
		vec.y = z * rhs.x - x * rhs.z;
		vec.z = x * rhs.y - y * rhs.x;

		return vec;
	}

	inline float len() const
	{
		float vecLen;

		float sum = x * x + y * y + z * z;
		vecLen = std::sqrt(sum);

		return vecLen;
	}

	void normalize()
	{
		float l = len();
		x /= l;
		y /= l;
		z /= l;
		return;
	}


public:
	/*float x;
	float y;
	float z;*/
};

