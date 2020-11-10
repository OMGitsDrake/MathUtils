#include <iostream>
//#include <random>
#include <time.h>
#include <stdlib.h>

using namespace std;

/**
 *
 * Monaci Lorenzo (Drake) 10/11/2020 Unipi
 * ---------------------------------------
 * 
 * Program to create a random seed generated linear system to resolve applying Gauss-Jordan Elimination algorythm.
 * 
 * This software is free to use and not covered by any license and/or right to be reserved to the original creator
 *  
*/
int main(int argc, char **argv) // returns non-zero values for any non expected end of program, 0 otherwise.
{
    /*
    random_device rd; // obtain a random number from hardware
    
    //    If you wonder "what the hack is mt19937 type?!" - 
    //    A Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits.
    //   It is a "wrapper" for the "mersenne_twister_engine" template (cplusplus.com/reference/random/mersenne_twister_engine)
    //    with pre-set params
    
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-7, 7); // define the range
    */

    srand(time(NULL));

    if (argc > 1) // Executing with user's input
    {
        // Checking input for columns c and rows r : 1<c<7 , 1<r<7.
        if(stoi(argv[1]) < 1 || stoi(argv[2]) < 1 || stoi(argv[1]) > 7 || stoi(argv[2]) > 7){
            cout << "=========================================================================";
            cout << "Valori non corretti, inserire valori entrambi maggiori di 1 e minori di 7";
            cout << "=========================================================================";
            return 1;
        }

        int known[stoi(argv[2])];
        int sys[stoi(argv[1])][stoi(argv[2])];

        printf("C x R\nSistema di ordine %d x %d\n----------\n", stoi(argv[1]), stoi(argv[2]));
        printf("\n=============================\nProgramma lanciato con input da tastiera.\n=============================\n");

        // Building the matrix with random values : -4 < a[i][j] < 9
        for (size_t i = 0; i < stoi(argv[2]); ++i)
        {
            known[i] = rand() % 9 + (-4) + 1;
            for (size_t j = 0; j < stoi(argv[1]); ++j)
                sys[i][j] = rand() % 9 + (-4) + 1;
        }

        // Writing down the matrix with some pretty indentation and values' relative signs
        for (size_t i = 0; i < stoi(argv[2]); ++i)
        {
            for (size_t j = 0; j < stoi(argv[1]); ++j)
            {
                if (sys[i][j] == 0)
                    cout << "+" << sys[i][j] << "   ";
                else
                    sys[i][j] > 0 ? cout << "+" << sys[i][j] << "   " : cout << sys[i][j] << "   ";
            }
            known[i] > 0 ? cout << "| +" << known[i] : cout << "| " << known[i];
            cout << "\n";
        }
    }
    else // Executing program with random data
    {
        short c_size = rand() % 5 + 2 + 1, r_size = rand() % 5 + 2 + 1, known[r_size];
        short sys[c_size][r_size];

        printf("C x R\nSistema di ordine %d x %d\n----------\n", c_size, r_size);
        printf("\n=============================\nProgramma lanciato con parametri casuali.\n=============================\n");

        // Building the matrix with random values : -4 < a[i][j] < 9
        for (size_t i = 0; i < r_size; ++i)
        {
            known[i] = rand() % 9 + (-4) + 1;
            for (size_t j = 0; j < c_size; ++j)
                sys[i][j] = rand() % 9 + (-4) + 1;
        }

        // Writing down the matrix with some pretty indentation and values' relative signs
        for (size_t i = 0; i < r_size; ++i)
        {
            for (size_t j = 0; j < c_size; ++j)
            {
                if (sys[i][j] == 0)
                    cout << "+" << sys[i][j] << "   ";
                else
                    sys[i][j] > 0 ? cout << "+" << sys[i][j] << "   " : cout << sys[i][j] << "   ";
            }
            if (known[i] == 0)
                cout << "| +" << known[i];
            else
                known[i] > 0 ? cout << "| +" << known[i] : cout << "| " << known[i];

            cout << "\n";
        }
    }

    return 0;
}