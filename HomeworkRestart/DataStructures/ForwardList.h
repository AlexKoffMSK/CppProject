#pragma once
#include <iostream>

namespace DataStructures
{
	struct ForwardListElem
	{
		int _value;
		ForwardListElem* _ptr_to_next_elem;

		ForwardListElem(int num_)
		{
			_value = num_;
			//в созданном новом элементе присвоено значение num
			_ptr_to_next_elem = nullptr;
			//указатель у нового созданного элемента на следующий - nullptr
		}
	};

	class ForwardList
	{
		ForwardListElem* _ptr_to_start = nullptr;
		int _size = 0;
	
	private:
		ForwardListElem* GetBackElem()
		{
			ForwardListElem* cur_ptr = _ptr_to_start;
			while (cur_ptr->_ptr_to_next_elem != nullptr)
			{
				cur_ptr = cur_ptr->_ptr_to_next_elem; 
			}
			//cur_ptr после выхода из while стоит в конце существующего списка, на последнем элементе
			return cur_ptr;
		}

		ForwardListElem* GetElemByPos(int position)
		{
			ForwardListElem* cur_ptr = _ptr_to_start;
			int cur_elem_pos = 0;
			while (cur_elem_pos != position)
			{
				cur_ptr = cur_ptr->_ptr_to_next_elem;
				cur_elem_pos++;
			}
			return cur_ptr;
		}

	public:
		void PushBack(int num)
		{
			_size++;
			if (_ptr_to_start == nullptr) //это означает, что список пустой
			{
				_ptr_to_start = new ForwardListElem(num);
				//в пустом списке создали новый элемент и сказали, что стартовый теперь смотрит на него
				return;
			}

			// попадаем сюда если список не пустой
			// тогда создаём дублирующий указатель на начало и ищем конец через него
			ForwardListElem* back_ptr = GetBackElem();
			back_ptr->_ptr_to_next_elem=new ForwardListElem(num);
		}

		void PushFront(int num)
		{
			_size++;
			ForwardListElem* new_ptr_to_start = new ForwardListElem(num);
			new_ptr_to_start->_ptr_to_next_elem = _ptr_to_start;
			_ptr_to_start = new_ptr_to_start;
		}

		void InsertAfter(int position, int num)
		{
			_size++;
			//принимаем как данность, что стартовый элемент нулевой. 
			//Если мы указываем position 0, то значит мы вставляем элемент после стартового

			ForwardListElem* cur_ptr = GetElemByPos(position);
			ForwardListElem* new_elem = new ForwardListElem(num);
			new_elem->_ptr_to_next_elem = cur_ptr->_ptr_to_next_elem;
			cur_ptr->_ptr_to_next_elem = new_elem;
		}

		void PopBack()
		{
			
			if (_ptr_to_start == nullptr)
			{
				return;
			}
			
			_size--;
			if (_ptr_to_start->_ptr_to_next_elem == nullptr)
			{
				delete _ptr_to_start; //сносит дом
				_ptr_to_start = nullptr; //затирает бумажку
				return;
			}
			
			ForwardListElem* cur_ptr = _ptr_to_start;
			while (cur_ptr->_ptr_to_next_elem->_ptr_to_next_elem != nullptr)
			{
				cur_ptr = cur_ptr->_ptr_to_next_elem;
			}
			delete cur_ptr->_ptr_to_next_elem;
			cur_ptr->_ptr_to_next_elem = nullptr;
		}

		void PopFront()
		{
			if (_ptr_to_start == nullptr)
			{
				return;
			}
			_size--;
			ForwardListElem* new_start = _ptr_to_start->_ptr_to_next_elem;
			delete _ptr_to_start;
			_ptr_to_start = new_start;
		}

		void Erase(int position)
		{
			if (_ptr_to_start == nullptr)
			{
				return;
			}
			if (position == 0)
			{
				PopFront();
				return;
			}
			_size--;
			ForwardListElem* cur_ptr = GetElemByPos(position-1);
			ForwardListElem* ptr_to_delete = cur_ptr->_ptr_to_next_elem;
			cur_ptr->_ptr_to_next_elem = cur_ptr->_ptr_to_next_elem->_ptr_to_next_elem;
			delete ptr_to_delete;
		}

