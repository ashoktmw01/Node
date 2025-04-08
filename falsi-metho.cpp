#include<iostream>
#include<math.h>
using namespace std;

double fxn(double x){
    return pow(x, 3) - x - 2;
}
void falsiFxn(double *a, double *b){
    if (*a == *b)
        cout<<"Both the points are same, enter different points"<<endl;

    double valatA, valatB;
    valatA = fxn(*a);
    valatB = fxn(*b);
    double c = *a - (valatA * (*b-*a))/(valatB-valatA);
    double valatC = fxn(c);
    if ( valatA * valatC < 0){
        *b= c;
    }else   
        *a= c;
}
int main(){
    double a = 1, b = 2;
    int iter = 0;
    while (abs(b-a)>0.000001)
    {
        falsiFxn(&a,&b);
        iter++;
    }
    cout<<"Apporx root of the equation are : "<<a<<" "<<"and "<<b<<endl;
    cout<<"Number of iterations : "<<iter;
    return 0;
}