/*
Дан односвязный линейный список и указатель на голову списка P1. Значения
элементов списка упорядочены по возрастанию. Необходимо создать копию исходного списка,
после чего во вновь созданном списке вставить в список значение M так, чтобы он остался
упорядоченным и вывести ссылку на первый элемент полученного списка P2.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
*/

#include <iostream>
#include <clocale>

//FIX_ME: Неправильное подключение Windows.h для кодировки
//#include <windows.h>

//FIX_ME: using namespace std; запрещено стандартом
//using namespace std;

// Класс узла списка
class Node3
{
public:
    int Data;       // Значение узла
    Node3* Next;     // Указатель на следующий узел

    // Конструктор узла
    explicit Node3(int InData) : Data(InData), Next(nullptr) {}
};

//FIX_ME: Отсутсвовал класс односвязного списка. методы были отдельными функциями, а не цельной структурой
// Класс односвязного списка
class LinkedList
{
private:
    Node3* Head;     // Указатель на голову списка

public:
    // Конструктор
    LinkedList() : Head(nullptr) {}

    // Деструктор
    ~LinkedList()
    {
        Clear();
    }

    // Добавление элемента в конец списка
    void PushBack(int InData)
    {
        Node3* NewNode = new Node3(InData);

        if (IsEmpty())
        {
            Head = NewNode;
        }
        else
        {
            Node3* Current = Head;
            while (Current->Next != nullptr)
            {
                Current = Current->Next;
            }
            Current->Next = NewNode;
        }
    }

    // Вставка элемента с сохранением упорядоченности
    void InsertSorted(int InData)
    {
        Node3* NewNode = new Node3(InData);

        // Если список пуст или новый элемент должен быть первым
        if (IsEmpty() || Head->Data >= InData)
        {
            NewNode->Next = Head;
            Head = NewNode;
            return;
        }

        // Поиск позиции для вставки
        Node3* Current = Head;
        while (Current->Next != nullptr && Current->Next->Data < InData)
        {
            Current = Current->Next;
        }

        // Вставка элемента
        NewNode->Next = Current->Next;
        Current->Next = NewNode;
    }

    // Удаление элемента по значению
    bool RemoveByValue(int InData)
    {
        if (IsEmpty())
        {
            return false;
        }

        // Если удаляем первый элемент
        if (Head->Data == InData)
        {
            Node3* Temp = Head;
            Head = Head->Next;
            delete Temp;
            return true;
        }

        // Поиск элемента для удаления
        Node3* Current = Head;
        while (Current->Next != nullptr && Current->Next->Data != InData)
        {
            Current = Current->Next;
        }

        // Если элемент найден
        if (Current->Next != nullptr)
        {
            Node3* Temp = Current->Next;
            Current->Next = Temp->Next;
            delete Temp;
            return true;
        }

        return false; // Элемент не найден
    }

    // Поиск элемента по значению (возвращает указатель на узел)
    Node3* Find(int InData) const
    {
        Node3* Current = Head;
        while (Current != nullptr && Current->Data != InData)
        {
            Current = Current->Next;
        }
        return Current;
    }

    // Поиск позиции для вставки (возвращает предыдущий узел)
    Node3* FindInsertPosition(int InData) const
    {
        if (IsEmpty() || Head->Data >= InData)
        {
            return nullptr; // Вставка в начало
        }

        Node3* Current = Head;
        while (Current->Next != nullptr && Current->Next->Data < InData)
        {
            Current = Current->Next;
        }
        return Current;
    }

    // Вывод всех элементов списка
    void Show() const
    {
        if (IsEmpty())
        {
            std::cout << "Список пуст!" << std::endl;
            return;
        }

        Node3* Current = Head;
        while (Current != nullptr)
        {
            std::cout << Current->Data << " ";
            Current = Current->Next;
        }
        std::cout << std::endl;
    }

    // Вывод адреса головы списка
    void ShowHeadAddress() const
    {
        std::cout << "Адрес головы списка P2: " << Head;
        if (Head != nullptr)
        {
            std::cout << " (значение: " << Head->Data << ")";
        }
        std::cout << std::endl;
    }

    // Проверка на пустоту
    bool IsEmpty() const
    {
        return Head == nullptr;
    }

    // Очистка списка
    void Clear()
    {
        while (!IsEmpty())
        {
            Node3* Temp = Head;
            Head = Head->Next;
            delete Temp;
        }
    }

    // Получение головы списка (для копирования)
    Node3* GetHead() const
    {
        return Head;
    }

    // Создание копии списка
    LinkedList* Clone() const
    {
        LinkedList* NewList = new LinkedList();

        Node3* Current = Head;
        while (Current != nullptr)
        {
            NewList->PushBack(Current->Data);
            Current = Current->Next;
        }

        return NewList;
    }
};

