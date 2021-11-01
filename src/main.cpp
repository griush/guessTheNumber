#include <iostream>
#include <random>
#include <time.h>
#include <Windows.h>

void introMenu()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 3);
    std::cout << "Guess the number!" << std::endl;
    std::cout << "A random number between 1 and 1000 is generated, you have to guess it!" << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
}

int generateNumber()
{
    srand(time(NULL));

    return rand() % 1000 + 1;
}

void winMessage(int attempts)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 10);
    std::cout << "You won!" << std::endl << "It took you " << attempts << " attempts!" << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void higher()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 6);
    std::cout << "Try higher!" << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void lower()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "Try lower!" << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
}

int main()
{
    bool isRunning = false;
    introMenu();

    int secret = generateNumber();
    int attempts = 0;

    isRunning = true;
    while (isRunning) 
    {
        int guess;
        std::cin >> guess;

        attempts++;

        if (guess == secret)
        {
            winMessage(attempts);
            isRunning = false;
        }
        else if (guess < secret)
        {
            higher();
        }
        else if (guess > secret)
        {
            lower();
        }
    }

    std::cin.get();
    std::cin.get();

    return 0;
}