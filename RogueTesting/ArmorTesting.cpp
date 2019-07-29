#include "pch.h"
#include "CppUnitTest.h"
#include "iWeapon.h"
#include "curses.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RogueTesting
{
	TEST_CLASS(ArmorTesting){
	public:		
		TEST_METHOD(iWeaponConstructorTest) {
			iWeapon TrainingSword(12, 12, 12, 1, 20, 0);
			string n = "Sharpener";
		
			iItem whetStone("Apples", 10, 10, [](iWeapon& toUse) {
				toUse.sumEnhancement(10);
				});
			whetStone.onConsumeWeapon_(TrainingSword);
			Assert::AreEqual(10, TrainingSword.getEnhancement());
		}
	};
}
