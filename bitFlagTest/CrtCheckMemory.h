#ifndef CRTCHECKMEMORY_H

#include "CppUnitTest.h"
#include "crtdbg.h"

#define _CRTDBG_MAP_ALLOC

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructuresTest
{
	struct CrtCheckMemory
	{
		_CrtMemState state1{};
		_CrtMemState state2{};
		_CrtMemState state3{};
		CrtCheckMemory()
		{
			_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
			_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
			_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
			_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
			_CrtMemCheckpoint(&state1);
		}

		CrtCheckMemory(const CrtCheckMemory& copy) = delete;
		CrtCheckMemory& operator=(const CrtCheckMemory& copy) = delete;
		CrtCheckMemory(CrtCheckMemory&& copy) = delete;
		CrtCheckMemory& operator=(CrtCheckMemory&& copy) = delete;

		~CrtCheckMemory()
		{
			_CrtMemCheckpoint(&state2);

			if (_CrtMemDifference(&state3, &state1, &state2) != 0)
			{
				Assert::Fail(L"Detected memory leaks!");
			}
		}
	};
}

#endif