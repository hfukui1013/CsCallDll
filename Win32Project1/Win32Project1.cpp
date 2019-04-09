// Win32Project1.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"

extern "C" __declspec(dllexport) int FunctionName(int x, int y)
{
	return x + y;
}
//
//class CTest
//{
//public:
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//
//};

// wrap_native_class_for_mgd_consumption.cpp
// compile with: /clr /LD
//#include <windows.h>
#include <vcclr.h>
#using <System.dll>

using namespace System;

namespace Hello
{

	class UnmanagedClass {
	public:
		LPCWSTR GetPropertyA() { return 0; }
		void MethodB(LPCWSTR) {}
		int Add(int x, int y) { return x + y; }
	};

	public ref class ManagedClass {
	public:
		// Allocate the native object on the C++ Heap via a constructor
		ManagedClass() : m_Impl(new UnmanagedClass) {}

		// Deallocate the native object on a destructor
		~ManagedClass() {
			delete m_Impl;
		}

	protected:
		// Deallocate the native object on the finalizer just in case no destructor is called
		!ManagedClass() {
			delete m_Impl;
		}

	public:
		property String ^  get_PropertyA {
			String ^ get() {
				return gcnew String(m_Impl->GetPropertyA());
			}
		}

		void MethodB(String ^ theString) {
			pin_ptr<const WCHAR> str = PtrToStringChars(theString);
			m_Impl->MethodB(str);
		}

		int Add(int x, int y)
		{
			return m_Impl->Add(x, y);
		}

	private:
		UnmanagedClass * m_Impl;
	};
}

