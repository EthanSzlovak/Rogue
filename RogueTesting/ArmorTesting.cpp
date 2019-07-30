#include "pch.h"
#include "CppUnitTest.h"
#include "iItem.hpp"
#include "iWeapon.h"
#include "curses.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RogueTesting
{
	TEST_CLASS(ArmorTesting){
	public:		
		TEST_METHOD(iWeaponConstructorTest) {
			iWeapon TrainingSword("Training Sword", 12, 12, 12, 1, 20, 0);
			string n = "Sharpener";
		
			iItem whetStone("Apples", 10, 10, [](iWeapon& toUse) {
				toUse.sumEnhancement(10);
				});
			whetStone.onConsumeWeapon_(TrainingSword);
			Assert::AreEqual(10, TrainingSword.getEnhancement());
		}


		TEST_METHOD(iWeaponAboveEnhancementTest) {
			iWeapon TrainingSword("Training Sword", 12, 12, 12, 1, 20, 0);
			string n = "Sharpener";

			iItem whetStone("Apples", 10, 10, [](iWeapon& toUse) {
				toUse.sumEnhancement(10);
				toUse.Value() *= 1.2;
				toUse.Name().append(" of sharpness");
			});
			whetStone.onConsumeWeapon_(TrainingSword);
			Assert::AreEqual(10, TrainingSword.getEnhancement());
			Assert::AreEqual(string("Training Sword of sharpness"), TrainingSword.Name());
		}
	};
}
