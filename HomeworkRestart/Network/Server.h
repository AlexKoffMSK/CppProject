#pragma once
#include <iostream>
#include <winsock.h>

namespace Network
{
	class Server
	{
	private:
		SOCKET _sock;
		SOCKET _client_sock; //��� ����� (�����,�����), ����� ������� �� ����� �������� � ���������� ��������, ������� � ��� �����������

	public:
		Server(int port_)
		{
			std::cout << "Run server" << std::endl;
			WSADATA ws;

			if (FAILED(WSAStartup(MAKEWORD(1, 1), &ws)))
			{
				auto error = WSAGetLastError();

				std::cout << "WSAStartup Error: " << error << std::endl;
				return;
			}

			if (INVALID_SOCKET == (_sock = socket(AF_INET, SOCK_STREAM, 0)))
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
			s_address.sin_port = htons(port_);

			int bind_error = bind(_sock, (sockaddr*)&s_address, sizeof(s_address));

			if (bind_error != 0)
			{
				std::cout << "Bind error: " << bind_error << std::endl;

				return;
			}

			std::cout << "Server start listening" << std::endl;

			int listen_error = listen(_sock, 0);

			if (listen_error != 0)
			{
				std::cout << "Listen error: " << listen_error << std::endl;

				return;
			}
			std::cout << "Server init complete" << std::endl;
		}

		void WaitForClient() //��������� ���������� �� ��� ���, ���� � ��� �� ����������� ������
		{
			sockaddr_in client_address;

			int size_client_adr = sizeof(client_address);

			_client_sock = accept(_sock, (sockaddr*)&client_address, &size_client_adr);

			if (_client_sock == INVALID_SOCKET)
			{
				auto error = WSAGetLastError();

				std::cout << "Accept error: " << error << std::endl;

				return;
			}

			std::cout << "Client connected: " << client_address.sin_port << std::endl;
		}

		std::string RecieveDataBlocked() //��������� ���������� �� ��� ���, ���� ������ ���-�� �� �������
		{
			char buff[256];

			if (SOCKET_ERROR == recv(_client_sock, buff, 256, 0))
			{
				auto error = WSAGetLastError();

				std::cout << "Recieve error: " << error << std::endl;

				exit(-1);
			}
			std::cout << "Client ID: " << _client_sock << ": recieved data: ";
			return buff;
		}

		std::string RecieveDataIfDataExist() //������ ������ ������, ���� ������ ������ �� �������, ����� ������ ��, ��� ������� ������
		{

		}
		
		void ShutDown()
		{

		}
	};
}