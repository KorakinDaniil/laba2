/*
Дано число N (> 0) и указатели P1 и P2 на начало и конец непустой очереди. Извлечь
из очереди N начальных элементов и вывести их значения (если очередь содержит менее N
элементов, то извлечь все ее элементы). Вывести также новые адреса начала и конца очереди
(для пустой очереди дважды вывести nullptr). После извлечения элементов из очереди
освобождать память, которую они занимали.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

В заданиях данной подгруппы структура «очередь» (queue) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Началом
очереди («головой», head) считается первый элемент цепочки, концом («хвостом», tail) — ее
последний элемент. Для возможности быстрого добавления в конец очереди нового элемента
удобно хранить, помимо указателя на начало очереди, также и указатель на ее конец. В случае
пустой очереди указатели на ее начало и конец полагаются равными nullptr. Как и для стека,
значением элемента очереди считается значение его поля Data.
*/

#include <iostream>
#include <clocale>

//FIX_ME: Неправильное подключение Windows.h для кодировки
//#include <windows.h>

//FIX_ME: using namespace std; запрещено стандартом
//using namespace std;

// Класс узла списка
class Node2
{
public:
    int Data;       // Значение узла
    Node2* Next;     // Указатель на следующий узел

    // Конструктор узла
    explicit Node2(int InData) : Data(InData), Next(nullptr) {}
};

//FIX_ME: Отсутсвовал класс очереди. методы были отдельными функциями, а не цельной структурой
class Queue
{
private:
    Node2* Head;     // Указатель на начало очереди
    Node2* Tail;     // Указатель на конец очереди

public:
    // Конструктор очереди
    Queue() : Head(nullptr), Tail(nullptr) {}

    // Деструктор очереди
    ~Queue()
    {
        Clear();
    }

    // Добавление элемента в конец очереди
    void Push(int InData)
    {
        Node2* NewNode = new Node2(InData);

        if (IsEmpty())
        {
            Head = NewNode;
            Tail = NewNode;
        }
        else
        {
            Tail->Next = NewNode;
            Tail = NewNode;
        }
    }

    // Удаление элемента из начала очереди
    int Pop()
    {
        if (IsEmpty())
        {
            return 0;
        }

        int Value = Head->Data;
        Node2* Temp = Head;
        Head = Head->Next;
        delete Temp;

        // Если очередь стала пустой, обнуляем Tail
        if (Head == nullptr)
        {
            Tail = nullptr;
        }

        return Value;
    }

    // Удаление нескольких элементов из начала очереди
    void PopMultiple(int InCount)
    {
        if (IsEmpty())
        {
            std::cout << "Очередь пуста!" << std::endl;
            return;
        }

        int ElementsToRemove = InCount;
        int QueueSize = GetSize();

        if (ElementsToRemove > QueueSize)
        {
            std::cout << "Очередь содержит менее " << InCount << " элементов. Извлекаем все элементы." << std::endl;
            ElementsToRemove = QueueSize;
        }

        std::cout << "Извлеченные элементы: ";
        for (int i = 0; i < ElementsToRemove; ++i)
        {
            int Value = Pop();
            std::cout << Value << " ";
        }
        std::cout << std::endl;
    }

    // Вывод всех элементов очереди на экран
    void Show() const
    {
        if (IsEmpty())
        {
            std::cout << "Очередь пуста!" << std::endl;
            return;
        }

        Node2* Current = Head;
        while (Current != nullptr)
        {
            std::cout << Current->Data << " ";
            Current = Current->Next;
        }
        std::cout << std::endl;
    }

    // Вывод адресов начала и конца очереди
    void ShowAddresses() const
    {
        std::cout << "Адрес начала очереди (Head): " << Head;
        if (Head != nullptr)
        {
            std::cout << " (значение: " << Head->Data << ")";
        }
        std::cout << std::endl;

        std::cout << "Адрес конца очереди (Tail): " << Tail;
        if (Tail != nullptr)
        {
            std::cout << " (значение: " << Tail->Data << ")";
        }
        std::cout << std::endl;
    }

