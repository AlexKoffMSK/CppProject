#pragma once
#include <filesystem>
#include <chrono>
#include "../SHA256 from GitHub/SHA256-GitHub.h"
#include <fstream>
#include <future>
#include <thread>
#include <queue>
#include <mutex>

namespace FileSystem
{
	//D:\PhotoVideoAll\UrgentSort\2021-08-29
	//D:\PhotoVideoAll\2021AugustCrimea\2021-08-29
	//const std::filesystem::path kPath1 = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\FileSystem\\Data1";
	//const std::filesystem::path kPath2 = "C:\\Users\\AlekseyRozhkov\\source\\repos\\CppProject\\HomeworkRestart\\FileSystem\\Data2";

	const std::filesystem::path kPath1 = "D:\\PhotoVideoAll\\UrgentSort\\2021-08-29";
	const std::filesystem::path kPath2 = "D:\\PhotoVideoAll\\2021AugustCrimea\\2021-08-29";

	struct FileNameAndHash
	{
		std::filesystem::path _name;
		std::string _hash;
		
		FileNameAndHash(std::filesystem::path name_, std::string hash_)
		{
			_name = name_;
			_hash = hash_;
		}

		friend bool operator<(FileNameAndHash fnh1, FileNameAndHash fnh2)
		{
			return fnh1._hash < fnh2._hash;
		}
	};
	
	bool CompareFileNameAndHashByHash(const FileNameAndHash& fnh1, const FileNameAndHash& fnh2)
	{
		return fnh1._hash < fnh2._hash;
	}

	std::string GetFileContentAsString(const std::filesystem::path& file_address_and_name)
	{
		std::ifstream ifs(file_address_and_name);
		
		if (!ifs.is_open())
		{
			throw std::exception("Can't open file"); //аналог ретурна, но с допом
		}
		
		std::string str;
		
		//while (!ifs.eof()) //analog the next
		//while (ifs)
		while (true)
		{
			char ch = ifs.get();
			if (ch == -1)
			{
				break;
			}
			str.push_back(ch);
		}
		return str;
	}

	std::vector<FileNameAndHash> GetHashesFromFolder(const std::filesystem::path& pth)
	{
		std::vector<FileNameAndHash> file_names_hashes;
		
		for (auto p : std::filesystem::directory_iterator(pth))
		{
			file_names_hashes.emplace_back(p.path(), SHA256FromGitHub(GetFileContentAsString(p.path())));
		}
		return file_names_hashes;
	}

	std::pair<std::vector<FileNameAndHash>, std::vector<FileNameAndHash>> ParallelGetHashesFromFolders(const std::filesystem::path& pth1, const std::filesystem::path& pth2)
	{
		std::future future1 = std::async(GetHashesFromFolder,pth1);
		std::future future2 = std::async(GetHashesFromFolder,pth2);
		
		future1.wait();
		future2.wait();

		std::vector<FileNameAndHash> file_names_hashes1 = future1.get();
		std::vector<FileNameAndHash> file_names_hashes2 = future2.get();

		return { file_names_hashes1,file_names_hashes2 };
	}

