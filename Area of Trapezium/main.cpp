#include <iostream>

using namespace std;

int main()
{
    float a,b,h,area;
    cout<<"Enter the upper base a, lower base b and height h: ";
    cin>>a>>b>>h;
    area = (a+b)*h/2;
    //cout <<"Trapezium area is : " <<area<< endl;
    printf("Trapezium area is : %.2f",area);
    return 0;
}
