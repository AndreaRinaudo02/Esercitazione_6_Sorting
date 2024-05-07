#include "SortingAlgorithm.hpp"
#include <chrono>
#include <iostream>
#include <unistd.h>
#include <numeric>
#include <vector>
#include <array>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace SortLibrary;

int main(int argc, char ** argv)
{
    // argc rappresnta il numero di prove effettuate dal programma (corrisponde a quanti vettori di dimensione diversa si usano per testare)

    const int n_ripetizioni = 20;   // numero di ripetizioni per ogni prova

    // si utilizzano due array per memorizzare i tempi medi di esecuzione
    double *tempi_BubbleSort = new double[argc];
    double *tempi_MergeSort = new double[argc];


    // vettori randomici

    cout << "Vettori con elementi randomici" << endl;
    cout << endl;


    for (int i = 1; i < argc; i++)
    {

        // crea due vettori identici (uno per ogni algoritmo). La dimensione è argomento di linea di comando
        vector<int> vettore1(atoi(argv[i]));
        vector<int> vettore2(atoi(argv[i]));

        for (int v = 0; v < atoi(argv[i]); v++)
        {
            vettore1[v] = rand() % 1000;  // vettore di interi casuali fino a 999
        }

        vettore2 = vettore1;


        // memorizzano i tempi delle ripetizioni
        double tempo_BubbleSort = 0;
        double tempo_MergeSort = 0;


        for (int n = 0; n < n_ripetizioni; n++)
        {

            chrono::steady_clock::time_point t_inizio_BubbleSort = chrono::steady_clock::now();
            BubbleSort(vettore1);
            chrono::steady_clock::time_point t_fine_BubbleSort = chrono::steady_clock::now();

            tempo_BubbleSort += chrono::duration_cast<chrono::nanoseconds> (t_fine_BubbleSort-t_inizio_BubbleSort).count();

            chrono::steady_clock::time_point t_inizio_MergeSort = chrono::steady_clock::now();
            MergeSort(vettore2);
            chrono::steady_clock::time_point t_fine_MergeSort = chrono::steady_clock::now();

            tempo_MergeSort += chrono::duration_cast<chrono::nanoseconds> (t_fine_MergeSort-t_inizio_MergeSort).count();

        }

        tempi_BubbleSort[i] = tempo_BubbleSort/n_ripetizioni;
        tempi_MergeSort[i] = tempo_MergeSort/n_ripetizioni;


        cout << "Per vettori di dimensione " << argv[i] << " la performance degli algoritmi di MergeSort e BubbleSort (in nanosecondi) e' stata rispettivamente di: " << endl;
        cout << fixed << setprecision(0) << tempi_MergeSort[i] << "    " << tempi_BubbleSort[i] << "      Differenza: " << tempi_MergeSort[i] - tempi_BubbleSort[i] << endl;
        cout << endl;
    }

    // vettori ordunati crescenti

    cout << "Vettori con elementi ordinati crescenti" << endl;
    cout << endl;


    for (int i = 1; i < argc; i++)
    {

        // crea due vettori identici (uno per ogni algoritmo). La dimensione è argomento di linea di comando
        vector<int> vettore1(atoi(argv[i]));
        vector<int> vettore2(atoi(argv[i]));

        for (int v = 0; v < atoi(argv[i]); v++)
        {
            vettore1[v] = 2*v;
        }

        vettore2 = vettore1;


        // memorizzano i tempi delle ripetizioni
        double tempo_BubbleSort = 0;
        double tempo_MergeSort = 0;


        for (int n = 0; n < n_ripetizioni; n++)
        {

            chrono::steady_clock::time_point t_inizio_BubbleSort = chrono::steady_clock::now();
            BubbleSort(vettore1);
            chrono::steady_clock::time_point t_fine_BubbleSort = chrono::steady_clock::now();

            tempo_BubbleSort += chrono::duration_cast<chrono::nanoseconds> (t_fine_BubbleSort-t_inizio_BubbleSort).count();

            chrono::steady_clock::time_point t_inizio_MergeSort = chrono::steady_clock::now();
            MergeSort(vettore2);
            chrono::steady_clock::time_point t_fine_MergeSort = chrono::steady_clock::now();

            tempo_MergeSort += chrono::duration_cast<chrono::nanoseconds> (t_fine_MergeSort-t_inizio_MergeSort).count();

        }

        tempi_BubbleSort[i] = tempo_BubbleSort/n_ripetizioni;
        tempi_MergeSort[i] = tempo_MergeSort/n_ripetizioni;


        cout << "Per vettori di dimensione " << argv[i] << " la performance degli algoritmi di MergeSort e BubbleSort (in nanosecondi) e' stata rispettivamente di: " << endl;
        cout << tempi_MergeSort[i] << "    " << tempi_BubbleSort[i] << "      Differenza: " << tempi_MergeSort[i] - tempi_BubbleSort[i] << endl;
        cout << endl;
    }


    // vettori ordinati decrescenti

    cout << "Vettori con elementi ordinati decrescenti" << endl;
    cout << endl;


    for (int i = 1; i < argc; i++)
    {

        // crea due vettori identici (uno per ogni algoritmo). La dimensione è argomento di linea di comando
        vector<int> vettore1(atoi(argv[i]));
        vector<int> vettore2(atoi(argv[i]));

        for (int v = 0; v < atoi(argv[i]); v++)
        {
            vettore1[v] = 2*(atoi(argv[i]) - v);
        }

        vettore2 = vettore1;


        // memorizzano i tempi delle ripetizioni
        double tempo_BubbleSort = 0;
        double tempo_MergeSort = 0;


        for (int n = 0; n < n_ripetizioni; n++)
        {

            chrono::steady_clock::time_point t_inizio_BubbleSort = chrono::steady_clock::now();
            BubbleSort(vettore1);
            chrono::steady_clock::time_point t_fine_BubbleSort = chrono::steady_clock::now();

            tempo_BubbleSort += chrono::duration_cast<chrono::nanoseconds> (t_fine_BubbleSort-t_inizio_BubbleSort).count();

            chrono::steady_clock::time_point t_inizio_MergeSort = chrono::steady_clock::now();
            MergeSort(vettore2);
            chrono::steady_clock::time_point t_fine_MergeSort = chrono::steady_clock::now();

            tempo_MergeSort += chrono::duration_cast<chrono::nanoseconds> (t_fine_MergeSort-t_inizio_MergeSort).count();

        }

        tempi_BubbleSort[i] = tempo_BubbleSort/n_ripetizioni;
        tempi_MergeSort[i] = tempo_MergeSort/n_ripetizioni;


        cout << "Per vettori di dimensione " << argv[i] << " la performance degli algoritmi di MergeSort e BubbleSort (in nanosecondi) e' stata rispettivamente di: " << endl;
        cout << tempi_MergeSort[i] << "    " << tempi_BubbleSort[i] << "      Differenza: " << tempi_MergeSort[i] - tempi_BubbleSort[i] << endl;
        cout << endl;
    }


    // vettori con elementi uguali

    cout << "Vettori con elementi tutti uguali" << endl;
    cout << endl;


    for (int i = 1; i < argc; i++)
    {

        // crea due vettori identici (uno per ogni algoritmo). La dimensione è argomento di linea di comando
        vector<int> vettore1(atoi(argv[i]));
        vector<int> vettore2(atoi(argv[i]));

        int valore = rand() %1000;

        for (int v = 0; v < atoi(argv[i]); v++)
        {
            vettore1[v] = valore;  // vettore di tutte componenti uguali
        }

        vettore2 = vettore1;


        // memorizzano i tempi delle ripetizioni
        double tempo_BubbleSort = 0;
        double tempo_MergeSort = 0;


        for (int n = 0; n < n_ripetizioni; n++)
        {

            chrono::steady_clock::time_point t_inizio_BubbleSort = chrono::steady_clock::now();
            BubbleSort(vettore1);
            chrono::steady_clock::time_point t_fine_BubbleSort = chrono::steady_clock::now();

            tempo_BubbleSort += chrono::duration_cast<chrono::nanoseconds> (t_fine_BubbleSort-t_inizio_BubbleSort).count();

            chrono::steady_clock::time_point t_inizio_MergeSort = chrono::steady_clock::now();
            MergeSort(vettore2);
            chrono::steady_clock::time_point t_fine_MergeSort = chrono::steady_clock::now();

            tempo_MergeSort += chrono::duration_cast<chrono::nanoseconds> (t_fine_MergeSort-t_inizio_MergeSort).count();

        }

        tempi_BubbleSort[i] = tempo_BubbleSort/n_ripetizioni;
        tempi_MergeSort[i] = tempo_MergeSort/n_ripetizioni;


        cout << "Per vettori di dimensione " << argv[i] << " la performance degli algoritmi di MergeSort e BubbleSort (in nanosecondi) e' stata rispettivamente di: " << endl;
        cout << tempi_MergeSort[i] << "    " << tempi_BubbleSort[i] << "      Differenza: " << tempi_MergeSort[i] - tempi_BubbleSort[i] << endl;
        cout << endl;
    }



    delete[] tempi_BubbleSort;
    delete[] tempi_MergeSort;
    return 0;
}
