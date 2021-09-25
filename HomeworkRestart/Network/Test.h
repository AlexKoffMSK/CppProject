#pragma once
#include <iostream>
#include <winsock.h>
#include "Client.h"
#include "Server.h"

namespace Network
{
	/*
	void TestServer()
	{
		std::cout << "Run server" << std::endl;
		WSADATA ws;

		if (FAILED(WSAStartup(MAKEWORD(1, 1), &ws)))
		{
			auto error = WSAGetLastError();

			std::cout << "WSAStartup Error: " << error << std::endl;
			return;
		}

		SOCKET sock;
		
		if (INVALID_SOCKET == (sock = socket(AF_INET, SOCK_STREAM, 0)))
		{
			auto error = WSAGetLastError();

			std::cout << "Socket init error: " << error << std::endl;

			return;
		}

		// ������� ���������� ��� �������� ������ 
		sockaddr_in s_address;

		// �������� ��:
		ZeroMemory(&s_address, sizeof(s_address));

		// ��� ������ (TCP/IP)
		s_address.sin_family = AF_INET;

		//����� �������. �.�. TCP/IP ������������ ������ � �������� ����, �� ��� �������� 
		// ������ ���������� ������� inet_addr.
		s_address.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

		// ����. ���������� ������� htons ��� �������� ������ ����� �� �������� � //TCP/IP �������������.
		s_address.sin_port = htons(2003);


		int bind_error = bind(sock, (sockaddr*)&s_address, sizeof(s_address));

		if (bind_error != 0)
		{
			std::cout << "Bind error: " << bind_error << std::endl;

			return;
		}
		
		std::cout << "Server start listening" << std::endl;

		int listen_error = listen(sock, 0);

		if (listen_error != 0)
		{
			std::cout << "Listen error: " << listen_error << std::endl;

			return;
		}

		SOCKET client_sock; //��� ����� (�����,�����), ����� ������� �� ����� �������� � ���������� ��������, ������� � ��� �����������

		sockaddr_in client_address;

		int size_client_adr = sizeof(client_address);
		
		client_sock = accept(sock, (sockaddr*)&client_address, &size_client_adr);

		if (client_sock == INVALID_SOCKET)
		{
			auto error = WSAGetLastError();
			
			std::cout << "Accept error: " << error << std::endl;

			return;
		}
		
		std::cout << "Client connected: " << client_address.sin_port << std::endl;

		while (true) 
		{
			char buff[256];
			
			if (SOCKET_ERROR == recv(client_sock, buff, 256, 0))
			{
				auto error = WSAGetLastError();

				std::cout << "Recieve error: " << error << std::endl;

				return;
			}
			std::cout << "Server recieve message:" << buff << std::endl;
		}

		std::cout << "Server is over!" << std::endl;
	}

	void TestClient()
	{
		std::cout << "Run client" << std::endl;
		WSADATA ws;

		if (FAILED(WSAStartup(MAKEWORD(1, 1), &ws)))
		{
			auto error = WSAGetLastError();

			std::cout << "WSAStartup Error: " << error << std::endl;
			return;
		}

		SOCKET sock;

		if (INVALID_SOCKET == (sock = socket(AF_INET, SOCK_STREAM, 0)))
		{
			auto error = WSAGetLastError();

			std::cout << "Socket init error: " << error << std::endl;

			return;
		}

		// ������� ���������� ��� �������� ������ 
		sockaddr_in s_address;

		// �������� ��:
		ZeroMemory(&s_address, sizeof(s_address));

		// ��� ������ (TCP/IP)
		s_address.sin_family = AF_INET;

		//����� �������. �.�. TCP/IP ������������ ������ � �������� ����, �� ��� �������� 
		// ������ ���������� ������� inet_addr.
		s_address.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

		// ����. ���������� ������� htons ��� �������� ������ ����� �� �������� � //TCP/IP �������������.
		s_address.sin_port = htons(2003);

		//int bind_error = bind(sock, (sockaddr*)&s_address, sizeof(s_address));
		//
		//if (bind_error != 0)
		//{
		//	std::cout << "Bind error: " << bind_error << std::endl;
		//
		//	return;
		//}
		//
		//int listen_error = listen(sock, 0);
		//
		//if (listen_error != 0)
		//{
		//	std::cout << "Listen error: " << listen_error << std::endl;
		//
		//	return;
		//}

		//int valid = 0;
		// 
		// 
		//while (TRUE) {
		//	int size_socket_in = sizeof(s_address);
		//	valid = accept(sock, &s_address, &size_socket_in);
		//
		//	if (valid != INVALID_SOCKET) {
		//		std::cout << "OK";
		//	}
		//}

		// ������ ��������� ����������:
		if (SOCKET_ERROR == (connect(sock, (sockaddr*)&s_address, sizeof(s_address))))
		{
			auto error = WSAGetLastError();

			std::cout << "Connect error: " << error << std::endl;
		
			return;
		}

		std::cout << "Connect established " << std::endl;
		
		while (true)
		{
			std::string str;
			std::cin >> str;
			
			if (SOCKET_ERROR == send(sock, str.c_str(), str.size()+1, 0))
			{
				auto error = WSAGetLastError();

				std::cout << "Send error: " << error << std::endl;

				return;
			}
		}

		std::cout << "Client is over!" << std::endl;
	}
	*/

	void TestServerClass()
	{
		Server serv(666);
		serv.WaitForClient();
		while (true)
		{
			std::string str = serv.RecieveDataBlocked(); //��� ������� �� ����� ���� ������, ���� �� ������ ������
			std::cout << str << std::endl;
		}
	}

	void TestClientClass()
	{
		Client client("127.0.0.1", 666);
		client.ConnectToServer();
		std::vector<std::string> log;
		while (true)
		{
			std::string str;
			std::cout << "Input data: ";
			std::cin >> str;
			client.SendDataToServer(str);
			log.push_back(str);
		}
	}
}

//����� - ��� ����������, �������� �����, � ������� ��� �� ������� ����� ���-�� �������/��������