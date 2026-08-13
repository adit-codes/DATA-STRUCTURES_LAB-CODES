#include<iostream>
#include<math>
using namespace std;
//MAGIC SQUARE
class ODDMAGIC
{
    int order;
    int** matrix = new int*[order];
    int row=0;int col=0;
    public:
        void create_matrix()
        {
           for (int i = 0; i < order; i++) {
                matrix[i] = new int[order];
                }
            for(int i=0;i<order;i++)
            {
                for(int j=0;j<order;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        void set_pos()
        {
            cin>>row>>col;
        }
        void oddmatrix()
        {
            create_matrix();
            set_pos();
            for(int i=1;i<=pow(n,n);i++)
            {
                row=
            }

        }

