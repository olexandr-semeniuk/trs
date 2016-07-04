#include "stdafx.h"
#define TRSManager_EXPORT
#include "TRSManager.h"
#include "FunctionalityForXML.h"
#include <iostream>

using namespace std;
TRSManager Manager;

TRSManager::TRSManager()
{

}

TRSManager::~TRSManager()
{

}

bool TRSManager::Init()
{
	return false;
}

bool TRSManager::Verify(char* path, char* name, char* tag)
{
	return false;
}

bool TRSManager::Run(char* path, char* name, char* tag)
{
	if (path != nullptr)
	{
		cout << "path: ";
		for (int i = 0; path[i] != 0; ++i)
			cout << path[i];
		cout << endl;
	}

	if (name != nullptr)
	{
		cout << "name: ";
		for (int i = 0; name[i] != 0; ++i)
			cout << name[i];
		cout << endl;
	}

	if (tag != nullptr)
	{
		cout << "tag: ";
		for (int i = 0; tag[i] != 0; ++i)
			cout << tag[i];
		cout << endl;
	}
	return false;
}

bool TRSManager::Pause(char* path, char* name, char* tag)
{
	return false;
}

bool TRSManager::Stop(char* path, char* name, char* tag)
{
	return false;
}

bool TRSManager::List(char* path, char* name, char* tag)
{
	WIN32_FIND_DATA ffd;//variable that contains file info(if such is open with it)
	HANDLE hFind;
	TCHAR szDir[MAX_PATH];//buffer that holds file path
	TCHAR hzDir[MAX_PATH];//help buffer that holds root path

	StringCchCopy(szDir, MAX_PATH, (TCHAR*)path);//copy path from line to buffer for recursive use
	StringCchCopy(hzDir, MAX_PATH, (TCHAR*)path);//and to help buffer
	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));//add end symbol to search in this directory

	hFind = FindFirstFile(szDir, &ffd);//open first Folder
	if (hFind == INVALID_HANDLE_VALUE)
	{
		std::cout << "FindFirstFile failed\n";
		return false;
	}
	else
	{
		do
		{
			if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)//check if it's a folder or not
			{
				_tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);
				if (*ffd.cFileName != (WCHAR)'.')//not to enter '.' and '..' folders
				{
					TCHAR subDir[MAX_PATH];//create additional buffer for recursive traverse
					StringCchCopy(subDir, MAX_PATH, hzDir);//fill additional buffer with this folder's path
					StringCchCat(subDir, MAX_PATH, TEXT("\\"));//additional slash))
					StringCchCat(subDir, MAX_PATH, ffd.cFileName);//name of last folder to search in
					std::cout << "\n\t";
					List((char*)subDir,"","");//workin' only for path,not for names or tags yet
				}
			}
			else
			{
				_tprintf(TEXT("  %s   <FILE>\n"), ffd.cFileName);//write file name if it was found in current folder
				std::wstring name(ffd.cFileName);//used for validating file name(checks if there is .xml in the end
				if (Validate(name))//validating function
				{
					TCHAR fileDir[MAX_PATH];//buffer which contains a path to an xml file
					StringCchCopy(fileDir, MAX_PATH, hzDir);//some moves to save path
					StringCchCat(fileDir, MAX_PATH, TEXT("\\"));
					StringCchCat(fileDir, MAX_PATH, ffd.cFileName);
					TiXmlDocument doc(convert(name, fileDir));//try to open such document wuth tinyXML parser
					bool loadOk = doc.LoadFile();//check if opening was successfull
					if (loadOk)
					{
						dump_to_stdout(&doc);//parse through XML and output all it's options
					}
				}
			}
		} while (FindNextFile(hFind, &ffd) != 0);//repeat
	}
	return true;
}

bool TRSManager::Status(char* path, char* name, char* tag)
{
	return false;
}

bool TRSManager::Info(char* path, char* name, char* tag)
{
	return false;
}

bool TRSManager::Destroy(char* path, char* name, char* tag)
{
	return false;
}