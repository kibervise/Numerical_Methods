#include <stdio.h>
#include <iostream>
using namespace std;

//double XX[] = { 0, 2, 3, 5 };
//double YY[] = { 1, 3, 2, 5 };

void handInput(){
    int enterX, enterY, size;
    double var, valueY, valueX;
    
    cout << "Enter number of quality elements: ";
    cin >> size;
    cout << endl;
    
    double XX[size];
    double YY[size];
    for( enterX = 0; enterX < size; enterX++)
    {
        cout << "Values of X[ " << enterX << " ] = ";
        cin >> XX[enterX];
    }
    cout << endl;
    for( enterY = 0; enterY < size; enterY++)
    {
        cout << "Values of Y[ " << enterY << " ] = ";
        cin >> YY[enterY];
    }
    
    cout << "\n\n\t\t----Тable with function values:----\n";
    cout << "\t\t\t\tX: ";
    for(enterX = 0; enterX < size; enterX++)
    {
        cout << XX[enterX] << " | " ;
    }
    
    cout << "\n\t\t\t\tY: ";
    for(enterY = 0; enterY < size; enterY++)
    {
        cout << YY[enterY] << " | " ;
    }
    
    cout << endl << endl;
    /////////////////////////
    cout << "Еnter value at point X: ";
    cin >> valueX;
    valueY = 0;
    for(int i = 0; i < size; i++)
    {
        var = 1;
        for(int j = 0; j < size; j++)
        {
            if( i != j)
                var = var * (( valueX - XX [j] ) / ( XX[i] - XX[j] ));
        }
        valueY = valueY + YY[i] * var;
    }
    cout << "f(" << valueX << ") ≈ " << valueY << endl;
}

void readyInput(){
    
    double XX[] = { 0, 2, 3, 5 };
    double YY[] = { 1, 3, 2, 5 };
    double var, valueY, valueX;
    
    cout << "\n\n\t\t----Тable with function values:----\n";
    cout << "\t\t\t\tX: ";
    for(int i = 0; i < 4; i++)
    {
        cout << XX[i] << "  |  ";
    }
    cout << endl;
    
    cout << "\t\t\t\tY: ";
    for(int i = 0; i < 4; i++)
    {
        cout << YY[i] << "  |  ";
    }
    cout << endl << endl;
    
    cout << "Еnter value at point X: ";
    cin >> valueX;
    valueY = 0;
    for(int i = 0; i < 4; i++)
    {
        var = 1;
        for(int j = 0; j < 4; j++)
        {
            if( i != j)
                var = var * (( valueX - XX [j] ) / ( XX[i] - XX[j] ));
        }
        valueY = valueY + YY[i] * var;
    }
    cout << "f(" << valueX << ") ≈ " << valueY << endl;
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

int  main ()
{
    menu();
}

