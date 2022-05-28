#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <fstream>

#define TMAX 100
#define TEMPERATURA_MAX 70
#define TEMPERATURA_MIN -35

using namespace std;

void Citire(int n, int a[]);
void Afisare(int n, int a[], char sir[]);
int Minim(int n, int a[]);
int Maxim(int n, int a[]);
double Media(int n, int a[]);
void Sortare(int n, int a[], int ordine);
void Rotire(int n, int a[], int optiune, int k);
void Inserare(int &n, int a[], int val, int pos);
int Cautare(int n, int a[], int val);
void Stergere(int &n, int a[], int val);
void Clasificare(int n, int a[]);
void Clasificare2(int n, int a[]);
int Generare(int n, int a[]);

int main()
{
    int optiune, poz, temperatura;
    int n = 10;
    int temperature[TMAX] = {32, 9, 4, 7, -10, 19, -6, 8, 24, 7};
    cout << "Cate elemente ? ";
    cin >> n;
    Citire(n, temperature);
    do
    {
        system("cls");
        cout << "Proiect nr.3 elaborat de Costiuc Igor" << endl;
        cout << "Tema: Temperatura(tabele)" << endl;
        cout << "1. Determinarea temperaturei minime si maxime" << endl;
        cout << "2. Determinarea mediei temperaturilor" << endl;
        cout << "3. Sortarea temperaturilor" << endl;
        cout << "4. Rotirea" << endl;
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
            Afisare(n, temperature, "initial");
            cout << "\n Cea mai mica temperatura este " << Minim(n, temperature);
            cout << "\n Cea mai mare temperatura este " << Maxim(n, temperature) << endl;
            break;
        case 2:
            Afisare(n, temperature, "initial");
            cout << "\ntemperatura medie: " << Media(n, temperature) << endl;
            break;
        case 3:
            Afisare(n, temperature, "initial");
            int ordine;
            cout << "Alegeti ordinea de sortare: " << endl;
            cout << "1. Crescator;" << endl;
            cout << "-1. Descrescator." << endl;
            cout << "\n\n\t Varianta aleasa: ";
            cin >> ordine;
            Sortare(n, temperature, ordine);
            Afisare(n, temperature, "aranjat");
            break;
        case 4:
            Afisare(n, temperature, "initial");
            int optiune, k;
            cout << "Alegeti tipul de rotire: " << endl;
            cout << "1. La dreapta;" << endl;
            cout << "2. La stanga." << endl;
            cout << "\n\n\t Optiunea aleasa -> ";
            cin >> optiune;
            cout << "Introduceti numarul de pozitii pentru rotire: ";
            cin >> k;
            Rotire(n, temperature, optiune, k);
            Afisare(n, temperature, "rotit");
            break;
        case 5:
            Afisare(n, temperature, "initial");
            cout << "temperatura pentru inserare: ";
            cin >> temperatura;
            cout << "Pozitia pe care doriti sa inserati: ";
            cin >> poz;
            Inserare(n, temperature, temperatura, poz);
            Afisare(n, temperature, "dupa inserare");
            break;
        case 6:
            Afisare(n, temperature, "initial");
            cout << "temperatura pentru stergere: ";
            cin >> temperatura;
            if ((poz = Cautare(n, temperature, temperatura)) < n)
            {
                Stergere(n, temperature, poz);
            }
            Afisare(n, temperature, "dupa eliminare");
            break;
        case 7:
            Afisare(n, temperature, "curent");
            cout << "\nAvem urmatoarele rezultate: " << endl;
            Clasificare(n, temperature);
            Clasificare2(n, temperature);
            break;
        }
        _getch();
    } while (optiune);
    return 0;
}

