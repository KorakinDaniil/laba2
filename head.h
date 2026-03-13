#include <iostream>
#include <string>
#include <clocale>
#include <fstream>
#include <cctype>
#include <ctime>
#include <list>
#include <cstdlib>
#include <limits>

// Общая проблема

//FIX_ME: Неправильное подключение Windows.h для кодировки
//#include <Windows.h>

//FIX_ME: using namespace std; запрещено стандартом
//using namespace std;

// Task1
// Класс узла стека
class Node1
{
public:
    int Data;           // Значение узла
    Node1* Next;         // Указатель на следующий узел

    // Конструктор узла
    explicit Node1(int InData);
};

// Класс стека
class Stack
{
private:
    Node1* Top; // Указатель на вершину стека

public:
    // Конструктор стека
    Stack();

    // Деструктор стека
    ~Stack();

    // Добавление элемента в конец стека
    void Push(int InData);

    // Удаление элемента из начала стека
    void Pop();

    // Вывод всех элементов стека на экран
    void Show() const;

    // Вывод адресов конца стека
    void ShowAddress() const;

    // Получение значения вершины элемента
    int GetTopValue() const;

    // Проверка стека на пустоту
    bool IsEmpty() const;
};

int Task1();

// Task2

// Класс узла очереди
class Node2
{
public:
    int Data;       // Значение узла
    Node2* Next;     // Указатель на следующий узел

    // Конструктор узла
    explicit Node2(int InData);
};

// Класс очереди
class Queue
{
private:
    Node2* Head;     // Указатель на начало очереди
    Node2* Tail;     // Указатель на конец очереди

public:
    // Конструктор очереди
    Queue();

    // Деструктор очереди
    ~Queue();

    // Основные методы

    // Добавление элемента в конец очереди
    void Push(int InData);

    // Удаление элемента из начала очереди
    int Pop();

    // Удаление нескольких элементов из начала очереди
    void PopMultiple(int InCount);

    // Вывод всех элементов очереди на экран
    void Show() const;

    // Вывод адресов начала и конца очереди
    void ShowAddresses() const;

    // Проверка очереди на пустоту
    bool IsEmpty() const;

    // Получение количества элементов в очереди
    int GetSize() const;
    
    // Очистка очереди
    void Clear();

    // Получение значения первого элемента
    int GetHeadValue() const;

    // Получение значения последнего элемента
    int GetTailValue() const;
};

// Функция для безопасного ввода целого числа с проверкой
int SafeInputInt(const std::string& InPrompt, bool bPositiveOnly = false, bool bOddOnly = false);

int Task2();

// Task3

// Класс узла очереди
class Node3
{
public:
    int Data;       // Значение узла
    Node3* Next;     // Указатель на следующий узел

    // Конструктор узла
    explicit Node3(int InData);
};

// Класс односвязного списка
class LinkedList
{
private:
    Node3* Head;      // Указатель на голову списка

public:
    // Конструктор
    LinkedList();

    // Деструктор
    ~LinkedList();

    // Добавление элемента в конец списка
    void PushBack(int InData);

    // Вставка элемента с сохранением упорядоченности
    void InsertSorted(int InData);

    // Удаление элемента по значению
    bool RemoveByValue(int InData);

    // Поиск элемента по значению (возвращает указатель на узел)
    Node3* Find(int InData) const;

    // Поиск позиции для вставки (возвращает предыдущий узел)
    Node3* FindInsertPosition(int InData) const;

    // Вывод всех элементов списка
    void Show() const;

    // Вывод адреса головы списка
    void ShowHeadAddress() const;

    // Проверка на пустоту
    bool IsEmpty() const;

    // Очистка списка
    void Clear();

    // Получение головы списка (для копирования)
    Node3* GetHead() const;

    // Создание копии списка
    LinkedList* Clone() const;
};

// Функция для безопасного ввода значения с проверкой на упорядоченность
int SafeInputValue(int InElementNumber, int PreviousValue = -1, bool bNeedGreater = false);

int Task3();

// Task4

// Структура узла двусвязного списка
struct Node
{
    int Data;           // Данные узла
    Node* Previous;     // Указатель на предыдущий узел
    Node* Next;         // Указатель на следующий узел
};

// Класс для работы с двусвязным списком
class DoublyLinkedList
{
private:
    Node* First;      // Указатель на первый узел

public:
    // Конструктор
    DoublyLinkedList();

    // Деструктор
    ~DoublyLinkedList();

    // Добавление элемента в конец списка
    void PushBack(int InValue);

    // Удаление указанного узла
    void RemoveNode(Node* InNodeToRemove);

    // Вывод списка на экран
    void Print() const;

    // Получение последнего элемента списка
    Node* GetLast() const;

    // Запись в файл в обратном порядке и удаление элементов
    void WriteToFileAndClear(const std::string& InFileName);

    // Проверка на пустоту
    bool IsEmpty() const;

    // Очистка всего списка
    void Clear();
};

// Функция для ввода числа с проверкой
int InputNumber();

// Функция для вывода содержимого файла
void PrintFileContent(const std::string& InFileName);

int Task4();

// Task5

// Заполнение списка выбранным способом
void InputList(std::list<int>& OutList, int InSize);

// Вывод содержимого списка на экран
void PrintList(const std::list<int>& InList);

// Вывод содержимого списка в обратном порядке
void PrintListReverse(const std::list<int>& InList);

// Перемещение среднего элемента из L1 в конец L2
void SpliceMiddleToListEnd(std::list<int>& InOutL1, std::list<int>& InOutL2);

int Task5();