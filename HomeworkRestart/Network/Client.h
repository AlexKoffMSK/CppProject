#pragma once
#include <iostream>
#include <winsock.h>

namespace Network
{
	class Client
	{
	private:
		SOCKET _sock;
		//������� ���������� ��� �������� ������ 
		sockaddr_in _s_address;
	
	public:
		Client(std::string ip_, int port_to_connect_)
		{
			std::cout << "Run client" << std::endl;
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

			// �������� ��:
			ZeroMemory(&_s_address, sizeof(_s_address));

			// ��� ������ (TCP/IP)
			_s_address.sin_family = AF_INET;

			//����� �������. �.�. TCP/IP ������������ ������ � �������� ����, �� ��� �������� 
			// ������ ���������� ������� inet_addr.
			_s_address.sin_addr.S_un.S_addr = inet_addr(ip_.c_str());

			// ����. ���������� ������� htons ��� �������� ������ ����� �� �������� � //TCP/IP �������������.
			_s_address.sin_port = htons(port_to_connect_);
		}

		void ConnectToServer()
		{
			// ������ ��������� ����������:
			if (SOCKET_ERROR == (connect(_sock, (sockaddr*)&_s_address, sizeof(_s_address))))
			{
				auto error = WSAGetLastError();

				std::cout << "Connect error: " << error << std::endl;

				return;
			}

			std::cout << "Connect established " << std::endl;
		}

		void SendDataToServer(std::string data)
		{
			if (SOCKET_ERROR == send(_sock, data.c_str(), data.size() + 1, 0))
			{
				auto error = WSAGetLastError();

				std::cout << "Send error: " << error << std::endl;

				return;
			}
		}

		void Disconnect()
		{

		}
	};
}