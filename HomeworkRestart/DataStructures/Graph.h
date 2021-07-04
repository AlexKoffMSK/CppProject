#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <climits>


namespace DataStructures
{
	struct Node; //forward declaration - объ€вление будущей структуры, хак чтобы следующа€ структура видела.
	struct NieghbourAndWeight
	{
		Node* _neighbour;
		int _weight;
	};
	
	struct Node
	{
		int _id = 0;
		int _user_param = INT_MAX;
		bool _is_visited = false;
		std::vector<NieghbourAndWeight> _neighbours;

		Node(int id_)
		{
			_id = id_;
		}

		bool is_neighbour_exist(int id)
		{
			for (int i = 0; i < _neighbours.size(); i++) //дл€ ускорени€ времени на опрос ближайших соседей можно использовать ћјѕ
			{
				if (_neighbours[i]._neighbour->_id == id)
				{
					return true;
				}
			}
			return false;
		}

		//принтуем граф обход€ его в глубину относительно какой-то ноды. если все части графа св€заны - напечатает весь граф.
		void PrintDFS()
		{
			std::cout << "Start node: " << _id << ", neighbours: ";
			_is_visited = true;

			for (NieghbourAndWeight q : _neighbours)
			{
				std::cout << q._neighbour->_id << ' ';
			}
			std::cout << std::endl;

			for (NieghbourAndWeight q : _neighbours)
			{
				std::cout << _id << ": try print neighbour: " << q._neighbour->_id << std::endl;
				if (q._neighbour->_is_visited == false)
				{
					q._neighbour->PrintDFS();
				}

			}
			std::cout << "Finish function to PrintDFS for node: " << _id << std::endl;
		}

		//принтуем граф обход€ его в ширину
		void PrintBFS()
		{
			std::queue<Node*> q;
			q.push(this);
			this->_is_visited = true;
			
			while (q.empty() == false)
			{
				std::cout << q.front()->_id << ": ";
				for (NieghbourAndWeight p : q.front()->_neighbours)
				{
					std::cout << p._neighbour->_id << ' ';
					if (p._neighbour->_is_visited == false)
					{
						q.push(p._neighbour);
						p._neighbour->_is_visited = true;
					}
				}
				std::cout << std::endl;
				q.pop();
			}
		}

		Node* FindBFS(int id)
		{
			std::queue<Node*> q;
			q.push(this);
			this->_is_visited = true;

			while (q.empty() == false)
			{
				if (q.front()->_id == id)
				{
					return q.front();
				}

				for (NieghbourAndWeight p : q.front()->_neighbours)
				{
					if (p._neighbour->_is_visited == false)
					{
						q.push(p._neighbour);
						p._neighbour->_is_visited = true;
					}
				}
				q.pop();
			}
			return nullptr;
		}

		Node* GetFirstNotVisitedNeighbour()
		{
			for (NieghbourAndWeight neighbour : _neighbours)
			{
				if (neighbour._neighbour->_is_visited == false)
				{
					return neighbour._neighbour;
				}
			}
			return nullptr;
		}

		Node* GetNeighbourWithMinUserParam()
		{
			Node* neighbour_with_min_user_param = _neighbours[0]._neighbour;
			
			for (NieghbourAndWeight neighbour : _neighbours)
			{
				if (neighbour._neighbour->_user_param <= neighbour_with_min_user_param->_user_param)
				{
					neighbour_with_min_user_param = neighbour._neighbour;
				}
			}
			return neighbour_with_min_user_param;
		}

	};

	void ResetIsVisited(map<int, Node*> m)
	{
		for (auto [id, ptr_node] : m)
		{
			ptr_node->_is_visited = false;
		}
	}

	void PrintZeroNeighbourPath(Node* start_node)
	{
		//печатаем не более 10 прыжков, либо пока не вернемс€ в себ€
		
		Node* cur_ptr = start_node;
		
		std::cout << "Start node: " << start_node->_id << ": ";

		for (int i = 0; i < 10; i++)
		{
			std::cout << cur_ptr->_id << ' ';
			cur_ptr->_is_visited = true;
			cur_ptr = cur_ptr->_neighbours[0]._neighbour;
			
			if (cur_ptr->_is_visited == true)
			{
				break;
			}
		}
		std::cout << std::endl;
	}

