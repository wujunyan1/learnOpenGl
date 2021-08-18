/********************************************************************
filename: 	Vector3.h
file path:	dev\engine\Src\Core\Math\

version:	1
author:		ajohn
company:	supernano
*********************************************************************/

#ifndef __LORD_VEC3_H__
#define __LORD_VEC3_H__

#include <array>
#include "Vector2.h"
#include "IntMath.h"
#include "LinearMath/btVector3.h"

namespace LORD
{
	class Quaternion;

	class LORD_CORE_API Vector3
	{
	public:
		union
		{
			struct 
			{
				Real x, y, z;
			};

			Real m[3];
		};

		static const Vector3 ZERO;					//!< Vec3(0, 0, 0)
		static const Vector3 ONE;					//!< Vec3(1, 1, 1)
		static const Vector3 HALF;					//!< Vec3(0.5f, 0.5f, 0.5f)
		static const Vector3 UNIT_X;				//!< Vec3(1, 0, 0)
		static const Vector3 UNIT_Y;				//!< Vec3(0, 1, 0)
		static const Vector3 UNIT_Z;				//!< Vec3(0, 0, 1)
		static const Vector3 NEG_UNIT_X;			//!< Vec3(-1, 0, 0)
		static const Vector3 NEG_UNIT_Y;			//!< Vec3(0, -1, 0)
		static const Vector3 NEG_UNIT_Z;			//!< Vec3(0, 0, -1)
		static const Vector3 INVALID;				//!< Vec3(Math::MAX_REAL, Math::MAX_REAL, Math::MAX_REAL)
		static ui32	 OP_COUNT;

	public:
		inline Vector3()
			: x(0.0)
			, y(0.0)
			, z(0.0)
		{
		}

		inline Vector3(Real _x, Real _y, Real _z)
			: x(_x)
			, y(_y)
			, z(_z)
		{
			ADD_MATH_OP_COUNT
		}

		inline Vector3(const Vector2& vec, Real _z)
			: x(vec.x)
			, y(vec.y)
			, z(_z)
		{
			ADD_MATH_OP_COUNT
		}

		inline Vector3(const Vector3& vec)
			: x(vec.x)
			, y(vec.y)
			, z(vec.z)
		{
			ADD_MATH_OP_COUNT
		}

		inline Vector3(const Vector3i& vec)
			: x(float(vec.x))
			, y(float(vec.y))
			, z(float(vec.z))
		{
			ADD_MATH_OP_COUNT
		}

		inline Vector3(const std::array<Real, 3>& vec)
			: Vector3(vec[0], vec[1], vec[2])
		{
			ADD_MATH_OP_COUNT
		}

		inline Vector3(const btVector3& vec)
			: Vector3(vec.x(), vec.y(), vec.z())
		{
			ADD_MATH_OP_COUNT
		}

	public:

		inline operator Vector2 ()
		{
			return Vector2(x, y);
		}

		inline operator const Vector2 () const
		{
			return Vector2(x, y);
		}

		inline operator std::array<Real, 3>() const
		{
			return { { x, y, z } };
		}

		inline operator btVector3() const
		{
			return { x, y, z };
		}

		inline Vector3& operator = (const Vector3& rhs)
		{
			x = rhs.x;
			y = rhs.y;
			z = rhs.z;
			ADD_MATH_OP_COUNT
			return *this;
		}

		inline Vector3& operator = (const std::array<Real, 3>& arr)
		{
			x = arr[0];
			y = arr[1];
			z = arr[2];
			ADD_MATH_OP_COUNT
			return *this;
		}

		inline Vector3& operator += (const Vector3& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			ADD_MATH_OP_COUNT
			return *this;
		}

		inline Vector3& operator += (float f)
		{
			x += f;
			y += f;
			z += f;
			ADD_MATH_OP_COUNT
			return *this;
		}

		inline Vector3& operator -= (const Vector3& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			ADD_MATH_OP_COUNT
			return *this;
		}

		inline Vector3& operator -= (float f)
		{
			x -= f;
			y -= f;
			z -= f;
			ADD_MATH_OP_COUNT
			return *this;
		}

		inline Vector3& operator *= (const Real value)
		{
			x *= value;
			y *= value;
			z *= value;
			ADD_MATH_OP_COUNT
			return *this;
		}

