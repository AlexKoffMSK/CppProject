//Hello Unicode World ☺. 
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <chrono>
#ifdef INCLUDES
#include <sys/types.h>
#include <winsock.h>
#include "Pointers.h"
#include "WorkWithTextFiles.h"
#include "DataStructures/Queue.h"
#include "Sequences.h"
#include "Functions.h"
#include "ConsoleFunctions.h"
#include "Sorts.h"
#include "DynamicMemory.h"
#include "Recusrion.h"
#include "Structures.h"
#include "Classes/Fraction.h"
#include "GlobalStructuresCarUtils.h"
#include "Geometry.h"
#include "Classes/ButtonStruct.h"
#include "Initializations.h"
#include "CorpPosition.h"
#include "Operators.h"
#include "ServiceClasess.h"
#include "Classes/CustomString.h"
#include "Classes/VectorWithinEvens.h"
#include "MapStdExamples.h"
#include "SetStdExamples.h"
#include "WorkWithBinaryFiles.h"
#include "2021-02-27.h"
#include "List.h"
#include "List1.h"
#include "DataStructures/ForwardList.h"
#include "DataStructures/List.h"
#include "DataStructures/BinaryTree.h"
#include "DataStructures/BinarySearchTree.h"
#include "DataStructures/BinarySearchTreeMap.h"
#include "DataStructures/Graph.h"
#include "Json/JsonTests.h"
#include "GameMatrix/GameMatrix.h"
#include "Hash/SHA256.h"
#include "SHA256 from GitHub/SHA256-GitHub.h"
#include "ParallelThreads/ParallelThreads.h"
#include "ParallelThreads/RingBuffer.h"
#include "ParallelThreads/RingBufferTest.h"
#include "Inheritance/InheritanceBasic.h"
#include "Inheritance/InheritanceSquareAndRectangle.h"
#include "EnumExamples.h"
#include "Hash/HashTableVector.h"
#include "Polymorphism/PolymorphismBasic.h"
#include "Polymorphism/DynamicCast.h"
#include "PointersAndReferences.h"
#include "ChronoTime.h"
#include "Polymorphism/SimplePatternStrategy.h"
#include "Network/Test.h"
#include "Iterators.h"
#include "Templates.h"
#include "Hash/HashTableOpenAddress.h"
#include "VariadicTemplates.h"
//#include "MoveSemantics/LvalueRvalue.h"
//#include "MoveSemantics/MoveSemanticsClass.h"
#include "SmartPointers/UniquePtr.h"
#include "SmartPointers/SharedPtr.h"
#include "MoveSemantics/PerfectForwarding.h"
#include "BitOperations/BitOperationsBasic.h"
#include "Union.h"
#include "BinanceDataAPI/DataFromInternet.h"
#include "LambdaFunctions.h"
#include "Exceptions.h"
#include "StdAlgorithms/StdAlgorithms.h"
#include "Polymorphism/VirtualDestructor.h"
#include "Polymorphism/VirtualConstructor.h"
#include "Polymorphism/VirtualInheritance.h"
#include "ParallelThreads/Mutexes.h"
#include "Polymorphism/Polymorphism_1.h"
#include "OpenCV/OpenCVTest.h"
#include "Polymorphism/Polymorphism_2.h"
#include "RandomTasks.h"
#include "STL/Vector/StlVectorExamples.h"
#include "STL/Map/STLMapExamples.h"
#include "FileSystem/FileSystemBasic.h"
#include "FileSystem/FoldersContentMatcher.h"
#include "ParallelThreads/Future.h"
#include "ParallelThreads/OnlineThreadsProcessor.h"
#include "STL/String/String.h"
#include "STL/Set/Set.h"
#include "STL/Stack/Stack.h"
#include "FunctionPointerReplace.h"
#endif
#include "AlgoTasks/Loops.h"
#include "AlgoTasks/Sequences.h"
#include "AlgoTasks/SimpleArrays.h"
#include "AlgoTasks/NotSimpleArrays.h"
#include "SharedMemory/SharedMemoryClient.h"
#include "SharedMemory/SharedMemoryServer.h"
#include "SharedMemory/SharedMemoryTest.h"
#include "SharedMemory/SharedMemoryTest1.h"
#include "SharedMemory/SharedMemoryTest2.h"
#include "STL/Deque/Deque.h"
#include "STL/Array/Array.h"
#include "STL/List/List.h"
#include "STL/BitSet/BitSet.h"
#include "Test/Classess.h"
#include "STL/MultiMap/MultiMap.h"
#include "STL/Queue/Queue.h"
#include "STL/MultiSet/MultiSet.h"
#include "STL/UnorderedMap/UnorderedMap.h"

#ifdef INCLUDES
#pragma endregion
#endif


void YoureFucked(int x)
{
	std::cout << "You're fucked!" << std::endl;
}



//первый аргумент - это то, сколько аргументов в функцию мы передали argc - arguments count
//второй аргумент - это массив указателей на строки, указатель на массив строк
int main(int argc, char* argv[])
{
	//Console.SetConsolePositionAndSize(10, 10, 900, 1400);
	
	signal(SIGSEGV, &YoureFucked);
	signal(SIGINT, &YoureFucked);

	srand(time(0));
	
	//FileSystem::PrintFoldersContentMatching(FileSystem::kPath1,FileSystem::kPath2);
	//FileSystem::Go();

	//StlString::TestAll();
	//STLSet::TestAll();
	//STLStack::TestAll();
	//StlDeque::TestTest();
	//AlgoTasks::Loops::Task44();
	//AlgoTasks::Sequences::Task8();
	//SharedMemory2::Test(argc,argv);
	
	//AlgoTasks::NotSimpleArrays::Task18();
	//STLArray::Run();
	//STLList::Run();

	//STLBitSet::Run();

	//TestInheritance::Test();

	//STLMultiMap::Run();

	//STLQueue::Run();
	
	//STLMultiSet::Run();

	STLUnorderedMap::Run();

	std::cout << "Process is over!" << std::endl;
	//getchar(); //ожидание ввода с клавиатуры
}


