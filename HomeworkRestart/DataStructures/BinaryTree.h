#pragma once
#include <iostream>
#include <queue>
#include <stack>

namespace DataStructures
{
	struct BinaryTreeElem
	{
		int _value = 0;
		BinaryTreeElem* _ptr_to_left_child;
		BinaryTreeElem* _ptr_to_right_child;
		BinaryTreeElem* _ptr_to_parent;

		BinaryTreeElem(int num)
		{
			_value = num;
			_ptr_to_left_child = nullptr;
			_ptr_to_right_child = nullptr;
			_ptr_to_parent = nullptr;
		}

		int GetDepth() //сколько под ним
		{
			int depth_left = -1; //-1 если глубина потомства без учёта себя самого
			if (_ptr_to_left_child != nullptr)
			{
				depth_left = _ptr_to_left_child->GetDepth();
			}
			
			int depth_right = -1; //-1 если глубина потомства без учёта себя самого
			if (_ptr_to_right_child != nullptr)
			{
				depth_right = _ptr_to_right_child->GetDepth();
			}
			return max(depth_left, depth_right) + 1;
		}

		int GetLevelFromRoot() //сколько над ним
		{
			if (_ptr_to_parent == nullptr)
			{
				return 0;
			}
			return _ptr_to_parent->GetLevelFromRoot()+1;
		}
	};

	int BinaryTreeSummElems(BinaryTreeElem* ptr_to_elem)
	{
		int summ_left_elems = 0;
		int summ_right_elems = 0;
		
		if (ptr_to_elem->_ptr_to_left_child != nullptr)
		{
			summ_left_elems = BinaryTreeSummElems(ptr_to_elem->_ptr_to_left_child);
		}

		if (ptr_to_elem->_ptr_to_right_child != nullptr)
		{
			summ_right_elems = BinaryTreeSummElems(ptr_to_elem->_ptr_to_right_child);
		}

		return summ_left_elems+summ_right_elems+ptr_to_elem->_value;
	}

	int BinaryMaxElemFromTree(BinaryTreeElem* ptr_to_elem)
	{
		int max_of_left_elems = 0;
		int max_of_right_elems = 0;

		if (ptr_to_elem->_ptr_to_left_child != nullptr)
		{
			max_of_left_elems = BinaryMaxElemFromTree(ptr_to_elem->_ptr_to_left_child);
		}

		if (ptr_to_elem->_ptr_to_right_child != nullptr)
		{
			max_of_right_elems = BinaryMaxElemFromTree(ptr_to_elem->_ptr_to_right_child);
		}

		return max(max(max_of_left_elems,max_of_right_elems),ptr_to_elem->_value);
	}

	void Print_1_level(BinaryTreeElem* ptr_to_elem)
	{
		//(condition ? action : action_if_condition_false)
		if (ptr_to_elem == nullptr)
		{
			std::cout << "Nullptr" << std::endl;
			return;
		}
		std::cout << ptr_to_elem->_value << std::endl;

		std::cout << "Left: ";
		if (ptr_to_elem->_ptr_to_left_child == nullptr)
		{
			std::cout << "Nullptr" << std::endl;
		}
		else
		{
			std::cout << ptr_to_elem->_ptr_to_left_child->_value << std::endl;
		}

		std::cout << "Right: ";
		if (ptr_to_elem->_ptr_to_right_child == nullptr)
		{
			std::cout << "Nullptr" << std::endl;
		}
		else
		{
			std::cout << ptr_to_elem->_ptr_to_right_child->_value << std::endl;
		}
		std::cout << std::endl;
	}

	void Print_1(BinaryTreeElem* ptr_to_elem, string offset)
	{
		//(condition ? action : action_if_condition_false)
		if (ptr_to_elem == nullptr)
		{
			std::cout << "Nullptr" << std::endl;
			return;
		}
		std::cout << ptr_to_elem->_value << std::endl;

		std::cout << offset << "Left: ";
		Print_1(ptr_to_elem->_ptr_to_left_child, offset+"   ");

		std::cout << offset << "Right: ";
		Print_1(ptr_to_elem->_ptr_to_right_child, offset + "   ");
		std::cout << std::endl;
	}