//FIX_ME: Отсутствие проверки на дурака
// Функция для безопасного ввода целого числа с проверкой
int SafeInputInt2(const std::string& InPrompt, bool bPositiveOnly = false, bool bOddOnly = false)
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

// Функция для безопасного ввода значения с проверкой на упорядоченность
int SafeInputValue(int InElementNumber, int PreviousValue = -1, bool bNeedGreater = false)
{
    int Value = 0;
    bool bValidInput = false;

    while (!bValidInput)
    {
        std::cout << "Введите элемент " << InElementNumber << ": ";
        std::cin >> Value;

        // Проверка на некорректный ввод
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите целое число!" << std::endl;
            continue;
        }

        // Проверка на упорядоченность (если требуется)
        if (bNeedGreater && Value <= PreviousValue)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: значение должно быть больше предыдущего (" << PreviousValue << ")!" << std::endl;
            continue;
        }

        // Если дошли сюда, ввод корректен
        bValidInput = true;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return Value;
}

int Task3()
{
    //FIX_ME: Неправильная установка кодировки
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    std::cout << "Добро пожаловать!" << std::endl;
    std::cout << "Перед нами последняя задача: " << std::endl;
    std::cout << "Дан односвязный линейный список. Значения элементов списка упорядочены по возрастанию." << std::endl;
    std::cout << "Необходимо создать копию исходного списка, после чего во вновь созданном списке вставить" << std::endl;
    std::cout << "значение M так, чтобы он остался упорядоченным и вывести ссылку на первый элемент полученного списка P2." << std::endl << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl << std::endl;
    std::cout << "Вам необходимо будет ввести количество элементов в списке," << std::endl;
    std::cout << "а позже ввести значения элементов СТРОГО В ПОРЯДКЕ ВОЗРАСТАНИЯ " << std::endl;
    std::cout << "и ввести число которое вы хотите вставить." << std::endl;
    std::cout << "ПРИМЕР ПОРЯДКА ВОЗРАСТАНИЯ: 1 2 3 4 5 6" << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;

    // Ввод количества элементов с проверкой
    int ElementCount = SafeInputInt2("Введите число N - количество элементов в списке: ", true);

    // Создаем исходный список
    LinkedList* OriginalList = new LinkedList();

    std::cout << "Введите " << ElementCount << " чисел в порядке возрастания:" << std::endl;

    int PreviousValue = 0; // Для проверки упорядоченности

    for (int i = 0; i < ElementCount; ++i)
    {
        int Value;

        if (i == 0)
        {
            Value = SafeInputValue(i + 1);
            PreviousValue = Value;
        }
        else
        {
            Value = SafeInputValue(i + 1, PreviousValue, true);
            PreviousValue = Value;
        }

        OriginalList->PushBack(Value);
    }

    // Создаем копию исходного списка
    LinkedList* CopiedList = OriginalList->Clone();

    // Ввод значения для вставки
    int ValueToInsert = SafeInputInt2("\nВведите целое значение числа M, которое необходимо будет вставить: ");

    // Вывод исходного списка
    std::cout << std::endl << "Исходный список P1: ";
    OriginalList->Show();

    // Вставка элемента в скопированный список
    CopiedList->InsertSorted(ValueToInsert);

    // Вывод результата
    std::cout << "Список P2 после вставки значения " << ValueToInsert << ": ";
    CopiedList->Show();
    CopiedList->ShowHeadAddress();

    // Дополнительная функциональность: удаление элементов по желанию пользователя
    std::cout << std::endl << "Хотите удалить какой-нибудь элемент?" << std::endl;
    std::cout << "Если да, то напишите 1" << std::endl;
    std::cout << "Если нет, то напишите 2" << std::endl;

    int Choice = SafeInputInt2("Ваш выбор: ", false);

    switch (Choice)
    {
    case 1:
    {
        int RemoveCount = SafeInputInt2("Введите количество элементов которое вы хотите удалить: ", true);

        for (int i = 0; i < RemoveCount; ++i)
        {
            int ValueToRemove = SafeInputInt2("Введите значение элемента, который вы хотите удалить: ");

            if (CopiedList->RemoveByValue(ValueToRemove))
            {
                std::cout << "Элемент " << ValueToRemove << " успешно удален." << std::endl;
            }
            else
            {
                std::cout << "Элемент " << ValueToRemove << " не найден в списке." << std::endl;
            }
        }

        std::cout << "Список после удаления: ";
        CopiedList->Show();
        break;
    }

    case 2:
    {
        std::cout << "Спасибо за терпение!!!" << std::endl;
        std::cout << "До свидания!!!" << std::endl;
        break;
    }

    default:
    {
        std::cout << "Введено неверное число" << std::endl;
        break;
    }
    }

    // Очистка памяти
    delete OriginalList;
    delete CopiedList;

    return 0;
}