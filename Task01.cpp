/* Дано число D и указатель P1 на вершину непустого стека.
   Добавить элемент со значением D в стек и вывести адрес P2 новой вершины стека.

   Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
   добавления/удаления/вывода элементов.
   Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

   В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
   узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
   стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
   его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
   элемента стека считается значение его поля Data */

#include <iostream>
#include <string>
#include <clocale>

//FIX_ME: Неправильное подключение Windows.h для кодировки
//#include <Windows.h>

//FIX_ME: using namespace std; запрещено стандартом
//using namespace std;

// Класс узла списка
class Node1
{
public:
    int Data;           // Значение узла
    Node1* Next;         // Указатель на следующий узел

    // Конструктор узла
    explicit Node1(int InData) : Data(InData), Next(nullptr) {}
};

class Stack
{
private:
    Node1* Top; // Указатель на вершину стека

public:
    // Конструктор стека
    Stack() : Top(nullptr) {}

    // Деструктор стека
    ~Stack()
    {
        while (!IsEmpty())
        {
            Node1* Temp = Top;
            Top = Top->Next;
            delete Temp;
        }
    }

    // Добавление элемента в конец стека
    void Push(int InData)
    {
        Node1* NewNode = new Node1(InData); // Создаем новый узел
        NewNode->Next = Top; // Новый узел указывает на старую вершину
        Top = NewNode; // Новый узел становится вершиной стека
    }

    //FIX_ME: Отсутствие стандартного метода удаления (по заданию был обязательным)
    // Удаление элемента из начала стека
    void Pop()
    {
        if (IsEmpty())
        {
            return;
        }

        Node1* Temp = Top;
        Top = Top->Next;
        delete Temp;
    }

    // Вывод всех элементов стека на экран
    void Show() const
    {
        if (IsEmpty())
        {
            std::cout << "Стек пуст!" << std::endl;
            return;
        }

        Node1* Current = Top;
        while (Current != nullptr)
        {
            std::cout << Current->Data << " ";
            Current = Current->Next;
        }
        std::cout << std::endl;
    }

    // Вывод адресов конца стека
    void ShowAddress() const
    {
        std::cout << "Адрес вершины стека: " << Top << std::endl;
    }

    // Получение значения вершины элемента
    int GetTopValue() const
    {
        if (Top != nullptr)
        {
            return Top->Data;
        }
        return 0; // Возвращаем 0 для пустого стека
    }

    // Проверка стека на пустоту
    bool IsEmpty() const
    {
        return Top == nullptr;
    }
};

int Task1()
{
    //FIX_ME: Неправильная установка кодировки
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Stack MyStack;

    int ElementCount = 0;
    std::cout << "Сколько чисел вы хотите, чтобы было в стеке? ";
    std::cin >> ElementCount;

    for (int i = 0; i < ElementCount; ++i)
    {
        int Value = 0;
        std::cout << "Введите число " << i + 1 << ": ";
        std::cin >> Value;
        MyStack.Push(Value);
    }

    MyStack.ShowAddress();
    std::cout << "Элементы в стеке: ";
    MyStack.Show();

    int NewValue = 0;
    std::cout << "Введите значение D для добавления в стек: ";
    std::cin >> NewValue;

    MyStack.Push(NewValue);

    std::cout << "Элементы в новом стеке: ";
    MyStack.Show();
    MyStack.ShowAddress();

    if (!MyStack.IsEmpty())
    {
        std::cout << "Значение новой вершины: " << MyStack.GetTopValue() << std::endl;
    }
    else
    {
        std::cout << "Стек пуст!" << std::endl;
    }

    return 0;
}