	void Print_2(BinaryTreeElem* ptr_to_elem, string offset)
	{
		//(condition ? action : action_if_condition_false)
		if (ptr_to_elem == nullptr)
		{
			std::cout << offset << "Nullptr" << std::endl;
			return;
		}
		//std::cout << offset << "Right: ";
		Print_2(ptr_to_elem->_ptr_to_right_child, offset + "      ");

		std::cout << offset << " /" << std::endl;

		std::cout << offset << ptr_to_elem->_value << std::endl;

		std::cout << offset << " \\" << std::endl;

		//std::cout << offset << "Left: ";
		Print_2(ptr_to_elem->_ptr_to_left_child, offset + "      ");

		//std::cout << std::endl;
	}

	void Print(BinaryTreeElem* ptr_to_elem, string offset, string prefix)
	{
		if (ptr_to_elem == nullptr)
		{
			std::cout << offset << "Nullptr" << std::endl;
			return;
		}
		Print(ptr_to_elem->_ptr_to_right_child, offset + "         ", "Right: ");

		std::cout << offset << "        /" << std::endl;

		//std::cout << offset << prefix << ptr_to_elem->_value << " [Depth: " << ptr_to_elem->GetDepth() << ", Level from root: " << ptr_to_elem->GetLevelFromRoot() << "]" << std::endl;
		//std::cout << offset << prefix << ptr_to_elem->_value << " [" << ptr_to_elem->GetDepth() << ", " << ptr_to_elem->GetLevelFromRoot() << "]" << std::endl;
		//std::cout << offset << prefix << ptr_to_elem->_value << " [" << BinaryTreeSummElems(ptr_to_elem) << "]" << std::endl;
		std::cout << offset << prefix << ptr_to_elem->_value << " [" << BinaryMaxElemFromTree(ptr_to_elem) << "]" << std::endl;

		std::cout << offset << "        \\" << std::endl;

		Print(ptr_to_elem->_ptr_to_left_child, offset + "         ", " Left: ");
	}

	void BinaryTreeTest1()
	{
		BinaryTreeElem* root = new BinaryTreeElem(4);
		
		root->_ptr_to_left_child = new BinaryTreeElem(1);
		root->_ptr_to_left_child->_ptr_to_parent = root;

		root->_ptr_to_right_child = new BinaryTreeElem(0);
		root->_ptr_to_right_child->_ptr_to_parent = root;

		root->_ptr_to_left_child->_ptr_to_left_child = new BinaryTreeElem(5);
		root->_ptr_to_left_child->_ptr_to_left_child->_ptr_to_parent = root->_ptr_to_left_child;

		root->_ptr_to_left_child->_ptr_to_right_child = new BinaryTreeElem(10);
		root->_ptr_to_left_child->_ptr_to_right_child->_ptr_to_parent = root->_ptr_to_left_child;

		root->_ptr_to_right_child->_ptr_to_right_child = new BinaryTreeElem(3);
		root->_ptr_to_right_child->_ptr_to_right_child->_ptr_to_parent = root->_ptr_to_right_child;

		Print(root,""," Root: ");
	}

	BinaryTreeElem* GetTree()
	{
		BinaryTreeElem* root = new BinaryTreeElem(4);

		root->_ptr_to_left_child = new BinaryTreeElem(1);
		root->_ptr_to_left_child->_ptr_to_parent = root;

		root->_ptr_to_right_child = new BinaryTreeElem(0);
		root->_ptr_to_right_child->_ptr_to_parent = root;

		root->_ptr_to_left_child->_ptr_to_left_child = new BinaryTreeElem(5);
		root->_ptr_to_left_child->_ptr_to_left_child->_ptr_to_parent = root->_ptr_to_left_child;

		root->_ptr_to_left_child->_ptr_to_right_child = new BinaryTreeElem(10);
		root->_ptr_to_left_child->_ptr_to_right_child->_ptr_to_parent = root->_ptr_to_left_child;

		BinaryTreeElem* ptr_to_10 = root->_ptr_to_left_child->_ptr_to_right_child;
		ptr_to_10->_ptr_to_right_child = new BinaryTreeElem(7);
		ptr_to_10->_ptr_to_right_child->_ptr_to_parent = ptr_to_10;

		root->_ptr_to_right_child->_ptr_to_right_child = new BinaryTreeElem(3);
		root->_ptr_to_right_child->_ptr_to_right_child->_ptr_to_parent = root->_ptr_to_right_child;

		BinaryTreeElem* ptr_to_3 = root->_ptr_to_right_child->_ptr_to_right_child;
		ptr_to_3->_ptr_to_left_child = new BinaryTreeElem(2);
		ptr_to_3->_ptr_to_left_child->_ptr_to_parent = ptr_to_3;

		return root;
	}

