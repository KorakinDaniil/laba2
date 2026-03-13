/*
Дан двусвязный линейный список и указатель на первый элемент этого
списка. Создать текстовый файл, в который вывести содержимое списка в обратном
порядке. По ходу вывода списка удалять элементы в нем. Числа выводить в одну строку,
разделяя ровно одним пробелом, в конце строки пробел не ставить.

Все динамические структуры данных реализовывать через классы. Не использовать STL.
Для каждой динамической структуры должен быть предусмотрен стандартный
набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно наличие
дружественного интерфейса. Ввод данных с клавиатуры.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <cctype> // для isdigit

//FIX_ME: using namespace std; запрещено стандартом
//using namespace std;

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
    Node* First;        // Указатель на первый узел

public:
    // Конструктор
    DoublyLinkedList() : First(nullptr) {}

    // Деструктор
    ~DoublyLinkedList()
    {
        Clear();
    }

    // Добавление элемента в конец списка
    void PushBack(int InValue)
    {
        Node* NewNode = new Node;
        NewNode->Data = InValue;
        NewNode->Previous = nullptr;
        NewNode->Next = nullptr;

        if (First == nullptr)
        {
            First = NewNode;
        }
        else
        {
            Node* Current = First;
            while (Current->Next != nullptr)
            {
                Current = Current->Next;
            }
            Current->Next = NewNode;
            NewNode->Previous = Current;
        }
    }

    // Удаление указанного узла
    void RemoveNode(Node* InNodeToRemove)
    {
        if (InNodeToRemove == nullptr)
        {
            return;
        }

        Node* Prev = InNodeToRemove->Previous;
        Node* Next = InNodeToRemove->Next;

        if (Prev != nullptr)
        {
            Prev->Next = Next;
        }
        else
        {
            First = Next;
        }

        if (Next != nullptr)
        {
            Next->Previous = Prev;
        }

        delete InNodeToRemove;
    }

    // Вывод списка на экран
    void Print() const
    {
        if (IsEmpty())
        {
            std::cout << "Список пуст!" << std::endl;
            return;
        }

        Node* Current = First;
        std::cout << "Список: ";
        while (Current != nullptr)
        {
            std::cout << Current->Data << " ";
            Current = Current->Next;
        }
        std::cout << std::endl;
    }

    // Получение последнего элемента списка
    Node* GetLast() const
    {
        if (IsEmpty())
        {
            return nullptr;
        }

        Node* Current = First;
        while (Current->Next != nullptr)
        {
            Current = Current->Next;
        }
        return Current;
    }

    // Запись в файл в обратном порядке и удаление элементов
    void WriteToFileAndClear(const std::string& InFileName)
    {
        std::ofstream File(InFileName);
        if (!File.is_open())
        {
            std::cout << "Ошибка открытия файла!" << std::endl;
            return;
        }

        bool bFirstElement = true;
        Node* Current = GetLast();

        // Записываем и удаляем элементы с конца
        while (Current != nullptr)
        {
            if (bFirstElement)
            {
                File << Current->Data;
                bFirstElement = false;
            }
            else
            {
                File << " " << Current->Data;
            }

            Node* Previous = Current->Previous;
            RemoveNode(Current);
            Current = Previous;
        }

        File.close();
        std::cout << "Данные записаны в файл и список очищен." << std::endl;
    }

    // Проверка на пустоту
    bool IsEmpty() const
    {
        return First == nullptr;
    }

    // Очистка всего списка
    void Clear()
    {
        Node* Current = First;
        while (Current != nullptr)
        {
            Node* Next = Current->Next;
            delete Current;
            Current = Next;
        }
        First = nullptr;
    }
};

// Функция для ввода числа с проверкой
int InputNumber()
{
    std::string Input;
    while (true)
    {
        std::cout << "Введите число (или '-1' для завершения): ";
        std::cin >> Input;

        if (Input == "-1")
        {
            return -1;
        }

        bool bIsValid = true;
        int Sign = 1;
        size_t StartIndex = 0;

        if (Input.empty())
        {
            bIsValid = false;
        }
        else if (Input[0] == '-')
        {
            Sign = -1;
            StartIndex = 1;
            if (Input.size() == 1)
            {
                bIsValid = false;
            }
        }

        for (size_t i = StartIndex; i < Input.size(); ++i)
        {
            if (!isdigit(Input[i]))
            {
                bIsValid = false;
                break;
            }
        }

        if (bIsValid)
        {
            int Number = 0;
            for (size_t i = StartIndex; i < Input.size(); ++i)
            {
                Number = Number * 10 + (Input[i] - '0');
            }
            return Number * Sign;
        }
        else
        {
            std::cout << "Некорректный ввод! Используйте цифры и знак '-' в начале." << std::endl;
        }
    }
}

// Функция для вывода содержимого файла
void PrintFileContent(const std::string& InFileName)
{
    std::ifstream File(InFileName);
    if (!File.is_open())
    {
        std::cout << "Ошибка при открытии файла для чтения!" << std::endl;
        return;
    }

    std::cout << "\n=== Содержимое файла ===" << std::endl;
    std::string Line;
    while (getline(File, Line))
    {
        std::cout << Line << std::endl;
    }
    File.close();
}

int Task4()
{
    setlocale(LC_ALL, "Russian");

    DoublyLinkedList MyList;

    std::cout << "=== Ввод чисел в список ===" << std::endl;
    while (true)
    {
        int Number = InputNumber();
        if (Number == -1)
        {
            break;
        }
        MyList.PushBack(Number);
    }

    MyList.Print();

    std::cout << "\n=== Запись в файл ===" << std::endl;
    std::string FileName;
    std::cout << "Введите имя файла: ";
    std::cin >> FileName;

    MyList.WriteToFileAndClear(FileName);
    PrintFileContent(FileName);

    return 0;
}