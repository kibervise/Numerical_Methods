#include <iostream>
#include <cmath>
using namespace std;

float a, b, h, n;
int i, k;
float X[100], Y[100], F[100];
int functionType, choice = 0, coeficient;

void Eiler(){
    n = (b - a) / h;
    for (int i = 0; i <= n; i++)
    {
        X[i + 1] = X[i] + h;
        if (functionType == 1)
        {
            Y[i + 1] = Y[i] + h*(X[i] - sin(Y[i]/(pow(coeficient,1/2))));
        }
        else
        {
            Y[i + 1] = Y[i] + h*(X[i] -cos(Y[i] / (pow(coeficient, 1 / 2))));
        }
        cout << X[i] << "\t|\t" << Y[i] << endl;
    }
}

void EilerKoshi(){

    n = (b - a) / h;
    for (int i = 0; i<= n; i++)
    {
        X[i + 1] = X[i] + h;
        if (functionType == 1)
        {
            Y[i + 1] = Y[i] + h/2*(X[i] + sin(Y[i] / (pow(coeficient, 1 / 2))  +X[i] +sin(Y[i]/ (pow(coeficient, 1 / 2)) +h*(X[i] + sin(Y[i] / (pow(coeficient, 1 / 2)))))));
        }
        else
        {
            Y[i + 1] = Y[i] + h/2*(X[i] + cos(Y[i] / (pow(coeficient, 1 / 2))) + X[i] + cos(Y[i] / (pow(coeficient, 1 / 2)) + h*(X[i] + cos(Y[i] / (pow(coeficient, 1 / 2))))));
        }
        cout<< X[i]<< "\t|\t" << Y[i] <<endl;
    }
}

int main()
{

    cout << "\t\ty' = x + func( y / √coef ) " << endl;
    cout << "\t\tОберіть вашу функцію \n1 - sin \n2 - cos " << endl;
    cout << "Ваш вибір функції: ";
    cin >> functionType;
    cout << "Введіть коєфіціент: ";
    cin >> coeficient;
    cout << "Введіть початковий відрізок [a; b]: a = ";
    cin >> a;
    cout << "Введіть кінцевий відрізок [a; b]: b = ";
    cin >> b;
    cout << "Введіть крок h = ";
    cin >> h;
    cout << "y(" << a << " ) = ";
    cin >> Y[0];
    X[0] = a;
    
    while(choice != 3){
        cout << "\t     -------------- MENU --------------\n" << endl;
        cout << "\t| 1 |. Метод Ейлера " << endl;
        cout << "\t| 2 |. Метод Ейлера-Коші" << endl;
        cout << "\t| 3 |. Вихід з меню " << endl;
        
        cout << "\n\tВаш вибір: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
            {
                Eiler();
                break;
            }
            case 2:
            {
                EilerKoshi();
                break;
            }
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