	void BinaryTreeTest2()
	{
		Print(GetTree(), "", " Root: ");
	}

	BinaryTreeElem* GetRandomElem(BinaryTreeElem* ptr_to_elem)
	{
		int rnd = rand() % 3;

		if (rnd == 0)
		{
			return ptr_to_elem;
		}
		
		if (rnd == 1)
		{
			if (ptr_to_elem->_ptr_to_left_child == nullptr)
			{
				return ptr_to_elem;
			}
			return GetRandomElem(ptr_to_elem->_ptr_to_left_child);
		}
		if (rnd == 2)
		{
			if (ptr_to_elem->_ptr_to_right_child == nullptr)
			{
				return ptr_to_elem;
			}
			return GetRandomElem(ptr_to_elem->_ptr_to_right_child);
		}
	}

	BinaryTreeElem* GetRandomLeaf(BinaryTreeElem* ptr_to_elem)
	{
		if (ptr_to_elem->_ptr_to_left_child == nullptr && ptr_to_elem->_ptr_to_right_child == nullptr)
		{
			return ptr_to_elem;
		}
		
		int rnd = rand() % 2;

		if (rnd == 0 )
		{
			if (ptr_to_elem->_ptr_to_left_child != nullptr)
			{
				return GetRandomLeaf(ptr_to_elem->_ptr_to_left_child);
			}
			else
			{
				return GetRandomLeaf(ptr_to_elem->_ptr_to_right_child);
			}
		}
		if (rnd == 1)
		{
			if (ptr_to_elem->_ptr_to_right_child != nullptr)
			{
				return GetRandomLeaf(ptr_to_elem->_ptr_to_right_child);
			}
			else
			{
				return GetRandomLeaf(ptr_to_elem->_ptr_to_left_child);
			}
		}
	}

	void BinaryTreeTest3()
	{
		BinaryTreeElem* root = GetTree();
		Print(root, "", " Root: ");

		for (int i = 0; i < 10; i++)
		{
			std::cout << GetRandomElem(root)->_value << ' ';
		}

		std::cout << std::endl;

		for (int i = 0; i < 10; i++)
		{
			std::cout << GetRandomLeaf(root)->_value << ' ';
		}
	}

	BinaryTreeElem* GetRandomTree()
	{
		BinaryTreeElem* random_tree = new BinaryTreeElem(rand() % 100);
		
		int rnd_left = rand() % 2;
		int rnd_right = rand() % 2;

		if (rnd_left == 1)
		{
			BinaryTreeElem* left = GetRandomTree();
			random_tree->_ptr_to_left_child = left;
		}

		if (rnd_right == 1)
		{
			BinaryTreeElem* right = GetRandomTree();
			random_tree->_ptr_to_right_child = right;
		}
		return random_tree;
	}

	BinaryTreeElem* GetRandomTreeWithDepth(int max_depth)
	{
		BinaryTreeElem* random_tree = new BinaryTreeElem(rand() % 100);

		if (max_depth == 0)
		{
			return random_tree;
		}
		
		int rnd_left = rand() % 100;
		int rnd_right = rand() % 100;

		if (rnd_left < 70)
		{
			BinaryTreeElem* left = GetRandomTreeWithDepth(max_depth -1);
			random_tree->_ptr_to_left_child = left;
		}

		if (rnd_right < 70)
		{
			BinaryTreeElem* right = GetRandomTreeWithDepth(max_depth -1);
			random_tree->_ptr_to_right_child = right;
		}
		return random_tree;
	}

