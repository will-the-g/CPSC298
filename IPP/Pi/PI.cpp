#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cout << "Enter in a non-negative upper limit of summation for the Leibnitz formular for computing pi:" << endl;
    cin >> n;
    double pi = 0.0;
    for (int k = 0; k <= n; k++){
        pi += pow(-1.0, k) / (2.0 * k + 1.0); 
    }
    pi *= 4;
    cout << "PI (approx): " << pi << "; n: " << setw(7) << n << endl;
    cout << "PI (actual): "<< "3.141592653589793" << endl;
    cout << "Decimal digits of precision: " << DBL_DIG << endl;
    cout << "Number of base 2 mantissa digits of double precision floating point value: " << DBL_MANT_DIG << endl;
    cout << "Next representable number from 3.141592653589793: " << nextafter(3.141592653589793, 3.14) << endl;




    return 0;
}