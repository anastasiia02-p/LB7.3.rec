#include "pch.h"
#include "CppUnitTest.h"
#include "../LB7.3.rec/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 3;

			int** matrix = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				matrix[i] = new int[colCount];

			matrix[0][0] = 0; matrix[0][1] = -1; matrix[0][2] = -2;
			matrix[1][0] = 1; matrix[1][1] = 2; matrix[1][2] = 3;   
			matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 0;  

			int result = FirstPositiveRow(matrix, rowCount, colCount);
			Assert::AreEqual(1, result); 

			
			for (int i = 0; i < rowCount; i++)
				delete[] matrix[i];
			delete[] matrix;

		}
	};
}
