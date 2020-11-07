#include <iostream>
#include <iostream>
#include <Windows.h>	
#include <string>
#include "ceasar.h"
#include "atbash.h"
#include "affine.h"
using namespace std;

string readSourceText()
{
    string sourceText;
    cin.ignore();
    cout << "Введите текст, который необходимо зашифровать -> ";
    getline(cin, sourceText);
    return sourceText;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "[ШИФРОВАНИЕ]\n";
    int mode;
    while (true)
    {
        while (true)
        {
            cout << "Выберите режим:\n1 - Шифр Цезаря\n2 - Афинный шифр\n3 - Шифр Атбаш\n0 - Выход из программы\n";
            cin >> mode;
            if (mode > 3 || mode < 0 || cin.fail())
            {
                cout << "Некорректный ввод! Попробуйте еще раз!";
                cin.clear();
                cin.ignore(32767, '\n');
            }
            else break;
        }
        switch (mode)
        {
        case 1: cout << "[Шифр Цезаря]\n"; cout << toCaesar(readSourceText()) << endl; break;
        case 2: cout << "[Шифр Аффинный]\n"; cout << toAffine(readSourceText()) << endl; break;
        case 3: cout << "[Шифр Атбаш]\n"; cout << toAtbash(readSourceText()) << endl; break;
        case 0: exit(0);
        }
    }

}