void Citire(int n, int a[])
{
    int varianta;
    cout << "\n Alege varianta de citire:" << endl;
    cout << "\n 1. De la tastatura;";
    cout << "\n 2. Aleator;";
    cout << "\n 3. Generat dupa o regula;";
    cout << "\n 4. Din fisier";
    cout << "\n\t -> ";
    cin >> varianta;
    for (int i = 0; i < n; i++)
    {
        switch (varianta)
        {
        case 1:
            cout << "Indica valoarea pentru elementul cu nr. " << i + 1 << ": ";
            cin >> a[i];
            break;
        case 2:
            a[i] = rand() % TEMPERATURA_MAX + TEMPERATURA_MIN;
            break;
        case 3:
            a[i] = i % 3 + 8;
            break;
        case 4:
            ifstream fisierTemperaturi;
            fisierTemperaturi.open("Temperatura.txt", ios::in);
            if (fisierTemperaturi.is_open())
            {
                fisierTemperaturi >> n;
                for (int i = 0; i < n; i++)
                {
                    fisierTemperaturi >> a[i];
                }
            }
            fisierTemperaturi.close();
            break;
        }
    }
}

void Afisare(int n, int a[], char sir[])
{
    int i;
    cout << "\nTabloul de temperaturi " << sir << "\n";
    for (i = 0; i < n; i++)
    {
        cout << setw(8) << a[i] << " ";
    }
    cout << endl;
}

int Minim(int n, int a[])
{
    int i, minim = a[0];
    for (i = 1; i < n; i++)
    {
        if (minim < a[i])
        {
            minim = a[i];
        }
    }
    return minim;
}

int Maxim(int n, int a[])
{
    int i, maxim = a[0];
    for (i = 1; i < n; i++)
    {
        if (maxim > a[i])
        {
            maxim = a[i];
        }
    }
    return maxim;
}

double Media(int n, int a[])
{
    double sum = a[0];
    for (int i = 1; i < n; i++)
    {
        sum += a[i];
    }
    return sum / n;
}

void Sortare(int n, int a[], int ordine)
{
    int i, k = 0;
    bool change;
    do
    {
        k++;
        change = false;
        for (i = 0; i < n - k; i++)
        {
            if (a[i] * ordine > a[i + 1] * ordine)
            {
                swap(a[i], a[i + 1]);
                change = true;
            }
        }
    } while (change);
}

void Rotire(int n, int a[], int optiune, int k)
{
    if (n == k)
    {
        cout << "Tabloul nu se va modifica! n=k!!!!" << endl;
        return;
    }
    if (optiune == 1)
    {
        for (int i = 0; i < k; i++)
        {
            int temp = a[n - 1];
            for (int i = n - 1; i > 0; i--)
            {
                a[i] = a[i - 1];
            }
            a[0] = temp;
        }
    }
    else if (optiune == 2)
    {
        int temp = a[0];
        for (int i = 0; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        a[n - 1] = temp;
    }
    else
    {
        cout << "Optiune inexistenta" << endl;
        return;
    }
}

// val - valoarea adaugata
void Inserare(int &n, int a[], int val, int pos)
{
    int i;
    n++;
    for (i = n; i >= pos; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos - 1] = val;
}

// vom lua n ca index de la care incepem
int Cautare(int n, int a[], int val)
{
    int i = 0;
    while (a[i] != val && (i < n))
    {
        i++;
    }
    return i;
}

void Stergere(int &n, int a[], int val)
{
    for (int i = val; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
}

void Clasificare(int n, int a[])
{
    char grad = 248;
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == true)
            continue;
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                visited[j] = true;
                count++;
            }
        }
        cout << a[i] << grad << " au " << count << " zile" << endl;
    }
}

void Clasificare2(int n, int a[])
{
    int canicula, cald, rece, frig;
    canicula = cald = rece = frig = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 30)
        {
            canicula++;
        }
        else if (a[i] > 15)
        {
            cald++;
        }
        else if (a[i] > 0)
        {
            rece++;
        }
        else
        {
            frig++;
        }
    }
    cout << "\nSunt: " << endl;
    if (canicula != 0)
        cout << canicula << " canicula" << endl;
    if (cald != 0)
        cout << cald << " cald" << endl;
    if (rece != 0)
        cout << rece << " rece" << endl;
    if (frig != 0)
        cout << frig << " frig" << endl;
}

int Generare(int n, int a[])
{
    return 1;
}