	void BinaryTreeTest4()
	{
		BinaryTreeElem* random_tree = GetRandomTreeWithDepth(4);
		Print(random_tree, "", "root:");
	}

	int GetCountOfElemsInTree(BinaryTreeElem* ptr_to_elem)
	{
		if (ptr_to_elem == nullptr)
		{
			std::cout << nullptr << std::endl;
			return 0;
		}
		
		std::cout << "!!! "<<ptr_to_elem->_value << std::endl;

		int count_of_elem_left = GetCountOfElemsInTree(ptr_to_elem->_ptr_to_left_child);
		
		int count_of_elem_right = GetCountOfElemsInTree(ptr_to_elem->_ptr_to_right_child);
		
		std::cout << ptr_to_elem->_value << " countLeft " << count_of_elem_left << " countRight " << count_of_elem_right << std::endl;

		return count_of_elem_left + count_of_elem_right + 1;
	}

	void BinaryTreeTest5()
	{
		BinaryTreeElem* random_tree = GetRandomTreeWithDepth(3);
		Print(random_tree, "", "root:");
		std:: cout << GetCountOfElemsInTree(random_tree);
	}

	int GetCountOfLeafsInTree(BinaryTreeElem* ptr_to_elem)
	{
		if (ptr_to_elem == nullptr)
		{
			std::cout << nullptr << std::endl;
			return 0;
		}

		std::cout << "!!! " << ptr_to_elem->_value << std::endl;

		if (ptr_to_elem->_ptr_to_left_child == nullptr && ptr_to_elem->_ptr_to_right_child == nullptr)
		{
			return 1;
		}
		int count_of_left_leafs = GetCountOfLeafsInTree(ptr_to_elem->_ptr_to_left_child);
		int count_of_right_leafs = GetCountOfLeafsInTree(ptr_to_elem->_ptr_to_right_child);

		std::cout << ptr_to_elem->_value << " countLeft " << count_of_left_leafs << " countRight " << count_of_right_leafs << std::endl;

		return count_of_left_leafs + count_of_right_leafs;
	}

	void BinaryTreeTest6()
	{
		BinaryTreeElem* random_tree = GetRandomTreeWithDepth(3);
		Print(random_tree, "", "root:");
		std::cout << GetCountOfLeafsInTree(random_tree);
	}

	BinaryTreeElem* GetTree1()
	{
		BinaryTreeElem* root = new BinaryTreeElem(0);

		root->_ptr_to_left_child = new BinaryTreeElem(1);
		root->_ptr_to_left_child->_ptr_to_parent = root;

		root->_ptr_to_right_child = new BinaryTreeElem(4);
		root->_ptr_to_right_child->_ptr_to_parent = root;

		root->_ptr_to_left_child->_ptr_to_left_child = new BinaryTreeElem(2);
		root->_ptr_to_left_child->_ptr_to_left_child->_ptr_to_parent = root->_ptr_to_left_child;

		root->_ptr_to_left_child->_ptr_to_right_child = new BinaryTreeElem(3);
		root->_ptr_to_left_child->_ptr_to_right_child->_ptr_to_parent = root->_ptr_to_left_child;

		root->_ptr_to_right_child->_ptr_to_right_child = new BinaryTreeElem(5);
		root->_ptr_to_right_child->_ptr_to_right_child->_ptr_to_parent = root->_ptr_to_right_child;

		BinaryTreeElem* ptr_to_5 = root->_ptr_to_right_child->_ptr_to_right_child;
		ptr_to_5->_ptr_to_left_child = new BinaryTreeElem(6);
		ptr_to_5->_ptr_to_left_child->_ptr_to_parent = ptr_to_5;

		ptr_to_5->_ptr_to_right_child = new BinaryTreeElem(7);
		ptr_to_5->_ptr_to_right_child->_ptr_to_parent = ptr_to_5;

		return root;
	}

