#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

/**
 * Author: Berk Saltuk Yilmaz
 * ID: 21903419
 * Homework 2
 */


void  sortArray1(int* arr1 , int* arr2, int size1, int*& arr3) // append arr1 first, Algorithm 1, O(N^2) size * size
{
    // initializing time
    double duration;
    clock_t startTime = clock();

    // code
    bool shifted = false;

    for( int i = 0; i < size1; i++)
    {
        arr3[i] = arr1[i];
    }


    for( int i = 0; i < size1; i++){

        for( int j = 0; j < size1 * 2; j++){

            if( arr2[i] <= arr3[j])
            {
                shifted = true;
                for( int k = (size1 *2) - 1; k > j; k--)
                {
                    arr3[k] = arr3[k - 1];
                }
                arr3[j] = arr2[i];
                break;
            }

        }
        if( shifted == false ){
        arr3[i + size1] = arr2[i];
        }
        shifted = false;
    }

    // computing the time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;


}

void  sortArray2(int* arr1 , int* arr2, int size1, int*& arr3) // Algorithm 2  O(N) size + size
{
    // initializing time
    double duration;
    clock_t startTime = clock();

    // code
    int counter = 0;
    int i = 0;
    int j = 0;

    while( i < size1 && j < size1)
    {
        if( arr1[i] >= arr2[j])
        {

            arr3[counter++] = arr2[j];

            j++;
        }
        else
        {

            arr3[counter++] = arr1[i];

            i++;

        }
    }

    while( i < size1)
    {
        arr3[counter++] = arr1[i++];
    }

    while( j < size1)
    {
        arr3[counter++] = arr2[j++];
    }

    // computing the time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;


}

