#include <iostream>
#include <cmath>

using namespace std;
float a, b, x, e,q ,x1,x2,y2, c1, c2, c3, c4, c5;

int flag, z, k, s,l;
float  y, t, p=0, p1, p2, n, c, i = 0;

float f(float x, int c1, int c2, int c3, int c4,int c5)
{
    float v=(c1 * pow(x, 4) + c2 * pow(x, 3) + c3 * pow(x, 2) + c4*x+c5);
    return v;
}
float dF(float x, int c1, int c2, int c3, int c4)
{
    float v = c1 * 4 * pow(x, 3) + c2 * 3 * pow(x, 2) + c3 * 2 * x + c4;
    return v;
};


void calc(int c1, int c2, int c3, int c4,int c5)
{
    
    if (a >= b) goto A;
    p1 = a; p2 = b; p = (p1 + p2) / 2; n = 1; q = 0; z = 6; k = 5; i = 1;
    do {
        n *= 10;
        q++;
    } while (n*e< 1);
    if (f(p1, c1, c2, c3, c4,c5)*f(p2, c1, c2, c3, c4,c5)> 0) goto A;
    y = f(p, c1, c2, c3, c4,c5);
    cout << "f(" << p << ") = " << y << endl;
    do {
        if (f(p1, c1, c2, c3, c4,c5)*f(p, c1, c2, c3, c4,c5)< 0)
        {
            p1 = p1;
            p2 = p;
            p = (p1 + p2) / 2;
        }
        else
        {
            p1 = p;
            p2 = p2;
            p = (p1 + p2) / 2;
        }
        z++; i++;
        y = f(p, c1, c2, c3, c4,c5);
        cout<<"f(" <<p<<") = "<< y<<endl;
        if (z == 21)
        {
            k = 42;
            l = z;
            z = 5;
        }
    } while (fabs(f(p, c1, c2, c3, c4,c5))> e);
    c = fabs((p1 - p2) / 2);
    cout<< "Корін рівняння x = " << p<< endl;
A:
    cout << "на заданому інтервалі немає коренів";
}

int main()
{
    int choice = 0;
    
    while(choice != 3){
        cout << "\t     -------------- MENU --------------\n" << endl;
        cout << "\t| 1 |. Розв'язання нелінійного рівняння методом Ньютона " << endl;
        cout << "\t| 2 |. Розв'язання нелінійного алгебраїчного рівняння методом бісекції " << endl;
        cout << "\t| 3 |. Exit" << endl;
        
        cout << "\n\tYour choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
            {
                
                cout << "a * x^4 + b * x^3 + c * x^2 + d * x + f= 0 " << endl;
                cout << "Введіть a: "; cin >> c1;
                cout << "Введіть b: "; cin >> c2;
                cout << "Введіть c: "; cin >> c3;
                cout << "Введіть d: "; cin >> c4;
                cout << "Введіть f: "; cin >> c5;
                cout << endl << c1 << " * x ^ 4 + "<< c2 <<" * x ^ 3 +"<< c3 <<" * x ^ 2 + "<< c4 <<" = 0"<< endl;
                cout << "Введіть проміжок[a; b]: "<<endl;
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                cout << "Введіть похибку e = ";
                cin >> e;
                i = 0;
                if (a> b)
                {
                    x = a;
                    a = b;
                    b = x;
                }
                cout<<"Kорені: " << endl;
                for (x = a;x < b; x += e * 100)
                {
                    float y1 = f(x,c1,c2,c3,c4,c5);
                    y2 = f(x + e * 100,c1,c2,c3,c4,c5);
                    if (((y1> 0) && (y2<0)) || ((y1<0) && (y2> 0)))
                    {
                        i++;
                        do {
                            x1 = x;
                            x2 = x1 - f(x1,c1,c2,c3,c4,c5) / dF(x1,c1,c2,c3,c5);
                            x1 = x2;
                            q = fabs(x1 - x2);
                        } while (q>e);
                        cout<<"x"<<i<< "= " << x1<< endl;
                    }
                }
                break;
            }
            case 2:
            {
                cout << "a * x^4 + b * x^3 + c * x^2 + d * x + f= 0 " << endl;
                cout << "Введіть a: "; cin >> c1;
                cout << "Введіть b: "; cin >> c2;
                cout << "Введіть c: "; cin >> c3;
                cout << "Введіть d: "; cin >> c4;
                cout << "Введіть f: "; cin >> c5;
                cout << endl << c1 << " * x ^ 4 + "<< c2 <<" * x ^ 3 +"<< c3 <<" * x ^ 2 + "<< c4 <<" = 0"<< endl;
                cout << "Введіть проміжок[a; b]: "<<endl;
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                cout << "Введіть похибку e = ";
                cin >> e;
                calc( c1, c2, c3, c4, c5);
            }
                break;
            case 3:
            {
                cout << "\n\t                       Bye :) " << endl;
                cout << "\n\t         --------------- END --------------\n" << endl;
                break;
            }
            default:
            {
                if(choice > 3 || choice < 1)
                {
                    cout << "Your choise is not correct, try again!\n" << endl;
                    break;
                }
            }
        }
    }
}

