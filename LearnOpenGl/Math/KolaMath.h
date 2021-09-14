#pragma once

#ifndef __KOLA_MATH_H__
#define __KOLA_MATH_H__


#undef min
#undef max
#undef PI

	namespace Math
	{
#ifdef FAST_MATH
		// 		extern void BuildFastMathTable(ui32 fastTableSinSize, ui32 fastTableTanSize);
		// 		extern void DeleteFastMathTable();
		// 		extern LORD_CORE_API ui32 FAST_TABLE_SIN_SIZE;
		// 		extern LORD_CORE_API ui32 FAST_TABLE_TAN_SIZE;
		// 		extern LORD_CORE_API float INV_SIN_TABLE_SIZE;
		// 		extern LORD_CORE_API float INV_TAN_TABLE_SIZE;
		// 		extern LORD_CORE_API float* ARR_SIN_TABLE;
		// 		extern LORD_CORE_API float* ARR_TAN_TABLE;
		// 		extern LORD_CORE_API bool	FAST_MATH_TABLE_INIT;
		// 		extern LORD_CORE_API float INV_SIN_TABLE_SIZE_RAD_TO_DEGREE;
		// 		extern LORD_CORE_API float INV_TAN_TABLE_SIZE_RAD_TO_DEGREE;
		extern void BuildFastMathTable(ui32 fastTableCosSize);
		extern void DeleteFastMathTable();
		extern LORD_CORE_API ui32 FAST_TABLE_COS_SIZE;
		extern LORD_CORE_API float* ARR_COS_TABLE;
		extern LORD_CORE_API float COS_FACTOR;
		extern LORD_CORE_API bool	FAST_MATH_TABLE_INIT;
#endif
		extern const float PI;					//!< 3.14159265358979323846264338327950288419716939937511
		extern const float PI_2;				//!< Math::PI * 2.0
		extern const float PI_DIV2;			//!< Math::PI / 2.0
		extern const float PI_DIV3;			//!< Math::PI / 3.0
		extern const float PI_DIV4;			//!< Math::PI / 4.0
		extern const float PI_DIV5;			//!< Math::PI / 5.0
		extern const float PI_DIV6;			//!< Math::PI / 6.0
		extern const float PI_DIV8;			//!< Math::PI / 8.0
		extern const float PI_DIV180;			//!< 180 / Math::PI
		extern const float PI_SQR;				//!< 9.86960440108935861883449099987615113531369940724079
		extern const float PI_INV;				//!< 0.31830988618379067153776752674502872406891929148091
		extern const float EPSILON;			//!< FLT: 1.1920929e-007; DBL: 2.2204460492503131e-016
		extern const float LOWEPSILON;			//!< 1e-04
		extern const float POS_INFINITY;		//!< infinity
		extern const float NEG_INFINITY;		//!< -infinity
		extern const float LN2;				//!< Math::log(2.0)
		extern const float LN10;				//!< Math::log(10.0)
		extern const float INV_LN2;			//!< 1.0f/Math::LN2
		extern const float INV_LN10;			//!< 1.0f/Math::LN10
		extern const float DEG2RAD;			//!< 0.01745329
		extern const float RAD2DEG;			//!< 57.29577
		extern const float SMALL_NUMBER;       //!< 1.e-8f
		extern const float KINDA_SMALL_NUMBER;	//!< 1.e-4f
		
		extern const float MIN_REAL;			//!< FLT: 1.175494351e-38F; DBL: 2.2250738585072014e-308 
		extern const float MAX_REAL;			//!< FLT: 3.402823466e+38F; DBL: 1.7976931348623158e+308
		
		extern const float SQUARER3;			//(Real)1.7320508075689;
		extern const float SQUARER2;			//(Real)1.4142135623731;

		extern const float MIN_FLOAT;			//!< 1.175494351e-38F
		extern const float MAX_FLOAT;			//!< 3.402823466e+38F
		extern const double MIN_DOUBLE;		//!< 2.2250738585072014e-308
		extern const double MAX_DOUBLE;		//!< 1.7976931348623158e+308

		extern const Byte MAX_BYTE;			//!< 0xff
		extern const short MIN_SHORT;			//!< -32768
		extern const short MAX_SHORT;			//!< 32767
		extern const int MIN_INT;			//!< -2147483648
		extern const int MAX_INT;			//!< 2147483647
		extern const Word MAX_WORD;			//!< 0xff
		extern const Dword MAX_DWORD;			//!< 0xffff
		extern const i8 MIN_I8;				//!< -128
		extern const i8 MAX_I8;				//!< 127
		extern const ui8 MAX_UI8;				//!< 0xff
		extern const i16 MIN_I16;				//!< -32768
		extern const i16 MAX_I16;				//!< 32767
		extern const ui16 MAX_UI16;			//!< 0xffff
		extern const i32 MIN_I32;				//!< -2147483648
		extern const i32 MAX_I32;				//!< 2147483647
		extern const ui32 MAX_UI32;			//!< 0xffffffff
		extern const i64 MIN_I64;				//!< -9223372036854775808
		extern const i64 MAX_I64;				//!< 9223372036854775807
		extern const ui64 MAX_UI64;			//!< 0xffffffffffffffff


		// for Int Math.
		extern const int	SINCOSTABSZ;
		extern const int	SINCOSTABSZ_LOG2;
		extern thread_local float* g_sintab;

#if LORD_MODE == LORD_MODE_DEBUG
#define ADD_MATH_OP_COUNT ++OP_COUNT;
#else
#define ADD_MATH_OP_COUNT
#endif

		template <typename T>
		inline T Abs(const T& x)
		{
			return x < T(0) ? -x : x;
		}

		template <typename T>
		inline T Sgn(const T& x)
		{
			return x < T(0) ? T(-1) : (x > T(0) ? T(1) : T(0));
		}

		template <typename T>
		inline T Sqr(const T& x)
		{
			return x * x;
		}

		template <typename T>
		inline T Cube(const T& x)
		{
			return sqr(x) * x;
		}

		template <typename T>
		inline T Sqrt(const T& x)
		{
			return std::sqrt(x);
		}

		template <typename T>
		inline T Log(const T& x)
		{
			return std::log(x);
		}

		// «Ûeµƒn¥Œ∑�
		template <typename T>
		inline T Exp(const T& x)
		{
			return std::exp(x);
		}

		template <typename T>
		inline T Pow(const T& base, const T& exponent)
		{
			return std::pow(base, exponent);
		}

		template <typename T>
		inline T Cos(const T& x)
		{
#if FAST_MATH
			if (FAST_MATH_TABLE_INIT)
			{
				//return Sin(x + PI*0.5f);
				float absX = (float)Abs(x);
				float xIn2PI = fmodf(absX, PI_2);
				int idx = 0;
				if (xIn2PI < PI)
				{
					idx = int(xIn2PI * COS_FACTOR);
				}
				else
				{
					idx = int((PI_2 - xIn2PI) * COS_FACTOR);
				}
				return ARR_COS_TABLE[idx];
			}
			else
			{
				return std::cos(x);
			}
#else
			return std::cos(x);
#endif
		}
		
		template <typename T>
		inline T Sin(const T& x)
		{
#if FAST_MATH
			if (FAST_MATH_TABLE_INIT)
			{
				// 				int idx;
				// 				if (x >= 0)
				// 				{
				// 					idx = int(x * INV_SIN_TABLE_SIZE_RAD_TO_DEGREE) % FAST_TABLE_SIN_SIZE;
				// 				}
				// 				else
				// 				{
				// 					idx = FAST_TABLE_SIN_SIZE - (int(-x * INV_SIN_TABLE_SIZE_RAD_TO_DEGREE) % FAST_TABLE_SIN_SIZE) - 1;
				// 				}
				// 
				// 				return ARR_SIN_TABLE[idx];

				return Cos(PI_DIV2 - x);
			}
			else
			{
				return std::sin(x);
			}
#else
			return std::sin(x);
#endif
		}
		inline float	Sin_tab(float x) { return g_sintab[(int)(x * 10430.378f) & 65535]; }
		inline float	Cos_tab(float x) { return g_sintab[(int)(x * 10430.378f + 16384.0f) & 65535]; }

		template <typename T>
		inline T Tan(const T& x)
		{
#if FAST_MATH
			if (FAST_MATH_TABLE_INIT)
			{
				//int idx = int(x * INV_TAN_TABLE_SIZE_RAD_TO_DEGREE) % FAST_TABLE_TAN_SIZE;
				//return ARR_TAN_TABLE[idx];
				return Sin(x) / Cos(x);
			}
			else
			{
				return std::tan(x);
			}
#else
			return std::tan(x);
#endif
		}

		template <typename T>
		inline T Sinh(const T& x)
		{
			return std::sinh(x);
		}

		template <typename T>
		inline T Cosh(const T& x)
		{
			return std::cosh(x);
		}

		template <typename T>
		inline T Tanh(const T& x)
		{
			return std::tanh(x);
		}

		template <typename T>
		inline T ASin(const T& x)
		{
			if (-(T)1.0 < x)
			{
				if (x < (T)1.0)
					return (T)::asin(x);
				else
					return PI_DIV2;
			}
			else
				return -PI_DIV2;
		}

		template <typename T>
		inline T ACos(const T& x)
		{
			if (-(T)1.0 < x)
			{
				if (x < (T)1.0)
					return std::acos(x);
				else
					return (T)0.0;
			}
			else
				return PI;
		}

		// [0, 2*PI]
		template <typename T>
		inline T ATan(const T& x)
		{
			return std::atan(x);
		}

		// [-PI, PI]
		template <typename T>
		inline T ATan2(const T& y, const T& x)
		{
			return std::atan2(y, x);
		}

		template <typename T>
		inline void Swap(T& x, T& y)
		{
			T temp;
			temp = x;
			x = y;
			y = temp;
		}

		inline bool IsInvalid(float f)
		{
			// std::isnan() is C99, not supported by all compilers
			// However NaN always fails this next test, no other number does.
			return f == MAX_REAL;
		}

		template <typename T>
		inline T Rad(const T& x)
		{
			return static_cast<T>(x * DEG2RAD);
		}
		template <typename T>
		inline T Deg(const T& x)
		{
			return static_cast<T>(x * RAD2DEG);
		}

		template <typename T>
		inline T Floor(const T& x)
		{
			return std::floor(x);
		}

		template <typename T>
		inline T Ceil(const T& x)
		{
			return std::ceil(x);
		}

		template <typename T>
		inline T Frac(const T& x)
		{
			return x - static_cast<int>(x);
		}

		template <typename T>
		inline T Round(const T& x)
		{
			return (x > 0) ? static_cast<T>(static_cast<int>(T(0.5) + x)) :
				-static_cast<T>(static_cast<int>(T(0.5) - x));
		}

		template <typename T>
		inline T Trunc(const T& x)
		{
			return static_cast<T>(static_cast<int>(x));
		}

		template <typename T>
		inline T Mod(const T& x, const T& y)
		{
			return x % y;
		}

		template<>
		inline float Mod<float>(const float& x, const float& y)
		{
			return std::fmod(x, y);
		}

		template <>
		inline double Mod<double>(const double& x, const double& y)
		{
			return std::fmod(x, y);
		}

		template<typename T>
		inline T PositiveMod(const T x, const T y)
		{
			auto ret = Mod(x, y);
			if (ret < 0)
			{
				ret += y;
			}
			return ret;
		}

		template <typename T>
		inline T const & Clamp(const T& val, const T& low, const T& high)
		{
			return std::max<T>(low, std::min<T>(high, val));
		}

		template <typename T>
		inline T Wrap(const T& val, const T& low, const T& high)
		{
			T ret(val);
			T rang(high - low);

			while (ret >= high)
			{
				ret -= rang;
			}
			while (ret < low)
			{
				ret += rang;
			}

			return ret;
		}

		inline Real WrapDegree(float degree)
		{
			degree = Mod(degree, 360.f);

			if (degree >= 180.0f)
				degree -= 360.0f;

			if (degree < -180.0f)
				degree += 360.0f;

			return degree;
		}

		inline double FastInvSqrt(double f)
		{
			double f1 = 0.5 * f;
			i64 i = *(i64*)(&f);
			i = 6910469410427058090LL - (i >> 1);
			f = *(double*)(&i);
			f = f * (1.5 - f1 * f * f);
			return f;
		}

		template <typename T>
		inline T Mirror(const T& val, const T& low, const T& high)
		{
			T ret(val);
			T rang(high - low);

			while ((ret > high) || (ret < low))
			{
				if (ret > high)
				{
					ret = 2 * high - val;
				}
				else
				{
					if (ret < low)
					{
						ret = 2 * low - val;
					}
				}
			}

			return ret;
		}

		template <typename T>
		inline bool IsOdd(T const & x)
		{
			return Mod(x, 2) != 0;
		}

		template <typename T>
		inline bool IsEven(T const & x)
		{
			return !IsOdd(x);
		}

		template <typename T>
		inline bool IsInBound(T const & val, T const & low, T const & high)
		{
			return ((val >= low) && (val <= high));
		}

		template <typename T>
		inline const T& Min(const T& a, const T& b)
		{
			return (std::min)(a, b);
		}

		template <typename T>
		inline const T& Max(const T& a, const T& b)
		{
			return (std::max)(a, b);
		}

		template <typename T>
		inline const T& RangeLimit(const T& d, const T& _min, const T& _max)
		{
			return ((d) < (_min) ? (_min) : ((d) > (_max) ? (_max) : (d)));
		}

		template <typename T>
		inline const T& Min3(const T& a, const T& b, const T& c)
		{
			return (std::min)((std::min)(a, b), c);
		}

		template <typename T>
		inline const T& Max3(const T& a, const T& b, const T& c)
		{
			return (std::max)((std::max)(a, b), c);
		}

		template <typename T>
		inline bool IsEqual(const T& lhs, const T& rhs)
		{
			return (lhs == rhs);
		}

		template <>
		inline bool IsEqual<float>(const float& lhs, const float& rhs)
		{
			return std::abs(lhs - rhs) <= LOWEPSILON * std::max({ 1.0f, std::abs(lhs), std::abs(rhs) });
		}
		template <>
		inline bool IsEqual<double>(const double& lhs, const double& rhs)
		{
			return Abs(lhs - rhs) <= LOWEPSILON * std::max({ 1.0, std::abs(lhs), std::abs(rhs) });
		}

		template<typename T>
		inline bool FarLessThan(const T& lhs, const T& rhs)
		{
			return lhs < rhs;
		}

		template <>
		inline bool FarLessThan<float>(const float& lhs, const float& rhs)
		{
			return rhs - lhs > LOWEPSILON * std::max({ 1.0f, std::abs(lhs), std::abs(rhs) });
		}
		template <>
		inline bool FarLessThan<double>(const double& lhs, const double& rhs)
		{
			return rhs - lhs > LOWEPSILON * std::max({ 1.0, std::abs(lhs), std::abs(rhs) });
		}

		template<typename T>
		inline bool FarGreaterThan(const T& lhs, const T& rhs)
		{
			return lhs < rhs;
		}

		template <>
		inline bool FarGreaterThan<float>(const float& lhs, const float& rhs)
		{
			return lhs - rhs > LOWEPSILON * std::max({ 1.0f, std::abs(lhs), std::abs(rhs) });
		}
		template <>
		inline bool FarGreaterThan<double>(const double& lhs, const double& rhs)
		{
			return lhs - rhs > LOWEPSILON * std::max({ 1.0, std::abs(lhs), std::abs(rhs) });
		}

		LORD_CORE_API Real UnitRandom(unsigned int uiSeed = 0);

		// [-1,1)
		LORD_CORE_API Real SymmetricRandom(unsigned int uiSeed = 0);

		// [min,max)
		LORD_CORE_API Real IntervalRandom(Real fMin, Real fMax, unsigned int uiSeed = 0);

		// [min,max)
		LORD_CORE_API Real IntervalRandom(int fMin, int fMax, unsigned int uiSeed = 0);

		// Write a n*8 bits integer value to memory in native endian.
		inline void IntWrite(void* pDest, int n, uint value)
		{
			switch (n)
			{
			case 1:
				((ui8*)pDest)[0] = (ui8)value;
				break;
			case 2:
				((ui16*)pDest)[0] = (ui16)value;
				break;
			case 3:
#if LORD_ENDIAN_BIG    
				((ui8*)pDest)[0] = (ui8)((value >> 16) & 0xFF);
				((ui8*)pDest)[1] = (ui8)((value >> 8) & 0xFF);
				((ui8*)pDest)[2] = (ui8)(value & 0xFF);
#else
				((ui8*)pDest)[2] = (ui8)((value >> 16) & 0xFF);
				((ui8*)pDest)[1] = (ui8)((value >> 8) & 0xFF);
				((ui8*)pDest)[0] = (ui8)(value & 0xFF);
#endif
				break;
			case 4:
				((ui32*)pDest)[0] = (ui32)value;
				break;
			}
		}

		//Read a n*8 bits integer value to memory in native endian.
		inline uint IntRead(const void* src, int n)
		{
			switch (n)
			{
			case 1:
				return ((ui8*)src)[0];
			case 2:
				return ((ui16*)src)[0];
			case 3:
#ifdef LORD_ENDIAN_BIG      
				return ((ui32)((ui8*)src)[0] << 16) | ((ui32)((ui8*)src)[1] << 8) | ((ui32)((ui8*)src)[2]);
#else
				return ((ui32)((ui8*)src)[0])| ((ui32)((ui8*)src)[1]<<8)| ((ui32)((ui8*)src)[2]<<16);
#endif
			case 4:
				return ((ui32*)src)[0];
			}
			return 0; // ?
		}

		/**
		* Convert floating point color channel value between 0.0 and 1.0 (otherwise clamped)
		* to integer of a certain number of bits. Works for any value of bits between 0 and 31.
		*/
		inline uint FloatToFixed(float value, uint bits)
		{
			if (value <= 0.0f)
				return 0;
			else if (value >= 1.0f)
				return (1 << bits) - 1;
			else
				return (uint)(value * (1 << bits));
		}

		// Fixed point to float
		inline float FixedToFloat(uint value, uint bits)
		{
			return (float)value / (float)((1 << bits) - 1);
		}

		// Floor division
		inline int FloorDivide(int x, int y)
		{
			return (x < 0) ^ (y < 0) ? -((-x - 1) / y) - 1 : x / y;
		}

		// Converts float in uint32 format to a a half in uint16 format
		inline ui16 FloatToHalfI(ui32 i)
		{
			int s = (i >> 16) & 0x00008000;
			int e = ((i >> 23) & 0x000000ff) - (127 - 15);
			int m = i & 0x007fffff;

			if (e <= 0)
			{
				if (e < -10)
				{
					return 0;
				}
				m = (m | 0x00800000) >> (1 - e);

				return static_cast<ui16>(s | (m >> 13));
			}
			else if (e == 0xff - (127 - 15))
			{
				if (m == 0) // Inf
				{
					return static_cast<ui16>(s | 0x7c00);
				}
				else    // NAN
				{
					m >>= 13;
					return static_cast<ui16>(s | 0x7c00 | m | (m == 0));
				}
			}
			else
			{
				if (e > 30) // Overflow
				{
					return static_cast<ui16>(s | 0x7c00);
				}

				return static_cast<ui16>(s | (e << 10) | (m >> 13));
			}
		}

		// Convert a float32 to a float16 (NV_half_float)
		inline ui16 FloatToHalf(float i)
		{
			union { float f; ui32 i; } v;
			v.f = i;
			return FloatToHalfI(v.i);
		}

		//Converts a half in uint16 format to a float in uint32 format
		inline ui32 HalfToFloatI(ui16 y)
		{
			int s = (y >> 15) & 0x00000001;
			int e = (y >> 10) & 0x0000001f;
			int m = y & 0x000003ff;

			if (e == 0)
			{
				if (m == 0) // Plus or minus zero
				{
					return s << 31;
				}
				else // unnormalized number -- renormalized it
				{
					while (!(m & 0x00000400))
					{
						m <<= 1;
						e -= 1;
					}

					e += 1;
					m &= ~0x00000400;
				}
			}
			else if (e == 31)
			{
				if (m == 0) // Inf
				{
					return (s << 31) | 0x7f800000;
				}
				else // NaN
				{
					return (s << 31) | 0x7f800000 | (m << 13);
				}
			}

			e = e + (127 - 15);
			m = m << 13;

			return (s << 31) | (e << 23) | m;
		}

		// Convert a float16 (NV_half_float) to a float32
		inline float HalfToFloat(ui16 y)
		{
			union { float f; ui32 i; } v;
			v.i = HalfToFloatI(y);
			return v.f;
		}

		// yet another half <-> float convert,  https://stackoverflow.com/questions/1659440/32-bit-to-16-bit-floating-point-conversion
		inline ui32 as_uint(const float x) {
			return *(ui32*)&x;
		}
		inline float as_float(const ui32 x) {
			return *(float*)&x;
		}
		inline half FloatToFloat16(const float x) { // IEEE-754 16-bit floating-point format (without infinity): 1-5-10, exp-15, +-131008.0, +-6.1035156E-5, +-5.9604645E-8, 3.311 digits
			const ui32 b = as_uint(x) + 0x00001000; // round-to-nearest-even: add last bit after truncated mantissa
			const ui32 e = (b & 0x7F800000) >> 23; // exponent
			const ui32 m = b & 0x007FFFFF; // mantissa; in line below: 0x007FF000 = 0x00800000-0x00001000 = decimal indicator flag - initial rounding
			return (b & 0x80000000) >> 16 | (e > 112) * ((((e - 112) << 10) & 0x7C00) | m >> 13) | ((e < 113) & (e > 101)) * ((((0x007FF000 + m) >> (125 - e)) + 1) >> 1) | (e > 143) * 0x7FFF; // sign : normalized : denormalized : saturate
		}
		inline float Float16ToFloat(const half x) { // IEEE-754 16-bit floating-point format (without infinity): 1-5-10, exp-15, +-131008.0, +-6.1035156E-5, +-5.9604645E-8, 3.311 digits
			const ui32 e = (x & 0x7C00) >> 10; // exponent
			const ui32 m = (x & 0x03FF) << 13; // mantissa
			const ui32 v = as_uint((float)m) >> 23; // evil log2 bit hack to count leading zeros in denormalized format
			return as_float((x & 0x8000) << 16 | (e != 0) * ((e + 112) << 23 | m) | ((e == 0) & (m != 0)) * ((v - 37) << 23 | ((m << (150 - v)) & 0x007FE000))); // sign : normalized : denormalized
		}

		// Determines wheter the number is power-of-two or not
		template <typename T>
		inline bool IsPO2(const T &num)
		{
			return (num & (num - 1)) == 0;
		}

		/** Return true if value is finite (not NaN and not Infinity). */
		static FORCEINLINE bool IsFinite(float A)
		{
			return ((*(ui32*)&A) & 0x7F800000) != 0x7F800000;
		}

		// if 2 float is approximately equal
		static FORCEINLINE bool FloatEqual(float A, float B, float epsilon = 0.00001f)
		{
			if (A == B)
				return true;
			const float diff = fabs(A - B);
			if (diff < epsilon)
				return true;
			return diff <= epsilon * std::min<float>(fabs(A), fabs(B));
		}

		// Return the closest power-of-two number greater or equal to value
		inline uint NearsetPO2(uint num)
		{
			--num;
			num |= num >> 16;
			num |= num >> 8;
			num |= num >> 4;
			num |= num >> 2;
			num |= num >> 1;
			++num;

			return num;
		}

		void LORD_CORE_API TBNComputeNormal(Vector3* normals, const Vector3* positions, int numVertex, const Word* tris, int numTris);

		void LORD_CORE_API TBNComputeTangentBinormal(Vector3* tangents, Vector3* binormals, const Vector3* positions, const Vector2* uvs, const Vector3* normals, int numVertex, const Word* tris, int numTris);

		/**
		*	Checks if a floating point number is nearly zero.
		*	@param Value			Number to compare
		*	@param ErrorTolerance	Maximum allowed difference for considering Value as 'nearly zero'
		*	@return					true if Value is nearly zero
		*/
		static FORCEINLINE bool IsNearlyZero(float Value, float ErrorTolerance = SMALL_NUMBER)
		{
			return Abs<float>(Value) < ErrorTolerance;
		}

		/**
		*	Checks if a floating point number is nearly zero.
		*	@param Value			Number to compare
		*	@param ErrorTolerance	Maximum allowed difference for considering Value as 'nearly zero'
		*	@return					true if Value is nearly zero
		*/
		static FORCEINLINE bool IsNearlyZero(double Value, double ErrorTolerance = SMALL_NUMBER)
		{
			return Abs<double>(Value) < ErrorTolerance;
		}

		/**
		* Performs a cubic interpolation
		*
		* @param  P - end points
		* @param  T - tangent directions at end points
		* @param  Alpha - distance along spline
		*
		* @return  Interpolated value
		*/
		template< class T, class U >
		static FORCEINLINE T CubicInterp(const T& P0, const T& T0, const T& P1, const T& T1, const U& A)
		{
			const float A2 = A  * A;
			const float A3 = A2 * A;

			return (T)(((2 * A3) - (3 * A2) + 1) * P0) + ((A3 - (2 * A2) + A) * T0) + ((A3 - A2) * T1) + (((-2 * A3) + (3 * A2)) * P1);
		}

		/** Performs a linear interpolation between two values, Alpha ranges from 0-1 */
		template< class T, class U >
		static FORCEINLINE T Lerp(const T& A, const T& B, const U& Alpha)
		{
			return (T)(A + Alpha * (B - A));
		}

		static FORCEINLINE float ClampDegree(float degree)
		{
			degree = Math::Mod<float>(degree, 360.0f);

			while (degree > 360)
			{
				degree -= 360;
			}

			while (degree < 0)
			{
				degree += 360;
			}

			return degree;
		}

		extern void		InitMathLib();
		extern void		ReleaseMathLib();
	}

#endif