#include <iostream>
using namespace std;
class Permutations
{
    private:
    int size;
    int* array;
    int** bigarr;
    public:
        Permutations(int n)
        {
            size = n;
            array = new int[size];
            bigarr= new int[factorial(size)];for (int i = 0; i < order; i++) {
                matrix[i] = new int[order];
                }
        }
        void inputArray()
        {
            for (int i = 0; i < size; i++)
            {
                cin >> array[i];
            }
        }
        int factorial(int n)
        {
            if (n == 0 || n == 1) return 1;
            return n * factorial(n - 1);
        }
        ~Permutations()
        {
            delete[] array;
        }
        void* recursive(int swaps)
        {
            if(swaps==0)return;
            recursive(swaps-1);
            for(int i=0;i)


        }
