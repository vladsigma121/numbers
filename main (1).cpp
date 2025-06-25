#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> 
#include <string>

using namespace std;

//проверка
int getValidInput() {
    int number;
    while (true) {
        cin >> number;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Ошибка! Введите число: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }
    }
}

//игра
void playGame() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    const int maxAttempts = 8;

    cout << "\nЯ загадал число от 1 до 100. Попробуй угадать!" << endl;
    cout << "У тебя есть " << maxAttempts << " попыток." << endl << endl;

    while (attempts < maxAttempts) {
        cout << "Попытка №" << attempts + 1 << ". Введи число: ";
        guess = getValidInput();
        attempts++;

        if (guess < secretNumber) {
            cout << "Слишком маленькое! Попробуй еще раз." << endl;
        }
        else if (guess > secretNumber) {
            cout << "Слишком большое! Попробуй еще раз." << endl;
        }
        else {
            cout << "Поздравляю! Ты угадал число: " << secretNumber
                << " за " << attempts << " попыток!" << endl;
            return;
        }
    }

    cout << "К сожалению, ты не угадал. Загаданное число было: "
        << secretNumber << endl;
}

int main() {
    setlocale(LC_ALL, "rus");

    char playAgain;

    cout << "|   Добро пожаловать в игру:  |" << endl;
    cout << "|=============================|" << endl;
    cout << "|    УГАДАЙ ЧИСЛО (1-100)     | " << endl;
    cout << "|=============================|" << endl;
    do {
        playGame();
        cout << "\nХочешь сыграть еще раз? (y/n): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Спасибо за игру! До свидания!" << endl;
    return 0;
}