	//void Test1()
	//{
	//	Node _start_node(0);
	//	_start_node._neighbours.push_back(new Node(2));
	//	_start_node._neighbours.push_back(new Node(3));
	//	
	//	_start_node._neighbours[0]->_neighbours.push_back(new Node(5));
	//	_start_node._neighbours[0]->_neighbours.push_back(new Node(1));
	//	_start_node._neighbours[0]->_neighbours.push_back(_start_node._neighbours[1]);
	//	_start_node._neighbours[0]->_neighbours.push_back(&_start_node);
	//	
	//	_start_node._neighbours[1]->_neighbours.push_back(new Node(4));
	//	_start_node._neighbours[1]->_neighbours.push_back(&_start_node);
	//	_start_node._neighbours[1]->_neighbours.push_back(_start_node._neighbours[0]);
	//
	//	_start_node._neighbours[0]->_neighbours[0]->_neighbours.push_back(_start_node._neighbours[0]->_neighbours[1]);
	//	_start_node._neighbours[0]->_neighbours[0]->_neighbours.push_back(_start_node._neighbours[0]);
	//
	//	_start_node._neighbours[0]->_neighbours[1]->_neighbours.push_back(_start_node._neighbours[1]->_neighbours[0]);
	//	_start_node._neighbours[0]->_neighbours[1]->_neighbours.push_back(_start_node._neighbours[0]);
	//	_start_node._neighbours[0]->_neighbours[1]->_neighbours.push_back(_start_node._neighbours[0]->_neighbours[0]);
	//
	//	_start_node._neighbours[1]->_neighbours[0]->_neighbours.push_back(_start_node._neighbours[0]->_neighbours[1]);
	//	_start_node._neighbours[1]->_neighbours[0]->_neighbours.push_back(_start_node._neighbours[1]);
	//
	//	_start_node.PrintDFS();
	//}

	//void Test9()
	//{
	//	//ключ инт, значение указатель на узел
	//	std::map<int, Node*> m;
	//	m[0] = new Node(0);
	//	m[1] = new Node(1);
	//	m[2] = new Node(2);
	//	m[3] = new Node(3);
	//	m[4] = new Node(4);
	//	m[5] = new Node(5);
	//
	//	m[0]->_neighbours.push_back(m[2]);
	//	m[0]->_neighbours.push_back(m[3]);
	//	
	//	m[2]->_neighbours.push_back(m[5]);
	//	m[2]->_neighbours.push_back(m[1]);
	//	m[2]->_neighbours.push_back(m[3]);
	//	m[2]->_neighbours.push_back(m[0]);
	//	
	//	m[3]->_neighbours.push_back(m[4]);
	//	m[3]->_neighbours.push_back(m[0]);
	//	m[3]->_neighbours.push_back(m[2]);
	//	
	//	m[5]->_neighbours.push_back(m[1]);
	//	m[5]->_neighbours.push_back(m[2]);
	//	
	//	
	//	m[1]->_neighbours.push_back(m[4]);
	//	m[1]->_neighbours.push_back(m[2]);
	//	m[1]->_neighbours.push_back(m[5]);
	//	
	//	m[4]->_neighbours.push_back(m[1]);
	//	m[4]->_neighbours.push_back(m[3]);
	//
	//
	//	//for (auto [id, ptr_node] : m)
	//	//{
	//	//	PrintZeroNeighbourPath(ptr_node);
	//	//	ResetIsVisited(m);
	//	//}
	//
	//	m[0]->PrintDFS();
	//	ResetIsVisited(m);
	//	std::cout << "===========" << std::endl;
	//	m[0]->PrintBFS();
	//	
	//}

	bool IsNode1UserParamLessThanNode2UserParam(Node* n1, Node* n2)
	{
		return n1->_user_param < n2->_user_param;
	}

	class Graph
	{
	private:
		std::map<int, Node*> id_to_node;

	public:
		int Add()
		{
			if (id_to_node.size() != 0)
			{
				int curr_end_id = id_to_node.rbegin()->first;
				id_to_node[curr_end_id+1] = new Node(curr_end_id+1);
				return curr_end_id + 1;
			}
			else
			{
				AddWithId(0);
				return 0;
			}
		}

