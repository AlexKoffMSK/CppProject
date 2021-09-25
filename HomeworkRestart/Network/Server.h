#pragma once
#include <iostream>
#include <winsock.h>

namespace Network
{
	class Server
	{
	private:
		SOCKET _sock;
		SOCKET _client_sock; //это сокет (труба,дырка), через который мы будем общатьс€ с конкретным клиентом, который к нам подключилс€

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

			// ќбъ€вим переменную дл€ хранени€ адреса 
			sockaddr_in s_address;

			// «аполним ее:
			ZeroMemory(&s_address, sizeof(s_address));

			// тип адреса (TCP/IP)
			s_address.sin_family = AF_INET;

			//адрес сервера. “.к. TCP/IP представл€ет адреса в числовом виде, то дл€ перевода 
			// адреса используем функцию inet_addr.
			s_address.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

			// ѕорт. »спользуем функцию htons дл€ перевода номера порта из обычного в //TCP/IP представление.
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

		void WaitForClient() //блокирует исполнение до тех пор, пока к нам не подключитс€ клиент
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

		std::string RecieveDataBlocked() //блокирует исполнение до тех пор, пока клиент что-то не пришлет
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

		std::string RecieveDataIfDataExist() //вернет пустую строку, если клиент ничего не прислал, иначе вернет то, что прислал клиент
		{

		}
		
		void ShutDown()
		{

		}
	};
}