    // Проверка очереди на пустоту
    bool IsEmpty() const
    {
        return Head == nullptr;
    }

    // Получение количества элементов в очереди
    int GetSize() const
    {
        int Size = 0;
        Node2* Current = Head;
        while (Current != nullptr)
        {
            ++Size;
            Current = Current->Next;
        }
        return Size;
    }

    // Очистка очереди
    void Clear()
    {
        while (!IsEmpty())
        {
            Node2* Temp = Head;
            Head = Head->Next;
            delete Temp;
        }
        Tail = nullptr;
    }

    //  Получение значения первого элемента
    int GetHeadValue() const
    {
        if (Head != nullptr)
        {
            return Head->Data;
        }
        return 0;
    }

    // Получение значения последнего элемента
    int GetTailValue() const
    {
        if (Tail != nullptr)
        {
            return Tail->Data;
        }
        return 0;
    }
};

//FIX_ME: Отсутствие проверки на дурака
// Функция для безопасного ввода целого числа с проверкой
int SafeInputInt(const std::string& InPrompt, bool bPositiveOnly = false, bool bOddOnly = false)
{
    int Value = 0;
    bool bValidInput = false;

    while (!bValidInput)
    {
        std::cout << InPrompt;
        std::cin >> Value;

        // Проверка на некорректный ввод (буквы, символы)
        if (std::cin.fail())
        {
            std::cin.clear(); // Сброс флага ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера
            std::cout << "Ошибка: введите целое число!" << std::endl;
            continue;
        }

        // Проверка на положительное число
        if (bPositiveOnly && Value <= 0)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: число должно быть положительным!" << std::endl;
            continue;
        }

        // Проверка на нечетное число
        if (bOddOnly && Value % 2 == 0)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: число должно быть нечетным!" << std::endl;
            continue;
        }

        // Если дошли сюда, ввод корректен
        bValidInput = true;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера
    }

    return Value;
}

int Task2()
{
    //FIX_ME: Неправильная установка кодировки
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    std::cout << "Добро пожаловать!" << std::endl;
    std::cout << "Перед нами новая задача:" << std::endl;
    std::cout << "Дано число N (> 0) и указатели P1 и P2 на начало и конец непустой очереди." << std::endl;
    std::cout << "Извлечь из очереди N начальных элементов" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Вам необходимо ввести количество элементов очереди и их значения" << std::endl;
    std::cout << "Мы выведем новые адреса начала и конца очереди, извлечем N значений и выведем на экран" << std::endl;
    std::cout << std::endl << std::endl << "----------------------------------------------------------------------------" << std::endl;

    // Ввод количества элементов с проверкой
    int ElementCount = SafeInputInt("Введите число M - количество элементов очереди: ", true);

    Queue MyQueue;

    std::cout << "Введите " << ElementCount << " значений элементов очереди через пробел: ";
    for (int i = 0; i < ElementCount; ++i)
    {
        int Value = 0;
        std::cin >> Value;

        // Проверка на некорректный ввод во время заполнения
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите целое число! Элемент " << i + 1 << " будет заменен на 0." << std::endl;
            Value = 0;
        }

        MyQueue.Push(Value);
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Ввод количества элементов для извлечения с проверкой
    int ExtractCount = SafeInputInt("\nВведите число N (N > 0) - количество элементов\nочереди, которые нужно извлечь из очереди: ", true);

    std::cout << std::endl << "Исходная очередь:" << std::endl;
    MyQueue.ShowAddresses();
    std::cout << "Элементы очереди: ";
    MyQueue.Show();

    MyQueue.PopMultiple(ExtractCount);

    std::cout << std::endl << "Результат после извлечения:" << std::endl;

    if (MyQueue.IsEmpty())
    {
        std::cout << "Очередь после удаления элементов оказалась пустой" << std::endl;
        std::cout << "Начало очереди: nullptr" << std::endl;
        std::cout << "Конец очереди: nullptr" << std::endl;
    }
    else
    {
        MyQueue.ShowAddresses();
        std::cout << "Оставшиеся элементы очереди: ";
        MyQueue.Show();
    }

    return 0;
}