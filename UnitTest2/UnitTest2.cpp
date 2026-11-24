#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5_2/Lab_5_2.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestMethodA)
        {
            double a = 0.5; // a0 при x = 0.5
            A(0.5, 1, a);   // обчислення a1 для n = 1
            Assert::AreEqual(-0.125, a, 0.00001);
        }

        TEST_METHOD(TestMethodS)
        {
            int n = 0;
            double s = 0;
            S(0.5, 0.000001, n, s);
            Assert::AreEqual(log(1.5), s, 0.00001);
        }
    };
}