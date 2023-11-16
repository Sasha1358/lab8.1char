#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* s)
{
    int k = 0;
    int pos = 0;
    char* t;

    while (t = strchr(s + pos, 'a')) // Пошук символу 'a'
    {
        pos = t - s + 1; // Позиція наступного символу після 'a'

        if (s[pos] == 'a')
        {
            k++;
        }
    }

    pos = 0;

    while (t = strchr(s + pos, 'b')) // Пошук символу 'a'
    {
        pos = t - s + 1; // Позиція наступного символу після 'a'

        if (s[pos] == 'b')
        {
            k++;
        }
    }
    pos = 0;
    

    while (t = strchr(s + pos, 'c')) // Пошук символу 'a'
    {
        pos = t - s + 1; // Позиція наступного символу після 'a'

        if (s[pos] == 'c' )
        {
            k++;
        }
    }

    return k;

}

char* Change(char* s)
{
    char* t = new char[strlen(s) * 3 + 1]; // Більший буфер для зберігання зміненого рядка
    char* p;
    int pos1 = 0;
    int pos2 = 0;
    *t = 0;

    while ((p = strchr(s + pos1, 'a')) || (p = strchr(s + pos1, 'b')) || (p = strchr(s + pos1, 'c'))) // Пошук символу 'a' 'b'
    {
        if ((s[p - s + 1] == 'a') || (s[p - s + 1] == 'b') || (s[p - s + 1] == 'c'))
        {
            pos2 = p - s + 2; // Позиція наступного символа після другого 'a' 'b'
            strncat(t, s + pos1, pos2 - pos1 - 2);
            strcat(t, "***");
            pos1 = pos2;
        }
        else
        {
            pos2 = p - s + 1; // Позиція наступного символа після першого 'a' 'b'
            strncat(t, s + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }
    while (p = strchr(s + pos1, 'c')) // Пошук символу 'c'
    {
        if ((s[p - s + 1] == 'c'))
        {
            pos2 = p - s + 2; // Позиція наступного символа після другого 'c'
            strncat(t, s + pos1, pos2 - pos1 - 2);
            strcat(t, "***");
            pos1 = pos2;
        }
        else
        {
            pos2 = p - s + 1; // Позиція наступного символа після першого 'c'
            strncat(t, s + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }

    strcat(t, s + pos1);
    strcpy(s, t);

    return t;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of 'aa', 'bb', 'cc'" << endl;

    char* dest = Change(str);
    cout << "Modified string (param): " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;

    return 0;
}