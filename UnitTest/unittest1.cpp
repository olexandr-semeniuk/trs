#include "stdafx.h"
#include "CppUnitTest.h"
#include "TRSLibrary\TRSManager.h"
#include <list>
#include <vector>
#include "TRSLibrary\Erorrs.h"
#include "TRSLibrary\FunctionalityForXML.h"

#define AMOUNT_OF_TESTS 18U
#define FIRST_BRANCH_AMOUNT 6U
#define SECOND_BRANCH_AMOUNT 7U
#define THIRD_BRANCH_AMOUNT 5U
#define MAX_TEST_NAME_LENGHT 10U
#define SUCCEED_TESTS 9U

#define TOTAL_AMOUNT_OF_DEBUG_TAGS 6U
#define TOTAL_AMOUNT_OF_RELEASE_TAGS 11U


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		//TEST_CLASS_INITIALIZE(ClassInitialization)
		//{
		//	Manager.Init();
		//}
		//
		//TEST_CLASS_CLEANUP(ClassCleanUp)
		//{
		//	Manager.Destroy();
		//}

		////========================================================================================
		////========================================================================================


		//TEST_METHOD(ListTest_NamesChecking)
		//{
		//	std::list<Suite*> list = *Manager.List(R"(../TestData/TestStrcuture)", nullptr, nullptr);

		//	unsigned int testsAmount = 0;

		//	std::list<Suite*>::iterator it = list.begin();

		//	for (it; it != list.end(); ++it)
		//	{
		//		testsAmount += (*it)->getList().size();
		//	}

		//	Assert::AreEqual(testsAmount, AMOUNT_OF_TESTS);
		//	
		//	char name[MAX_TEST_NAME_LENGHT];

		//	std::list<Suite*>::iterator iter = list.begin();
		//	
		//	int i = 1;
		//	for (; i <= FIRST_BRANCH_AMOUNT; ++iter)
		//	{
		//		
		//		std::list<TRSTest*>::iterator testIt = (*iter)->getList().begin();
		//		for (testIt; testIt != (*iter)->getList().end(); ++testIt, ++i)
		//		{
		//			sprintf(name, "Test %d", i);
		//			int cmp_result = strcmp(name, (*testIt)->getName());
		//			Assert::IsTrue(cmp_result == 0);
		//		}
		//	}

		//	for (i = 1; i <= SECOND_BRANCH_AMOUNT; ++iter)
		//	{
		//		std::list<TRSTest*>::iterator testIt = (*iter)->getList().begin();
		//		for (testIt; testIt != (*iter)->getList().end(); ++testIt, ++i)
		//		{
		//			sprintf(name, "Test %d", i);
		//			int cmp_result = strcmp(name, (*testIt)->getName());
		//			Assert::IsTrue(cmp_result == 0);
		//		}
		//	}

		//	for (i = 1; i <= THIRD_BRANCH_AMOUNT; ++iter)
		//	{
		//		std::list<TRSTest*>::iterator testIt = (*iter)->getList().begin();
		//		for (testIt; testIt != (*iter)->getList().end(); ++testIt, ++i)
		//		{
		//			sprintf(name, "Test %d", i);
		//			int cmp_result = strcmp(name, (*testIt)->getName());
		//			Assert::IsTrue(cmp_result == 0);
		//		}
		//	}
		//}

		//// **************************************************************************************************************
		//TEST_METHOD(ListTest_NameAmount_TestStrcuture)
		//{
		//	std::list<Suite*> list;
		//	unsigned int count = 0;
		//	std::list<Suite*>::iterator it;
		//	for (int i = 1; i <= 5; ++i)
		//	{
		//		char name[MAX_TEST_NAME_LENGHT];
		//		sprintf(name, "Test %d", i);

		//		list = *Manager.List(R"(../TestData/TestStrcuture)", name, nullptr);
		//		
		//		 it= list.begin();
		//		for (it; it != list.end(); ++it)
		//		{
		//			count += (*it)->getList().size();
		//		}
		//		Assert::AreEqual(count, 3U);
		//		count = 0;
		//	}

		//	count = 0;
		//	list = *Manager.List(R"(../TestData/TestStrcuture)", "Test 6", nullptr);
		//	it = list.begin();
		//	for (it; it != list.end(); ++it)
		//	{
		//		count += (*it)->getList().size();
		//	}
		//	Assert::AreEqual(count, 2U);
		//	count = 0;
		//	list = *Manager.List(R"(../TestData/TestStrcuture)", "Test 7", nullptr);
		//	it = list.begin();
		//	for (it; it != list.end(); ++it)
		//	{
		//		count += (*it)->getList().size();
		//	}
		//	Assert::AreEqual(count, 1U);
		//}

		//// **************************************************************************************************************
		////_________________________________________________________________________________________________________________
		//TEST_METHOD(ListTest_ReleaseTagAmount_TestStrcuture)
		//{
		//	std::list<Suite*> list = *Manager.List(R"(../TestData/TestStrcuture)", nullptr, "Release");

		//	unsigned int count = 0;
		//	std::list<Suite*>::iterator it = list.begin();
		//	for (it; it != list.end(); ++it)
		//	{
		//		std::list<TRSTest*>::iterator iter = (*it)->getList().begin();
		//		for (iter; iter != (*it)->getList().end(); ++iter)
		//		{
		//			if (!strcmp((*iter)->getTag(), "Release"))
		//			{
		//				++count;
		//			}
		//		}
		//	}
		//	Assert::AreEqual(count, TOTAL_AMOUNT_OF_RELEASE_TAGS);
		//}

		//TEST_METHOD(ListTest_DebugTagAmount_TestStrcuture)
		//{
		//	std::list<Suite*> list = *Manager.List(R"(../TestData/TestStrcuture)", nullptr, "Debug");

		//	unsigned int count = 0;
		//	std::list<Suite*>::iterator it = list.begin();
		//	for (it; it != list.end(); ++it)
		//	{
		//		std::list<TRSTest*>::iterator iter = (*it)->getList().begin();
		//		for (iter; iter != (*it)->getList().end(); ++iter)
		//		{
		//			if (!strcmp((*iter)->getTag(), "Debug"))
		//			{
		//				++count;
		//			}
		//		}
		//	}

		//	Assert::AreEqual(count, TOTAL_AMOUNT_OF_DEBUG_TAGS);
		//}

		//TEST_METHOD(ListTest_SingleTagAmount_TestStrcuture)
		//{
		//	std::list<Suite*> list = *Manager.List(R"(../TestData/TestStrcuture)", nullptr, "Single");

		//	unsigned int count = 0;
		//	std::list<Suite*>::iterator it = list.begin();
		//	for (it; it != list.end(); ++it)
		//	{
		//		std::list<TRSTest*>::iterator iter = (*it)->getList().begin();
		//		for (iter; iter != (*it)->getList().end(); ++iter)
		//		{
		//			if (!strcmp((*iter)->getTag(), "Single"))
		//			{
		//				++count;
		//			}
		//		}
		//	}

		//	Assert::AreEqual(count, 1U);
		//}

		////_________________________________________________________________________________________________________________
		//TEST_METHOD(ListTest_TotalAmount_TestStrcuture)
		//{
		//	std::list<Suite*> list = *Manager.List(R"(../TestData/TestStrcuture)", nullptr, nullptr);
		//
		//	unsigned int count = 0;
		//	std::list<Suite*>::iterator it = list.begin();
		//	for (it; it != list.end(); ++it)
		//	{
		//		count += (*it)->getList().size();
		//	}

		//	Assert::AreEqual(count, AMOUNT_OF_TESTS);
		//}

		//TEST_METHOD(ListTest_TotalAmount_Suite1)
		//{
		//	std::list<Suite*> list = *Manager.List(R"(../TestData/TestStrcuture/Suite1)", nullptr, nullptr);

		//	unsigned int count = 0;
		//	std::list<Suite*>::iterator it = list.begin();
		//	for (it; it != list.end(); ++it)
		//	{
		//		count += (*it)->getList().size();
		//	}

		//	Assert::AreEqual(count, FIRST_BRANCH_AMOUNT);
		//}
		//TEST_METHOD(ListTest_TotalAmount_Suite11)
		//{
		//	std::list<Suite*> list = *Manager.List(R"(../TestData/TestStrcuture/Suite1/Suite1)", nullptr, nullptr);

		//	unsigned int count = 0;
		//	std::list<Suite*>::iterator it = list.begin();
		//	for (it; it != list.end(); ++it)
		//	{
		//		count += (*it)->getList().size();
		//	}


		//	Assert::AreEqual(count, 5U);
		//}
		//TEST_METHOD(ListTest_TotalAmount_Suite111)
		//{
		//	std::list<Suite*> list = *Manager.List(R"(../TestData/TestStrcuture/Suite1/Suite1/Suite1)", nullptr, nullptr);

		//	unsigned int count = 0;
		//	std::list<Suite*>::iterator it = list.begin();
		//	for (it; it != list.end(); ++it)
		//	{
		//		count += (*it)->getList().size();
		//	}

		//	Assert::AreEqual(count, 2U);
		//}

		//TEST_METHOD(ListTest_TotalAmount_Suite2)
		//{
		//	std::list<Suite*> list = *Manager.List(R"(../TestData/TestStrcuture/Suite2)", nullptr, nullptr);

		//	unsigned int count = 0;
		//	std::list<Suite*>::iterator it = list.begin();
		//	for (it; it != list.end(); ++it)
		//	{
		//		count += (*it)->getList().size();
		//	}

		//	Assert::AreEqual(count, SECOND_BRANCH_AMOUNT);
		//}

		//TEST_METHOD(ListTest_TotalAmount_Suite3)
		//{
		//	std::list<Suite*> list = *Manager.List(R"(../TestData/TestStrcuture/Suite3)", nullptr, nullptr);

		//	unsigned int count = 0;
		//	std::list<Suite*>::iterator it = list.begin();
		//	for (it; it != list.end(); ++it)
		//	{
		//		count += (*it)->getList().size();
		//	}

		//	Assert::AreEqual(count, THIRD_BRANCH_AMOUNT);
		//}
		////=============================================================================================================
		////=============================================================================================================

		//TEST_METHOD(RunTest_Result)
		//{
		//	std::vector<TRSResult> run_result = Manager.Run(R"(../TestData/TestStrcuture)", nullptr, nullptr);


		//	unsigned succeed_counter = 0;
		//	for each (auto val in run_result)
		//	{
		//		if (val.get_result() == true)
		//			++succeed_counter;
		//	}
		//	Assert::AreEqual(succeed_counter, SUCCEED_TESTS);
		//}
		//// **************************************************************************************************************
		//TEST_METHOD(RunTest_NameAmount_TestStrcuture)
		//{
		//	std::vector<TRSResult> run_result;
		//	for (int i = 1; i <= 5; ++i)
		//	{
		//		char name[MAX_TEST_NAME_LENGHT];
		//		sprintf(name, "Test %d", i);

		//		run_result = Manager.Run(R"(../TestData/TestStrcuture)", name, nullptr);

		//		Assert::AreEqual(run_result.size(), 3U);
		//	}


		//	run_result = Manager.Run(R"(../TestData/TestStrcuture)", "Test 6", nullptr);

		//	Assert::AreEqual(run_result.size(), 2U);

		//	run_result = Manager.Run(R"(../TestData/TestStrcuture)", "Test 7", nullptr);

		//	Assert::AreEqual(run_result.size(), 1U);
		//}

		//// **************************************************************************************************************
		////_________________________________________________________________________________________________________________
		//TEST_METHOD(RunTest_ReleaseTagAmount_TestStrcuture)
		//{
		//	std::vector<TRSResult> run_result = Manager.Run(R"(../TestData/TestStrcuture)", nullptr, "Release");

		//	Assert::AreEqual(run_result.size(), TOTAL_AMOUNT_OF_RELEASE_TAGS);
		//}

		//TEST_METHOD(RunTest_DebugTagAmount_TestStrcuture)
		//{
		//	std::vector<TRSResult> run_result = Manager.Run(R"(../TestData/TestStrcuture)", nullptr, "Debug");

		//	Assert::AreEqual(run_result.size(), TOTAL_AMOUNT_OF_DEBUG_TAGS);
		//}

		//TEST_METHOD(RunTest_SingleTagAmount_TestStrcuture)
		//{
		//	std::vector<TRSResult> run_result = Manager.Run(R"(../TestData/TestStrcuture)", nullptr, "Single");

		//	Assert::AreEqual(run_result.size(), 1U);
		//}

		////_________________________________________________________________________________________________________________


		//TEST_METHOD(RunTest_TotalAmount_TestStructure)
		//{
		//	std::vector<TRSResult> run_result = Manager.Run(R"(../TestData/TestStrcuture)", nullptr, nullptr);

		//	Assert::AreEqual(run_result.size(), AMOUNT_OF_TESTS);
		//}

		//TEST_METHOD(RunTest_TotalAmount_Suite1)
		//{
		//	std::vector<TRSResult> run_result = Manager.Run(R"(../TestData/TestStrcuture/Suite1)", nullptr, nullptr);

		//	Assert::AreEqual(run_result.size(), FIRST_BRANCH_AMOUNT);
		//}
		//TEST_METHOD(RunTest_TotalAmount_Suite11)
		//{
		//	std::vector<TRSResult> run_result = Manager.Run(R"(../TestData/TestStrcuture/Suite1/Suite1)", nullptr, nullptr);

		//	Assert::AreEqual(run_result.size(), 5U);
		//}
		//TEST_METHOD(RunTest_TotalAmount_Suite111)
		//{
		//	std::vector<TRSResult> run_result = Manager.Run(R"(../TestData/TestStrcuture/Suite1/Suite1/Suite1)", nullptr, nullptr);

		//	Assert::AreEqual(run_result.size(), 2U);
		//}

		//TEST_METHOD(RunTest_TotalAmount_Suite2)
		//{
		//	std::vector<TRSResult> run_result = Manager.Run(R"(../TestData/TestStrcuture/Suite2)", nullptr, nullptr);

		//	Assert::AreEqual(run_result.size(), SECOND_BRANCH_AMOUNT);
		//}

		//TEST_METHOD(RunTest_TotalAmount_Suite3)
		//{
		//	std::vector<TRSResult> run_result = Manager.Run(R"(../TestData/TestStrcuture/Suite3)", nullptr, nullptr);

		//	Assert::AreEqual(run_result.size(), THIRD_BRANCH_AMOUNT);
		//}

		//TEST_METHOD(Verify_Name_absent)
		//{
		//	Assert::IsFalse((int)Manager.Verify(R"(../TestData/TestStrcuture)",nullptr,nullptr)==(int)INVALID_NAME);
		//}
		//TEST_METHOD(Verify_INVALID_EXECUTION_NAME_absent)
		//{
		//	Assert::IsFalse((int)Manager.Verify(R"(../TestData/TestStrcuture)", nullptr, nullptr) == (int)INVALID_EXECUTION_NAME);
		//}
		//TEST_METHOD(Verify_INVALID_RESULT_absent)
		//{
		//	Assert::IsFalse((int)Manager.Verify(R"(../TestData/TestStrcuture)", nullptr, nullptr) == (int)INVALID_RESULT);
		//}
		//TEST_METHOD(Verify_INVALID_EXE_FILE_absent)
		//{
		//	Assert::IsFalse((int)Manager.Verify(R"(../TestData/TestStrcuture)", nullptr, nullptr) == (int)INVALID_EXE_FILE);
		//}
		//TEST_METHOD(Verify_SUCCSEED)
		//{
		//	Assert::IsTrue((int)Manager.Verify(R"(../TestData/TestStrcuture)", nullptr, nullptr) == (int)SUCCSEED);
		//}
	};
}