		int GetValueByPosition(int position)
		{
			ForwardListElem* cur_ptr = GetElemByPos(position);
			return cur_ptr->_value;
		}

		int Get_size()
		{
			return _size;
		}

		void Print()
		{
			std::cout << '[' << _size << "] ";
			std::cout << "start -> ";
			ForwardListElem* cur_ptr = _ptr_to_start;
			while (cur_ptr != nullptr)
			{
				std::cout << cur_ptr->_value << " -> ";
				cur_ptr = cur_ptr->_ptr_to_next_elem;
			}
			std::cout << " nullptr" << std::endl;
			
		}

		void MergeListToBack(ForwardList* f_list)
		{
			ForwardListElem* ptr_to_back = GetBackElem();
			ptr_to_back->_ptr_to_next_elem = f_list->_ptr_to_start;
			f_list->_ptr_to_start = nullptr;
			_size += f_list->_size;
			f_list->_size = 0;
		}
	};

	void TestForwardList1()
	{
		ForwardList f_list;
		
		f_list.Print();
		f_list.PushBack(4);
		f_list.Print();
		f_list.PushBack(5);
		f_list.Print();
		f_list.PushBack(6);
		f_list.Print();
		
		f_list.PushFront(1);
		f_list.Print();
		f_list.PushFront(2);
		f_list.Print();
		f_list.PushFront(3);
		f_list.Print();
		
		f_list.InsertAfter(2, 97);
		f_list.Print();
		f_list.InsertAfter(4, 98);
		f_list.Print();

		f_list.PopBack();
		f_list.Print();
		f_list.PopBack();
		f_list.Print();
		
		f_list.PopFront();
		f_list.Print();
		
		f_list.Erase(3);
		f_list.Print();
		
		f_list.Erase(1);
		f_list.Print();

	}

	void TestForwardList2()
	{
		ForwardList f_list;
		
		f_list.PushBack(4);
		f_list.Print();
		
		f_list.PopBack();
		f_list.Print();
	}

	void TestForwardList3()
	{
		ForwardList f_list;
		
		for (int i = 0; i < 1000; i++)
		{
			int rnd_a = rand() % 6;

			if (rnd_a == 0)
			{
				f_list.PushBack(rand() % 10);
			}
			if (rnd_a == 1)
			{
				f_list.PushFront(rand() % 10);
			}
			if (rnd_a == 2)
			{
				f_list.PopBack();
			}
			if (rnd_a == 3)
			{
				f_list.PopFront();
			}
			if (rnd_a == 4)
			{
				if (f_list.Get_size() != 0)
				{
					f_list.InsertAfter(rand() % f_list.Get_size(), rand() % 10);
				}
			}
			if (rnd_a == 5)
			{
				if (f_list.Get_size() != 0)
				{
					f_list.Erase(rand() % f_list.Get_size());
				}
			}
			f_list.Print();
		}
	}

	void TestForwardList4()
	{
		ForwardList f_list;
		for (int i = 0; i < 10; i++)
		{
			f_list.PushBack(rand() % 10);
		}
		f_list.Print();
		//найти наибольший элемент списка

		int cur_max = f_list.GetValueByPosition(0);
		for (int i = 1; i < 10; i++)
		{
			if (f_list.GetValueByPosition(i) > cur_max)
			{
				cur_max = f_list.GetValueByPosition(i);
			}
		}
		std::cout << cur_max << std::endl;
	}

	void TestForwardList5()
	{
		ForwardList f_list;
		f_list.PushBack(1);
		f_list.PushBack(2);
		f_list.PushBack(3);
		f_list.Print();
		
		ForwardList f_list_1;
		f_list_1.PushBack(4);
		f_list_1.PushBack(5);
		f_list_1.Print();

		f_list.MergeListToBack(&f_list_1);
		f_list.Print();
		f_list_1.Print();
	}
	//создать список из вектора
}