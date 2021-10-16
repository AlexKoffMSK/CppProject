#pragma once
#include <iostream>

namespace DataStructures
{
	struct ListElem // это элемент в контейнере
	{
		int _value;
		ListElem* _ptr_to_next_elem;
		ListElem* _ptr_to_prev_elem;

		ListElem(int num_)
		{
			_value = num_;
			//в созданном новом элементе присвоено значение num
			_ptr_to_next_elem = nullptr;
			//указатель у нового созданного элемента на следующий - nullptr
			_ptr_to_prev_elem = nullptr;
			//указатель у нового созданного элемента на предыдущий - nullptr
		}
	};

	class List //это контейнер в целом
	{
		ListElem* _ptr_to_front_elem = nullptr;
		ListElem* _ptr_to_back_elem = nullptr;
		int _size = 0;

	public:

		void PushBack(int num)
		{
			_size++;
			if (_ptr_to_back_elem == nullptr)
			{
				ListElem* new_ptr = new ListElem(num);
				_ptr_to_front_elem = new_ptr;
				_ptr_to_back_elem = new_ptr;
				return;
			}
			
			_ptr_to_back_elem->_ptr_to_next_elem = new ListElem(num);
			_ptr_to_back_elem->_ptr_to_next_elem->_ptr_to_prev_elem = _ptr_to_back_elem;
			_ptr_to_back_elem = _ptr_to_back_elem->_ptr_to_next_elem;
		}

		void PushFront(int num)
		{
			_size++;
			if (_ptr_to_back_elem == nullptr)
			{
				ListElem* new_ptr = new ListElem(num);
				_ptr_to_front_elem = new_ptr;
				_ptr_to_back_elem = new_ptr;
				return;
			}
			ListElem* new_ptr = new ListElem(num);
			new_ptr->_ptr_to_next_elem = _ptr_to_front_elem;
			new_ptr->_ptr_to_next_elem->_ptr_to_prev_elem = new_ptr;
			//_ptr_to_front_elem->_ptr_to_prev_elem = new_ptr; //аналогичная запись строки выше
			_ptr_to_front_elem = new_ptr;
			
		}

		void InsertAfter(int position, int num)
		{
			if (position == _size-1)
			{
				PushBack(num);
				return;
			}

			_size++;
			if (_ptr_to_front_elem == nullptr)
			{
				ListElem* new_ptr = new ListElem(num);
				_ptr_to_front_elem = new_ptr;
				_ptr_to_back_elem = new_ptr;
				return;
			}

			ListElem* temp_ptr = _ptr_to_front_elem;

			for (int i = 0; i < position; i++)
			{
				temp_ptr = temp_ptr->_ptr_to_next_elem;
			}

			ListElem* new_ptr = new ListElem(num);
			new_ptr->_ptr_to_prev_elem = temp_ptr;
			temp_ptr->_ptr_to_next_elem->_ptr_to_prev_elem = new_ptr;
			new_ptr->_ptr_to_next_elem = temp_ptr->_ptr_to_next_elem;
			//temp_ptr->_ptr_to_next_elem = new_ptr;
			new_ptr->_ptr_to_prev_elem->_ptr_to_next_elem = new_ptr;
		}

		void PopBack()
		{
			if (_ptr_to_back_elem == nullptr)
			{
				return;
			}

			_size--;

			//==================если один элемент==========//

			if (_ptr_to_front_elem->_ptr_to_next_elem == nullptr) //или _size == 1
			{
				delete _ptr_to_front_elem;
				_ptr_to_front_elem = nullptr;
				_ptr_to_back_elem = nullptr;
				return;
			}

			//==================если больше чем один элемент==========//

			//_ptr_to_back_elem->_ptr_to_prev_elem->_ptr_to_next_elem = nullptr;
			//ListElem* temp_ptr = _ptr_to_back_elem;
			//_ptr_to_back_elem = _ptr_to_back_elem->_ptr_to_prev_elem;
			//delete temp_ptr;
			
			_ptr_to_back_elem = _ptr_to_back_elem->_ptr_to_prev_elem;
			delete _ptr_to_back_elem->_ptr_to_next_elem;
			_ptr_to_back_elem->_ptr_to_next_elem = nullptr;
		}

