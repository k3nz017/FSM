#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

/*
File-System-Manager
this is a library designed to manage files for your application.
even thought this is an extremely basic library, its pretty nice to use for projects that want to be-
-neatly coded.

Features:
 Read From Files
 Easy to Read/Edit/Modify the code
 Check if files exist
 Copy files, and put them in a diffrent directory/place
 and much more!

*/

#define FILESYSTEMMANAGER_VERSION "v1.0.0" //the FSM-Version
#define FILESYSTEMMANAGER_CMD_DEBUG false //to-do: when "true", then use debug-console logs.


namespace fs_cpp {

	enum class FileStatus {
		FILE_EXISTS,
		FILE_DOESNT_EXIST,
		FILE_UNRESOLVED_ERROR
	};

	struct FileSystem {
		DWORD FileSize;
		FileStatus Status;
		std::string FileData;
	};

	FileSystem* FILE_SYSTEM = new FileSystem();

	FileStatus GetFileStatus(const char* file_name_path) {
		std::ifstream File;
		File.open(file_name_path);
		if (File)
			FILE_SYSTEM->Status = FileStatus::FILE_EXISTS;
		if (!File)
			FILE_SYSTEM->Status = FileStatus::FILE_DOESNT_EXIST;

		return FILE_SYSTEM->Status;
	}

	bool DoesFileExistOnSystem(const char* file_name_path) {
		auto f_status = fs_cpp::GetFileStatus(file_name_path);
		if (f_status == FileStatus::FILE_EXISTS)
			return true;

		if (f_status == FileStatus::FILE_DOESNT_EXIST)
			return false;

		return false;
	}

	std::string GetFileData(const char* file_name_path) {
		std::string ret;
		if(DoesFileExistOnSystem(file_name_path)) {
			std::ifstream FILE_D(file_name_path);
			if (FILE_D.is_open())
			{
				while (std::getline(FILE_D, FILE_SYSTEM->FileData))
				{
					ret = FILE_SYSTEM->FileData;
				}
				FILE_D.close();
			}

		}
		return ret;
	}

	void RemoveFile(const char* file) {
		if (file == NULL)
			return;

		std::remove(file);
	}


	void MoveFileToDirectory(const char* input, const char* output) {
		if (input == NULL || output == NULL)
			return;
		MoveFileA(input, output);
	}

}