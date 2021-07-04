#pragma once
#include <iostream>
#include <bitset>
#include "BitOperations/BitOperations.h"

namespace Hash
{
	int K[] = { 0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
			    0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
			    0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
			    0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
			    0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
			    0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
			    0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
			    0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2 };

	void TestBitSet()
	{
		std::bitset<13> bit_13 = 0b0101;//битовое число 5
		bit_13[5] = 1;
		std::cout << bit_13[0] << std::endl;
		std::cout << bit_13[1] << std::endl;
		std::cout << bit_13[2] << std::endl;
		std::cout << bit_13[3] << std::endl;
		std::cout << bit_13[4] << std::endl;
		std::cout << bit_13[5] << std::endl;
		std::cout << bit_13[6] << std::endl;
		std::cout << bit_13[7] << std::endl;
		std::cout << bit_13[8] << std::endl;
		std::cout << bit_13[9] << std::endl;
		std::cout << bit_13[10] << std::endl;
		std::cout << bit_13[11] << std::endl;
		std::cout << bit_13[12] << std::endl;
	}

	int FindNearNumberDividable512_basic(int start_number)
	{
		while (start_number % 512 != 0)
		{
			start_number += 1;
		}
		return start_number;
	}

	int FindNearNumberDividable512_advanced(int start_number)
	{
		return start_number - (start_number % 512) + 512;
	}

	vector<string> SplitToWords(string str, int word_size)
	{
		vector<string> result;
		while (str.size() != 0)
		{
			std::string word = str.substr(0, word_size);
			result.push_back(word);
			str = str.substr(word_size);
		}
		return result;
	}

	int String4BytesToInt(string str)
	{
		return *((int*)&str[0]);
	}

	//void test()
	//{
	//	std::cout << FindNearNumberDividable512_basic(500) << ' ' << FindNearNumberDividable512_advanced(500) << std::endl;
	//	std::cout << FindNearNumberDividable512_basic(514) << ' ' << FindNearNumberDividable512_advanced(514) << std::endl;
	//	std::cout << FindNearNumberDividable512_basic(1020) << ' ' << FindNearNumberDividable512_advanced(1020) << std::endl;
	//	std::cout << FindNearNumberDividable512_basic(1300) << ' ' << FindNearNumberDividable512_advanced(1300) << std::endl;
	//	std::cout << FindNearNumberDividable512_basic(2500) << ' ' << FindNearNumberDividable512_advanced(2500) << std::endl;
	//}

	vector<int> SHA256(std::string message)
	{
		int h0 = 0x6A09E667;
		int h1 = 0xBB67AE85;
		int h2 = 0x3C6EF372;
		int h3 = 0xA54FF53A;
		int h4 = 0x510E527F;
		int h5 = 0x9B05688C;
		int h6 = 0x1F83D9AB;
		int h7 = 0x5BE0CD19;

		int n = message.size() * 8 + 1 + 64;
		int n1 = FindNearNumberDividable512_advanced(n);
		int k = n1 - n;
		long message_length = message.size()*8;

		message.push_back(0b10000000);
		k -= 7;
		assert(k % 8 == 0);

		for (int i = 0; i < k / 8; i++)
		{
			message.push_back(0);
		}

		std::string temp_str((char*)&message_length, 8);
		message += temp_str;

		std::cout << message.size()*8 << std::endl;

		assert(message.size() % (512/8) == 0);

		std::cout << message << std::endl;

		//std::string sub_string = message.substr(0, 64); //берет подстроку начиная с нулевого символа выдает 64 байта
		//std::cout << sub_string << std::endl;
		//message = message.substr(64); //берем начиная с 64 символа - до конца, переписывая имеющийся мессадж, укорачиваем строку

		while (message.size() != 0)
		{
			std::string block = message.substr(0, 64); //берет подстроку начиная с нулевого символа выдает 64 байта

			std::cout << "Block: " << block << std::endl;

			vector<string> splited_words = SplitToWords(block, (32 / 8));

			vector<int> w;

			for (string word : splited_words)
			{
				std::cout << word << ' ' << std::endl;
				w.push_back(String4BytesToInt(word));
			}
			
			w.resize(64); //увеличиваем размер массива до 64,таким образом запись w[i] = не будет выходить за границу массива
			for (int i = 16; i < 64; i++)
			{
				 // s0 = (w[i-15] rotr 7) xor (w[i-15] rotr 18) xor (w[i-15] shr 3)
				int s0 = BitOperations::RotateRight(w[i - 15],7) ^ BitOperations::RotateRight(w[i - 15], 18) ^ (w[i - 15] >> 3);
				
				//  s1 = (w[i-2] rotr 17) xor (w[i-2] rotr 19) xor (w[i-2] shr 10)
				int s1 = BitOperations::RotateRight(w[i - 2], 17) ^ BitOperations::RotateRight(w[i - 2], 19) ^ (w[i - 2] >> 10);

				//w[i] = w[i - 16] + s0 + w[i - 7] + s1
				w[i] = w[i - 16] + s0 + w[i - 7] + s1;
			}

			int a = h0;
			int b = h1;
			int c = h2;
			int d = h3;
			int e = h4;
			int f = h5;
			int g = h6;
			int h = h7;

			for (int i = 0; i < 64; i++)
			{
				//Σ0: = (a rotr 2) xor (a rotr 13) xor (a rotr 22)
				//Ma : = (a and b) xor (a and c) xor (b and c)
				//t2 : = Σ0 + Ma
				//Σ1 : = (e rotr 6) xor (e rotr 11) xor (e rotr 25)
				//Ch : = (e and f) xor ((not e) and g)
				//t1 : = h + Σ1 + Ch + k[i] + w[i]
				//
				//h : = g
				//g : = f
				//f : = e
				//e : = d + t1
				//d : = c
				//c : = b
				//b : = a
				//a : = t1 + t2

				int Sigma0 = BitOperations::RotateRight(a, 2) ^ BitOperations::RotateRight(a, 13) ^ BitOperations::RotateRight(a, 22);
				int Ma = (a & b) ^ (a & c) ^ (b & c);
				int t2 = Sigma0 + Ma;

				int Sigma1 = BitOperations::RotateRight(e, 6) ^ BitOperations::RotateRight(e, 11) ^ BitOperations::RotateRight(e, 25);
				int Ch = (e & f) ^ (~e & g);
				int t1 = h + Sigma1 + Ch + K[i] + w[i];

				h = g;
				g = f;
				f = e;
				e = d + t1;
				d = c;
				c = b;
				b = a;
				a = t1 + t2;
			}

			h0 = h0 + a;
			h1 = h1 + b;
			h2 = h2 + c;
			h3 = h3 + d;
			h4 = h4 + e;
			h5 = h5 + f;
			h6 = h6 + g;
			h7 = h7 + h;

			message = message.substr(64);
		}

		vector<int> result;
		result.push_back(h0);
		result.push_back(h1);
		result.push_back(h2);
		result.push_back(h3);
		result.push_back(h4);
		result.push_back(h5);
		result.push_back(h6);
		result.push_back(h7);

		for (int res : result)
		{
			std::cout << std::hex << res;
		}
		std::cout << std::endl;
		return result;
	}

	void Test()
	{
		SHA256("Aaa");
	}

}