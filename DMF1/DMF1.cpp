
#include <iostream>
#include <stdlib.h>


using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m, s, s2, i, t, kol, number, size1 = 0, size2 = 0;
    int a[20];
    int b[20];
    cout << '\t' << "Vvedite moschnost mnozhestva A, ne prevoshodyashuyu 20: " << endl;
    cin >> n;  //вводится мощность множества А
    if (n > 20)  //проверка, удовлетворяет ли мощность условию, если нет, то выводится ошибка и происходит выход из программы
    {
        cout << '\t' << "ERROR! Moschnost mnozhestva A prevoshodit maksimalnuyu vozmozhnuyu moschnost." << endl;
        exit(0);
    }
    cout << '\t' << "Vvedite elementi mnozhestva A: " << endl;
    for (i = 0; i < n; i++) //ввод элементов множества А
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++) //Цикл проверки на повторяющиеся элементы ( не знаю нужен ли он, но решила сделать на всякий случай)
    {
        number = a[i]; //выбираем элемент, который проверяем
        kol = 1;
        for (t = 0; t < n; t++) //проходимся по элементам, если есть тот же элемент, то добавляем к переменной, обозначающей количество какого-либо числа множества 1
        {
            if (a[t] == number)
            {
                kol++;
            }
        }
        if (kol >= 2) //если элемент повторяется 2+ раз, то выводится окно ошибки и выход из программы
        {
            cout << '\t' << "ERROR! Zadannaya posledovatelnost chisel ne yavlyaetsya mnozhestvom." << endl;
            exit(0);
        }
    }
    cout << '\t' << "Vvedite moschnost mnozhestva B, ne prevoshodyashuyu 20: " << endl;
    cin >> m;  //вводится мощность множества В
    if (m > 20)  //проверка, удовлетворяет ли мощность условию, если нет, то выводится ошибка и происходит выход из программы
    {
        cout << '\t' << "ERROR! Moschnost mnozhestva B prevoshodit maksimalnuyu vozmozhnuyu moschnost." << endl;
        exit(0);
    }
    cout << '\t' << "Vvedite elementi mnozhestva B: " << endl;
    for (i = 0; i < m; i++) //ввод элементов множества B
    {
        cin >> b[i];
    }
    for (i = 0; i < m; i++) //опять он
    {
        number = b[i]; //выбираем элемент, который проверяем
        kol = 1;
        for (t = 0; t < m; t++)   //проходимся по элементам, если есть тот же элемент, то добавляем к переменной, обозначающей количество какого-либо числа множества 1
        {
            if (b[t] == number)
            {
                kol++;
            }
        }
        if (kol >= 2) //если элемент повторяется 2+ раз, то выводится окно ошибки и выход из программы
        {
            cout << '\t' << "ERROR! Zadannaya posledovatelnost chisel ne yavlyaetsya mnozhestvom." << endl;
            exit(0);
        }
    }
    while (true)
    {
        cout << '\t' << "Viberite deistvie:" << endl;
        cout << '\t' << "1 - obedinenie mnozhestv;" << '\n' << '\t' << "2 - peresechenie mnozhestv;" << '\n' << '\t' << "3 - rasnost;" << '\n' << '\t' << "4 - simmetricheskaya raznost;" << '\n' << '\t' << "5 - dekartovo proizvedenie;" << '\n' << '\t' << "6 - dopolnenie;" << '\n' << '\t' << "0 - exit." << endl;
        cin >> s; //происходит выбор опции
        switch (s)
        {
        case 1: // объединение
            cout << '\t' << "Obedinenie mnozhestv = ( ";
            int c[40];
            size1 = 0;
            size2 = 0;
            int d[20];
            for (i = 0; i < m; i++) //циклически проверяем каждый элемент из множества В
            {
                number=b[i];
                kol = 1;
                for (t = 0; t < n; t++) //сравниваем его с каждым элементом множества А, если они повторяются, то добавляем к количественной переменной 1
                {
                    if (a[t] == number)
                    {
                        kol++;
                    }
                }
                if (kol == 1) //если элемент множества В не повторяется в множестве А, то записываем его в рандомное множество
                {
                    d[size2] = b[i];
                    size2++;
                }
            }
            for (i = 0; i < n; i++) //записываем все элементы множества А в множество, которое является объединением
            {
                c[size1] = a[i];
                size1++;
            }
            for (i = 0; i < size2; i++) //записываем не повторяющиеся элементы множества В
            {
                c[size1] = d[i];
                size1++;
            }
            for (i = 0; i < size1; i++) //выводим на экран
            {
                cout << c[i] << " ";
            }
            cout << ")" << '\n' << endl;
            break;
        case 2: //пересечение
            cout << '\t' << "Peresechenie mnozhestv = ( ";
            int e[20];
            size1 = 0;
            size2 = 0;
            for (i = 0; i < m; i++) //циклически проверяем каждый элемент множества В
            {
                number = b[i];
                kol = 1;
                for (t = 0; t < n; t++) //сравниваем его с каждым элементом множества А, если они повторяются, то добавляем к количественной переменной 1
                {
                    if (a[t] == number)
                    {
                        kol++;
                    }
                }
                if (kol > 1) //если  элементы повторяются в обоих множествах, записываем их в множество пересечения
                {
                    e[size2] = b[i];
                    size2++;
                }
            }
            for (i = 0; i < size2; i++) //выводим на экран
            {
                cout << e[i] << " ";
            }
            cout << ")" << '\n' << endl;
            break;
        case 3: //разность
            cout << '\t' << "Viberite deistvie:" << endl;
            cout << '\t' << "1 - A-B;" << '\n' << '\t' << "2 - B-A;" << '\n' << '\t' << "0 - exit." << endl;
            cin >> s2; //выбираем, отнимаем ли мы В от А или А от В
            switch (s2)
            {
            case 1: // A-B
                cout << '\t' << "Raznost A-B = ( ";
                int f[20];
                size1 = 0;
                size2 = 0;
                for (i = 0; i < n; i++)
                {
                    number = a[i];
                    kol = 1;
                    for (t = 0; t < m; t++)
                    {
                        if (b[t] == number)
                        {
                            kol++;
                        }
                    }
                    if (kol == 1)
                    {
                        f[size1] = a[i];
                        size1++;
                    }
                }
                for (i = 0; i < size1; i++)
                {
                    cout << f[i] << " ";
                }
                cout << ")" << '\n' << endl;
                break;
            case 2: //B-A
                cout << '\t' << "Raznost B-A = ( ";
                int g[20];
                size1 = 0;
                size2 = 0;
                for (i = 0; i < m; i++)
                {
                    number = b[i];
                    kol = 1;
                    for (t = 0; t < n; t++)
                    {
                        if (a[t] == number)
                        {
                            kol++;
                        }
                    }
                    if (kol == 1)
                    {
                        g[size2] = b[i];
                        size2++;
                    }
                }
                for (i = 0; i < size2; i++)
                {
                    cout << g[i] << " ";
                }
                cout << ")" << '\n' << endl;
                break;
            case 0: //Выход если вдруг кто-то передумал
                break;
            }
            break;
        case 4:
            cout << '\t' << "Simmetricheskaya raznost = ( ";
            int h[20];
            int j[20];
            size1 = 0;
            size2 = 0;
            for (i = 0; i < n; i++)
            {
                number = a[i];
                kol = 1;
                for (t = 0; t < m; t++)
                {
                    if (b[t] == number)
                    {
                        kol++;
                    }
                }
                if (kol == 1)
                {
                    h[size1] = a[i];
                    size1++;
                }
            }
            for (i = 0; i < m; i++)
            {
                number = b[i];
                kol = 1;
                for (t = 0; t < n; t++)
                {
                    if (a[t] == number)
                    {
                        kol++;
                    }
                }
                if (kol == 1)
                {
                    j[size2] = b[i];
                    size2++;
                }
            }
            for (i = 0; i < size1; i++)
            {
                cout << h[i] << " ";
            }
            for (i = 0; i < size2; i++)
            {
                cout << j[i] << " ";
            }
            cout << ")" << '\n' << endl;
            break;
        case 5: //декартово произведение
            cout << '\t' << "Dekartovoe proizvedenie = ( ";
            break;
        case 6: //дополнение
            cout << '\t' << "Dopolnenie = ( ";
            break;
        case 0: //выход
            exit(1);
        }
    }
}



