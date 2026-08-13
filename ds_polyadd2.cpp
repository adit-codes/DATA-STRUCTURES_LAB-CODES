#include<iostream>
using namespace std;
typedef struct { int coef, expo; } TERM;
typedef struct { TERM t[100]; int nT; } POLY;
POLY createPoly() {POLY p; p.nT=0; return p;}
void printPoly(POLY p)
{   for (int i=0; i<p.nT; i++)
        printf("+%dx^%d", p.t[i].coef, p.t[i].expo);
    return;
}
POLY attachTerm(POLY p, TERM t)
{   int i = p.nT-1;
    while (i>=0) if (p.t[i].expo == t.expo) return p; else i = i - 1; //duplicate term testing
    i = p.nT-1;
    //attaching a new term in the decreasing order of exponent
    while ((i>=0) && (p.t[i].expo < t.expo)) {p.t[i+1] = p.t[i]; i = i - 1;}
    p.t[i+1] = t; p.nT = p.nT + 1;
    return p;
}
POLY poly_add(POLY p1, POLY p2)
{
    POLY p3 = createPoly();
    int i = 0, j = 0;
    int n = p1.nT, m = p2.nT;
    while(i<n && j<m)
    {
        //if exponents are equal
        if(p1.t[i].expo==p2.t[j].expo)
        {
            TERM t={p1.t[i].coef+p2.t[i].coef,p1.t[i].expo};
            p3=attachTerm(p3,t);
            i+=1;j+=1;
        }
        //if n greater
        else if(p1.t[i].expo>p2.t[j].expo)
        {
            p3=ttachTerm(p3,p1.t[i]);
            i+=1;
        }
        //if n is lesser
        else
        {
            p3=attachTerm(p3,p2.t[j]);
            j+=1;
        }
    }
    while(i<n)
    {
        p3=attachTerm(p3,p1.t[i]);
        i+=1;
    }
    while(j<m)
    {
        p3=attachTerm(p3,p2.t[j]);
        j+=1;
    }
    return p3;

}

int main()
{
    TERM t1 = {2, 12}, t2 = { 7, 12}, t3 = {3, 7}; POLY p;
    p = createPoly();
    p = attachTerm(p, t1);
    p = attachTerm(p, t2);
    p = attachTerm(p, t3);
    printf ("\n P1 = ");printPoly(p);
    POLY p2=poly_add(p,p);
    printPoly(p2);
    return 0;
}
