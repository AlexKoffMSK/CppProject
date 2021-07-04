#pragma once
#include <iostream>

namespace DataStructures
{
	struct BinarySearchTreeElemMap
	{
		int _key = 0;
		int _value = 0;
		BinarySearchTreeElemMap* _p_left;
		BinarySearchTreeElemMap* _p_right;
		BinarySearchTreeElemMap* _p_parent;

		BinarySearchTreeElemMap(int key_, int value_)
		{
			_key = key_;
			_value = value_;
			_p_left = nullptr;
			_p_right = nullptr;
			_p_parent = nullptr;
		}

		void Add(int key, int value)
		{
			if (key < _key)
			{
				if (_p_left == nullptr)
				{
					_p_left = new BinarySearchTreeElemMap(key, value);
					_p_left->_p_parent = this; //это указатель на объект для которого был вызван текущий метод (в данном случае Add)
				}
				else
				{
					_p_left->Add(key, value);
				}
			}
			else if (key > _key)
			{
				if (_p_right == nullptr)
				{
					_p_right = new BinarySearchTreeElemMap(key, value);
					_p_right->_p_parent = this; //это указатель на объект для которого был вызван текущий метод (в данном случае Add)
				}
				else
				{
					_p_right->Add(key, value);
				}
			}
		}

		void Print(std::string offset, std::string prefix)
		{
			if (_p_right != nullptr)
			{
				_p_right->Print(offset + "         ", "Right: ");
			}
			else
			{
				std::cout << "         " << offset << "Right: " << " Nullptr" << std::endl;
			}

			std::cout << offset << "        /" << std::endl;
			std::cout << offset << prefix << _key << "," << _value << std::endl;
			std::cout << offset << "        \\" << std::endl;

			if (_p_left != nullptr)
			{
				_p_left->Print(offset + "         ", " Left: ");
			}
			else
			{
				std::cout << "         " << offset << " Left: " << " Nullptr" << std::endl;
			}
		}

		bool IsElemExist(int key)
		{
			if (_key == key)
			{
				return true;
			}
			
			if (key < _key)
			{
				if (_p_left != nullptr)
				{
					return _p_left->IsElemExist(key);
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (_p_right != nullptr)
				{
					return _p_right->IsElemExist(key);
				}
				else
				{
					return false;
				}
			}
		}

		BinarySearchTreeElemMap* FindElem(int key)
		{
			if (key == _key)
			{
				return this;
			}
			
			if (key < _key)
			{
				if (_p_left != nullptr)
				{
					return _p_left->FindElem(key);
				}
				else
				{
					return nullptr;
				}
			}
			else
			{
				if (_p_right != nullptr)
				{
					return _p_right->FindElem(key);
				}
				else
				{
					return nullptr;
				}
			}
		}

		int Root0Left1Right2()
		{
			if (_p_parent == nullptr)
			{
				return 0;
			}
			if (_p_parent->_p_left == this)
			{
				return 1;
			}
			if (_p_parent->_p_right == this)
			{
				return 2;
			}
		}

		BinarySearchTreeElemMap* FindLowestLeftElem()
		{
			BinarySearchTreeElemMap* cur_ptr = this;

			while (cur_ptr->_p_left != nullptr)
			{
				cur_ptr = cur_ptr->_p_left;
			}
			return cur_ptr;
		}
	};
	
	class BinarySearchTreeMap
	{
		BinarySearchTreeElemMap* _root;
		
	public:

		BinarySearchTreeMap()
		{
			_root = nullptr;
		}

		void Add(int key, int value)
		{
			if (_root == nullptr)
			{
				_root = new BinarySearchTreeElemMap(key, value);
			}
			else
			{
				_root->Add(key, value);
			}
		}

		void Print()
		{
			std::cout << "================================" << std::endl;
			if (_root != nullptr)
			{
				_root->Print("", "Root:");
			}
			std::cout << "================================" << std::endl;
		}

		bool IsElemExist(int key)
		{
			if (_root == nullptr)
			{
				return false;
			}
			return _root->IsElemExist(key);
		}

