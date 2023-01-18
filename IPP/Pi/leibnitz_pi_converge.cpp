#include <iostream>
#include <cmath>
#include <iomanip>
#include <cfloat>
using namespace std;
int main(){
    int n;
    double pi = 0.0;
    for (n = 2; n <= 1048576; n *= 2){
        for (int k = 0; k <= n; k++){
            pi += pow(-1.0, k) / (2.0 * k + 1.0); 
        }
        pi = pi * 4;
        cout << fixed << setprecision(DBL_DIG);
        cout << "PI: " << pi << "; n: " << setw(7) << n << endl;
        pi = 0.0;
    }
}