	void PrintElemsThroughBreadth(BinaryTreeElem* ptr_to_elem) //breadth - ширина в контексте обхода бинарного дерева
	{
		/*
		0) Добавляем в очередь стартовый элемент
		1) Если очередь пустая - заканчиваем
		2) Берём первый элемент из очереди
		3) Пушим его детей (которые существуют!) в очередь
		4) Принтуем его (первый элемент очереди)
		5) Удаляем элемент из очереди (первый)
		6) Goto1
		Очередь работает по методу FIFO - первый зашедший - первым выходит
		Стэк работает по методку LIFO - последний зашедший - первым входит
		*/

		std::queue<BinaryTreeElem*> q;
		q.push(ptr_to_elem);

		while (q.size() != 0) // пока очередь не пустая - делаем действия! или q.empty - вернет true если пустая очередь
		{
			BinaryTreeElem* front_elem = q.front();

			if (front_elem->_ptr_to_left_child != nullptr)
			{
				q.push(front_elem->_ptr_to_left_child);
			}
			if (front_elem->_ptr_to_right_child != nullptr)
			{
				q.push(front_elem->_ptr_to_right_child);
			}

			std::cout << q.front()->_value << std::endl;

			q.pop();
		}
	}

	void BinaryTreeTest7()
	{
		BinaryTreeElem* random_tree = GetTree1();
		Print(random_tree, "", "root");
		PrintElemsThroughBreadth(random_tree);
	}

	void StdQueueTest()
	{
		std::queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);

