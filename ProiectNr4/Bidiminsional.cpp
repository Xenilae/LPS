#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <fstream>

#define TMAX 100
#define TEMPERATURA_MAX 70
#define TEMPERATURA_MIN -35
#define MONTHS 12
#define DAYS 20

using namespace std;
const string Luni[12] = {"Ianuarie  ", "Februarie ", "Martie    ", "Aprilie   ", "Mai       ", "Iunie     ", "Iulie     ", "August    ", "Septembrie", "Octombrie ", "Noiembrie ", "Decembrie "};

void Citire(int a[][DAYS]);
void Afisare(int a[][DAYS], char sir[]);
int Minim(int a[][DAYS]);
int Maxim(int a[][DAYS]);
void Interschimbare(int a[][DAYS]);
void Adaugare(int a[][DAYS]);
void Sortare(int a[][DAYS], int ordine);
int main()
{
    int optiune, poz, opt, temperatura;
    // int n = 10;
    int temperature[MONTHS][DAYS];
    Citire(temperature);
    do
    {
        system("cls");
        cout << "Proiect nr.4 elaborat de Costiuc Igor" << endl;
        cout << "Tema: Temperatura(tabele bidiminsionale)" << endl;
        cout << "1. Determinarea temperaturei minime si maxime" << endl;
        cout << "2. Interschimbarea a 2 linii sau 2 coloane" << endl;
        cout << "3. De adaugat o linie sau o coloana" << endl;
        cout << "4. Sortare" << endl;
        cout << "5. Inserarea unei temperatura" << endl;
        cout << "6. Stergerea unei temperatura" << endl;
        cout << "7. Clasificarea" << endl;
        cout << "8. Generare" << endl;
        cout << "0. Iesire" << endl;
        cout << "\n\n\t Alege o optiune de la 0 la 8 -> ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            Afisare(temperature, "initial");
            cout << "\n Cea mai mica temperatura este " << Minim(temperature);
            cout << "\n Cea mai mare temperatura este " << Maxim(temperature) << endl;
            break;
        case 2:
            Afisare(temperature, "initial");
            Interschimbare(temperature);
            Afisare(temperature, "interschimbat");
            break;
        case 3:
            Afisare(temperature, "initial");
            Adaugare(temperature);
            Afisare(temperature, "adaugat");

            break;
        case 4:
            Afisare(temperature, "initial");
            cout << "\n\n\t 1. Sortare crescatoare" << endl;
            cout << "\t 2. Sortare descrescatoare" << endl;
            cout << "\t Alege o optiune -> ";
            cin >> opt;
            Sortare(temperature, opt);
            Afisare(temperature, "sortat");
            break;
        case 5:
            Afisare(temperature, "initial");
            Afisare(temperature, "dupa inserare");
            Afisare(temperature, "initial");
            Afisare(temperature, "dupa eliminare");
            break;
        case 7:
            Afisare(temperature, "curent");
            break;
        }
        _getch();
    } while (optiune);
    return 0;
}

void Citire(int a[][DAYS])
{
    int varianta;
    cout << "\n Alege varianta de citire:" << endl;
    cout << "\n 1. De la tastatura;";
    cout << "\n 2. Aleator;";
    cout << "\n 3. Generat dupa o regula;";
    cout << "\n 4. Din fisier";
    cout << "\n\t -> ";
    cin >> varianta;
    for (int row = 0; row < MONTHS; row++)
        for (int column = 0; column < DAYS; column++)
        {
            switch (varianta)
            {
            case 1:
                cout << "Indica valoarea pentru elementul din randul " << row + 1 << " si coloana " << column + 1 << ": ";
                cin >> a[row][column];
                break;
            case 2:
                a[row][column] = rand() % TEMPERATURA_MAX + TEMPERATURA_MIN;
                break;
            case 3:
                a[row][column] = row % 3 + 8;
                break;
            case 4:
                ifstream fisierTemperaturi;
                fisierTemperaturi.open("temperature.in", ios::in);
                if (fisierTemperaturi.is_open())
                {
                    // fisierTemperaturi >> n;
                    for (int row = 0; row < MONTHS; row++)
                    {
                        fisierTemperaturi >> a[row][column];
                    }
                }
                fisierTemperaturi.close();
                break;
            }
        }
}

