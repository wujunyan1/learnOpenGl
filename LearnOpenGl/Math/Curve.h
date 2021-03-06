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
	// 主要参考：<<DirectX 实时渲染技术详解>> 第21章节 贝赛尔面片
	//			 伯恩斯坦多项式 ( Bernstein polynomials)
	// 
	// 说明：
	//	由一组控制点来表述的曲线(此处我暂只给出四个控制点的实现)
	// out 返回点
	// v1,v2,v3,v4 控制点
	// amount      控制量
	Vector3 LORD_CORE_API Bezier3( Vector3& out, const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4, float amount);

	//---------------------------------------------------------------
	// 主要参考：<<game programming gems 1>> 3.4-A*审美优化
	// 
	// 说明：
	//     Catmull-Rom样条可以使空间中的点序列变得平滑,它产生了一条
	// 能够经过原始路径中所有控制点的曲线(不像Bezier曲线,虽然比较平
	// 滑但是不能经过所有的控制点)。
	//	   Catmull-Rom公式要求4个输入点,然后给出一条位于第2点和第3点
	// 之间的光滑曲线。
	//     为了得到第1个输入点和第二个输入点之间的点,你可以为这个函数
	// 输入第1个点两次,接着输入第2点和第3点。为了获得第3点和第4点之间
	// 的点,可以先为函数输入第2点和第3点，然后输入第4点两次。
	// out 返回点
	// v1,v2,v3,v4 控制点
	// amount      控制量
	Vector3 LORD_CORE_API CatmullRom3( Vector3& out, const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4, float amount);

	//贝塞尔曲线
	bool LORD_CORE_API BezierEx(const vector<Vector2>& oriVertices, vector<Vector2>& out, float multiple = 2.f);
	bool LORD_CORE_API BezierEx(const vector<Vector3>& oriVertices, vector<Vector3>& out, float multiple = 2.f);
	bool LORD_CORE_API BezierEx(const vector<Vector4>& oriVertices, vector<Vector4>& out, float multiple = 2.f);
}

#endif