		inline Vector3& operator /= (const Real value)
		{
			x /= value;
			y /= value;
			z /= value;
			ADD_MATH_OP_COUNT
			return *this;
		}

		inline const Vector3& operator + () const
		{
			ADD_MATH_OP_COUNT
			return *this;
		}

		inline Vector3 operator - () const
		{
			ADD_MATH_OP_COUNT
			return Vector3(-x, -y, -z);
		}

		inline bool operator == (const Vector3& rhs) const
		{
			ADD_MATH_OP_COUNT
			return (x==rhs.x && y==rhs.y && z==rhs.z);
		}

		inline bool operator != (const Vector3& rhs) const
		{
			ADD_MATH_OP_COUNT
			return (x!=rhs.x || y!=rhs.y || z!=rhs.z);
		}

		inline Vector3 operator + (const Vector3& rhs) const
		{
			ADD_MATH_OP_COUNT
			return Vector3(x+rhs.x, y+rhs.y, z+rhs.z);
		}

		inline Vector3 operator + (float f) const
		{
			ADD_MATH_OP_COUNT
			return Vector3(x + f, y + f, z + f);
		}

		inline Vector3 operator - (const Vector3& rhs) const
		{
			ADD_MATH_OP_COUNT
			return Vector3(x-rhs.x, y-rhs.y, z-rhs.z);
		}

		inline Vector3 operator - (float f) const
		{
			ADD_MATH_OP_COUNT
			return Vector3(x - f, y - f, z - f);
		}

		inline Vector3 operator * (const Vector3& rhs) const
		{
			ADD_MATH_OP_COUNT
			return Vector3(x*rhs.x, y*rhs.y, z*rhs.z);
		}

		inline Vector3 operator * (const Real f) const
		{
			ADD_MATH_OP_COUNT
			return Vector3(x*f, y*f, z*f);
		}

		inline friend Vector3 operator * (const Real f, const Vector3& rkVec)
		{
			ADD_MATH_OP_COUNT
			return Vector3(f*rkVec.x, f*rkVec.y, f*rkVec.z);
		}

		inline Vector3 operator / (const Real f) const
		{
			ADD_MATH_OP_COUNT
			return Vector3(x/f, y/f, z/f);
		}

		inline friend Vector3 operator / (const Real f, const Vector3& rkVec)
		{
			ADD_MATH_OP_COUNT
			return Vector3(f/rkVec.x, f/rkVec.y, f/rkVec.z);
		}

		inline Vector3 operator / (const Vector3& rhs) const
		{
			ADD_MATH_OP_COUNT
			return Vector3(x/rhs.x, y/rhs.y, z/rhs.z);
		}


		inline Real& operator [] (int index)
		{
			ADD_MATH_OP_COUNT
			LordAssertX(index >= 0 && index < 3, "Access out of bounds");
			return m[index];
		}

		inline const Real& operator [] (int index) const
		{
			ADD_MATH_OP_COUNT
			LordAssertX(index >= 0 && index < 3, "Access out of bounds");
			return m[index];
		}

		inline bool operator < (const Vector3& rhs) const
		{
			ADD_MATH_OP_COUNT
			if( x < rhs.x && y < rhs.y && z < rhs.z)
				return true;
			else
				return false;
		}

		inline bool operator <= (const Vector3& rhs) const
		{
			ADD_MATH_OP_COUNT
			if( x <= rhs.x && y <= rhs.y && z <= rhs.z)
				return true;
			else
				return false;
		}

		inline bool operator > (const Vector3& rhs) const
		{
			ADD_MATH_OP_COUNT
			if( x > rhs.x && y > rhs.y && z > rhs.z)
				return true;
			else
				return false;
		}

		inline bool operator >= (const Vector3& rhs) const
		{
			ADD_MATH_OP_COUNT
			if( x >= rhs.x && y >= rhs.y && z >= rhs.z)
				return true;
			else
				return false;
		}

		inline Real* ptr()
		{
			ADD_MATH_OP_COUNT
			return &x;
		}

		inline const Real* ptr() const
		{
			ADD_MATH_OP_COUNT
			return &x;
		}

		inline void zero()
		{
			ADD_MATH_OP_COUNT
			x = 0.0;
			y = 0.0;
			z = 0.0;
		}

