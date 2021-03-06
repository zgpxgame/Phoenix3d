/*
* Phoenix 3D 引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2MinHeap.hpp
*
* 版本		:	1.0 (2011/03/19)
*
* 作者		：	more
*
*/

#ifndef PX2MINHEAP_HPP
#define PX2MINHEAP_HPP

#include "PX2CorePrerequisites.hpp"
#include "PX2Memory.hpp"

namespace PX2
{

	//----------------------------------------------------------------------------
	template <typename Generator, typename Scalar> class MinHeap;

	//----------------------------------------------------------------------------
	template <typename Generator, typename Scalar>
	class MinHeapRecord
	{
	public:
		MinHeapRecord ();
		~MinHeapRecord ();

		// 成员访问
		inline Generator GetGenerator () const;
		inline Scalar GetValue () const;
		inline int GetIndex () const;

	private:
		friend class MinHeap<Generator,Scalar>;

		Generator mGenerator;
		Scalar mValue;
		int mIndex;
	};

	//----------------------------------------------------------------------------
	template <typename Generator, typename Scalar>
	class MinHeap
	{
	public:
		MinHeap (int maxElements, int growBy, Scalar initialValue);
		~MinHeap ();

		// 成员访问
		inline int GetMaxElements () const;
		inline int GetGrowBy () const;
		inline int GetNumElements () const;
		inline void GetMinimum (Generator& generator, Scalar& value) const;
		inline const MinHeapRecord<Generator,Scalar>* GetRecord (int i) const;

		// Insert into the heap the number 'value' that corresponds to the object
		// identified by 'generator'.  The return value is a pointer to the heap
		// record storing the information.
		const MinHeapRecord<Generator,Scalar>* Insert (Generator generator,
			Scalar value);

		// Remove the root of the heap.  The root contains the minimum value of
		// all heap elements.  The root information is returned by the function's
		// output parameters.
		void Remove (Generator& generator, Scalar& value);

		// The value of a heap record must be modified through this function call.
		// The side effect is that the heap must be updated accordingly to
		// accommodate the new value.
		void Update (const MinHeapRecord<Generator,Scalar>* constRecord,
			Scalar value);

		// Support for debugging.  The first two functions check wheter the array
		// of records really do form a heap.  The last function prints the heap
		// to a file.
		bool IsValid (int start, int final);
		bool IsValid ();
		void Print (const char* filename);

	private:
		// The actual record storage, allocated in one large chunk.
		int mNumElements, mMaxElements, mGrowBy;
		Scalar mInitialValue;
		MinHeapRecord<Generator,Scalar>* mRecords;

		// Pointers to the records in storage.  The two-level system avoids the
		// large number of allocations and deallocations that would occur if each
		// element of m_apkRecord were to be allocated/deallocated individually.
		MinHeapRecord<Generator,Scalar>** mRecordPointers;
	};

#include "PX2MinHeap.inl"

}

#endif