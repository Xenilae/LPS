#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#define LMAX 254
using namespace std;

int NumarCuvinte(char sir[]);
int CuvinteCuLiteraAlesa(char sir[], char Litera);
int CuvinteLitera(char sir[], char Litera);
int CuvinteCuCelMultSix(char sir[]);
int NumarCuvint();
int CuvinteCuLiteraAlesaFile();
int CuvinteLitera(char Litera);
int Transfer(char Litera);
int Elimina(char Litera);
void PreviewFile(char nume[]);

int main()
{
    int optiune, nr;
    char lit;
    char fraza[LMAX] = "Sergiu nu stie cine este Laura, Igor ca Igor, prieteneste cu Dima...";
    do
    {
        system("cls");
        cout << "\nProiect nr. 5 elaborat de Costiuc Igor";
        cout << "\nTema: Temperaturile intro luna calindaristica. Lucrul cu siruri de caractere\n";
        cout << "\n1. Numarul de cuvinte dintro fraza";
        cout << "\n2. Cuvinte care incep cu litera data dintro fraza";
        cout << "\n3. Cuvintele cu cel mult 6 litere dintro fraza";
        cout << "\n4. Numarul de cuvinte dintrun fisier";
        cout << "\n5. Cuvintele care incep cu litera data dintrun fisier";
        cout << "\n6. Cuvintele cu indicatorul din dintro fisier";
        cout << "\n0. Stop";
        cout << "\n\n\tAlege (de la 0 la 6) -> ";
        cin >> optiune;

        switch (optiune)
        {
        case 1:
            cout << "\n\nFraza initiala:\n";
            fflush(stdin);
            gets(fraza);
            nr = NumarCuvinte(fraza);
            if (nr > 0)
                printf("\n%s\n Sunt %d cuvinte in fraza data", fraza, nr);
            else
                cout << "\nNu sunt cuvinte";
            break;
        case 2:
            cout << "Dati o litera cu care se vor efectua operatiile: ";
            cin >> lit;
            cout << "Fraza initiala\n";
            fflush(stdin);
            gets(fraza);
            nr = CuvinteCuLiteraAlesa(fraza, lit);
            if (nr > 0)
                printf("%s\n Sunt %d cuvinte care incep cu litera %c", fraza, nr, lit);
            else
            {
                printf("%s", fraza);
                cout << "\nNu sunt cuvinte care incep cu litera propusa";
            }
            break;
        case 3:
            cout << "Fraza initiala:\n";
            fflush(stdin);
            gets(fraza);
            nr = CuvinteCuCelMultSix(fraza);
            if (nr > 0)
                printf("%s\n Sunt %d cuvinte", fraza, nr);
            else
                cout << "\nNu sunt cuvinte care au 6 litere dintro fraza";
            break;
        case 4:
            // cout << "Fraza initiala din fisier:\n";
            PreviewFile("file.txt");
            nr = NumarCuvint();
            // cout << NumarCuvint() << " cuvinte";
            if (nr > 0)
                // cout << "\nin total " << nr << " cuvinte\n";
                printf("\nIn total %d cuvinte\n", nr);
            else
                cout << "Nu-s cuvinte\n";
            break;
        case 5:
            cout << "Fraza initiala din fisier:\n";
            PreviewFile("file.txt");
            nr = CuvinteCuLiteraAlesaFile();
            if (nr > 0)
                // cout << "\nin total " << nr << " cuvinte\n";
                printf("\nIn total %d cuvinte cu litera aleasa\n", nr);
            else
                cout << "Nu-s cuvinte\n";
            break;
        case 6:
            cout << "Fraza initiala din fisier:\n";
            PreviewFile("file.txt");
            nr = CuvinteLitera('a');
            if (nr > 0)
                // cout << "\nin total " << nr << " cuvinte\n";
                printf("\nIn total %d cuvinte cu litera aleasa\n", nr);
            else
                cout << "Nu-s cuvinte\n";

        default:
            break;
        }
        _getch();
    } while (optiune);
    return 0;
}

int NumarCuvinte(char sir[])
{
    int n = 0;
    char *cuvant, copia[LMAX];
    strcpy(copia, sir);
    if ((cuvant = strtok(copia, " ,.!\n\t?..")) == NULL)
        return 0;
    n++;
    while ((cuvant = strtok(NULL, " ,.!\n\t?..")) != NULL)
        n++;
    return n;
}

int CuvinteCuLiteraAlesa(char sir[], char Litera)
{
    int n = 0;
    char *cuvant, copia[LMAX];
    strcpy(copia, sir);
    if ((cuvant = strtok(copia, " ,.!\n\t?..")) == NULL)
        return 0;
    while ((cuvant = strtok(NULL, " ,.!\n\t?..")) != NULL)
    {
        if ((cuvant[0] == Litera) || (cuvant[0] == Litera - 32))
            n++;
    }
    return n;
}

int CuvinteCuCelMultSix(char sir[])
{
    int n = 0;
    char *cuvant, copia[LMAX];
    strcpy(copia, sir);
    if ((cuvant = strtok(copia, " ,.!\n\t?..")) == NULL)
        return 0;
    while ((cuvant = strtok(NULL, " ,.!\n\t?..")) != NULL)
    {
        if (strlen(cuvant) < 6)
            n++;
    }
    return n;
}

int NumarCuvint()
{
    FILE *f;
    char sir[LMAX];
    int nr = 0;
    f = fopen("file.txt", "r");
    while (fscanf(f, "%s", sir) != EOF)
    {
        // cout << "Am intrat\n";
        nr++;
        // cout << nr << " ";
    }
    fclose(f);
    return nr;
}

int CuvinteCuLiteraAlesaFile()
{
    FILE *f;
    char sir[LMAX];
    char fraza[LMAX] = "";
    char lit;
    cout << "\nDati o litera cu care se vor efectua operatiile: ";
    cin >> lit;
    cout << "\n";
    int nr = 0;

    f = fopen("file.txt", "r");
    while (fscanf(f, "%s", sir) != EOF)
    {
        strcat(fraza, sir);
        strcat(fraza, " ");
    }
    fclose(f);
    nr = CuvinteCuLiteraAlesa(fraza, lit);
    return nr;
}

int CuvinteLitera(char Litera)
{
    FILE *f;
    char sir[LMAX];
    char fraza[LMAX] = "";
    int nr = 0;

    f = fopen("file.txt", "r");
    while (fscanf(f, "%s", sir) != EOF)
    {
        strcat(fraza, sir);
        strcat(fraza, " ");
    }
    fclose(f);
    nr = CuvinteCuLiteraAlesa(fraza, Litera);
    return nr;
}

void PreviewFile(char nume[])
{
    {
        FILE *f;
        char sir[LMAX];
        f = fopen(nume, "r");
        while (fgets(sir, LMAX - 1, f) != NULL)
            cout << sir;
        fclose(f);
    }
}