		inline void one()
		{
			ADD_MATH_OP_COUNT
			x = 1.0;
			y = 1.0;
			z = 1.0;
		}

		inline void invalid()
		{
			ADD_MATH_OP_COUNT
			*this = INVALID;
		}

		inline void set(Real x, Real y, Real z)
		{
			ADD_MATH_OP_COUNT
			this->x = x;
			this->y = y;
			this->z = z;
		}

		inline void set(Real* p)
		{
			ADD_MATH_OP_COUNT
			this->x = p[0];
			this->y = p[1];
			this->z = p[2];
		}

		inline void setVec2(const Vector2& vec2, Real _z)
		{
			ADD_MATH_OP_COUNT
			x = vec2.x;
			y = vec2.y;
			z = _z;
		}

		inline Real dot(const Vector3& rhs) const
		{
			ADD_MATH_OP_COUNT
			return (x * rhs.x + y * rhs.y + z * rhs.z);
		}

		inline Real absdot(const Vector3& rhs) const
		{
			return Math::Abs(x * rhs.x) + Math::Abs(y * rhs.y) + Math::Abs(z * rhs.z);
		}

		inline Vector3 cross(const Vector3& rhs) const
		{
			Vector3 vec;

			vec.x = y * rhs.z - z * rhs.y;
			vec.y = z * rhs.x - x * rhs.z;
			vec.z = x * rhs.y - y * rhs.x;

			ADD_MATH_OP_COUNT

			return vec;
		}

		inline void inverse()
		{
			x = 1.0f / x;
			y = 1.0f / y;
			z = 1.0f / z;
			ADD_MATH_OP_COUNT
		}

		inline void sqrt()
		{
			x = Math::Sqrt(x);
			y = Math::Sqrt(y);
			z = Math::Sqrt(z);
			ADD_MATH_OP_COUNT
		}

		inline void invSqrt()
		{
			ADD_MATH_OP_COUNT

			x = 1.0f / Math::Sqrt(x);
			y = 1.0f / Math::Sqrt(y);
			z = 1.0f / Math::Sqrt(z);
		}

		inline Real len() const
		{
			ADD_MATH_OP_COUNT

			Real vecLen;

			Real sum = x * x + y * y + z * z;
			vecLen = Math::Sqrt(sum);

			return vecLen;
		}

		inline Real lenSqr() const
		{
			ADD_MATH_OP_COUNT

			return (x * x + y * y + z * z);
		}

		inline Real distanceTo(const Vector3& v) const
		{
			Real dx = x - v.x;
			Real dy = y - v.y;
			Real dz = z - v.z;
			return Math::Sqrt(dx*dx + dy*dy + dz*dz);
		}

		inline Real squareDistanceTo(const Vector3& v) const
		{
			Real dx = x - v.x;
			Real dy = y - v.y;
			Real dz = z - v.z;
			return dx*dx + dy*dy + dz*dz;
		}

		inline void normalize()
		{
			ADD_MATH_OP_COUNT

			Real length = len();
			if ( length > 1e-08 )
			{
				x /= length;
				y /= length;
				z /= length;
			}
		}

		inline Real normalizeLen()
		{
			ADD_MATH_OP_COUNT

			Real length = len();

			x /= length;
			y /= length;
			z /= length;

			return length;
		}

		inline Vector3 normalizedCopy() const
		{
			ADD_MATH_OP_COUNT

			Vector3 ret = *this;
			ret.normalize();
			return ret;
		}

		inline Vector3& abs()
		{
			ADD_MATH_OP_COUNT

			x = Math::Abs(x);
			y = Math::Abs(y);
			z = Math::Abs(z);

			return *this;
		}

		inline Vector3& neg()
		{
			ADD_MATH_OP_COUNT

			x = -x;
			y = -y;
			z = -z;

			return *this;
		}

		inline Vector3& saturate()
		{
			ADD_MATH_OP_COUNT

			if ( x > 1.0 ) x = 1.0;
			if ( y > 1.0 ) y = 1.0;
			if ( z > 1.0 ) z = 1.0;

			if ( x < 0.0 ) x = 0.0;
			if ( y < 0.0 ) y = 0.0;
			if ( z < 0.0 ) z = 0.0;

			return *this;
		}

		inline Vector3& clampZero()
		{
			ADD_MATH_OP_COUNT

			if ( x < 0.0 ) x = 0.0;
			if ( y < 0.0 ) y = 0.0;
			if ( z < 0.0 ) z = 0.0;

			return *this;
		}

