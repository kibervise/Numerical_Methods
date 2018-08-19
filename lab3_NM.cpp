#include <stdio.h>
#include <iostream>
using namespace std;

void readyInput()
{
    const int quality = 6;
    double X[] = { 0, 0.1, 0.2, 0.3, 0.4, 0.5 };
    double Y[] = { 1.2733,1.8007,2.3606,2.9577,3.5969,4.2833 };
    double y1[quality];
    double y2[quality];
    double y3[quality];
    double y4[quality];
    double y5[quality];
    double enterValueX, q, h, firstDerivative, secondDerivative;
    int k, i;
    
    cout << "Тable of values of a function:" << endl;
    cout << "\t\t\tX" << "\t|" << "\tY" << endl;
    cout << "\t\t\t--------------" << endl;
    for (i = 0; i < quality; i++)
    cout << "\t\t\t" << X[i] << "\t|" << "\t" << Y[i] << endl;
    cout << endl;
    cout << "Еnter value X: "; cin >> enterValueX;
    
    h = 0;
    i = 1;
    q = 0;
    k = 0;

    h = (X[i] - X[i - 1]);
    cout << "\nh = " << h << endl;
    q = (enterValueX - X[i - 1]) / h;
    cout << "q = " << q << endl << endl;;
    
    cout << "\t\t\t  ∆yi" << endl;
    cout << "\t\t\t------" << endl;
    for (int j = 1; j<quality; j++)
    {
        y1[k] = Y[j] - Y[j - 1];
        cout << "\t\t\t" << y1[k] << endl;
        k++;
    }
    
    cout << "\n\t\t\t  ∆2yi" << endl;
    cout << "\t\t\t------" << endl;
    k = 0;
    for (int j = 1; j<quality - 1; j++)
    {
        y2[k] = y1[j] - y1[j - 1];
        cout <<  "\t\t\t" << y2[k] << endl;
        k++;
    }
    
    cout << "\n\t\t\t  ∆3yi" << endl;
    cout << "\t\t\t------" << endl;
    k = 0;
    for (int j = 1; j<quality - 2; j++)
    {
        y3[k] = y2[j] - y2[j - 1];
        cout <<  "\t\t\t" << y3[k] << endl;
        k++;
    }
    
    cout << "\n\t\t\t  ∆4yi" << endl;
    cout << "\t\t\t------" << endl;
    k = 0;
    for (int j = 1; j<quality - 3; j++)
    {
        y4[k] = y3[j] - y3[j - 1];
        cout <<  "\t\t\t" << y4[k] << endl;
        k++;
    }
    
    cout << "\n\t\t\t  ∆5yi" << endl;
    cout << "\t\t\t------" << endl;
    k = 0;
    for (int j = 1; j < quality - 4; j++)
    {
        y5[k] = y4[j] - y4[j - 1];
        cout <<  "\t\t\t" << y5[k] << endl;
        k++;
    }

    firstDerivative = (y1[0] + y2[0] * (2 * q - 1) / 2 + y3[0] * (3 * q*q - 6 * q + 2) / 6 + y4[0] * (4 * q*q*q - 18 * q*q + 22 * q - 6) / 24 + y5[0] * (5 * q*q*q*q + 40 * q*q*q + 105 * q*q - 100 * q + 24) / 120) / h;
    cout << "\nY' = " << firstDerivative << endl;

    secondDerivative = (y2[0] + y3[0] * (q - 1) + y4[0] * (12 * q*q - 36 * q + 22) / 24 + y5[0] * (20 * q*q*q - 120 * q*q + 210 * q - 100) / 120) / (h*h);
    cout << "Y\" = " << secondDerivative;
    cout << endl;

}

