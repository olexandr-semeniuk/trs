#ifndef PROJECTPROPERTIES_H_
#define PROJECTPROPERTIES_H_
#include "stdafx.h"
#include "TRSLibrary\TinyXML\tinyxml.h"
#include <vector>
#include "Functionality.h"
class ProjectProperties
{
	char* path;
	char* name;
	char* tag=nullptr;
	char* testName=nullptr;
	char* threads=nullptr;
public:
	ProjectProperties(char* path, char* name);
	ProjectProperties();
	~ProjectProperties();
	ProjectProperties& operator=(ProjectProperties& pro);

	bool setPath(const char* path);
	bool setName(const char* name);
	bool setTag(char* tag);
	bool setThreads(char* threads);
	bool setTestName(char* testName);
	char* getProjPath();
	bool SaveProject(CListBox*List);
	char* getPath();
	char* getName();
	char* getThreads();
	char* getTag();
	char* getTestName();
};

#endif