#pragma once
#include <iostream>
#include <winsock.h>
#include <thread>
#include <mutex>
#include <vector>

namespace Network
{
	class Server
	{
	private:
		SOCKET _sock;
		std::vector<SOCKET> _client_sock; //��� ����� (�����,�����), ����� ������� �� ����� �������� � ���������� ��������, ������� � ��� �����������

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
			//������ ���������� ������� inet_addr.
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

		void WaitForClients() //��������� ���������� �� ��� ���, ���� � ��� �� ����������� ������
		{
			while (true)
			{
				sockaddr_in client_address;

				int size_client_adr = sizeof(client_address);

				SOCKET tmp_client_sock = accept(_sock, (sockaddr*)&client_address, &size_client_adr);

				if (tmp_client_sock == INVALID_SOCKET)
				{
					auto error = WSAGetLastError();

					std::cout << "Accept error: " << error << std::endl;

					return;
				}

				_client_sock.push_back(tmp_client_sock);

				std::cout << "Client connected. ID: " << tmp_client_sock << ". Port: " << client_address.sin_port << std::endl;
				
				std::thread client_recieve_data_thread(&Server::RecieveDataBlocked, this, tmp_client_sock);
				client_recieve_data_thread.detach();
			}
		}

		void RecieveDataBlocked(SOCKET client_sock) //��������� ���������� �� ��� ���, ���� ������ ���-�� �� �������
		{
			char buff[256];

			while (true)
			{
				if (SOCKET_ERROR == recv(client_sock, buff, 256, 0))
				{
					auto error = WSAGetLastError();

					std::cout << "Recieve error: client: " << client_sock << ", error: " << error << std::endl;

					return;
				}
				std::cout << "Client ID: " << client_sock << ": recieved data: " << buff << std::endl;

				if (SOCKET_ERROR == send(client_sock, "Pong", 5, 0))
				{
					auto error = WSAGetLastError();

					std::cout << "Send error: " << error << std::endl;

					return;
				}


			}
		}
		
		std::string RecieveDataIfDataExist() //������ ������ ������, ���� ������ ������ �� �������, ����� ������ ��, ��� ������� ������
		{

		}
		
		void ShutDown()
		{

		}
	};
}