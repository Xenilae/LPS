#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#define TMIN -50
#define TMAX 50
int Citire(int n, int a[]);
void Afisare(int n, int a[], char sir[]);
int Minim(int n, int a[]);
int Maxim(int n, int a[]);
double Media(int n, int a[]);
int Sortare(int n, int a[]);
int Rotire(int n, int a[], int opt2, int k);
int Inserare(int &n, int a[], int val);
int Cautare(int n, int a[], int val);
int Stergere(int &n, int a[], int val);
int Clasificare(int &n, int a[]);
int Generare(int n, int a[]);

using namespace std;
int main()
{
    int n = 10, temp = 9, poz;
    int optiune, cateOri = 1, opt2 = 1;
    int temperatura[TMAX] = {5, 19, 16, 17, 13, 32, 25, 18, 30, 22};
    cout << "Cate elemente:";
    cin >> n;
    Citire(n, temperatura);
    do
    {
        system("cls");
        cout << "\nProiect nr. 3 elaborat de Costiuc Igor\n";
        cout << "Tema: Temperaturile intro luna calindaristica\n";
        cout << "\n1. De determinat minimul si maximul";
        cout << "\n2. Media";
        cout << "\n3. Sortare";
        cout << "\n4. Rotirea la dreapata sau stanga";
        cout << "\n5. Inserare";
        cout << "\n6. Eliminare";
        cout << "\n7. Clasificare";
        cout << "\n8. Generare";
        cout << "\n0. Stop";
        cout << "\n\n\tAlege (de la 0 la 8) -> ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            Afisare(n, temperatura, "initial");
            cout << "\n Cea mai mica temperatura este: " << Minim(n, temperatura);
            cout << "\n Cea mai mare temperatura este: " << Maxim(n, temperatura);
            break;
        case 2:
            Afisare(n, temperatura, "initial");
            cout << "\nMedia temperaturilor este: " << Media(n, temperatura);
            break;
        case 3:
            Afisare(n, temperatura, "initial");
            Sortare(n, temperatura);
            Afisare(n, temperatura, "sortat");

            break;
        case 4:
            Afisare(n, temperatura, "initial");
            Rotire(n, temperatura, opt2, cateOri);
            Afisare(n, temperatura, "rotit la stanga");

            break;
        case 5:
            Afisare(n, temperatura, "initial");
            temp = 9;
            if ((poz = Cautare(n, temperatura, temp)) == n)
                Inserare(n, temperatura, 10);
            else
                Inserare(n, temperatura, 10 /*poz*/);
            Afisare(n, temperatura, "cu inserare");

            break;
        case 6:
            Afisare(n, temperatura, "initial");
            Sortare(n, temperatura);
            Afisare(n, temperatura, "cu eliminare");

            break;
        case 7:
            Afisare(n, temperatura, "initial");
            Clasificare(n, temperatura);
            Afisare(n, temperatura, "initial");

            break;
        case 8:
            Afisare(n, temperatura, "initial");
            Sortare(n, temperatura);
            Afisare(n, temperatura, "initial");

            break;
        default:
            break;
        }
        _getch();
    } while (optiune);
    return 0;
}

int Citire(int n, int a[])
{
    ifstream f("Temperatura.txt");
    f.open("Temperatura.txt", ios::in);
    // if (f.is_open())
    //     cout << "Vseo ok";
    // else
    //     cout << "vseo ne ok";
    int varianta;
    cout << "\n Alege varianta de citire;\n";
    cout << "\n 1. De la tastatura;\n";
    cout << "\n 2. Aleator;\n";
    cout << "\n 3. Generat dupa o regula;\n";
    cout << "\n 4. Din fisier;\n";
    cout << "\n 5. Implicit;\n";
    cout << "\n\n\tAlege (de la 0 la 5) ->  ";
    cin >> varianta;
    for (int i = 0; i < n; i++)
        switch (varianta)
        {
        case 1:
            cout << "Indica valoarea pentru temperatura nr. " << i << ": ";
            cin >> a[i];
            break;
        case 2:
            a[i] = rand() % (TMAX - TMIN + 1) + TMIN;
            break;
        case 3:
            a[i] = i % 3 + 8;
            break;
        case 4:
            f >> a[i];
            break;
        case 5:
            break;

        default:
            break;
        }
    f.close();
    return 1;
}

void Afisare(int n, int a[], char sir[])
{
    int i;
    cout << "\n Tabloul de temperatura " << sir << "\n";
    for (i = 0; i < n; i++)
        cout << setw(12) << *(a + i);
}

int Minim(int n, int a[])
{
    int i, aux;
    aux = a[0];
    for (i = 1; i < n; i++)
        if (a[i] < aux)
            aux = a[i];
    return aux;
}

int Maxim(int n, int a[])
{
    int i, aux;
    aux = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > aux)
            aux = a[i];
    return aux;
}

double Media(int n, int a[])
{
    int i;
    double aux = 0;
    for (i = 0; i < n; i++)
        aux += a[i];
    aux /= n;
    return aux;
}

int Sortare(int n, int a[])
{
    int i, k;
    bool change;
    for (k = 0; k < n - 1; k++)
        for (i = k + 1; i < n; i++)
            if (a[i] < a[k])
                swap(a[i], a[k]);
}

int Rotire(int n, int a[], int opt2, int k)
{
    int st = (opt2 > 0) ? 0 : n - 1;
    int dr = (opt2 < 0) ? 0 : n - 1;
    for (int j = 0; j < k; j++)
    {
        int aux = a[st];
        for (int i = st; i * opt2 < dr * opt2; i += opt2)
        {
            a[i] = a[i + opt2];
        }
        a[dr] = aux;
    }
    return 1;
}
// val - valoarea adaugata
int Inserare(int &n, int a[], int val)
{
    n++;
    a[n - 1] = val;
    return 1;
}
// vom lua n ca index de la care incepem
int Cautare(int n, int a[], int val)
{
    int i = 0;
    while ((a[i] != val) && (i < n))
    {
        i++;
    }
    return i;
}
// val pozitia
int Stergere(int &n, int a[], int val)
{
    for (int i = val; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    return 1;
}
int Clasificare(int n, int a[], int m, int b[])
{
    int i, j;
    int limite[] = {4, 6, 8, 101};
    for (j = 0; j < m; j++)
        b[m] = 0;
    for (i = 0; i < n; i++)

        for (j = 0; j < m; j++)
            if (a[i] <= limite[j])
            {
                b[j]++;
                break;
            }
    return 1;
}
int Generare(int n, int a[])
{
    return 1;
}
