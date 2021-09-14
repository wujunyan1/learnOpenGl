/********************************************************************
filename: 	Vector2.h
file path:	dev\engine\Src\Core\Math\

version:	1
author:		ajohn
company:	supernano
*********************************************************************/

#ifndef __LORD_VEC2_H__
#define __LORD_VEC2_H__


namespace LORD
{
	class Vector2
	{
	public:

		union
		{
			struct 
			{
				float x, y;
			};

			float m[2];
		};

		static const Vector2 ZERO;				//!< Vec2(0, 0)
		static const Vector2 ONE;				//!< Vec2(1, 1)
		static const Vector2 UNIT_X;			//!< Vec2(1, 0)
		static const Vector2 UNIT_Y;			//!< Vec2(0, 1)
		static const Vector2 NEG_UNIT_X;		//!< Vec2(-1, 0)
		static const Vector2 NEG_UNIT_Y;		//!< Vec2(0, -1)
		static const Vector2 INVALID;			//!< Vec2(Math::MAX_REAL, Math::MAX_REAL)

	public:
		inline Vector2()
		{
			// do nothing
		}

		inline Vector2(const float _x, const float _y)
			: x(_x)
			, y(_y)
		{
			
		}

		inline Vector2(const Vector2 &vec)
			: x(vec.x)
			, y(vec.y)
		{
		}

		inline Vector2& operator= (const Vector2& rhs)
		{
			x = rhs.x;
			y = rhs.y;
			return *this;
		}

		inline float* ptr()
		{
			return &x;
		}

		inline const float* ptr() const
		{
			return &x;
		}

		inline const Vector2 operator+ ()
		{
			return *this;
		}

		inline Vector2 operator- () const
		{
			return Vector2(-x, -y);
		}

		inline bool operator == (const Vector2& rhs) const
		{
			return (x==rhs.x && y==rhs.y);
		}

		inline bool operator != (const Vector2& rhs) const
		{
			return (x!=rhs.x || y!=rhs.y);
		}

		inline Vector2 operator + (const Vector2& rhs) const
		{
			return Vector2(x+rhs.x, y+rhs.y);
		}

		inline Vector2 operator - (const Vector2& rhs) const
		{
			return Vector2(x-rhs.x, y-rhs.y);
		}

		inline Vector2 operator * (const Vector2& rhs) const
		{
			return Vector2(x*rhs.x, y*rhs.y);
		}

		inline Vector2 operator * (const float f) const
		{
			return Vector2(x*f, y*f);
		}

		inline friend Vector2 operator * (const float f, const Vector2& rkVec)
		{
			return Vector2(f*rkVec.x, f*rkVec.y);
		}

		inline Vector2 operator / (const float f) const
		{
			return Vector2(x/f, y/f);
		}

		inline Vector2 operator / (const Vector2& rhs) const
		{
			return Vector2(x/rhs.x, y/rhs.y);
		}

		inline friend Vector2 operator / (const float f, const Vector2& rkVec)
		{
			return Vector2(f/rkVec.x, f/rkVec.y);
		}

