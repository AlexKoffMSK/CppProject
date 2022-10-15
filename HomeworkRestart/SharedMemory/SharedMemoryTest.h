#pragma once
#include <iostream>
#include "SharedMemory/SharedMemoryClient.h"
#include "SharedMemory/SharedMemoryServer.h"

//��������� ������ ����� ������� ����

namespace SharedMemory
{
	const char kTriggerAfterWrite = '1';
	const char kTriggerAfterRead = '0';
	const int kOffsetForStartToReadAndWrite = 1;
	const int kAdditionalSizeForTerminalZero = 1;
	
	struct Mapping
	{
		char _trigger_for_write_and_read; //1 - � 0 ����� ����� ���� ���
		char _data[50]; //50 - ������� � 1 �� 50 ���� ������������ ������ ������������� ��� 1 ���� ��� ���
		int _data_int = 1; //4 - ������� � 51 �� 54 ������������ - ��� ���, �.�. 1 �������� ����
		double _data_double[10];//80 - ������� � 55 �� 134 - ��� �����
	};

	void TestServer()
	{
		SharedMemoryServer::SharedMemoryServer sh_ser((sizeof(Mapping)));

		//*sh_ser.GetBuf() = kTriggerAfterWrite;

		Mapping* m = (Mapping*)sh_ser.GetBuf(); //����������� �������� �� ���������� ����� ������, �.�. � ������ 134 ����� (����� �� ���������) �� �� ������ ������� ������ �����, ���� �������� ����� m.
		//m->_data_int = 4;

		while (true)
		{
			std::string str;
			std::cout << "Enter data: ";
			std::cin >> str;

			CopyMemory((PVOID)(&(m->_data[0])), str.c_str(), (str.size() + kAdditionalSizeForTerminalZero));
			
			m->_trigger_for_write_and_read = kTriggerAfterWrite;

			if (str == "0")
			{
				return;
			}

			//*(int*)(sh_ser.GetBuf() + 50) = 4; //������� � 50 ����� �� 54 ���� ������ ���������� � 4 ����� ��� ������� ����������

		}
		_getch();
	}

	void TestClient()
	{
		SharedMemoryClient::SharedMemoryClient sh_cli((sizeof(Mapping)));
		
		Mapping* m = (Mapping*)sh_cli.GetBuf();

		std::string str1;

		while (true) 
		{
			if (m->_trigger_for_write_and_read != kTriggerAfterWrite)
			{
				continue;
			}
			
			std::string str(&(m->_data[0]));
			
			if (str == "0")
			{
				//return;
				exit(0);
			}

			std::cout << str << std::endl;
			
			m->_trigger_for_write_and_read = kTriggerAfterRead;

			//std::cout << (char*)sh_cli.GetBuf() << std::endl;

			//MessageBox(NULL, (LPCWSTR)sh_cli.GetBuf(), TEXT("Process2"), MB_OK);
		}
	}

	void Test(int argc, char* argv[])
	{
		if (argc == 1)
		{
			return;
		}

		if (std::string(argv[1]) == "0")
		{
			TestServer();
		}
		else if (std::string(argv[1]) == "1")
		{
			TestClient();
		}
		else
		{
			return;
		}
	}
}

//���������� ����� ����
//������ �� ��������� ������ � ��������� �������� � �������� � ����� ������ lock-free �����������
//C:\Users\AlekseyRozhkov\source\repos\CppProject\x64\Debug