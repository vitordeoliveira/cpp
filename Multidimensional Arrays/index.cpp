#include <iostream>


int main()
{

    // Is very inefficient because a multiple dim array is a pointer of a pointer of data. 
    // Every time we need to change the dim computer need to search for the next block of memory
    int exemple[10][20];

    int* ex = new int[20];
    int** a2d = new int*[10];


    // We can do everything in one dim
    int *array = new int[5 * 5];

    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            int pos = x + y * 5;
            array[pos] = 2;

            std::cout << pos << "\n";
        }
    }
}