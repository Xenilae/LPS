#include <iostream>
#include <sstream>
#include <iomanip>
#define NMAX 2147483647
using namespace std;
int a, b, n;

bool Par(int nr)
{

    return (nr % 2 == 0);
}

bool ParOptimizat(int n)
{
    return (!(n & 1));
}

bool ParPrinImpar(int n)
{
    return (!(n % 2 != 0));
}

void PrintMenu()
{
    cout << "\nAlegeti operatia:\n\n";
    cout << "1 - De verificat daca numarul nr este par\n";
    cout << "2 - De indicat toate numerele din intervalul [a; b], care sunt pare\n";
    cout << "3 - De indicat primele n numere, care sunt pare\n";
    cout << "4 - De indicat toate numerele din intervalul [a; b], care sunt pare (varianta optimizata)\n";
    cout << "5 - De determinat cel mai mare numar, care este par\n";
    cout << "6 - De determinat cel mai mic numar, care este par\n";
    cout << "* - Exit\n\n";
}

void CreateRange()
{
    cout << "Indicati intervalul [a; b]\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "Intervalul propus este [" << a << "; " << b << "]\n\n";
}

void CreateRangeWithN()
{
    cout << "Indicati intervalul [a; b]\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "n = ";
    cin >> n;
    cout << "Intervalul propus este [" << a << "; " << b << "]\n\n";
}

void FindEvenNumbersInRange(int a, int b)
{
    int contor = 0;
        for (int i = a; i <= b; i++)
        {
            if (Par(i))
            {
                contor++;
                cout << setw(9) << i;
                if (contor % 10 == 0)
                cout << endl;
            }
        }
    // else
    // {
    //     for (int i = a; i <= b; i++)
    //     {

    //         if (Par(i))
    //             contor++;
    //         cout << setw(9) << i;
    //         if (contor % 20 == 0)
    //             cout << endl;
    cout << "\nIn total sunt " << contor << "numere pare\n";
    //     }
}

void FindFirstNEvenNumbersInRange(int a, int b, int n)
{
    int count;
    count = 0;
        for (int i = a; i <= b; i++)
        {
            if (count == n)
                break;

            if (Par(i) && (n != count))
            {
                cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n\n";
                count = count + 1;
            }
        }
    }

void FindMaxEvenNumberInRange(int a, int b)
{
    int max;
    max = -NMAX;
    if (b < a)
    {
        for (int i = a; i >= b; i--)
        {
            if (ParOptimizat(i))
            {
                if (i > max)
                    max = i;
            }
        }
    }
    else
    {
        for (int i = a; i <= b; i++)
        {
            if (ParOptimizat(i))
            {
                if (i > max)
                    max = i;
            }
        }
    }

    cout << "Cel mai mare numar care corespunde conditiei este " << max << "\n\n";
}

void FindMinEvenNumberInRange(int a, int b)
{
    int min;
    min = NMAX;
    if (b < a)
    {
        for (int i = a; i >= b; i--)
        {
            if (Par(i))
            {
                if (i < min)
                    min = i;
            }
        }
    }
    else
    {
        for (int i = a; i <= b; i++)
        {
            if (Par(i))
            {
                if (i < min)
                    min = i;
            }
        }
    }

    cout << "Cel mai mic numar care corespunde conditiei este " << min << "\n\n";
}

int main()
{
    cout << "\nProiect nr. 2 elaborat de Costiuc Igor\n";
    cout << "Tema: Numere pare\n\n";
menu:
    PrintMenu();
    int choice;
    int number;
    cout << "Operatia alesa: ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
    {
        // 1. De verificat dacă numărul nr este par
        cout << "Dati un numar intreg: ";
        cin >> number;
        if (Par(number))
            cout << "Numarul " << number << " este par\n\n";
        else
            cout << "Numarul " << number << " e impar\n\n";
        goto menu;
    }
    case 2:
    {
        // 2. De indicat toate numerele din intervalul [a; b], care sunt pare
        CreateRange();
        FindEvenNumbersInRange(a, b);
        goto menu;
    }
    case 3:
    {
    // 3. De indicat primele n numere, care satisfac proprietatea de bază
    WrongN:
        CreateRangeWithN();
        if (n <= 0)
        {
            cout << "Introduceti numere pozitive pentr n !!\n";
            goto WrongN;
        }
        FindFirstNEvenNumbersInRange(a, b, n);
        goto menu;
    }
    case 4:
    {
        // 4. De indicat toate numerele din intervalul [a; b], care sunt pare(varianta optimizata)
        CreateRange();
        FindEvenNumbersInRange(a, b);
        goto menu;
    }
    case 5:
    {
        // 5. De determinat cel mai mare numar, care este par
        CreateRange();
        FindMaxEvenNumberInRange(a, b);
        goto menu;
    }
    // Optional
    case 6:
    {
        // 6. De determinat cel mai mic numar, care este par
        CreateRange();
        FindMinEvenNumberInRange(a, b);
        goto menu;
    }
    default:
        break;
    }
    return 0;
}