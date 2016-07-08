#include "stdafx.h"
#include "ProcessCollection.h"
#include "TRSManager.h"

#include <list>

using std::list;


// futher implementation of priority will be added
ProcessCollection::ProcessCollection(const Suite& suite)
{
	int max_threads =  atoi(suite.getMaxThreads());
	if (max_threads < 0)
		logger << "Negative value in max_threas field";

	semaphore_ = CreateSemaphore(NULL, max_threads, max_threads , NULL);
	if (semaphore_ == NULL)
	{
		logger << "Creation of semaphore failed";
	}

	int path_len = strlen(suite.get_path());
	path_ = new char[path_len + 1];
	strcpy_s(path_, path_len + 1, suite.get_path());

	for each (TRSTest* var in suite.getList())
		tests_.push_back(ProcessInfo(*var, path_, semaphore_));

	undone_tests_ = tests_.size();
}

ProcessCollection::~ProcessCollection()
{
	if (!CloseHandle(semaphore_))
		logger << "Closing semaphore's handle failed";

	delete[] path_;
}

list<TRSResult> ProcessCollection::RunAll()
{
	while (undone_tests_)
	{
		int wait_result = WaitForSingleObject(semaphore_, INFINITE);
	
		if (wait_result == WAIT_OBJECT_0)
		{
			for (auto var = tests_.begin(); var != tests_.end(); ++var)
			{
				if (var->get_status() == Status::Running && var->ReleaseResources())
				{
					// this test is already "Done", so decrement the counter
					--undone_tests_;
					continue;
				}
				else if (var->get_status() == Status::Waiting)
				{
					// ProcessInfo owns the name resource so it must properly create and release it
					char* name = var->ProcessTest();
					if (name == nullptr)
					{
						// test was not waiting for anything and it is running now
						break;
					}
					// if this test is waiting for test, which is already done
					int result = IsDone(name);

				    if (result == 1)
					{
						var->ProcessTest(true);
						break;
					}
					else if (result ==  2)
					{
						--undone_tests_;
						var->ProcessTest(true);
						break;
					}
					else if (result < 0)
					{
						logger << "Waitfor name is not exist in current namespace";
						return list<TRSResult>();
					}

					// So, this test is wating fo another test which is still runnig.
					// so it was not a test, which signaled to main thread. Continue searching
				}
			}
		}
		else 
		{
			logger << "Wait for semaphore failed";
			return list<TRSResult>();
		}

	}

	return list<TRSResult>(tests_.begin(), tests_.end());
}

// returns:
// 0 - if test is not Done
// 1 - test was Done before checking
// 2 - we release resources of this test and change its status to Done
// -1 - error: this test is not exist in current suite
int ProcessCollection::IsDone(char* name)
{
	if (name == nullptr)
		return 0;

	for (auto var = tests_.begin(); var != tests_.end(); ++var)
	{
		if (!strcmp(name, var->get_name()))
		{
			switch (var->get_status())
			{
			case Status::Done:
				return 1;

			case Status::Running:
				// if it is finished
				if (var->ReleaseResources())
					return 2;
				else
					return 0;

			default:
				return 0;
			}
		}
	}

	return -1;
}