	void PrintFoldersContentMatching(const std::filesystem::path& path1, const std::filesystem::path& path2)
	{
		//auto pair_of_vectors = ParallelGetHashesFromFolders(pth1, pth2);
		
		//auto [a, b, c] = std::tuple{ 1, 2, 3 }; //как пример того, что происходит ниже. std::tuple - кортеж данных, присваиваемых соответствующим переменным
		auto [file_names_hashes1, file_names_hashes2] = ParallelGetHashesFromFolders(path1, path2);

		//std::sort(file_names_hashes1.begin(), file_names_hashes1.end(), CompareFileNameAndHashByHash);
		//std::sort(file_names_hashes2.begin(), file_names_hashes2.end(), CompareFileNameAndHashByHash);
		//std::sort(file_names_hashes1.begin(), file_names_hashes2.end());

		//сохраняем лямбда функцию к переменную Compare. При этом, переменная Compare именована с большой буквы, т.к. она одновременно выступает функцией.
		auto Compare = [](FileNameAndHash fnh1, FileNameAndHash fnh2) {return fnh1._hash < fnh2._hash; }; 

		std::sort(file_names_hashes1.begin(), file_names_hashes1.end(), Compare);
		std::sort(file_names_hashes2.begin(), file_names_hashes2.end(), Compare);

		//for (auto v : file_names_hashes1)
		//{
		//	std::cout << v._name << '-' << v._hash << std::endl;
		//}
		//std::cout << std::endl;
		//
		//for (auto v : file_names_hashes2)
		//{
		//	std::cout << v._name << '-' << v._hash << std::endl;
		//}

		std::vector<FileNameAndHash> files_in_1;
		std::vector<FileNameAndHash> files_in_2;
		std::vector<std::pair<FileNameAndHash,FileNameAndHash>> files_in_both;

		int ind1=0;
		int ind2=0;

		while (ind1 < file_names_hashes1.size() || ind1 < file_names_hashes2.size())
		{
			if (ind1 == file_names_hashes1.size())
			{
				files_in_2.push_back(file_names_hashes2[ind2]);
				ind2++;
				continue;
			}
			if (ind2 == file_names_hashes2.size())
			{
				files_in_1.push_back(file_names_hashes1[ind1]);
				ind1++;
				continue;
			}

			std::string hash1 = file_names_hashes1[ind1]._hash;
			std::string hash2 = file_names_hashes2[ind2]._hash;

			if (hash1 < hash2)
			{
				files_in_1.push_back(file_names_hashes1[ind1]);
				ind1++;
			}
			else if (hash1 > hash2)
			{
				files_in_2.push_back(file_names_hashes2[ind2]);
				ind2++;
			}
			else
			{
				files_in_both.push_back({ file_names_hashes1[ind1],file_names_hashes2[ind2] });
				ind1++;
				ind2++;
			}
		}

		std::cout <<"====================Files that only exists in first directory===========================" << std::endl;
		//файлы, которые есть только в первой папке
		for (auto v : files_in_1)
		{
			std::cout << v._name << std::endl;
		}

		std::cout <<"====================Files that only exists in second directory==========================" << std::endl;
		//файлы, которые есть только во второй папке

		for (auto v : files_in_2)
		{
			std::cout << v._name << std::endl;
		}

		std::cout<< "====================Files that exists in both directories===============================" << std::endl;
		//файлы, которые есть в обеих папках

		for (auto v : files_in_both)
		{
			std::cout << v.first._name << " - " << v.second._name << std::endl;
		}

	}

	//=====================================================================================================================================================//

	std::vector<FileNameAndHash> data_from_1;
	std::vector<FileNameAndHash> data_from_2;
	std::mutex mtx;


	void Generator(const std::filesystem::path pth, std::vector<FileNameAndHash>& data_to_fill)
	{
		for (auto p : std::filesystem::directory_iterator(pth))
		{
			mtx.lock();
			std::cout << "Generate hash for: " << p.path() << std::endl;
			mtx.unlock();
			data_to_fill.emplace_back(p.path(), SHA256FromGitHub(GetFileContentAsString(p.path())));
		}
	}

	void Processor()
	{
		int ind1 = 0;
		int ind2 = 0;

		std::queue<FileNameAndHash> q1;
		std::queue<FileNameAndHash> q2;

		while (true)
		{
			if (ind1 < data_from_1.size())
			{
				//поток процессора пока стоит здесь
				q1.push(data_from_1[ind1]);
				mtx.lock();
				std::cout << "Processor for 1:" << data_from_1[ind1]._name << std::endl;
				mtx.unlock();
				ind1++;
			}
			if (ind2 < data_from_2.size())
			{
				q2.push(data_from_2[ind2]);
				mtx.lock();
				std::cout << "Processor for 2:" << data_from_2[ind2]._name << std::endl;
				mtx.unlock();
				ind2++;
			}
			if (!q1.empty() && !q2.empty())
			{
				if (q1.front()._hash == q2.front()._hash)
				{
					mtx.lock();
					std::cout <<"Equal" << q1.front()._name << "  &  " << q2.front()._name << std::endl;
					mtx.unlock();
				}
				else
				{
					mtx.lock();
					std::cout << "Not Equal" << q1.front()._name << "  &  " << q2.front()._name << std::endl;
					mtx.unlock();
				}
				q1.pop();
				q2.pop();
			}
		}
	}

	void Go()
	{
		std::thread th1(Generator, kPath1, std::ref(data_from_1));
		std::thread th2(Generator, kPath2, std::ref(data_from_2));
		std::thread th3(Processor);
		
		th1.join();
		th2.join();
		th3.join();
	}
}