void Afisare(int a[][DAYS], char sir[])
{
    int row, column;
    cout << "\nTabloul de temperaturi " << sir << "\n";

    for (row = 0; row < MONTHS; row++)
    {
        cout << Luni[row] << ": ";
        for (int column = 0; column < DAYS; column++)
        {
            cout << setw(4) << a[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int Minim(int a[][DAYS])
{
    int minim = a[0][0];
    for (int row = 0; row < MONTHS; row++)
    {
        for (int column = 0; column < DAYS; column++)
        {
            if (a[row][column] < minim)
            {
                minim = a[row][column];
            }
        }
    }
    return minim;
}

int Maxim(int a[][DAYS])
{
    int maxim = a[0][0];
    for (int row = 0; row < MONTHS; row++)
    {
        for (int column = 0; column < DAYS; column++)
        {
            if (a[row][column] > maxim)
            {
                maxim = a[row][column];
            }
        }
    }
    return maxim;
}

void Interschimbare(int a[][DAYS])

{
    printf("Ce doriti sa schimabati?\n1. Linii\n2. Coloane\n");
    int optiune;
    cin >> optiune;
    if (optiune == 1)
    {
        int linie1, linie2;
        cout << "Linia 1: ";
        cin >> linie1;
        cout << "Linia 2: ";
        cin >> linie2;
        linie1--;
        linie2--;
        for (int column = 0; column < DAYS; column++)
        {
            int aux = a[linie1][column];
            a[linie1][column] = a[linie2][column];
            a[linie2][column] = aux;
        }
    }
    else
    {
        int coloana1, coloana2;
        cout << "Coloana 1: ";
        cin >> coloana1;
        cout << "Coloana 2: ";
        cin >> coloana2;
        coloana1--;
        coloana2--;
        for (int row = 0; row < MONTHS; row++)
        {
            int aux = a[row][coloana1];
            a[row][coloana1] = a[row][coloana2];
            a[row][coloana2] = aux;
        }
    }
}

void Adaugare(int a[][DAYS])
{
    cout << "Ce doriti sa adaugati?\n1. Linie\n2. Coloana\n";
    int optiune;
    cin >> optiune;
    cout << "\n Alege varianta de citire:" << endl;
    cout << "\n 1. De la tastatura;";
    cout << "\n 2. Aleator;";
    cout << "\n 3. Generat dupa o regula;";
    cout << "\n 4. Din fisier";
    cout << "\n\t -> ";
    int varianta;
    cin >> varianta;
    if (optiune == 1)
    {
        int linie;
        cout << "Linia: ";
        cin >> linie;
        linie--;
        for (int column = 0; column < DAYS; column++)
        {
            switch (varianta)
            {
            case 1:
                cout << "Indica valoarea pentru elementul din randul " << linie + 1 << " si coloana " << column + 1 << ": ";
                cin >> a[linie][column];
                break;
            case 2:
                a[linie][column] = rand() % TEMPERATURA_MAX + TEMPERATURA_MIN;
                break;
            case 3:

                a[linie][column] = linie % 3 + 8;
                break;
            case 4:
                ifstream fisierTemperaturi;
                fisierTemperaturi.open("temperature.in", ios::in);
                if (fisierTemperaturi.is_open())
                {
                    // fisierTemperaturi >> n;
                    for (int row = 0; row < MONTHS; row++)
                    {
                        fisierTemperaturi >> a[row][column];
                    }
                }
                fisierTemperaturi.close();
                break;
            }
        }
    }
    else
    {
        int coloana;
        cout << "Coloana: ";
        cin >> coloana;
        coloana--;
        for (int row = 0; row < MONTHS; row++)
        {
            switch (varianta)
            {
            case 1:
                cout << "Indica valoarea pentru elementul din randul " << row + 1 << " si coloana " << coloana + 1 << ": ";
                cin >> a[row][coloana];
                break;
            case 2:
                a[row][coloana] = rand() % TEMPERATURA_MAX + TEMPERATURA_MIN;
                break;
            case 3:
                a[row][coloana] = row % 3 + 8;
                break;
            case 4:
                ifstream fisierTemperaturi;
                fisierTemperaturi.open("temperature.in", ios::in);
                if (fisierTemperaturi.is_open())
                {
                    // fisierTemperaturi >> n;
                    for (int row = 0; row < MONTHS; row++)
                    {
                        fisierTemperaturi >> a[row][coloana];
                    }
                }
                fisierTemperaturi.close();
                break;
            }
        }
    }
}

void Sortare(int a[][DAYS], int ordine)
{
    cout << "Ce doriti sa sortati?\n1. Linie\n2. Coloana\n";
    int optiune;
    cin >> optiune;
    if (optiune == 1)
    {
        int linie;
        cout << "Linia: ";
        cin >> linie;
        linie--;
        for (int column = 0; column < DAYS - 1; column++)
        {
            for (int i = column + 1; i < DAYS; i++)
            {
                if (ordine == 1)
                {
                    if (a[linie][column] > a[linie][i])
                    {
                        int aux = a[linie][column];
                        a[linie][column] = a[linie][i];
                        a[linie][i] = aux;
                    }
                }
                else
                {
                    if (a[linie][column] < a[linie][i])
                    {
                        int aux = a[linie][column];
                        a[linie][column] = a[linie][i];
                        a[linie][i] = aux;
                    }
                }
            }
        }
    }
    else
    {
        int coloana;
        cout << "Coloana: ";
        cin >> coloana;
        coloana--;
        for (int row = 0; row < MONTHS - 1; row++)
        {
            for (int i = row + 1; i < MONTHS; i++)
            {
                if (ordine == 1)
                {
                    if (a[row][coloana] > a[i][coloana])
                    {
                        int aux = a[row][coloana];
                        a[row][coloana] = a[i][coloana];
                        a[i][coloana] = aux;
                    }
                }
                else
                {
                    if (a[row][coloana] < a[i][coloana])
                    {
                        int aux = a[row][coloana];
                        a[row][coloana] = a[i][coloana];
                        a[i][coloana] = aux;
                    }
                }
            }
        }
    }
}

void InserareRand(int &n, int a[], int val, int pos)
{
}