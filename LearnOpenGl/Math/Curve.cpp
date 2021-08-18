#include "Core.h"
#include "Math/Curve.h"

namespace LORD
{
	//---------------------------------------------------------------
	// ��Ҫ�ο���<<DirectX ʵʱ��Ⱦ�������>> ��21�½� ��������Ƭ
	// 
	// ˵����
	//	��һ����Ƶ�������������(�˴�����ֻ�����ĸ����Ƶ��ʵ��)
	// out ���ص�
	// v1,v2,v3,v4 ���Ƶ�
	// amount      ������
	Vector3 Bezier3( Vector3& out, const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4, float amount)
	{
		// amount
		float  s  = amount;
		float _s = 1.f - amount;

		out = v1 *   _s * _s * _s +
			  v2 *  3.f *  s * _s * _s +
			  v3 *  3.f *  s *  s * _s +
			  v4 *    s *  s *  s;

		return out;
	}

	// ˵����
	//     Catmull-Rom��������ʹ�ռ��еĵ����б��ƽ��,��������һ��
	// �ܹ�����ԭʼ·�������п��Ƶ������(����Bezier����,��Ȼ�Ƚ�ƽ
	// �����ǲ��ܾ������еĿ��Ƶ�)��
	Vector3 CatmullRom3( Vector3& out, const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4, float amount)
	{
		// amount
		float u3 = amount * amount * amount;
		float u2 = amount * amount;
		float u1 = amount;

		out = v1 * ( -0.5f * u3 +         u2 - 0.5f * u1) +
			v2 * (  1.5f * u3 + -2.5f * u2 + 1.f)		  +
			v3 * ( -1.5f * u3 +   2.f * u2 + 0.5f * u1) +
			v4 * (  0.5f * u3 -  0.5f * u2);

		return out;
	}
	
	//
	bool LORD_CORE_API BezierEx(const vector<Vector2>& oriVertices, vector<Vector2>& out, float multiple/* = 2.f*/)
	{
		LordAssert(multiple > 0.f);
		if (oriVertices.size() < 2)
			return false;

		vector<Vector2> p = oriVertices;
		int n = oriVertices.size() - 1;

		int newCnt = int(n * multiple);
		float step = 1.0f / newCnt;

		out.clear();
		out.reserve(newCnt);

		for (float u = 0; u <= 1; u += step)
		{
			for (int i = 0; i <= n; i++)
				p[i] = oriVertices[i];

			for (int r = 1; r <= n; r++)
			{
				for (int i = 0; i <= n - r; i++)
				{
					p[i].x = (1 - u)*p[i].x + u * p[i + 1].x;
					p[i].y = (1 - u)*p[i].y + u * p[i + 1].y;
				}
			}
			out.push_back(p[0]);
		}
		return true;
	}

	bool LORD_CORE_API BezierEx(const vector<Vector3>& oriVertices, vector<Vector3>& out, float multiple/* = 2.f*/)
	{
		LordAssert(multiple > 0.f);
		if (oriVertices.size() < 2)
			return false;

		vector<Vector3> p = oriVertices;
		int n = oriVertices.size() - 1;

		int newCnt = int(n * multiple);
		float step = 1.0f / newCnt;

		out.clear();
		out.reserve(newCnt);

		for (float u = 0; u <= 1; u += step)
		{
			p = oriVertices;

			for (int r = 1; r <= n; r++)
			{
				for (int i = 0; i <= n - r; i++)
				{
					p[i].x = (1 - u)*p[i].x + u * p[i + 1].x;
					p[i].y = (1 - u)*p[i].y + u * p[i + 1].y;
					p[i].z = (1 - u)*p[i].z + u * p[i + 1].z;
				}
			}
			out.push_back(p[0]);
		}
		return true;
	}

	bool LORD_CORE_API BezierEx(const vector<Vector4>& oriVertices, vector<Vector4>& out, float multiple/* = 2.f*/)
	{
		LordAssert(multiple > 0.f);
		if (oriVertices.size() < 2)
			return false;

		vector<Vector4> p = oriVertices;
		int n = oriVertices.size() - 1;

		int newCnt = int(n * multiple);
		float step = 1.0f / newCnt;

		out.clear();
		out.reserve(newCnt);

		for (float u = 0; u <= 1; u += step)
		{
			p = oriVertices;

			for (int r = 1; r <= n; r++)
			{
				for (int i = 0; i <= n - r; i++)
				{
					p[i].x = (1 - u)*p[i].x + u * p[i + 1].x;
					p[i].y = (1 - u)*p[i].y + u * p[i + 1].y;
					p[i].z = (1 - u)*p[i].z + u * p[i + 1].z;
					p[i].w = (1 - u)*p[i].w + u * p[i + 1].w;
				}
			}
			out.push_back(p[0]);
		}
		return true;
	}
}