/*Путь к успеху!
+ Массивы, переменные, условия, циклы
+ Сортировки базовые (пузырь, вставка, выборка, слияние и быстрая сортировка
+ Работа с указателями и памятью
При работе с указателями важно:
- чтобы и слева и справа от оператора присваивания (=) был одинаковый тип данных, либо тип данных справа должен иметь возможность быть неявно преобразован к типу данных слева (int a = 3.14)
- унарный & (операция взятия адреса) добавляет к типу звездочку 
- унарная * (операция разыменования) убирает от типа звездочку
+ Работа с динамической паматью
+ Рекурсии
+ Структуры (классы):
+ 1.конструкторы
+ 2.методы
+ 3.уровни доступа
+ 4.операторы (кастомные операторы внутри класса)
(1-4 - инкапсуляция)
+- работа с CommonLanguageInterface, .net
++ работа с текстовыми файлами
+- работа с бинарными файлами
+- списки: односвязный, двухсвязный

Написать свои контейнеры:
+- очередь через массив
+ список
+ бинарное дерево
+ бинарное дерево поиска (ассоциативный массив),
+ хэш-таблица метод открытой адресации.
+- граф
+- Наследование,полиморфизм
+ хэш-таблица Сделан метод цепочек
- vector
- map
- string
- set
- stack
- queue
- dequeue
- list
- unordered map
- unordered set
- multimap
- multiset
- array
- bitset

Контейнеры STL 
+ vector
+ map
+ string
+ set
+ stack
+ deque
+ array
+ list
+ bitset
+ multimap
+ queue
+ multiset
- unordered map
- unordered set

Алгоритмы STL:
+ partition (stable partition)
+ find_if
+ sort
- max_element
- count (count_if)
- copy
- move
- fillф	
- transform
- remove_if
- rotate
- shift
- shuffle
- partial_sort
- n_element
- lower_bound
- merge
- includes
- set_union
- equal
- is_permitation
- next_permitation
- accumulate

Паттерны проектирования:
-...

Static inline

- Работа с сетью:
	- сделать игру (проект А)- на сервере игровое поле, игрок управляется из клиента
	- чат
	- биржа
- написать MachineLearning NeuralNet AI
- красно-черное дерево и много других клевых структур!!
+- Многопоточность, параллельные вычисления
+- шаблоны

+- переменное число параметров в функции (реализуется через шаблон)

+ абстрактный класс - Класс, у которого есть чистая функция (=0), называется абстрактным
+ интерфейс - иногда это просто абстрактный класс или класс, у которого все функции чистые

++ rvalue lvalue
++ move-семантика
++ умные указатели
++ идеальная передача

+- таблица виртуальных методов и функций
+ виртуальный деструктор (Есть виртуальная функция - должен быть виртуальный деструктор)
+ виртуальный конструктор
+ виртуальное наследование

+- лямбда-функции
+ исключения

- mutable mutex симафор

+ как умножить разделить на два битовыми операциями
+ битовые операции

Важное про ожидаемое значение при инкрементировании
int a = n++; //в а будет старое значение n
int b = ++n; //в b будет новое значение n

Важное про скорость при инкрементировании

Важное про структурирование данных:
Если неважна отсортированность:
- если элементов много, то используем хэш-таблицу (std::unordered_map, std:: unordered_set)
- если элементов мало, то отсортированный массив
- если элементов мало, дисперсия малая, известна нижняя граница, то использовать массив, где ключом является нижний элемент - маска
Если важна отсортированность элементов, то:
- если элементов много - то дерево (std::map, std::set),
- если мало - отсортированный массив.
Если нужна отсортированность - мапа, если не нужна - хэш-таблица, а если элементов мало - массив.

Важное про ссылки и указатели:
Ссылка и указатель различаются тем, что:
	   ссылка не может быть перевязана на новый объект, не может смотреть в никуда
	   при работе с сылками не используются & и *, когда нам надо объект изменить
	   над указателями можно проводить адресную арифметику, можно сдвинуть указатель, ссылку нельзя
	   у указателей есть - указатель на указатель. у ссылок такого нет. Но есть ссылка на указатель.
Если мы хотим принять объект в функцию и не хотим его копиировать, у нас выбор - указатель или ссылка. Нужно определиться:
	1) Хотим ли мы, чтобы нам могли пригонять nullptr? Если да, то - указатель, если нет - ссылка.
	2) Хотим ли мы изменить то куда смотрит пригнанный указатель/ссылка внутри текущей функции. Если да, то - указатель, если нет - ссылка (ссылку нельзя менять).
	3) Хотим ли мы с этим объектом производить адресную арифметику? Если да, то - указатель, если нет - ссылка.
	4) Хотим ли мы менять то, куда смотрит указатель/ссылка? Если нет, то добавить const.
Важное про классы:
Есть new - должен быть delete
Есть виртуальная функция - должен быть виртуальный деструктор

Алгоритмические задачи:
- 

*/

/*
// https://github.com/AlexKoffMSK/CppProject.git
// git@github.com:AlexKoffMSK/CppProject.git
// https://miro.com/app/board/o9J_lFH_iBs=/
*/

//ReSharper C++