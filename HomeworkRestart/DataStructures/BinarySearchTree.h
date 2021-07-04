#pragma once
#include <iostream>

namespace DataStructures
{
	struct BinarySearchTreeElem
	{
		int _value = 0;
		BinarySearchTreeElem* _p_left;
		BinarySearchTreeElem* _p_right;
		BinarySearchTreeElem* _p_parent;

		BinarySearchTreeElem(int num_)
		{
			_value = num_;
			_p_left = nullptr;
			_p_right = nullptr;
			_p_parent = nullptr;
		}

		void Add(int num)
		{
			if (num < _value)
			{
				if (_p_left == nullptr)
				{
					_p_left = new BinarySearchTreeElem(num);
					_p_left->_p_parent = this; //это указатель на объект для которого был вызван текущий метод (в данном случае Add)
				}
				else
				{
					_p_left->Add(num);
				}
			}
			else if (num > _value)
			{
				if (_p_right == nullptr)
				{
					_p_right = new BinarySearchTreeElem(num);
					_p_right->_p_parent = this; //это указатель на объект для которого был вызван текущий метод (в данном случае Add)
				}
				else
				{
					_p_right->Add(num);
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
			std::cout << offset << prefix << _value << std::endl;
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

		bool IsElemExist(int num)
		{
			if (_value == num)
			{
				return true;
			}
			
			if (num < _value)
			{
				if (_p_left != nullptr)
				{
					return _p_left->IsElemExist(num);
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
					return _p_right->IsElemExist(num);
				}
				else
				{
					return false;
				}
			}
		}

		BinarySearchTreeElem* FindElem(int num)
		{
			if (num == _value)
			{
				return this;
			}
			
			if (num < _value)
			{
				if (_p_left != nullptr)
				{
					return _p_left->FindElem(num);
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
					return _p_right->FindElem(num);
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

		BinarySearchTreeElem* FindLowestLeftElem()
		{
			BinarySearchTreeElem* cur_ptr = this;

			while (cur_ptr->_p_left != nullptr)
			{
				cur_ptr = cur_ptr->_p_left;
			}
			return cur_ptr;
		}
	};
	
	class BinarySearchTree
	{
		BinarySearchTreeElem* _root;
		
	public:

		BinarySearchTree()
		{
			_root = nullptr;
		}

		void Add(int num)
		{
			if (_root == nullptr)
			{
				_root = new BinarySearchTreeElem(num);
			}
			else
			{
				_root->Add(num);
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

		bool IsElemExist(int num)
		{
			if (_root == nullptr)
			{
				return false;
			}
			return _root->IsElemExist(num);
		}

		void Delete(int num)
		{
			BinarySearchTreeElem* ptr_to_elem_for_remove = _root->FindElem(num);

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
	};

	void BinarySearchTreeTest11()
	{
		BinarySearchTree bst;
		bst.Add(6);
		bst.Add(10);
		bst.Add(12);
		bst.Add(2);
		bst.Print();
		//std::cout << bst.IsElemExist(10) << std::endl;
		bst.Add(4);
		bst.Add(8);
		bst.Print();
		bst.Add(3);
		bst.Add(5);
		bst.Add(1);
		bst.Print();
		while (bst.IsTreeEmpty() == false)
		{
			bst.Delete(bst.GetRootValue());
			bst.Print();
		}
	}

	void BinarySearchTreeTest()
	{
		BinarySearchTree bst;
		
		int a = 0;
		
		while (true)
		{

		std::cin >> a;
		
		for (int i = 0; i < a; i++)
		{
			bst.Add(rand()%1000);
		}
		bst.Print();
		getchar();
		while (bst.IsTreeEmpty() == false)
		{
			bst.Delete(bst.GetRootValue());
			bst.Print();
		}
		}

	}



































}