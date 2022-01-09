#pragma once
#ifdef DEBUG
#include <iostream>
#include <winsock.h>
#include <thread>
#include <mutex>
#include <vector>
#include <queue>

namespace Network
{
	class Server
	{
	private:
		SOCKET _sock;
		std::queue<std::string> _incoming_data_from_client;

		void WaitForClients() //блокирует исполнение до тех пор, пока к нам не подключитс€ клиент
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

		void RecieveDataBlocked(SOCKET client_sock) //блокирует исполнение до тех пор, пока клиент что-то не пришлет
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

				_incoming_data_from_client.push(buff);
			}
		}

	public:
		std::vector<SOCKET> _client_sock; //это сокет (труба,дырка), через который мы будем общатьс€ с конкретным клиентом, который к нам подключилс€

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
			//адреса используем функцию inet_addr.
			s_address.sin_addr.S_un.S_addr = inet_addr("192.168.88.183");

			// ѕорт. »спользуем функцию htons дл€ перевода номера порта из обычного в //TCP/IP представление.
			s_address.sin_port = htons(port_);

			int bind_error = bind(_sock, (sockaddr*)&s_address, sizeof(s_address));

			if (bind_error != 0)
			{
				auto bind_error = WSAGetLastError();
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
			std::thread waiting_for_clients_thread(&Server::WaitForClients, this);
			waiting_for_clients_thread.detach();
		}

		void SendDataToClient(SOCKET client_sock, std::string str)
		{
			if (SOCKET_ERROR == send(client_sock, str.c_str(), str.size()+1, 0))
			{
				auto error = WSAGetLastError();

				std::cout << "Can't send data [" << str << "]. Client: " << client_sock << ", error: " << error << std::endl;

				return;
			}
		}

		std::string GetNextIncomingMessageFromClient() //возвращает текущее пришедшее от клиента сообщение или пустую строку если сообщений нет
		{
			if (_incoming_data_from_client.empty())
			{
				return "";
			}
			std::string tmp = _incoming_data_from_client.front();
			_incoming_data_from_client.pop();
			return tmp;
		}

		void ShutDown()
		{

		}
	};
}
#endif