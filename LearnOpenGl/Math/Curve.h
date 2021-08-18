/********************************************************************
filename: 	Curve.h
file path:	dev\engine\Src\Core\Math\

version:	1
author:		ajohn
company:	supernano
*********************************************************************/
#ifndef __LORD_CURVE_H__
#define __LORD_CURVE_H__

#include "Vector3.h"

namespace LORD
{
	//---------------------------------------------------------------
	// ��Ҫ�ο���<<DirectX ʵʱ��Ⱦ�������>> ��21�½� ��������Ƭ
	//			 ����˹̹����ʽ ( Bernstein polynomials)
	// 
	// ˵����
	//	��һ����Ƶ�������������(�˴�����ֻ�����ĸ����Ƶ��ʵ��)
	// out ���ص�
	// v1,v2,v3,v4 ���Ƶ�
	// amount      ������
	Vector3 LORD_CORE_API Bezier3( Vector3& out, const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4, float amount);

	//---------------------------------------------------------------
	// ��Ҫ�ο���<<game programming gems 1>> 3.4-A*�����Ż�
	// 
	// ˵����
	//     Catmull-Rom��������ʹ�ռ��еĵ����б��ƽ��,��������һ��
	// �ܹ�����ԭʼ·�������п��Ƶ������(����Bezier����,��Ȼ�Ƚ�ƽ
	// �����ǲ��ܾ������еĿ��Ƶ�)��
	//	   Catmull-Rom��ʽҪ��4�������,Ȼ�����һ��λ�ڵ�2��͵�3��
	// ֮��Ĺ⻬���ߡ�
	//     Ϊ�˵õ���1�������͵ڶ��������֮��ĵ�,�����Ϊ�������
	// �����1��������,���������2��͵�3�㡣Ϊ�˻�õ�3��͵�4��֮��
	// �ĵ�,������Ϊ���������2��͵�3�㣬Ȼ�������4�����Ρ�
	// out ���ص�
	// v1,v2,v3,v4 ���Ƶ�
	// amount      ������
	Vector3 LORD_CORE_API CatmullRom3( Vector3& out, const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4, float amount);

	//����������
	bool LORD_CORE_API BezierEx(const vector<Vector2>& oriVertices, vector<Vector2>& out, float multiple = 2.f);
	bool LORD_CORE_API BezierEx(const vector<Vector3>& oriVertices, vector<Vector3>& out, float multiple = 2.f);
	bool LORD_CORE_API BezierEx(const vector<Vector4>& oriVertices, vector<Vector4>& out, float multiple = 2.f);
}

#endif