		inline Vector3& clampOne()
		{
			ADD_MATH_OP_COUNT

			if ( x > 1.0 ) x = 1.0;
			if ( y > 1.0 ) y = 1.0;
			if ( z > 1.0 ) z = 1.0;

			return *this;
		}

		inline Vector3& floor()
		{
			ADD_MATH_OP_COUNT

			x = Math::Floor(x);
			y = Math::Floor(y);
			z = Math::Floor(z);

			return *this;
		}

		inline Vector3i getFloor() const
		{
			ADD_MATH_OP_COUNT

			Vector3i ret;
			ret.x = int(Math::Floor(x));
			ret.y = int(Math::Floor(y));
			ret.z = int(Math::Floor(z));

			return ret;
		}

		inline Vector3& ceil()
		{
			ADD_MATH_OP_COUNT

			x = Math::Ceil(x);
			y = Math::Ceil(y);
			z = Math::Ceil(z);

			return *this;
		}

		inline Vector3& trunc()
		{
			ADD_MATH_OP_COUNT

			x = std::trunc(x);
			y = std::trunc(y);
			z = std::trunc(z);

			return *this;
		}

		inline Vector3 midPoint(const Vector3& vec) const
		{
			ADD_MATH_OP_COUNT

			return Vector3((x + vec.x) * 0.5f, (y + vec.y) * 0.5f, (z + vec.z) * 0.5f);
		}

		inline void makeFloor(const Vector3& cmp)
		{
			ADD_MATH_OP_COUNT

			if( cmp.x < x ) x = cmp.x;
			if( cmp.y < y ) y = cmp.y;
			if( cmp.z < z ) z = cmp.z;
		}

		inline void makeCeil(const Vector3& cmp)
		{
			ADD_MATH_OP_COUNT

			if( cmp.x > x ) x = cmp.x;
			if( cmp.y > y ) y = cmp.y;
			if( cmp.z > z ) z = cmp.z;
		}

		inline bool isInvalid() const
		{
			ADD_MATH_OP_COUNT

			return Math::IsInvalid(x) || Math::IsInvalid(y) || Math::IsInvalid(z);
		}

		inline bool isFinite() const
		{
			ADD_MATH_OP_COUNT

			return isfinite(x) && isfinite(y) && isfinite(z);
		}

		inline bool isZeroLength() const
		{
			ADD_MATH_OP_COUNT

			Real sqlen = (x * x) + (y * y) + (z * z);
			return (sqlen < (1e-06 * 1e-06));
		}

		inline Vector3 perpendicular() const
		{
			ADD_MATH_OP_COUNT

			Vector3 perp = this->cross(UNIT_X);

			// Check length
			if(perp.lenSqr() == 0.0)
			{
				/* This vector is the Y axis multiplied by a scalar, so we have
				to use another axis.
				*/
				perp = this->cross(UNIT_Y);
			}
			perp.normalize();

			return perp;
		}

		inline void Vec3Sub(const Vector3& a,const Vector3& b)
		//Find Vectors for two edges sharing b
		{
			ADD_MATH_OP_COUNT

			x=a.x-b.x;
			y=a.y-b.y;
			z=a.z-b.z;
		}

		Vector3 getIntermediateWithXValue(const Vector3& v1, float xValue) const
		{
			Vector3 delta = v1 - *this;

			if (delta.x * delta.x < 1e-7)
			{
				return Vector3::INVALID;
			}
			else
			{
				Real ratio = (xValue - x) / delta.x;
				if (ratio >= 0.f && ratio <= 1.f)
					return *this + delta * ratio;
			}
			return Vector3::INVALID;
		}

		Vector3 getIntermediateWithYValue(const Vector3& v1, float yValue) const
		{
			Vector3 delta = v1 - *this;

			if (delta.y * delta.y < 1e-7)
			{
				return Vector3::INVALID;
			}
			else
			{
				Real ratio = (yValue - y) / delta.y;
				if (ratio >= 0.f && ratio <= 1.f)
					return *this + delta * ratio;
			}
			return Vector3::INVALID;
		}
		
