#pragma once
#include <filesystem>
#include <chrono>

namespace FileSystem
{
	/*
	std::filesystem::path
	свойство файла
	итерирование по директории
	операции с файлами и каталогами
	*/

	void PathBasic()
	{
		std::filesystem::path pth;
		//pth = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\FileSystem\\test.txt";
		pth = "C:/Users/AlekseyRozhkov/source/repos/CppProject/HomeworkRestart/FileSystem/test.txt";
		std::cout << pth.filename() << std::endl;
		std::cout << pth.parent_path() << std::endl;
		std::cout << pth.parent_path().parent_path() << std::endl;

		std::filesystem::path filename = pth.filename();
		std::cout << filename.stem() << std::endl;
		std::cout << filename.extension() << std::endl;

		std::cout << pth.root_name() << std::endl;
		std::cout << pth.root_directory() << std::endl;
		std::cout << pth.root_path() << std::endl;

		std::filesystem::path pth1 = "C:/a/b/c"; //абсолютный путь, т.к. идет от корня
		std::filesystem::path pth2 = "b/c"; //относительный путь, который не стартует от корня

		std::cout << pth1.is_relative() << std::endl;
		std::cout << pth1.is_absolute() << std::endl;

		std::cout << pth2.is_relative() << std::endl;
		std::cout << pth2.is_absolute() << std::endl;


	}

	void PathBuilding()
	{
		//std::filesystem::path pth = "C:\\Users\\" // без разницы - есть слэш или нет
		std::filesystem::path pth = "C:\\Users\\";

		pth.append("b");

		std::cout << pth << std::endl;

		std::filesystem::path pth1 = "A\\C";
		std::filesystem::path pth2 = "E";

		std::filesystem::path path_result = pth / pth1 / pth2;

		std::cout << path_result << std::endl;

		pth /= "D";

		std::cout << pth << std::endl;
	}

	void FileProperties()
	{
		//узнать размер файла, время создания, время изменения, права

		std::filesystem::path pth = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\FileSystem\\a.txt";
		std::filesystem::path pth1 = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\FileSystem\\b.txt";
		std::filesystem::path pth2 = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject";

		std::cout << std::boolalpha << std::filesystem::exists(pth) << std::endl;
		std::cout << std::boolalpha << std::filesystem::exists(pth1) << std::endl;
		std::cout << std::boolalpha << std::filesystem::exists(pth2) << std::endl;

		std::cout << std::filesystem::file_size(pth) << std::endl;
		//std::cout << std::filesystem::file_size(pth1) << std::endl; //для несуществующего файла кидает исключение, можно поймать
		std::cout << std::filesystem::file_size(pth2) << std::endl;
	}

	void FilePermissions()
	{
		std::filesystem::path pth = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\FileSystem\\a.txt";
		std::filesystem::perms p = std::filesystem::status(pth).permissions();

		std::cout << ((p & std::filesystem::perms::owner_read) != std::filesystem::perms::none ? "r" : "-")
			<< ((p & std::filesystem::perms::owner_write) != std::filesystem::perms::none ? "w" : "-")
			<< ((p & std::filesystem::perms::owner_exec) != std::filesystem::perms::none ? "x" : "-")
			<< ((p & std::filesystem::perms::group_read) != std::filesystem::perms::none ? "r" : "-")
			<< ((p & std::filesystem::perms::group_write) != std::filesystem::perms::none ? "w" : "-")
			<< ((p & std::filesystem::perms::group_exec) != std::filesystem::perms::none ? "x" : "-")
			<< ((p & std::filesystem::perms::others_read) != std::filesystem::perms::none ? "r" : "-")
			<< ((p & std::filesystem::perms::others_write) != std::filesystem::perms::none ? "w" : "-")
			<< ((p & std::filesystem::perms::others_exec) != std::filesystem::perms::none ? "x" : "-")
			<< '\n';
	}

	//void FileTimes()
	//{
	//	std::filesystem::path pth = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\FileSystem\\a.txt";
	//
	//	auto print_last_write_time = [](std::filesystem::file_time_type const& ftime) 
	//	{
	//		std::time_t cftime = std::chrono::system_clock::to_time_t(std::chrono::file_clock::to_sys(ftime));
	//		std::cout << "File write time is " << std::asctime(std::localtime(&cftime));
	//	};
	//
	//	print_last_write_time(std::filesystem::last_write_time(pth));
	//	
	//}

	void DirectoryIterations()
	{
		std::filesystem::path pth = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject";

		for (auto p : std::filesystem::directory_iterator(pth))
		{
			std::cout << p.path() << '!' << p.is_directory() << '-' << p.file_size() << std::endl;
		}
	}

	int GetTotalSize(std::filesystem::path pth)
	{
		int total_size = 0;
		for (auto p : std::filesystem::directory_iterator(pth))
		{
			int size = 0;
			if (p.is_directory())
			{
				size = GetTotalSize(p.path());
			}
			else
			{
				size = p.file_size();
			}
			total_size += size;
			std::cout << p.path() << " - " << size << std::endl;
		}
		return total_size;
	}

	void TestGetTotalSize()
	{
		double sz = GetTotalSize("C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart");
		std::cout << sz << " b" << std::endl;
		std::cout << sz / 1024 << " kb" << std::endl;
		std::cout << sz / 1024 / 1024 << " mb" << std::endl;

	}

	void CopyFile()
	{
		std::filesystem::path pth = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\FileSystem\\a.txt";
		
		std::filesystem::path result_path = pth.parent_path() / "b.txt";
		
		std::filesystem::copy_file(pth, result_path);
	}
	
	void DeleteFile()
	{
		std::filesystem::path pth = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\FileSystem\\b.txt";

		std::filesystem::remove(pth);
	}

	void RenameFile()
	{
		std::filesystem::path pth = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\FileSystem\\a.txt";

		std::filesystem::path result_path = pth.parent_path() / "b.txt";

		std::filesystem::rename(pth, result_path);
	}
}