		bool AddWithId(int id)
		{
			if (id_to_node.find(id) != id_to_node.end()) //не дошли до конца=нашли элемент в контейнере
			{
				return false;
			}
			id_to_node[id] = new Node(id);
			//id_to_node.emplace(id,new Node(id)); //альтернативный способ
			return true;
		}

		bool AddEdge(int id1, int id2, int weight=1) //=1 - если €вно не укажем значение - будет по умолчанию 1
		{
			if (id1 == id2)
			{
				return false;
			}
			if (id_to_node.find(id1) == id_to_node.end() || id_to_node.find(id2) == id_to_node.end()) // "==" элемент не существует, "!=" элемент существует
			{
				return false;
			}
			if (id_to_node[id1]->is_neighbour_exist(id2) != false)
			{ 
				return false;
			}
			if (id_to_node[id2]->is_neighbour_exist(id1) != false)
			{
				return false;
			}

			id_to_node[id1]->_neighbours.push_back(NieghbourAndWeight{ id_to_node[id2],weight });
			id_to_node[id2]->_neighbours.push_back(NieghbourAndWeight{ id_to_node[id1],weight });
			return true;
		}

		int GetNodesCount()
		{
			return id_to_node.size();
		}

		int GetEdgesCountBFS() //доделать надо
		{
		}
		//пары кодировать через хэш
		int GetEdgesCountDFS() //доделать надо
		{
		}

		void PrintBFS()
		{
			if (id_to_node.size() != 0)
			{
				id_to_node.begin()->second->PrintBFS();
			}
		}

		void PrintDFS()
		{
			if (id_to_node.size() != 0)
			{
				id_to_node.begin()->second->PrintDFS();
			}
		}

		void Print()
		{
			for (auto [key, value] : id_to_node)
			{
				std::cout << key << ' ' << value->_user_param << ' ' << value->_neighbours.size() << "\t:\t";
				for (NieghbourAndWeight neighbour : value->_neighbours)
				{
					std::cout << '[' << neighbour._neighbour->_id << ',' << neighbour._weight << ']' <<"\t";
				}
				std::cout << std::endl;
			}
		}

		void WriteToFile(std::string filename) //сериализаци€
		{
			std::ofstream ofs(filename); //"открываем файл на запись", объ€вл€ем о установлении маршрута потока данных
			ofs << GetNodesCount() << std::endl;
			for (auto [key, value] : id_to_node)
			{
				ofs << key << ' ';
			}
			ofs << std::endl;

			for (auto [key, value] : id_to_node)
			{
				ofs << key << ' ' << value->_neighbours.size() << " : ";

				for (NieghbourAndWeight neighbour : value->_neighbours)
				{
					ofs << neighbour._neighbour->_id << ' ' << neighbour._weight << '\t';
				}
				ofs << std::endl;
			}
		}

		void LoadFromFile(std::string filename) //де-сериализаци€
		{
			std::ifstream ifs(filename);
			int nodes_count;
			ifs >> nodes_count; //считает до ближайшего пробельного символа - пробел,табул€ци€ или переход на др.строку

			int node_id;

			for (int i = 0; i < nodes_count; i++)
			{
				ifs >> node_id;
				AddWithId(node_id);
			}
			for (int i = 0; i < nodes_count; i++)
			{
				ifs >> node_id;

				int  neighb_count;
				ifs >> neighb_count;

				char a;
				ifs >> a; //вот здесь записываетс€ в переменную а двоеточие или иной символ, не соответствующий пробелу, табу или переносу на строку ниже... и игнорируетс€

				for (int i = 0; i < neighb_count; i++)
				{
					int cur_neighb;
					ifs >> cur_neighb;

					int cur_weight;
					ifs >> cur_weight;

					AddEdge(node_id, cur_neighb, cur_weight);
				}
			}
		}

