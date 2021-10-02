#pragma once
#include <iostream>
#include <winsock.h>
#include <thread>
#include <mutex>
#include <queue>

namespace Network
{
	class Client
	{
	private:
		SOCKET _sock;
		//Объявим переменную для хранения адреса 
		sockaddr_in _s_address;

		std::queue<std::string> _incoming_data_from_server;

		void RecieveDataFromServer()
		{
			char buff[256];

			while (true)
			{
				if (SOCKET_ERROR == recv(_sock, buff, 256, 0))
				{
					auto error = WSAGetLastError();

					std::cout << "Recieve error: client: " << _sock << ", error: " << error << std::endl;

					return;
				}
				_incoming_data_from_server.push(buff);
				std::cout << "Recieve data from server: " << _incoming_data_from_server.back() << std::endl;
			}
		}

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

			// Заполним ее:
			ZeroMemory(&_s_address, sizeof(_s_address));

			// тип адреса (TCP/IP)
			_s_address.sin_family = AF_INET;

			//адрес сервера. Т.к. TCP/IP представляет адреса в числовом виде, то для перевода 
			// адреса используем функцию inet_addr.
			_s_address.sin_addr.S_un.S_addr = inet_addr(ip_.c_str());

			// Порт. Используем функцию htons для перевода номера порта из обычного в //TCP/IP представление.
			_s_address.sin_port = htons(port_to_connect_);
		}

		void ConnectToServer()
		{
			// Дальше выполняем соединение:
			if (SOCKET_ERROR == (connect(_sock, (sockaddr*)&_s_address, sizeof(_s_address))))
			{
				auto error = WSAGetLastError();

				std::cout << "Connect error: " << error << std::endl;

				return;
			}

			std::cout << "Connect established " << std::endl;
			std::thread recieve_data_from_server_thread(&Client::RecieveDataFromServer, this);
			recieve_data_from_server_thread.detach();
		}

		void SendDataToServer(std::string data)
		{
			if (data.empty())
			{
				return;
			}

			if (SOCKET_ERROR == send(_sock, data.c_str(), data.size() + 1, 0))
			{
				auto error = WSAGetLastError();

				std::cout << "Send error: " << error << std::endl;

				return;
			}
		}

		std::string GetNextIncomingMessageFromServer() //возвращает текущее пришедшее от сервера сообщение или пустую строку если сообщений нет
		{
			if (_incoming_data_from_server.empty())
			{
				return "";
			}
			std::string tmp = _incoming_data_from_server.front();
			_incoming_data_from_server.pop();
			return tmp;
		}

		void Disconnect()
		{

		}
	};
}