		void Delete(int key)
		{
			BinarySearchTreeElemMap* ptr_to_elem_for_remove = _root->FindElem(key);

			if (ptr_to_elem_for_remove == nullptr)
			{
				return;
			}

			if (ptr_to_elem_for_remove->_p_left == nullptr && ptr_to_elem_for_remove->_p_right == nullptr)
			{
				if (ptr_to_elem_for_remove->Root0Left1Right2() == 0)
				{
					delete ptr_to_elem_for_remove;
					_root = nullptr;
					return;
				}

				if (ptr_to_elem_for_remove->Root0Left1Right2() == 1)
				{
					ptr_to_elem_for_remove->_p_parent->_p_left = nullptr;
					delete ptr_to_elem_for_remove;
					return;
				}
				else
				{
					ptr_to_elem_for_remove->_p_parent->_p_right = nullptr;
					delete ptr_to_elem_for_remove;
					return;
				}
			}

			if (ptr_to_elem_for_remove->_p_left == nullptr && ptr_to_elem_for_remove->_p_right != nullptr)
			{
				if (ptr_to_elem_for_remove->Root0Left1Right2() == 0)
				{
					_root = ptr_to_elem_for_remove->_p_right;
					_root->_p_parent = nullptr;
					delete ptr_to_elem_for_remove;
					return;
				}
				if (ptr_to_elem_for_remove->Root0Left1Right2() == 1)
				{
					ptr_to_elem_for_remove->_p_right->_p_parent = ptr_to_elem_for_remove->_p_parent;
					ptr_to_elem_for_remove->_p_parent->_p_left = ptr_to_elem_for_remove->_p_right;
					//ptr_to_elem_for_remove->_p_parent = nullptr; - делать не нужно, т.к. удалится вместе с элементом, чьим полем указатель является
					//ptr_to_elem_for_remove->_p_right = nullptr;
					delete ptr_to_elem_for_remove;
					return;
				}
				if (ptr_to_elem_for_remove->Root0Left1Right2() == 2)
				{
					ptr_to_elem_for_remove->_p_right->_p_parent = ptr_to_elem_for_remove->_p_parent;
					ptr_to_elem_for_remove->_p_parent->_p_right = ptr_to_elem_for_remove->_p_right;
					delete ptr_to_elem_for_remove;
					return;
				}
			}

			if (ptr_to_elem_for_remove->_p_left != nullptr && ptr_to_elem_for_remove->_p_right == nullptr)
			{
				if (ptr_to_elem_for_remove->Root0Left1Right2() == 0)
				{
					_root = ptr_to_elem_for_remove->_p_left;
					_root->_p_parent = nullptr;
					delete ptr_to_elem_for_remove;
					return;
				}

				if (ptr_to_elem_for_remove->Root0Left1Right2() == 1)
				{
					ptr_to_elem_for_remove->_p_left->_p_parent = ptr_to_elem_for_remove->_p_parent;
					ptr_to_elem_for_remove->_p_parent->_p_left = ptr_to_elem_for_remove->_p_left;
					//ptr_to_elem_for_remove->_p_parent = nullptr; - делать не нужно, т.к. удалится вместе с элементом, чьим полем указатель является
					//ptr_to_elem_for_remove->_p_right = nullptr;
					delete ptr_to_elem_for_remove;
					return;
				}

				if (ptr_to_elem_for_remove->Root0Left1Right2() == 2)
				{
					ptr_to_elem_for_remove->_p_left->_p_parent = ptr_to_elem_for_remove->_p_parent;
					ptr_to_elem_for_remove->_p_parent->_p_right = ptr_to_elem_for_remove->_p_left;
					delete ptr_to_elem_for_remove;
					return;
				}
			}

			if (ptr_to_elem_for_remove->_p_left != nullptr && ptr_to_elem_for_remove->_p_right != nullptr)
			{
				ptr_to_elem_for_remove->_p_left->_p_parent = ptr_to_elem_for_remove->_p_right->FindLowestLeftElem(); //важен порядок строк. Эта должна быть первой
				ptr_to_elem_for_remove->_p_right->FindLowestLeftElem()->_p_left = ptr_to_elem_for_remove->_p_left;
				//ptr_to_elem_for_remove->_p_left->_p_parent->_p_left = ptr_to_elem_for_remove->_p_left;
				
				if (ptr_to_elem_for_remove->Root0Left1Right2() == 0)
				{
					_root = ptr_to_elem_for_remove->_p_right;
					_root->_p_parent = nullptr;
					delete ptr_to_elem_for_remove;
					return;
				}
				if (ptr_to_elem_for_remove->Root0Left1Right2() == 1)
				{
					ptr_to_elem_for_remove->_p_right->_p_parent = ptr_to_elem_for_remove->_p_parent;
					ptr_to_elem_for_remove->_p_parent->_p_left = ptr_to_elem_for_remove->_p_right;
					//ptr_to_elem_for_remove->_p_parent = nullptr; - делать не нужно, т.к. удалится вместе с элементом, чьим полем указатель является
					//ptr_to_elem_for_remove->_p_right = nullptr;
					delete ptr_to_elem_for_remove;
					return;
				}
				if (ptr_to_elem_for_remove->Root0Left1Right2() == 2)
				{
					ptr_to_elem_for_remove->_p_right->_p_parent = ptr_to_elem_for_remove->_p_parent;
					ptr_to_elem_for_remove->_p_parent->_p_right = ptr_to_elem_for_remove->_p_right;
					delete ptr_to_elem_for_remove;
					return;
				}
			}
		}

