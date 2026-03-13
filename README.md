# laba2

Общие изменения

using namespace std; -> Убрано, добавлен префикс std::

Подключение Windows.h -> setlocale(LC_ALL, "ru")

SetConsoleCP/SetConsoleOutputCP -> setlocale

Комментарии Улучшены и приведены к стандарту

Добавлены отступы, фигурные скобки

Отсутствие деструкторов ->	Добавлены деструкторы с освобождением памяти

Task1

class Node ->	class Node1 (для уникальности в head.h)

Поле x ->	Data

Поле next ->	Next

Параметр int d ->	int InData

Конструктор Node(int d) ->	explicit Node1(int InData)

Указатель top ->	Top

Метод push() ->	Push()

Метод show() ->	Show()

Метод showAddress() ->	ShowAddress()

Метод getTopValue() ->	GetTopValue()

Метод isEmpty()	-> IsEmpty()

Отсутствие метода удаления ->	Добавлен метод Pop()

Отсутствие деструктора ->	Добавлен ~Stack() с очисткой памяти

Переменная N ->	ElementCount

Переменная n ->	Value

Переменная D ->	NewValue

newNode ->	NewNode

current ->	Current

temp ->	Temp

Task2

class Node ->	class Node2 (для уникальности в head.h)

Поле data ->	Data

Поле next ->	Next

Конструктор Node2(int InData) ->	Добавлен explicit Node2(int InData)

Отсутствие класса Queue ->	Создан класс Queue

Глобальные функции add, del, show1, show2 ->	Методы класса: Push, Pop, PopMultiple, Show, ShowAddresses

Указатели Head и Tail ->	Инкапсулированы в классе

typedef Node* PNode ->	Удалено

Переменная m ->	ElementCount

Переменная n ->	ExtractCount

Переменная j ->	Value

Temp ->	Temp или Current

Добавлены методы:	GetSize(), Clear(), IsEmpty(), GetHeadValue(), GetTailValue()

Отсутствие проверки на дурака ->	Добавлена функция SafeInputInt

Task3

class Node ->	class Node3 (для уникальности в head.h)

Поле x ->	Data

Поле next ->	Next

Конструктор Node3(int InData) ->	Добавлен explicit Node3(int InData)

Отсутствие класса LinkedList ->	Создан класс LinkedList

Глобальные функции add, find, newadd, show, DeleteNode ->	Методы класса: PushBack, InsertSorted, RemoveByValue, Find, FindInsertPosition, Show, ShowHeadAddress, Clone

Указатель Head ->	Инкапсулирован в классе

typedef Node* PNode ->	Удалено

Переменная n ->	ElementCount

Переменная m ->	ValueToInsert

Temp, Mynode, Prev ->	Current, NewNode, Temp

Добавлены методы:	Clone(), Clear(), IsEmpty(), GetHead()

Отсутствие проверки на дурака ->	Добавлена функция SafeInputInt2

Добавлена функция SafeInputValue с проверкой упорядоченности

Task4

struct Uzel ->	struct Node

Поле Dannye ->	Data

Поле Predydushiy ->	Previous

Поле Sleduyushiy ->	Next

class Spisok ->	class DoublyLinkedList

Указатель Perviy ->	First

Метод Inicializacia() ->	Удален (заменен конструктором)

Метод DobavitElement() ->	PushBack()

Метод UdalitElement() ->	RemoveNode()

Метод Pechat() ->	Print()

Метод ZapisatVFailIOchistit() ->	WriteToFileAndClear()

Метод Ochistka() ->	Clear()

Функция VvodChisla() ->	InputNumber()

Функция VivodSoderzhimogoFaila() ->	PrintFileContent()

Переменная Tekushiy ->	Current

Переменная Novyj ->	NewNode

Переменная Pred ->	Prev

Переменная Sled ->	Next

Переменная Chislo ->	Number

Переменная ImyaFaila ->	FileName

PerviyElement ->	bFirstElement (префикс b)

Korrektno ->	bIsValid (префикс b)

Отсутствие конструктора ->	Добавлен DoublyLinkedList() : First(nullptr) {}

Отсутствие деструктора ->	Добавлен ~DoublyLinkedList() с очисткой памяти

Добавлены методы:	GetLast(), IsEmpty()

Task5

Функция Input() ->	InputList()

Функция Print() ->	PrintList()

Функция Splice() ->	SpliceMiddleToListEnd()

Добавлена новая функция	PrintListReverse() для обратного вывода

Параметр L ->	OutList (выходной параметр)

Параметр n ->	InSize (входной параметр)

Параметр L1, L2 ->	InOutL1, InOutL2 (входные-выходные)

Переменная m ->	Choice

Переменная x ->	Value

Переменная it ->	Iterator

srand(time(0)) ->	std::srand(static_cast<unsigned int>(std::time(nullptr)))

Проверка открытия файла ->	Использование is_open() вместо !file

Добавлена проверка	if (InList.empty()) в функциях вывода

Улучшены сообщения об ошибках ->	Более подробные описания