		Vector3 getIntermediateWithZValue(const Vector3& v1, float zValue) const
		{
			Vector3 delta = v1 - *this;

			if (delta.z * delta.z < 1e-7)
			{
				return Vector3::INVALID;
			}
			else
			{
				Real ratio = (zValue - z) / delta.z;
				if (ratio >= 0.f && ratio <= 1.f)
					return *this + delta * ratio;
			}
			return Vector3::INVALID;
		}

		void rotateAroundX(float radian)
		{
			Real c = Math::Cos(radian);
			Real s = Math::Sin(radian);
			Real fx = x;
			Real fy = y * c + z * s;
			Real fz = z * c - y * s;
			x = fx;
			y = fy; 
			z = fz;
		}

		void rotateAroundY(float radian)
		{
			Real c = Math::Cos(radian);
			Real s = Math::Sin(radian);
			Real fx = x * c + z * s;
			Real fy = y;
			Real fz = z * c - x * s;
			x = fx;
			y = fy;
			z = fz;
		}

		void rotateAroundZ(float radian)
		{
			Real c = Math::Cos(radian);
			Real s = Math::Sin(radian);
			Real fx = x * c + y * s;
			Real fy = y * c - x * s;
			Real fz = z;
			x = fx;
			y = fy;
			z = fz;
		}

		Quaternion getRotationTo(const Vector3& dest, const Vector3& fallbackAxis = Vector3::ZERO) const;

		static inline Real Dot(const Vector3& a, const Vector3& b)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector3::OP_COUNT;
#endif

			return (a.x * b.x + a.y * b.y + a.z * b.z);
		}

		static inline void Cross(Vector3& outVec, const Vector3& a, const Vector3& b)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector3::OP_COUNT;
#endif

			outVec.x = a.y * b.z - a.z * b.y;
			outVec.y = a.z * b.x - a.x * b.z;
			outVec.z = a.x * b.y - a.y * b.x;
		}

		static inline void Lerp(Vector3& outVec, const Vector3& a, const Vector3& b, const Real t)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector3::OP_COUNT;
#endif

			outVec = a + (b - a) * t;
		}

		static inline void Max(Vector3& outVec, const Vector3& a, const Vector3& b)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector3::OP_COUNT;
#endif

			outVec.x = a.x > b.x ? a.x : b.x;
			outVec.y = a.y > b.y ? a.y : b.y;
			outVec.z = a.z > b.z ? a.z : b.z;
		}

		static inline void Min(Vector3& outVec, const Vector3& a, const Vector3& b)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector3::OP_COUNT;
#endif

			outVec.x = a.x < b.x ? a.x : b.x;
			outVec.y = a.y < b.y ? a.y : b.y;
			outVec.z = a.z < b.z ? a.z : b.z;
		}

		static inline void Inverse(Vector3& outVec, const Vector3& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector3::OP_COUNT;
#endif

			outVec = a;
			outVec.inverse();
		}

		static inline void Sqrt(Vector3& outVec, const Vector3& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector3::OP_COUNT;
#endif

			outVec = a;
			outVec.sqrt();
		}

		static inline void InvSqrt(Vector3& outVec, const Vector3& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector3::OP_COUNT;
#endif
			outVec = a;
			outVec.invSqrt();
		}

		static inline void Normalize(Vector3& outVec, const Vector3& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector3::OP_COUNT;
#endif

			outVec = a;
			outVec.normalize();
		}

		static inline Real NormalizeLen(Vector3& outVec, const Vector3& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector3::OP_COUNT;
#endif

			outVec = a;
			Real vecLen = outVec.normalizeLen();
			return vecLen;
		}

		static inline void Abs(Vector3& outVec, const Vector3& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector3::OP_COUNT;
#endif

			outVec = a;
			outVec.abs();
		}

		static inline void Neg(Vector3& outVec, const Vector3& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector3::OP_COUNT;
#endif

			outVec = a;
			outVec.neg();
		}

		static inline void Saturate(Vector3& outVec, const Vector3& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector3::OP_COUNT;
#endif

			outVec= a;
			outVec.saturate();
		}

		inline Vector3 Reflect(const Vector3& normal) const
		{
			return Vector3(*this - (2 * this->dot(normal) * normal));
		}

		inline Vector3 Project(const Vector3& n) const
		{
			return n * Dot(*this, n) / n.lenSqr();
		}
	};
}

#endif