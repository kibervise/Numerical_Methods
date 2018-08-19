//
//  lab4_NM.cpp
//  lNM
//
//  Created by Kibervise on 03.04.2018.
//  Copyright © 2018 Kibervise. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
#include <math.h>

double f(double x)
{
    return 1/sqrt(x+3);
}

double LeftS(double a, double b, int n)  // Метод лівих прямокутників
{
    double s = 0;
    double x = a;
    double h=(b-a)/double(n);
    for(int i=0; i<n; i++)
    {
        s+=f(x);
        x+=h;
    }
    s*=h;
    return s;
}

double RightS(double a, double b, int n)  // Метод правих прямокутників
{
    double s=0;
    double h=(b-a)/double(n);
    double x=a+h;
    for(int i=1; i<=n; i++)
    {
        s+=f(x);
        x+=h;
    }
    s*=h;
    return s;
}
double MidelS(double a, double b, int n)  // Метод середніх прямокутників
{
    double s=0;
    double x=a;
    double h=(b-a)/double(n);
    for(int i=0; i<n; i++)
    {
        s+=f(x+h/2);
        x+=h;
    }
    s*=h;
    return s;
}
double SiS(double a, double b, int n) // Метод Сімпсона
{
    double s=0;
    double s1=0;
    double s2=0;
    double h=(b-a)/double(n);
    double x=a+h;
    for(int i=1; i<n; i+=2)
    {
        s1+=f(x);
        x+=2*h;
    }
    x=a+2*h;
    for(int i=2; i<n; i+=2)
    {
        s2+=f(x);
        x+=2*h;
    }
    s+=f(a)+f(b)+s1*4+s2*2;
    s*=h/3;
    return s;
}
double TrS(double a, double b, int n)  // Метод трапецій
{
    double s=0;
    double x=a;
    double h=(b-a)/double(n);
    for(int i=1; i<n; i++)
    {
        s+=f(x);
        x+=h;
    }
    s+=f(a)/2+f(b)/2;
    s*=h;
    return s;
}

void menu(){
    int choice = 0;
    double x;
    double a;
    double b;
    int n;

    cout << "Integration of a function f(x)=1/sqrt(0.3*x+1.2*x) on the interval [a;b]";
    cout<< endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "Enter the number of division segments n = ";
    cin >> n;
    
    while(choice != 6){
        cout << "\t     -------------- MENU --------------\n" << endl;
        cout << "\t| 1 |. Count by left-hand rectangles " << endl;
        cout << "\t| 2 |. Count by right-hand rectangles " << endl;
        cout << "\t| 3 |. Count by mid-square rectangles " << endl;
        cout << "\t| 4 |. Count by Simpson's method " << endl;
        cout << "\t| 5 |. Count by trapezoids method " << endl;
        cout << "\t| 6 |. Exit" << endl;
        
        cout << "\n\tYour choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
            {
                cout << " S = " << LeftS(a, b, n)<<endl;
                break;
            }
            case 2:
            {
                cout << " S = " << RightS(a, b, n)<<endl;
                break;
            }
            case 3:
            {
                cout << " S = " << MidelS(a, b, n)<<endl;
                break;
            }
            case 4:
            {
                cout << " S = " << SiS(a, b, n)<<endl;
                break;
            } case 5:
            {
                cout << " S = " << TrS(a, b, n)<<endl;
                break;
            }
            case 6:
            {
                cout << "\n\t                       Bye :) " << endl;
                cout << "\n\t         --------------- END --------------\n" << endl;
                break;
            }
            default:
            {
                if(choice > 6 || choice < 1)
                {
                    cout << "Your choise is not correct, try again!\n" << endl;
                    break;
                }
            }
        }
    }
    
}
    
int main()
{
    menu();
}

