#pragma once
#include <iostream>
#include <fstream>

namespace WorkWithBinaryFiles
{
	void WriteIntToFile(std::ofstream& ofs, int a)
	{
		ofs.write((char*)&a, sizeof(a));
	}

	int ReadIntFromFile(std::ifstream& ifs)
	{
		int a;
		ifs.read((char*)&a, sizeof(a));
		return a;
	}

	void WriteDoubleToFile(std::ofstream& ofs, double a)
	{
		ofs.write((char*)&a, sizeof(a));
	}

	double ReadDoubleFromFile(std::ifstream& ifs)
	{
		double a;
		ifs.read((char*)&a, sizeof(a));
		return a;
	}

	//=================================================================

	void ExampleWrite1()
	{
		std::ofstream ofs_b("BinaryFiles/File1.bin", std::ios::binary);
		WriteIntToFile(ofs_b, 15);
		WriteIntToFile(ofs_b, 4);
		WriteIntToFile(ofs_b, 65);
	}
	
	void ExampleWrite2()	
	{
		std::ofstream ofs_b("BinaryFiles/File1.bin", std::ios::binary);
		WriteDoubleToFile(ofs_b, 0.1);
		WriteDoubleToFile(ofs_b, 2.003);
		WriteDoubleToFile(ofs_b, 3.1123543567578);

		std::ofstream ofs_t("BinaryFiles/File2.txt");
		ofs_t << 0.1 << endl;
		ofs_t << 2.003 << endl;
		ofs_t << setprecision(32) << 3.1123543567570000000008 << endl;
	}

	void ExampleRead1()
	{
		std::ifstream ifs_t("BinaryFiles/File2.txt");
		double a;
		ifs_t >> a;
		cout << setprecision(32) << a << endl;
		ifs_t >> a;
		cout << setprecision(32) << a << endl;
		ifs_t >> a;
		cout << setprecision(32) << a << endl;

		std::ifstream ifs_b("BinaryFiles/File1.bin", std::ios::binary);
		cout << setprecision(32) << ReadDoubleFromFile(ifs_b) << endl;
		cout << setprecision(32) << ReadDoubleFromFile(ifs_b) << endl;
		cout << setprecision(32) << ReadDoubleFromFile(ifs_b) << endl;
	}

	void SaveVectorToBinaryFile(vector<int> vec, string filepath)
	{
		std::ofstream ofs_b(filepath, std::ios::binary);
		if (!ofs_b.is_open())
		{
			std::cout << "File not found!" << std::endl;
			return;
		}

		for (int a : vec)
		{
			WriteIntToFile(ofs_b, a);
		}
	}

	void TestSaveVectorToBinaryFile()
	{
		std::vector<int> vec = get_random_vector_max_range_size(10, 10);
		SaveVectorToBinaryFile(vec, "BinaryFiles/FileVec.bin");
	}
}