int main(){

    cout << "****************** CASE I ******************" << endl;
    // for (i) N = 100
    int N = 100;

    int* array1 = new int[ N ];
    int* array2 = new int[ N ];

    for( int i = 0; i < N; i++)
    {
        array1[i] = i;
    }

    for( int i = N; i < 2*N; i++)
    {
        array2[i - N] = i;
    }

    int* array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 100 and for (i)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    int* array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 100 and for (i)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;

    // for (i) N = 1000
    cout << "*********************************************" << endl;
    cout << endl;
    cout << "*********************************************" << endl;
    N = 1000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = 0; i < N; i++)
    {
        array1[i] = i;
    }

    for( int i = N; i < 2*N; i++)
    {
        array2[i - N] = i;
    }

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 1000 and for (i)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 1000 and for (i)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << "*********************************************" << endl;
    cout << endl;
    // for (i) N = 10000
    cout << "*********************************************" << endl;
    N = 10000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = 0; i < N; i++)
    {
        array1[i] = i;
    }

    for( int i = N; i < 2*N; i++)
    {
        array2[i - N] = i;
    }

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 10000 and for (i)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 10000 and for (i)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << "*********************************************" << endl;
    cout << endl;

    // for (i) N = 20000
    cout << "*********************************************" << endl;
    N = 20000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = 0; i < N; i++)
    {
        array1[i] = i;
    }

    for( int i = N; i < 2*N; i++)
    {
        array2[i - N] = i;
    }

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 20000 and for (i)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 20000 and for (i)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << "*********************************************" << endl;
    cout << endl;

    // for (i) N = 30000
    cout << "*********************************************" << endl;
    N = 30000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = 0; i < N; i++)
    {
        array1[i] = i;
    }

    for( int i = N; i < 2*N; i++)
    {
        array2[i - N] = i;
    }

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 30000 and for (i)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 30000 and for (i)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << "*********************************************" << endl;
    cout << endl;

    // for (i) N = 40000
    cout << "*********************************************" << endl;

    cout << "Since Algorithm 1 takes too long for bigger numbers from now on only Algorithm 2 will be called." << endl;
    cout << endl;
    N = 40000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = 0; i < N; i++)
    {
        array1[i] = i;
    }

    for( int i = N; i < 2*N; i++)
    {
        array2[i - N] = i;
    }

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 40000 and for (i)" << endl;
    sortArray2( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << endl;
    // for (i) N = 50000
    cout << "*********************************************" << endl;
    cout << endl;
    N = 50000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = 0; i < N; i++)
    {
        array1[i] = i;
    }

    for( int i = N; i < 2*N; i++)
    {
        array2[i - N] = i;
    }

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 50000 and for (i)" << endl;
    sortArray2( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << endl;
    // for (i) N = 100000
    cout << "*********************************************" << endl;
    cout << endl;
    N = 100000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = 0; i < N; i++)
    {
        array1[i] = i;
    }

    for( int i = N; i < 2*N; i++)
    {
        array2[i - N] = i;
    }

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 100000 and for (i)" << endl;
    sortArray2( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << endl;

    // for (i) N = 500000
    cout << "*********************************************" << endl;
    cout << endl;
    N = 500000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = 0; i < N; i++)
    {
        array1[i] = i;
    }

    for( int i = N; i < 2*N; i++)
    {
        array2[i - N] = i;
    }

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 500000 and for (i)" << endl;
    sortArray2( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << endl;
    cout << "****************** CASE II ******************" << endl;
    // for (ii) N = 100

    N = 100;

    array1 = new int[ N ];
    array2 = new int[ N ];


    for( int i = N; i < 2*N; i++)
    {
        array1[i - N] = i;
    }

    for( int i = 0; i < N; i++)
    {
        array2[i ] = i;
    }

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 100 and for (ii)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 100 and for (ii)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;

    cout << "*********************************************" << endl;
    cout << endl;
    // for (ii) N = 1000
    cout << "*********************************************" << endl;
    N = 1000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = N; i < 2*N; i++)
    {
        array1[i - N] = i;
    }

    for( int i = 0; i < N; i++)
    {
        array2[i ] = i;
    }

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 1000 and for (ii)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 1000 and for (ii)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;

    cout << "*********************************************" << endl;
    cout << endl;
    // for (ii) N = 10000
    cout << "*********************************************" << endl;
    N = 10000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = N; i < 2*N; i++)
    {
        array1[i - N] = i;
    }

    for( int i = 0; i < N; i++)
    {
        array2[i ] = i;
    }

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 10000 and for (ii)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 10000 and for (ii)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;

    cout << "*********************************************" << endl;
    cout << endl;


    // for (ii) N = 20000
    cout << "*********************************************" << endl;
    N = 20000;

    array1 = new int[ N ];
    array2 = new int[ N ];

     for( int i = N; i < 2*N; i++)
    {
        array1[i - N] = i;
    }

    for( int i = 0; i < N; i++)
    {
        array2[i ] = i;
    }


    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 20000 and for (ii)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 20000 and for (ii)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << "*********************************************" << endl;
    cout << endl;

    // for (ii) N = 30000
    cout << "*********************************************" << endl;
    N = 30000;

    array1 = new int[ N ];
    array2 = new int[ N ];

     for( int i = N; i < 2*N; i++)
    {
        array1[i - N] = i;
    }

    for( int i = 0; i < N; i++)
    {
        array2[i ] = i;
    }


    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 30000 and for (ii)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 30000 and for (ii)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << "*********************************************" << endl;
    cout << endl;

    // for (ii) N = 40000
    cout << "*********************************************" << endl;

    cout << "Since Algorithm 1 takes too long for bigger numbers from now on only Algorithm 2 will be called." << endl;
    cout << endl;
    N = 40000;

    array1 = new int[ N ];
    array2 = new int[ N ];

     for( int i = N; i < 2*N; i++)
    {
        array1[i - N] = i;
    }

    for( int i = 0; i < N; i++)
    {
        array2[i ] = i;
    }


    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 40000 and for (ii)" << endl;
    sortArray2( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << endl;
    // for (ii) N = 50000
    cout << "*********************************************" << endl;
    cout << endl;
    N = 50000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = N; i < 2*N; i++)
    {
        array1[i - N] = i;
    }

    for( int i = 0; i < N; i++)
    {
        array2[i ] = i;
    }


    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 50000 and for (ii)" << endl;
    sortArray2( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << endl;
    // for (ii) N = 100000
    cout << "*********************************************" << endl;
    cout << endl;
    N = 100000;

    array1 = new int[ N ];
    array2 = new int[ N ];

     for( int i = N; i < 2*N; i++)
    {
        array1[i - N] = i;
    }

    for( int i = 0; i < N; i++)
    {
        array2[i ] = i;
    }


    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 100000 and for (ii)" << endl;
    sortArray2( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << endl;

    // for (ii) N = 500000
    cout << "*********************************************" << endl;
    cout << endl;
    N = 500000;

    array1 = new int[ N ];
    array2 = new int[ N ];

     for( int i = N; i < 2*N; i++)
    {
        array1[i - N] = i;
    }

    for( int i = 0; i < N; i++)
    {
        array2[i ] = i;
    }


    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 500000 and for (ii)" << endl;
    sortArray2( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << endl;


    cout << "****************** CASE III ******************" << endl;
    // for (iii) N = 100

    N = 100;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = 0; i < N; i++)
    {
        array1[i] = rand();
    }

    for( int i = 0; i < N; i++)
    {
        array2[i] = rand();
    }

    sort( array1, array1 + N);
    sort( array2, array2 + N);

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 100 and for (iii)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 100 and for (iii)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;

    cout << "*********************************************" << endl;
    cout << endl;
    // for (iii) N = 1000
    cout << "*********************************************" << endl;
    N = 1000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = 0; i < N; i++)
    {
        array1[i] = rand();
    }

    for( int i = 0; i < N; i++)
    {
        array2[i] = rand();
    }

    sort( array1, array1 + N);
    sort( array2, array2 + N);

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 1000 and for (iii)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 1000 and for (iii)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;


    cout << "*********************************************" << endl;
    cout << endl;
    // for (iii) N = 10000
    cout << "*********************************************" << endl;
    N = 10000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = 0; i < N; i++)
    {
        array1[i] = rand();
    }

    for( int i = 0; i < N; i++)
    {
        array2[i] = rand();
    }

    sort( array1, array1 + N);
    sort( array2, array2 + N);

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 10000 and for (iii)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 10000 and for (iii)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;

    // for (iii) N = 20000
    cout << "*********************************************" << endl;
    N = 20000;

    array1 = new int[ N ];
    array2 = new int[ N ];

     for( int i = 0; i < N; i++)
    {
        array1[i] = rand();
    }

    for( int i = 0; i < N; i++)
    {
        array2[i] = rand();
    }


    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 20000 and for (iii)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 20000 and for (iii)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << "*********************************************" << endl;
    cout << endl;

    // for (iii) N = 30000
    cout << "*********************************************" << endl;
    N = 30000;

    array1 = new int[ N ];
    array2 = new int[ N ];

     for( int i = 0; i < N; i++)
    {
        array1[i] = rand();
    }

    for( int i = 0; i < N; i++)
    {
        array2[i] = rand();
    }

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 30000 and for (iii)" << endl;
    sortArray1( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    array4 = new int [ 2 * N ];

    cout << "Calling second algorithm for N = 30000 and for (iii)" << endl;
    sortArray2( array1, array2, N, array4);


    delete [] array4;
    array4 = NULL;
    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << "*********************************************" << endl;
    cout << endl;

    // for (i) N = 40000
    cout << "*********************************************" << endl;

    cout << "Since Algorithm 1 takes too long for bigger numbers from now on only Algorithm 2 will be called." << endl;
    cout << endl;
    N = 40000;

    array1 = new int[ N ];
    array2 = new int[ N ];

     for( int i = 0; i < N; i++)
    {
        array1[i] = rand();
    }

    for( int i = 0; i < N; i++)
    {
        array2[i] = rand();
    }

    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 40000 and for (iii)" << endl;
    sortArray2( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << endl;
    // for (i) N = 50000
    cout << "*********************************************" << endl;
    cout << endl;
    N = 50000;

    array1 = new int[ N ];
    array2 = new int[ N ];

    for( int i = 0; i < N; i++)
    {
        array1[i] = rand();
    }

    for( int i = 0; i < N; i++)
    {
        array2[i] = rand();
    }


    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 50000 and for (iii)" << endl;
    sortArray2( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << endl;
    // for (i) N = 100000
    cout << "*********************************************" << endl;
    cout << endl;
    N = 100000;

    array1 = new int[ N ];
    array2 = new int[ N ];

     for( int i = 0; i < N; i++)
    {
        array1[i] = rand();
    }

    for( int i = 0; i < N; i++)
    {
        array2[i] = rand();
    }


    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 100000 and for (iii)" << endl;
    sortArray2( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << endl;

    // for (i) N = 500000
    cout << "*********************************************" << endl;
    cout << endl;
    N = 500000;

    array1 = new int[ N ];
    array2 = new int[ N ];

     for( int i = 0; i < N; i++)
    {
        array1[i] = rand();
    }

    for( int i = 0; i < N; i++)
    {
        array2[i] = rand();
    }


    array3 = new int [ 2 * N ];

    cout << "Calling first algorithm for N = 500000 and for (iii)" << endl;
    sortArray2( array1, array2, N, array3);

    cout << "*********************************************" << endl;

    delete [] array3;
    array3 = NULL;

    delete [] array1;
    delete [] array2;
    cout << endl;

return 0;
}

