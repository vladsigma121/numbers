#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> 
#include <string>

using namespace std;

//��������
int getValidInput() {
    int number;
    while (true) {
        cin >> number;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "������! ������� �����: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }
    }
}

//����
void playGame() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    const int maxAttempts = 8;

    cout << "\n� ������� ����� �� 1 �� 100. �������� �������!" << endl;
    cout << "� ���� ���� " << maxAttempts << " �������." << endl << endl;

    while (attempts < maxAttempts) {
        cout << "������� �" << attempts + 1 << ". ����� �����: ";
        guess = getValidInput();
        attempts++;

        if (guess < secretNumber) {
            cout << "������� ���������! �������� ��� ���." << endl;
        }
        else if (guess > secretNumber) {
            cout << "������� �������! �������� ��� ���." << endl;
        }
        else {
            cout << "����������! �� ������ �����: " << secretNumber
                << " �� " << attempts << " �������!" << endl;
            return;
        }
    }

    cout << "� ���������, �� �� ������. ���������� ����� ����: "
        << secretNumber << endl;
}

int main() {
    setlocale(LC_ALL, "rus");

    char playAgain;

    cout << "|   ����� ���������� � ����:  |" << endl;
    cout << "|=============================|" << endl;
    cout << "|    ������ ����� (1-100)     | " << endl;
    cout << "|=============================|" << endl;
    do {
        playGame();
        cout << "\n������ ������� ��� ���? (y/n): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "������� �� ����! �� ��������!" << endl;
    return 0;
}