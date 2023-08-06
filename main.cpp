#include <iostream>

void Add(int a, int b, int& result);    //Add two numbers and return the result through a reference parameter
void Factorial(int a, int& result);    //Find factorial of a number and return that through a reference parameter
void Swap(int& a, int& b);

void Add(int a, int b, int& result) {
    result = a + b;
    return;
}

void Swap(int& a, int& b) {
    int helper{ a };
    a = b;
    b = helper;

    return;
}

void Factorial(int a, int& result) {
    int i;
    int lim{ a };
    result = a;

    for (i = 0; i + 1 < a; ++i) {
        result = (result) * (lim - (i + 1));
    }

    return;
}

/*Main notes -------------------------------------------------------------------------
--> Input not protected
-----------------------*/

int main() {
    int a{ 5 }, b{ 0 }, c{ 0 }; // for testing
    int& refa{ a }, & refb{ b }, & refc{ c }; // this does not allocate any memory
    int d{ 0 }, e{ 0 }; // for swap testing

    using namespace std;
    /*Addition testing ----------------------------------------------
    -----------------------*/
    cout << "Enter two numbers to calculate the addition: " << endl;
    cin >> a;
    cout << "Enter anoether one" << endl;
    cin >> b;
    Add(a, b, refc);
    cout << "your result is " << refc << endl;


    /*Factorial testing ----------------------------------------------
    -----------------------*/
    cout << "Enter a number to calculate the factorial : " << endl;
    cin >> a;

    Factorial(a, refb);
    cout << "The result of the factorial of " << a << " is: " << refb << endl;


    /*swap testing ----------------------------------------------------
    -----------------------*/
    cout << "enter a two digit number to swap: " << endl;
    cin >> refa;
    refb = refa / 10;
    refc = refa - refb * 10;
    Swap(refb, refc);
    cout << "The result is: " << (refb * 10 + refc) << endl;

    return 0;
}