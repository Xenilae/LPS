#include <iostream>
#include <iomanip>
#define TMAX 100
using namespace std;

int main()
{
    int i, n, temperatura;
    int maxim, minim, decalaj;
    float media;
    int mici, mari, egale, valoareIndicata;
    int canicula, cald, racoare, rece, frig, ger;

    cout << "\nProiect nr. 1 elaborat de Costiuc Igor\n";
    cout << "Tema: Temperaturile intro luna calindaristica\n";

    //   Citirea datelor
    cout << "Indicati numarul de zile: ";
    cin >> n;
    cin >> valoareIndicata;
    maxim = -TMAX;
    minim = TMAX;
    media = 0;
    char grad = 248;
    mici = mari = egale = 0;
    canicula = cald = racoare = rece = frig = ger = 0;
    for (i = 1; i <= n; i++)
    {
        do
        {
            cout << "Temperatura (in " << grad << "C) in ziua " << i << " este ";
            cin >> temperatura;
        } while ((temperatura < -TMAX) || (temperatura > TMAX));

        // 1. De determinat cea mai mica si cea mai mare temperatura
        if (temperatura > maxim)
            maxim = temperatura;
        if (temperatura < minim)
            minim = temperatura;
        media += temperatura;
        // 4. De determinat de valori, egale, mai mici sau mai mari ca o valoare indicata
        if (temperatura < valoareIndicata)
            mici++;
        else if (temperatura > valoareIndicata)
            mari++;
        else
            egale++;
        if (temperatura > 30)
            canicula++;
        else if (temperatura >= 20)
            cald++;
        else if (temperatura > 9)
            racoare++;
        else if (temperatura >= 0)
            rece++;
        else if (temperatura >= -15)
            frig++;
        else
            ger++;
    }

    // 2. De determinat decalajul;
    decalaj = maxim - minim;

    // 3. De determinat media
    media /= n;

    cout << "1.\tTemperatura maxima este: " << maxim << endl;
    cout << "\tTemperatura minima este: " << minim << "\n\n";
    cout << "2.\tDecalajul de temperatura este: " << decalaj << "\n\n";
    cout << "3.\tTemperatura medie este: " << setprecision(4) << media << "\n\n";
    if (mici > 0)
        cout << "4.\tIn " << mici << " zile temperatura este sub " << valoareIndicata << " grade\n";
    if (egale > 0)
        cout << "\tIn " << egale << " zile temperatura este egala cu " << valoareIndicata << " grade\n";
    if (mari > 0)
        cout << "\tIn " << mari << " zile temperatura este peste " << valoareIndicata << " grade\n";
    cout << endl
         << "5.";
    if (canicula > 0)
        cout << "\tIn " << canicula << " zile a fost canicula\n";
    if (cald > 0)
        cout << "\tIn " << cald << " zile a fost cald\n";
    if (racoare > 0)
        cout << "\tIn " << racoare << " zile a fost racoare\n";
    if (rece > 0)
        cout << "\tIn " << rece << " zile a fost rece\n";
    if (frig > 0)
        cout << "\tIn " << frig << " zile a fost frig\n";
    if (ger > 0)
        cout << "\tIn " << ger << " zile a fost ger\n";
    cout << endl;
    return 0;
}