		inline Vector2& operator+= (const Vector2& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		inline Vector2& operator-= (const Vector2& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		inline Vector2& operator*= (const float value)
		{
			x *= value;
			y *= value;
			return *this;
		}

		inline Vector2& operator/= (const float value)
		{
			x /= value;
			y /= value;
			return *this;
		}

		inline float& operator[] (int index)
		{
			return m[index];
		}

		inline const float& operator[] (int index) const
		{
			return m[index];
		}

		inline bool operator< (const Vector2& rhs) const
		{
			return (x<rhs.x && y<rhs.y);
		}

		inline bool operator<=(const Vector2& rhs) const
		{
			return (x<=rhs.x && y<=rhs.y);
		}

		inline bool operator> (const Vector2& rhs) const
		{
			return (x>rhs.x && y>rhs.y);
		}

		inline bool operator >= (const Vector2& rhs) const
		{
			return (x>=rhs.x && y>=rhs.y);
		}

		inline void zero()
		{
			x = 0.0;
			y = 0.0;
		}

		inline void one()
		{
			x = 1.0;
			y = 1.0;
		}

		inline void invalid()
		{
			*this = INVALID;
		}

		inline void set(float _x, float _y)
		{
			x = _x;
			y = _y;
		}

		inline void set(float *p)
		{
			this->x = p[0];
			this->y = p[1];
		}

		inline float dot(const Vector2& rhs) const
		{
			return (x * rhs.x + y * rhs.y);
		}

		inline float cross(const Vector2& rhs) const
		{
			return (x * rhs.y - y * rhs.x);
		}

		inline void inverse()
		{
			x = 1.0f / x;
			y = 1.0f / y;
		}

		inline void sqrt()
		{
			x = Math::Sqrt(x);
			y = Math::Sqrt(y);
		}

		inline void invSqrt()
		{
			x = 1.0f / Math::Sqrt(x);
			y = 1.0f / Math::Sqrt(y);
		}

		inline float len() const
		{
			float vecLen;

			float sum = x*x + y*y;
			vecLen = Math::Sqrt(sum);

			return vecLen;
		}

		inline Real lenSqr() const
		{
			ADD_MATH_OP_COUNT
			Real vecLen = x * x + y * y;
			return vecLen;
		}

		inline Real distance(const Vector2& rhs) const
		{
			ADD_MATH_OP_COUNT
			return (*this - rhs).len();
		}

		inline void normalize()
		{
			ADD_MATH_OP_COUNT
			Real length = len();
			x /= length;
			y /= length;
		}

		inline Real normalizeLen()
		{
			ADD_MATH_OP_COUNT
			Real length = len();
			x /= length;
			y /= length;
			return length;
		}

		inline Vector2& abs()
		{
			ADD_MATH_OP_COUNT
			x = Math::Abs(x);
			y = Math::Abs(y);
			return *this;
		}

		inline Vector2& neg()
		{
			ADD_MATH_OP_COUNT
			x = -x;
			y = -y;
			return *this;
		}

		inline Vector2& saturate()
		{
			ADD_MATH_OP_COUNT
			if ( x > 1.0 ) x = 1.0;
			if ( y > 1.0 ) y = 1.0;

			if ( x < 0.0 ) x = 0.0;
			if ( y < 0.0 ) y = 0.0;
			return *this;
		}

		inline Vector2& frac()
		{
			ADD_MATH_OP_COUNT
			x = fabs(x - (int)x);
			y = fabs(y - (int)y);
			return *this;
		}

		inline Vector2& clampZero()
		{
			ADD_MATH_OP_COUNT
			if ( x < 0.0 ) x = 0.0;
			if ( y < 0.0 ) y = 0.0;
			return *this;
		}

		inline Vector2& clampOne()
		{
			ADD_MATH_OP_COUNT
			if ( x > 1.0 ) x = 1.0;
			if ( y > 1.0 ) y = 1.0;
			return *this;
		}

		inline Vector2& floor()
		{
			ADD_MATH_OP_COUNT
			x = Math::Floor(x);
			y = Math::Floor(y);
			return *this;
		}

		inline Vector2& ceil()
		{
			ADD_MATH_OP_COUNT
			x = Math::Ceil(x);
			y = Math::Ceil(y);
			return *this;
		}

		inline Vector2 midPoint(const Vector2& vec) const
		{
			ADD_MATH_OP_COUNT
			return Vector2((x + vec.x) * 0.5f, (y + vec.y) * 0.5f);
		}
		
		inline void makeFloor(const Vector2& cmp)
		{
			ADD_MATH_OP_COUNT
			if( cmp.x < x ) x = cmp.x;
			if( cmp.y < y ) y = cmp.y;
		}

		inline void makeCeil(const Vector2& cmp)
		{
			ADD_MATH_OP_COUNT
			if( cmp.x > x ) x = cmp.x;
			if( cmp.y > y ) y = cmp.y;
		}
		
		inline bool isInvalid() const
		{
			ADD_MATH_OP_COUNT
			return Math::IsInvalid(x) || Math::IsInvalid(y);
		}

	public:

		static inline Real Dot(const Vector2& a, const Vector2& b)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector2::OP_COUNT;
#endif
			return a.x * b.x + a.y * b.y;
		}

		static inline Real Cross(const Vector2& a, const Vector2& b)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector2::OP_COUNT;
#endif
			return a.x * b.y - a.y * b.x;
		}

		static inline void Lerp(Vector2& outVec, const Vector2& a, const Vector2& b, const Real t)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector2::OP_COUNT;
#endif
			outVec = a + (b - a) * t;
		}

		static inline void Max(Vector2& outVec, const Vector2& a, const Vector2& b)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector2::OP_COUNT;
#endif
			outVec.x = a.x > b.x ? a.x : b.x;
			outVec.y = a.y > b.y ? a.y : b.y;
		}

		static inline void Min(Vector2& outVec, const Vector2& a, const Vector2& b)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector2::OP_COUNT;
#endif
			outVec.x = a.x < b.x ? a.x : b.x;
			outVec.y = a.y < b.y ? a.y : b.y;
		}

		static inline void Inverse(Vector2& outVec, const Vector2& a)
		{ 
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector2::OP_COUNT;
#endif
			outVec = a;
			outVec.inverse();
		}

		static inline void Sqrt(Vector2& outVec, const Vector2& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector2::OP_COUNT;
#endif
			outVec = a;
			outVec.sqrt();
		}

		static inline void InvSqrt(Vector2& outVec, const Vector2& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector2::OP_COUNT;
#endif
			outVec = a;
			outVec.invSqrt();
		}

		static inline void Normalize(Vector2& outVec, const Vector2& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector2::OP_COUNT;
#endif
			outVec = a;
			outVec.normalize();
		}

		static inline Real NormalizeLen(Vector2& outVec, const Vector2& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector2::OP_COUNT;
#endif
			outVec = a;
			Real vectorlength = outVec.normalizeLen();
			return vectorlength;
		}

		static inline void Abs(Vector2& outVec, const Vector2& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector2::OP_COUNT;
#endif
			outVec = a;
			outVec.abs();
		}

		static inline void Neg(Vector2& outVec, const Vector2& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector2::OP_COUNT;
#endif
			outVec = a;
			outVec.neg();
		}

		static inline void Saturate(Vector2& outVec, const Vector2& a)
		{
#if LORD_MODE == LORD_MODE_DEBUG
			++Vector2::OP_COUNT;
#endif
			outVec = a;
			outVec.saturate();
		}

	};
}


#endif
