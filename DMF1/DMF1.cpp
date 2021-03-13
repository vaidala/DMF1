
#include <iostream>
#include <stdlib.h>


using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m, s, s2, s3, s4, s5, i, y, t, kol, number, size1 = 0, size2 = 0;
    int a[20];
    int b[20];
    cout << '\t' << "Vvedite moschnost mnozhestva A, ne prevoshodyashuyu 20: " << endl;
    cin >> n;  //вводится мощность множества А
    if (n > 20)  //проверка, удовлетворяет ли мощность условию, если нет, то выводится ошибка и происходит выход из программы
    {
        cout << '\t' << "ERROR! Moschnost mnozhestva A prevoshodit maksimalnuyu vozmozhnuyu moschnost." << endl;
        exit(0);
    }
    cout << '\t' << "Vvedite sposob zadania mnozhestva A:" << endl;;
    cout << '\t' << "1- s klaviaturi;" << '\n' << '\t' << "2 - viskazivaniem" << '\n' << endl;
    cin >> s2; //выбор способа задания множества
    switch (s2)
    {
    case 1:
        cout << '\t' << "Vvedite elementi mnozhestva A: " << endl; //задание с клавиатуры
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
            if (kol > 2) //если элемент повторяется 2+ раз, то выводится окно ошибки и выход из программы
            {
                cout << '\t' << "ERROR! Zadannaya posledovatelnost chisel ne yavlyaetsya mnozhestvom." << endl;
                exit(0);
            }
        }
        break;
    case 2:  //задание выражением
        cout << '\t' << "A = ( ";
        for (y = 0; y < n; y++) 
        {
            a[y] = 2 * y - 1;
            cout << a[y] << " ";
        }
        cout << ")" << '\n' << endl;
        break;
    }
    cout << '\t' << "Vvedite moschnost mnozhestva B, ne prevoshodyashuyu 20: " << endl;
    cin >> m;  //вводится мощность множества В
    if (m > 20)  //проверка, удовлетворяет ли мощность условию, если нет, то выводится ошибка и происходит выход из программы
    {
        cout << '\t' << "ERROR! Moschnost mnozhestva B prevoshodit maksimalnuyu vozmozhnuyu moschnost." << endl;
        exit(0);
    }
    cout << '\t' << "Vvedite sposob zadania mnozhestva B:" << endl;;
    cout << '\t' << "1- s klaviaturi;" << '\n' << '\t' << "2 - viskazivaniem" << '\n' << endl;
    cin >> s3; //выбирается способ задания множества
    switch (s3)
    {
    case 1:   
        cout << '\t' << "Vvedite elementi mnozhestva B: " << endl; //ввод с клавиатуры
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
            if (kol > 2) //если элемент повторяется 2+ раз, то выводится окно ошибки и выход из программы
            {
                cout << '\t' << "ERROR! Zadannaya posledovatelnost chisel ne yavlyaetsya mnozhestvom." << endl;
                exit(0);
            }
        }
        break;
    case 2:
        cout << '\t' << "B = ( "; //ввод с использованием выражения
        for (y = 0; y < m; y++)
        {
            b[y] = 2 * y + 3;
            cout << b[y] << " ";
        }
        cout << ")" << '\n' << endl;
        break;
    }
    while (true)
    {
        cout << '\t' << "Viberite deistvie:" << endl;
        cout << '\t' << "1 - obedinenie mnozhestv;" << '\n' << '\t' << "2 - peresechenie mnozhestv;" << '\n' << '\t' << "3 - rasnost;" << '\n' << '\t' << "4 - simmetricheskaya raznost;" << '\n' << '\t' << "5 - dekartovo proizvedenie;" << '\n' << '\t' << "6 - dopolnenie;" << '\n' << '\t' << "0 - exit." << endl;
        cin >> s4; //происходит выбор опции
        switch (s4)
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
            cin >> s4; //выбираем, отнимаем ли мы В от А или А от В
            switch (s4)
            {
            case 1: // A-B
                cout << '\t' << "Raznost A-B = ( ";
                int f[20];
                size1 = 0;
                size2 = 0;
                for (i = 0; i < n; i++) //для всех элементов множества А
                {
                    number = a[i];
                    kol = 1;
                    for (t = 0; t < m; t++) //сравниваем их с элементами множества В и если они повторяются то добавляем 1 к численной переменной 
                    {
                        if (b[t] == number)
                        {
                            kol++;
                        }
                    }
                    if (kol == 1) //если данный элемент повторяется 1 раз, то он вписывается в множество разности
                    {
                        f[size1] = a[i];
                        size1++;
                    }
                }
                for (i = 0; i < size1; i++) //вывод на экран
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
                for (i = 0; i < m; i++) //для каждого элемента множества В
                {
                    number = b[i];
                    kol = 1;
                    for (t = 0; t < n; t++) //сравниваем с элементом множества А, если они одинаковы, то добавляем к количественной переменной, обозначающей 1
                    {
                        if (a[t] == number) 
                        {
                            kol++;
                        }
                    }
                    if (kol == 1) //если элемент существует только в множестве В, то он записывается в множество разности
                    {
                        g[size2] = b[i];
                        size2++;
                    }
                }
                for (i = 0; i < size2; i++) //вывод на экран
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
            for (i = 0; i < n; i++) //для каждого элемента множества А
            {
                number = a[i];
                kol = 1;
                for (t = 0; t < m; t++) //сравнивается с каждым элементом множества В, если выбранный элемент А равен выбранному элементу В, то к количественной переменной добавляется 1
                {
                    if (b[t] == number)
                    {
                        kol++;
                    }
                }
                if (kol == 1) //если элемент существует только в множестве А, то он записывается в 1 дополнительное множество ака 1 разность
                {
                    h[size1] = a[i];
                    size1++;
                }
            }
            for (i = 0; i < m; i++) //для каждого элемента множества В
            {
                number = b[i];
                kol = 1;
                for (t = 0; t < n; t++) //сравниваем с каждым элементом множества А, если выбранный элемент В равен выбранному элементу А, то к количественной переменной добавляется 1
                {
                    if (a[t] == number)
                    {
                        kol++;
                    }
                }
                if (kol == 1) //если количесвенная переменная = 1, т.е. данный элемент существует только в множестве В, то он записывается во 2 дополнительное множество, ака разность 1
                {
                    j[size2] = b[i];
                    size2++;
                }
            }
            for (i = 0; i < size1; i++) //на экран выводятся элементы 1 дополнительного множества
            {
                cout << h[i] << " ";
            }
            for (i = 0; i < size2; i++) //на экран выводятся элементы 2 дополнительного множества
            {
                cout << j[i] << " ";
            }
            cout << ")" << '\n' << endl;
            break;
        case 5: //декартово произведение
            cout << '\t' << "Dekartovoe proizvedenie = (";
            for (i = 0; i < n; i++) //для каждого элемента множества А
            {
                for (t = 0; t < n; t++) //записываем кортежи с каждым элементом множества В и выводим на экран
                {
                    cout<< " < " << a[i] << " " << b[t] << " >";
                }
            }
            cout << " )"<< '\n' <<endl;
            break;
        case 6: //дополнение
            cout << '\t' << "Viberite deistvie:" << endl;
            cout << '\t' << "1 - dopolnenie A;" << '\n' << '\t' << "2 - dopolnenie B;" << '\n' << '\t' << "0 - exit" << '\n' << endl;
            cin >> s5; //происходит выбор функции
            switch (s5)
            {
            case 1:
                cout << '\t' << "Dopolnenie A = ( ";
                int k[20];
                size2 = 0; //т.к. разность множества В-А по определению является дополнением множества А
                for (i = 0; i < m; i++) //для каждого элемента множества В
                {
                    number = b[i];
                    kol = 1;
                    for (t = 0; t < n; t++) //сравниваем с каждым элементом множества А, и, если выбранные элементы равны, прибавляем к количественной переменной 1
                    {
                        if (a[t] == number)
                        {
                            kol++;
                        }
                    }
                    if (kol == 1) //если данный элемент существует только в множестве В, записываем его в множество дополнения
                    {
                        k[size2] = b[i];
                        size2++;
                    }
                }
                for (i = 0; i < size2; i++) //выводим на экран
                {
                    cout << k[i] << " ";
                }
                cout << ")" << '\n' << endl;
                break;
            case 2:
                cout << '\t' << "Dopolnenie B = ( ";
                int l[20];
                size2 = 0; //т.к. разность А-В по определению является дополнением множества В
                for (i = 0; i < n; i++) //для каждого элемента множества А
                {
                    number = a[i];
                    kol = 1;
                    for (t = 0; t < m; t++) //сравним с каждым элементом множества В, если выбранные элементы А и В равны, то добавляем к количественной переменной 1
                    {
                        if (b[t] == number)
                        {
                            kol++;
                        }
                    }
                    if (kol == 1) //если элемент принадлежит только множеству А, записываем его в множество дополнения
                    {
                        l[size2] = a[i];
                        size2++;
                    }
                }
                for (i = 0; i < size2; i++) //выводим на экран
                {
                    cout << l[i] << " ";
                }
                cout << ")" << '\n' << endl;
                break;
            case 3: //выход
                break;
            }
            break;
        case 0: //выход
            exit(1);
        }
    }
}



