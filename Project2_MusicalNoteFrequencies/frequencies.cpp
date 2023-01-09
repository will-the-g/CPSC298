#include <iostream>
#include <tgmath.h>
using namespace std;
float frequency(int v, int k){
    return 16.35 * pow(2, v) * pow(1.059463094359, k);
}

float wavelength(float frequency){
    return (345.0 / frequency) * 100.0;
}
int main (){
    cout << "Reference Frequency: 16.35 Hz"<< endl;
    cout << "Speed of Sound: 345 m/s" << endl;

    float f = frequency(0,0);
    float w = wavelength(f);
    cout << "C0; nu: 0; frequency: " <<  f << " Hz; wavelength: " << w << " cm" << endl;

    f = frequency(0,1);
    w = wavelength(f);
    cout << "C0; nu: 0; frequency: " <<  f << " Hz; wavelength: " << w << " cm" << endl;
    
    f = frequency(0,2);
    w = wavelength(f);
    cout << "C0; nu: 0; frequency: " <<  f << " Hz; wavelength: " << w << " cm" << endl;

    f = frequency(4,0);
    w = wavelength(f);
    cout << "C0; nu: 0; frequency: " <<  f << " Hz; wavelength: " << w << " cm" << endl;

    f = frequency(7,3);
    w = wavelength(f);
    cout << "C0; nu: 0; frequency: " <<  f << " Hz; wavelength: " << w << " cm" << endl;

    f = frequency(8,0);
    w = wavelength(f);
    cout << "C0; nu: 0; frequency: " <<  f << " Hz; wavelength: " << w << " cm" << endl;
    return 0;
}