		std::cout << q.front() << std::endl; //1
		q.pop();
		std::cout << q.front() << std::endl; //2
		q.push(4);
		q.push(5);
		std::cout << q.front() << std::endl; //2
		q.pop();
		q.pop();
		std::cout << q.front() << std::endl; //4
	}

	void StdQueueTest1()
	{
		BinaryTreeElem* root = GetTree1();

		std::queue<BinaryTreeElem*> q;

		q.push(root); //0
		q.push(root->_ptr_to_left_child); //0 1
		q.push(root->_ptr_to_right_child); //0 1 4

		std::cout << q.front()->_value << std::endl; //0
		
		q.pop(); //0 del, 1 4

		std::cout << q.front()->_value << std::endl; //1

		q.push(q.front()->_ptr_to_left_child); //1 4 2
		q.push(q.front()->_ptr_to_right_child); // 1 4 2 3

		q.pop(); //1 del, 4 2 3
		q.pop(); //4 del, 2 3

		std::cout << q.front()->_value << std::endl; //2
	}

	void StdStackTest()
	{
		std::stack<int> q;
		q.push(1);
		q.push(2);
		q.push(3);

		std::cout << q.top() << std::endl; //3
		q.pop();
		std::cout << q.top() << std::endl; //2
		q.push(4);
		q.push(5);
		std::cout << q.top() << std::endl; //5
		q.pop();
		q.pop();
		std::cout << q.top() << std::endl; //2
	}

	void PrintElemsThroughDepth(BinaryTreeElem* ptr_to_elem) //Depth - глубина в контексте обхода бинарного дерева
	{
		/*
		0) Добавляем в стэк стартовый элемент
		1) Если стэк пустой - заканчиваем
		2) Берём верхний элемент из стэка
		3) если есть левый потомок - добавляем его в стэк и возвращаемся в п.1
		4) если есть правый потомок - добавляем его в стэк и возвращаемся в п.1
		5) принтуем верхний элемент
		6) удаляем его из стэка
		7) goto 1

		Очередь работает по методу FIFO - первый зашедший - первым выходит
		Стэк работает по методку LIFO - последний зашедший - первым входит
		*/

		std::stack<BinaryTreeElem*> s;
		s.push(ptr_to_elem);
		
		while (s.size() != 0) // пока стэк не пустой - делаем действия! или q.empty - вернет true если стэк пустой
		{
			BinaryTreeElem* top_elem = s.top();

			if (top_elem->_ptr_to_left_child != nullptr)
			{
				s.push(top_elem->_ptr_to_left_child);
			}
			if (top_elem->_ptr_to_right_child != nullptr)
			{
				s.push(top_elem->_ptr_to_right_child);
			}

			std::cout << s.top()->_value << std::endl;

			s.pop();
		}
		/*
		s=0
		s=4 1 0
		p 4
		s= 1 0
		s = 3 2 1 0
		p 3
		s= 2 1 0
		p 2
		s= 1 0

		*/

		//НЕДОДЕЛАНО, ВЕРНУТЬСЯ ПОСЛЕ ИЗУЧЕНИЯ ПАР
	}

	void BinaryTreeTest8()
	{
		BinaryTreeElem* random_tree = GetTree1();
		Print(random_tree, "", "root");
		PrintElemsThroughDepth(random_tree);
	}

	void AddElemToBinarySearchTree(BinaryTreeElem* ptr_to_BST, int elem_to_add)
	{
		if (elem_to_add < ptr_to_BST->_value)
		{
			if (ptr_to_BST->_ptr_to_left_child == nullptr)
			{
				ptr_to_BST->_ptr_to_left_child = new BinaryTreeElem(elem_to_add);
				ptr_to_BST->_ptr_to_left_child->_ptr_to_parent = ptr_to_BST;
				return;
			}
			AddElemToBinarySearchTree(ptr_to_BST->_ptr_to_left_child, elem_to_add);
		}
		else if (elem_to_add > ptr_to_BST->_value)
		{
			if (ptr_to_BST->_ptr_to_right_child == nullptr)
			{
				ptr_to_BST->_ptr_to_right_child = new BinaryTreeElem(elem_to_add);
				ptr_to_BST->_ptr_to_right_child->_ptr_to_parent = ptr_to_BST;
				return;
			}
			AddElemToBinarySearchTree(ptr_to_BST->_ptr_to_right_child, elem_to_add);
		}
		else
		{
			return;
		}
	}

	void BinarySearchTreeTest0()
	{
		BinaryTreeElem* root = new BinaryTreeElem(5);
		AddElemToBinarySearchTree(root, 2);
		Print(root, "", "root:");
		std::cout << "==============================" << std::endl;
		AddElemToBinarySearchTree(root, 1);
		Print(root, "", "root:");
		std::cout << "==============================" << std::endl;
		AddElemToBinarySearchTree(root, 8);
		Print(root, "", "root:");
		std::cout << "==============================" << std::endl;
		AddElemToBinarySearchTree(root, 7);
		Print(root, "", "root:");
		std::cout << "==============================" << std::endl;
		AddElemToBinarySearchTree(root, 9);
		Print(root, "", "root:");
		std::cout << "==============================" << std::endl;
		AddElemToBinarySearchTree(root, 3);
		Print(root, "", "root:");
	}

	bool IsElemExistsInBinarySearchTree(BinaryTreeElem* ptr_to_BST, int elem_to_find)
	{
		if (ptr_to_BST == nullptr)
		{
			return false;
		}
		if (ptr_to_BST->_value == elem_to_find)
		{
			return true;
		}
		if (elem_to_find < ptr_to_BST->_value)
		{
			return IsElemExistsInBinarySearchTree(ptr_to_BST->_ptr_to_left_child, elem_to_find);
		}
		else if (elem_to_find > ptr_to_BST->_value)
		{
			return IsElemExistsInBinarySearchTree(ptr_to_BST->_ptr_to_right_child, elem_to_find);
		}
	}

	void BinarySearchTreeTest1()
	{
		BinaryTreeElem* root = new BinaryTreeElem(4);
		AddElemToBinarySearchTree(root, 2);
		AddElemToBinarySearchTree(root, 3);
		AddElemToBinarySearchTree(root, 5);
		AddElemToBinarySearchTree(root, 7);
		AddElemToBinarySearchTree(root, 8);
		AddElemToBinarySearchTree(root, 9);
		Print(root, "", "root:");
		std::cout << IsElemExistsInBinarySearchTree(root, 10);
		std::cout << IsElemExistsInBinarySearchTree(root, 11);
		std::cout << IsElemExistsInBinarySearchTree(root, 3);
	}








}