		void FindPath(int id1, int id2)
		{
			std::stack<Node*> stack; //push-положить top-посмотреть pop-достать/убрать
			
			if (id_to_node.find(id1) == id_to_node.end())
			{
				return;
			}
			
			stack.push(id_to_node[id1]);
			
			while (!stack.empty())
			{
				Node* a = stack.top();
				a->_is_visited = true;
				if (a->_id == id2)
				{
					break;
				}
				Node* first_not_visited_neighbour = a->GetFirstNotVisitedNeighbour();
				if (first_not_visited_neighbour == nullptr)
				{
					stack.pop();
					//continue; // Ќ≈ јЋ№“≈–Ќј“»¬ј! вернет на начало цикла, аналог break по написанию, но это избыточно, так как он итак вернетс€ в начало цикла
				}
				else
				{
					stack.push(first_not_visited_neighbour);
				}
			}
			while (!stack.empty())
			{
				std::cout << stack.top()->_id << "<-";
				stack.pop();
			}
		}

		void FindShortPath(int id1, int id2) //јлгоритм ƒейкстры
		{
			id_to_node[id1]->_user_param = 0;
			std::vector<Node*> not_visited_nodes;
			for (auto [key, value] : id_to_node)
			{
				not_visited_nodes.push_back(value);
			}
			
			while (!not_visited_nodes.empty())
			{
				std::sort(not_visited_nodes.begin(), not_visited_nodes.end(), IsNode1UserParamLessThanNode2UserParam);
				Node* a = not_visited_nodes[0];
				for (NieghbourAndWeight neighbour : a->_neighbours)
				{
					if (neighbour._neighbour->_is_visited == true)
					{
						continue;
					}
					
					int weight_path_from_a = a->_user_param + neighbour._weight;
					if (weight_path_from_a < neighbour._neighbour->_user_param)
					{
						neighbour._neighbour->_user_param = weight_path_from_a;
					}
				}
				a->_is_visited = true;
				not_visited_nodes.erase(not_visited_nodes.begin()); //удал€ем первый элемент из массива, остальные сдвинутс€
			}
			
			Node* cur_node = id_to_node[id2];
			
			while (cur_node != id_to_node[id1])
			{
				std::cout << "Start from: " <<'[' << "Node: " << cur_node->_id << ' ' << "SummWeight: " <<cur_node->_user_param << ']' << " -> ";
				
				Node* neighbour_with_min_user_param = nullptr;

				for (NieghbourAndWeight neighbour : cur_node->_neighbours)
				{
					if (cur_node->_user_param - neighbour._weight != neighbour._neighbour->_user_param)
					{
						continue;
					}
					if (neighbour_with_min_user_param == nullptr)
					{
						neighbour_with_min_user_param = neighbour._neighbour;
					}
					
					if (neighbour._neighbour->_user_param <= neighbour_with_min_user_param->_user_param)
					{
						neighbour_with_min_user_param = neighbour._neighbour;
					}
				}
				cur_node = neighbour_with_min_user_param;
				
				std::cout << "Next to step: " << '[' << "Node: " << cur_node->_id << ' ' << "SummWeight: "<<cur_node->_user_param << ']' << " -> " << std::endl;
				
			}

		}
	};

	void Test77()
	{
		Graph g;

		assert(g.Add() == 0); //ожидаем, что вернет 0
		
		assert(g.AddWithId(3) == true);
		assert(g.AddWithId(3) == false);

		assert(g.AddWithId(1) == true);
		assert(g.AddWithId(2) == true);

		assert(g.Add() == 4);
		assert(g.Add() == 5);

		assert(g.AddEdge(0, 5) == true);
		assert(g.AddEdge(5, 0) == false);
		assert(g.AddEdge(0, 5) == false);

		assert(g.AddEdge(0, 1) == true);
		assert(g.AddEdge(4, 5) == true);
		
		assert(g.AddEdge(4, 8) == false);
		assert(g.AddEdge(4, 4) == false);

		assert(g.AddEdge(4, 2) == true);
		assert(g.AddEdge(3, 5) == true);
		assert(g.AddEdge(3, 2) == true);

		g.WriteToFile("TextFiles/a.txt");


		//g.PrintBFS();
		//g.PrintDFS();

		//std::cout << g.GetEdgesCountBFS() << std::endl;

		//assert(g.GetNodesCount() == 6);
		//assert(g.GetEdgesCountBFS() == 6);

	}

	void Test()
	{
		Graph g;
	
		g.LoadFromFile("GraphsFiles/Graph_1.txt");
		
		g.FindShortPath(2, 11);
		
		//g.Print();
	}



































}