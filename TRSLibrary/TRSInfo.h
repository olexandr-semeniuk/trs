#ifndef TRSINFO_H_
#define TRSINFO_H_

#ifdef TRSLibrary_EXPORT
#define TRSInfo_API  __declspec(dllexport) 
#else
#define TRSInfo_API  __declspec(dllimport) 
#endif

#include "Metadata.h"

#include "TinyXML\tinyxml.h"



class TRSInfo_API TRSInfo
{
	char* Name=nullptr;
	char* description=nullptr;
	char* tag=nullptr;
	char* repeat=nullptr;
	char* maxTime=nullptr;
	char* maxThreads=nullptr;
	int expectedResult;
	char* executableName;
	
	Metadata* metadata;
public:
	TRSInfo(char*Name, char*Description);
	TRSInfo();
	~TRSInfo();

	bool setTag(char*tag_);
	bool setRepeat(char*repeat_);
	bool setMaxTime(char*maxTime_);
	bool setMaxThreads(char*maxThreads_);

	inline char* get_executableName()
	{
		return executableName;
	}
	inline int get_expectedResult()
	{
		return expectedResult;
	}

	bool setName(char*Name_);
	bool setDescription(char*Desc_);
	bool setMetadata(Metadata* metadata_);

	char* getName();
	char* getDescription();
	char* getTag();
	char* getRepeat();
	char* getMaxTime();
	char* getMaxThreads();
	Metadata* getMetadata();
	bool Parse(TiXmlNode* pParent);
};
#endif