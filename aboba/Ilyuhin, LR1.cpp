// aboba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    string file_name_input, password, file_name_output;
    int n;

    cout << "-------------------------" << endl
        << "1. Реализовать шифрование по таблице Виженера" << endl
        << "2. Реализовать дешифровнаие по таблице Виженера" << endl
        << "0. Выйти" << endl
        << "Введите действие:" << endl;
    cin >> n;

    if (n == 0)
        return 0;
    else
    {
        cout << "Введите название файла, откуда считывать текст (вместе с расширением!)" << endl;
        cin >> file_name_input;

        cout << "Введите пароль!" << endl;
        cin >> password;

        cout << "Введите название файла, куда сохранять текст (вместе с расширением!)" << endl;
        cin >> file_name_output;

        ifstream fin;
        fin.open(file_name_input, ios_base::binary);

        ofstream fout;
        fout.open(file_name_output, ios_base::binary);
        int i = 0;
        char ch;

        while (true)
        {
            if (fin.get(ch))
            {
                if (i >= (password.size() - 1))
                {
                    i = 0;
                }
                i += 1;
                if (n == 1)
                    fout << unsigned char(ch + password[i]);
                if (n == 2)
                    fout << unsigned char(ch - password[i]);
            }
            else
            {
                fin.close();
                fout.close();
                cout << "-------------------------" << endl
                    << "1. Реализовать шифрование по таблице Виженера" << endl
                    << "2. Реализовать дешифровнаие по таблице Виженера" << endl
                    << "0. Выйти" << endl
                    << "Введите действие:" << endl;
                cin >> n;
                if (n == 0)
                    return 0;
                else
                {

                    cout << "Введите название файла, откуда считывать текст (вместе с расширением!)" << endl;
                    cin >> file_name_input;

                    cout << "Введите пароль!" << endl;
                    cin >> password;

                    cout << "Введите название файла, куда сохранять текст (вместе с расширением!)" << endl;
                    cin >> file_name_output;

                    fin.open(file_name_input, ios_base::binary);
                    if (!fin.is_open())
                        cout << "не удалось открыть файл";

                    fout.open(file_name_output, ios_base::binary);

                    i = 0;
                }
            }
        }
    }
    return 0;
}