		void PopFront()
		{
			if (_ptr_to_front_elem == nullptr)
			{
				return;
			}

			_size--;

			//==================если один элемент==========//

			if (_ptr_to_front_elem->_ptr_to_next_elem == nullptr) //или _size == 1
			{
				delete _ptr_to_front_elem;
				_ptr_to_front_elem = nullptr;
				_ptr_to_back_elem = nullptr;
				return;
			}

			//==================если больше чем один элемент==========//

			_ptr_to_front_elem = _ptr_to_front_elem->_ptr_to_next_elem;
			delete _ptr_to_front_elem->_ptr_to_prev_elem;
			_ptr_to_front_elem->_ptr_to_prev_elem = nullptr;
		}

		void Erase(int position)
		{
			if (_ptr_to_front_elem == nullptr)
			{
				return;
			}

			if (position == 0)
			{
				PopFront();
				return;
			}
			_size--;

			ListElem* temp_ptr = _ptr_to_front_elem; //!!СМОТРИТ ТУДА ЖЕ, КУДА И... в данном случае - куда смотрит указатель _ptr_to_front_elem
			for (int i = 0; i < position; i++)
			{
				temp_ptr = temp_ptr->_ptr_to_next_elem;
			}

			temp_ptr->_ptr_to_prev_elem->_ptr_to_next_elem = temp_ptr->_ptr_to_next_elem;
			temp_ptr->_ptr_to_next_elem->_ptr_to_prev_elem = temp_ptr->_ptr_to_prev_elem;
			delete temp_ptr; //после этой строки - мы отдаем системе память ту, куда смотрит tmp_ptr
		}

		int GetValueByPos(int position)
		{
			ListElem* temp_ptr = _ptr_to_front_elem;
			for (int i = 0; i < position; i++)
			{
				temp_ptr = temp_ptr->_ptr_to_next_elem;
			}
			return temp_ptr->_value;
		}

		void MergeListToBack(List* list_to_merge_with)
		{
			_ptr_to_back_elem->_ptr_to_next_elem = list_to_merge_with->_ptr_to_front_elem;
			list_to_merge_with->_ptr_to_front_elem->_ptr_to_prev_elem = _ptr_to_back_elem;

			_ptr_to_back_elem = list_to_merge_with->_ptr_to_back_elem;
			list_to_merge_with->_ptr_to_back_elem = nullptr;
			list_to_merge_with->_ptr_to_front_elem = nullptr;

			_size += list_to_merge_with->_size;
			list_to_merge_with->_size = 0;
		}

		void Print()
		{
			ListElem* tmp_ptr = _ptr_to_front_elem;
			
			std::cout << '[' << _size << "] ";
			std::cout << "nullptr <-> ";
			
			while (tmp_ptr != nullptr)
			{
				std::cout << tmp_ptr->_value << " <-> ";
				tmp_ptr = tmp_ptr->_ptr_to_next_elem;
			}
			std::cout << "nullptr" << std::endl;
		}
	};

	void TestList1()
	{
		List list;
		list.PushBack(1);
		list.PushBack(2);
		list.PushBack(3);
		list.PushBack(4);
		list.Print();

		list.PushFront(5);
		list.PushFront(6);
		list.PushFront(7);
		list.Print();

		list.InsertAfter(6, 99);
		list.InsertAfter(3, 99);
		list.InsertAfter(0, 99);
		list.Print();
		
		list.PopBack();
		list.Print();
		list.PopBack();
		list.Print();
		list.PopBack();
		list.Print();

		list.PopFront();
		list.Print();
		list.PopFront();
		list.Print();
		list.PopFront();
		list.Print();

		list.Erase(1);
		list.Print();
		
		list.InsertAfter(1, 999);
		list.InsertAfter(2, 998);
		list.InsertAfter(0, 997);
		list.Print();

		cout << list.GetValueByPos(0) << endl;

		List list1;
		list1.PushBack(888);
		list1.PushBack(889);
		list1.PushBack(890);
		list1.Print();

		list.MergeListToBack(&list1);
		list.Print();
	}
}