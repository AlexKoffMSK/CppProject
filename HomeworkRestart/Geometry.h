#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace Geometry
{
	/*
	1. �������� ��������� - �������������.
	����:
	*. ����� width. (���) (� ������)
	*. ������ height. (���) (� ������)
	
	������������:
	*. ��� ����������, ����� ��������� ������������� �� ��������� 10 �� 20.
	*. � ����� ���������� s. ��������� ������������� �� ��������� s �� s.
	*. � ����� �����������.
	
	������:
	*. ���������� true, ���� ������������� �������� ���������.
	*. ���������� ������� ��������������.
	*. ���������� �������� ��������������.
	
	����� ������� cout �������� �������������.
	
	���������:
	1.1. ������� ������ ��������������� � ���������� ��������� � ��������� [1,3]:[1,3].
	1.2. ������� �� ����� ��� ��������������.
	1.3. ������� ������ ��������.
	1.4. ������� ������ �� ��������������, ������� ������� ������ 4.
	1.5. ��������� ����� ���������� ���� ���������������.
	*/

	struct Rectangle
	{
		int width; //������
		int height; //������

		//----------������������----------
		Rectangle()
		{
			width = 10;
			height = 20;
		}
		Rectangle(int s)
		{
			width = s;
			height = s;
		}
		Rectangle(int width_, int height_)
		{
			width = width_;
			height = height_;
		}
	
		//------------������--------------
		bool is_rectangle_square()
		{
			return width == height;
		}
		int area_of_rectangle()
		{
			return width * height;
		}
		int perimeter_of_rectangle()
		{
			return 2 * (width + height);
		}
		//������ �� �������������� �������, ������� ������� �� ������
		void rect_to_square()
		{
			if (width < height)
			{
				height = width;
			}
			else
			{
				width = height;
			}
		}
	};

	ostream& operator<<(ostream& os, Rectangle r)
	{
		os << "Height: " <<r.height << ", " << "Width: " << r.width;
		return os;
	}





















}