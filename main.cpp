#include "head.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    // Флаг для продолжения
    bool bContinue = false;

    std::cout << "Выполняем запуск Task1" << std::endl;
    Task1();

    // Очищаем буфер после Task1
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Продолжить выполнение следующего задания? (1 - да, 0 - нет): ";
    std::cin >> bContinue;

    if (bContinue)
    {
        std::cout << "\nВыполняем запуск Task2" << std::endl;
        Task2();

        // Очищаем буфер после Task2
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Продолжить выполнение следующего задания? (1 - да, 0 - нет): ";
        std::cin >> bContinue;

        if (bContinue)
        {
            std::cout << "\nВыполняем запуск Task3" << std::endl;
            Task3();

            // Очищаем буфер после Task3
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Продолжить выполнение следующего задания? (1 - да, 0 - нет): ";
            std::cin >> bContinue;

            if (bContinue)
            {
                std::cout << "\nВыполняем запуск Task4" << std::endl;
                Task4();

                // Очищаем буфер после Task4
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Продолжить выполнение следующего задания? (1 - да, 0 - нет): ";
                std::cin >> bContinue;

                if (bContinue)
                {
                    std::cout << "\nВыполняем запуск Task5" << std::endl;
                    Task5();
                }
            }
        }
    }

    std::cout << "\nВсе задания выполнены. До свидания!" << std::endl;
    return 0;
}