void handInput()
{
    int enterX, enterY;
    int size;
    double y1[size];
    double y2[size];
    double y3[size];
    double y4[size];
    double y5[size];
    double enterValueX, q, h, firstDerivative, secondDerivative;
    int k, i;
    
    cout << "\nEnter number of quality elements: ";
    cin >> size;
    cout << endl;
    
    double X[size];
    double Y[size];
    for( enterX = 0; enterX < size; enterX++)
    {
        cout << "Values of X[ " << enterX << " ] = ";
        cin >> X[enterX];
    }
    cout << endl;
    for( enterY = 0; enterY < size; enterY++)
    {
        cout << "Values of Y[ " << enterY << " ] = ";
        cin >> Y[enterY];
    }
    
    cout << "\nТable of values of a function:" << endl;
    cout << "\t\t\tX" << "\t|" << "\tY" << endl;
    cout << "\t\t\t--------------" << endl;
    for (i = 0; i < size; i++)
    cout << "\t\t\t" << X[i] << "\t|" << "\t" << Y[i] << endl;
    cout << endl;
    cout << "Еnter value X: "; cin >> enterValueX;
    
    h = 0;
    i = 1;
    q = 0;
    k = 0;
    
    h = (X[i] - X[i - 1]);
    cout << "\nh = " << h << endl;
    q = (enterValueX - X[i - 1]) / h;
    cout << "q = " << q << endl << endl;;
    
    cout << "\t\t\t  ∆yi" << endl;
    cout << "\t\t\t------" << endl;
    for (int j = 1; j< size; j++)
    {
        y1[k] = Y[j] - Y[j - 1];
        cout << "\t\t\t" << y1[k] << endl;
        k++;
    }
    cout << "\n\t\t\t  ∆2yi" << endl;
    cout << "\t\t\t------" << endl;
    
    k = 0;
    for (int j = 1; j< size - 1; j++)
    {
        y2[k] = y1[j] - y1[j - 1];
        cout <<  "\t\t\t" << y2[k] << endl;
        k++;
    }
    
    cout << "\n\t\t\t  ∆3yi" << endl;
    cout << "\t\t\t------" << endl;
    k = 0;
    for (int j = 1; j< size - 2; j++)
    {
        y3[k] = y2[j] - y2[j - 1];
        cout <<  "\t\t\t" << y3[k] << endl;
        k++;
    }
    
    cout << "\n\t\t\t  ∆4yi" << endl;
    cout << "\t\t\t------" << endl;
    k = 0;
    for (int j = 1; j< size - 3; j++)
    {
        y4[k] = y3[j] - y3[j - 1];
        cout <<  "\t\t\t" << y4[k] << endl;
        k++;
    }
    
    cout << "\n\t\t\t  ∆5yi" << endl;
    cout << "\t\t\t------" << endl;
    k = 0;
    for (int j = 1; j< size - 4; j++)
    {
        y5[k] = y4[j] - y4[j - 1];
        cout <<  "\t\t\t" << y5[k] << endl;
        k++;
    }
    
    int zero = 0;
    firstDerivative = (y1[zero] + y2[zero] * (2 * q - 1) / 2 + y3[zero] * (3 * q*q - 6 * q + 2) / 6 + y4[zero] * (4 * q*q*q - 18 * q*q + 22 * q - 6) / 24 + y5[zero] * (5 * q*q*q*q + 40 * q*q*q + 105 * q*q - 100 * q + 24) / 120) / h;
    cout << "\nY' = " << firstDerivative << endl;
    secondDerivative = (y2[zero] + y3[zero] * (q - 1) + y4[zero] * (12 * q*q - 36 * q + 22) / 24 + y5[zero] * (20 * q*q*q - 120 * q*q + 210 * q - 100) / 120) / (h*h);
    cout << "Y\" = " << secondDerivative;
    cout << endl;
}

void menu(){
    int choice = 0;
    
    cout << "\t         -------------- MENU --------------\n" << endl;
    cout << "\t| 1 |. Show ready table with function values" << endl;
    cout << "\t| 2 |. Create new table with function values" << endl;
    cout << "\t| 3 |. Exit" << endl;
    cout << "\n\tYour choice: ";
    cin >> choice;
    
    switch(choice)
    {
        case 1:
        {
            readyInput();
            menu();
            break;
        }
        case 2:
        {
            handInput();
            menu();
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
            if(choice > 4 || choice < 1)
            {
                cout << "Your choise is not correct, try again!\n" << endl;
                menu();
                break;
            }
        }
    }
}

int main()
{
    menu();
}


