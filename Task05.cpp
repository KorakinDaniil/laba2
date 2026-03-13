/*
Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать
разными способами (с клавиатуры, рандом, из файла)

Даны списки L1 и L2; список L1 имеет нечетное количество элементов.
Переместить средний элемент списка L1 в конец списка L2. Использовать один вызов
функции-члена splice.
*/

#include <ctime>
#include <list>
#include <fstream>
#include <iostream>
#include <clocale>
#include <cstdlib> // для rand и srand

//FIX_ME: using namespace std; запрещено стандартом
//using namespace std;

// Заполнение списка выбранным способом
void InputList(std::list<int>& OutList, int InSize)
{
    int Choice = 0;
    int Value = 0;

    std::cout << "Выберите способ заполнения контейнера: " << std::endl;
    std::cout << "1) Ввод с клавиатуры." << std::endl;
    std::cout << "2) Ввод с помощью рандомайзера." << std::endl;
    std::cout << "3) Ввод данных из текстового файла." << std::endl;
    std::cin >> Choice;

    switch (Choice)
    {
    case 1: // Ввод с клавиатуры
    {
        for (int i = 0; i < InSize; ++i)
        {
            std::cout << "Введите " << i + 1 << " элемент: ";
            std::cin >> Value;
            OutList.insert(OutList.end(), Value);
        }
        break;
    }

    case 2: // Случайные числа
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        for (int i = 0; i < InSize; ++i)
        {
            OutList.insert(OutList.end(), std::rand() % 101 - 50);
        }
        break;
    }

    case 3: // Чтение из файла
    {
        std::ifstream File("a.txt", std::ios::in); // a.txt { 27 -8 -11 -25 33 47 -30 -41 -8 3 -13 -29 -38 -18}
        if (!File.is_open())
        {
            std::cout << "Ошибка. Файл не был открыт." << std::endl;
            return;
        }
        for (int i = 0; i < InSize; ++i)
        {
            File >> Value;
            OutList.insert(OutList.end(), Value);
        }
        File.close();
        break;
    }

    default:
    {
        std::cout << "Ошибка ввода." << std::endl;
        break;
    }
    }
}

// Вывод содержимого списка на экран
void PrintList(const std::list<int>& InList)
{
    if (InList.empty())
    {
        std::cout << "(пустой список)";
        return;
    }

    for (auto It = InList.begin(); It != InList.end(); ++It)
    {
        std::cout << *It << " ";
    }
}

// Вывод содержимого списка в обратном порядке
void PrintListReverse(const std::list<int>& InList)
{
    if (InList.empty())
    {
        std::cout << "(пустой список)";
        return;
    }

    for (auto It = InList.rbegin(); It != InList.rend(); ++It)
    {
        std::cout << *It << " ";
    }
}

// Перемещение среднего элемента из L1 в конец L2
void SpliceMiddleToListEnd(std::list<int>& InOutL1, std::list<int>& InOutL2)
{
    if (InOutL1.empty())
    {
        return;
    }

    auto Iterator = InOutL1.begin();
    size_t Size = InOutL1.size();

    // Перемещаем итератор на средний элемент (для нечетного размера)
    for (size_t i = 0; i < Size / 2; ++i)
    {
        ++Iterator;
    }

    // Один вызов splice для перемещения элемента
    InOutL2.splice(InOutL2.end(), InOutL1, Iterator);
}

int Task5()
{
    setlocale(LC_ALL, "Russian");

    int Size1 = 0;
    int Size2 = 0;
    std::list<int> List1;
    std::list<int> List2;

    std::cout << "Введите размерность списка n1 (n1 - нечётное): ";
    std::cin >> Size1;

    // Проверка корректности размера первого списка
    if (Size1 < 0 || Size1 % 2 != 1)
    {
        std::cout << "Ошибка. Недопустимый размер списка. n1 должно быть нечётным положительным числом." << std::endl;
        return 1;
    }

    InputList(List1, Size1);

    std::cout << "Введите размерность списка n2 (n2 >= 0): ";
    std::cin >> Size2;

    // Проверка корректности размера второго списка
    if (Size2 < 0)
    {
        std::cout << "Ошибка. Недопустимый размер списка. n2 должно быть >= 0." << std::endl;
        return 1;
    }

    InputList(List2, Size2);

    // Вывод исходных списков
    std::cout << "\nИсходное содержимое списков:" << std::endl;
    std::cout << "L1 (прямой порядок): ";
    PrintList(List1);
    std::cout << "\nL1 (обратный порядок): ";
    PrintListReverse(List1);

    std::cout << "\nL2 (прямой порядок): ";
    PrintList(List2);
    std::cout << "\nL2 (обратный порядок): ";
    PrintListReverse(List2);
    std::cout << std::endl;

    // Выполнение операции splice
    SpliceMiddleToListEnd(List1, List2);

    // Вывод измененных списков
    std::cout << "\nИзменённое содержимое списков:" << std::endl;
    std::cout << "L1 (прямой порядок): ";
    PrintList(List1);
    std::cout << "\nL1 (обратный порядок): ";
    PrintListReverse(List1);

    std::cout << "\nL2 (прямой порядок): ";
    PrintList(List2);
    std::cout << "\nL2 (обратный порядок): ";
    PrintListReverse(List2);
    std::cout << std::endl;

    return 0;
}