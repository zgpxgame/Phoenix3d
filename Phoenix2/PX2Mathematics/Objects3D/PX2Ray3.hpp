/*
* Phoenix 3D ��Ϸ���� Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* �ļ�����	��	PX2Ray3.hpp
*
* �汾		:	1.0 (2011/02/19)
*
* ����		��	more
*
*/

#ifndef PX2RAY3_HPP
#define PX2RAY3_HPP

#include "PX2MathematicsPrerequisites.hpp"
#include "PX2Vector3.hpp"

namespace PX2
{

	/// ������
	/**
	* ���ߵı�����ʽΪP+t*D��PΪ���ߵ�ԭ�㣬DΪ��λ���ȵķ�������������t>=0����
	* ������ȷ��DΪ��λ���ȡ�
	*/
	template <typename Real>
	class Ray3
	{
	public:
		Ray3 ();  //< δ��ʼ��
		~Ray3 ();

		Ray3 (const Vector3<Real>& origin, const Vector3<Real>& direction);

		Vector3<Real> Origin, Direction;
	};

#include "PX2Ray3.inl"

	typedef Ray3<float> Ray3f;
	typedef Ray3<double> Ray3d;

}

#endif