		bool IsTreeEmpty()
		{
			if (_root == nullptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		int GetRootValue()
		{
			if (_root != nullptr)
			{
				return _root->_value;
			}
			else
			{
				return 0;
			}
		}

		int GetRootKey()
		{
			if (_root != nullptr)
			{
				return _root->_key;
			}
			else
			{
				return 0;
			}
		}

		int GetValueByKey(int key)
		{
			if (_root->FindElem(key) != nullptr)
			{
				return _root->FindElem(key)->_value;
			}
			else
			{
				return 0;
			}

		}

		void UpdateValueByKey(int key, int new_value)
		{
			//если элемента в дереве нет - создаст, если есть - изменит
			BinarySearchTreeElemMap* tmp_ptr = _root->FindElem(key);
			
			if (tmp_ptr != nullptr)
			{
				tmp_ptr->_value = new_value;
			}
			else
			{
				_root->Add(key, new_value);
			}
		}
	};

	void BinarySearchTreeMapTest1()
	{
		BinarySearchTreeMap bst;
		bst.Add(6,106);
		bst.Add(10,110);
		bst.Add(12,112);
		bst.Add(2,102);
		bst.Print();
		//std::cout << bst.IsElemExist(10) << std::endl;
		bst.Add(4,104);
		bst.Add(8,108);
		bst.Print();
		bst.Add(3,103);
		bst.Add(5,105);
		bst.Add(1,101);
		bst.Print();
		while (bst.IsTreeEmpty() == false)
		{
			bst.Delete(bst.GetRootKey());
			bst.Print();
		}
	}

	void BinarySearchTreeMapTest2()
	{
		BinarySearchTreeMap bst;
		bst.Add(1, 101);
		bst.Add(6, 106);
		bst.Add(7, 107);
		bst.Add(12, 112);
		for (int i = 0; i < 30; i++)
		{
			std::cout << bst.GetValueByKey(i) << std::endl;
		}
	}

	void BinarySearchTreeMapTest()
	{
		const int n = 30;
		int arr[n];

		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 10;
			std::cout << arr[i] << ' ';
		}
		std::cout << std::endl;

		BinarySearchTreeMap map;

		for (int i = 0; i < n; i++)
		{
			//смотрим есть ли в мапе ключ arr[i]. если нет - добавляем в мапу со значением 1, если есть - увеличиваем это значение на 1
			if (map.IsElemExist(arr[i]) == false)
			{
				map.Add(arr[i], 1);
			}
			else
			{
				map.UpdateValueByKey(arr[i],map.GetValueByKey(arr[i])+1);
			}
		}
		map.Print();

	}
}