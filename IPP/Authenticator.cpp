#include <iostream>
using namespace std;
int main(){
    string Authentication_code;
    const char k_cAuthenticatorCodeCharacter1 = 'E'; 
    const char k_cAuthenticatorCodeCharacter2 = 'C'; 
    const char k_cAuthenticatorCodeCharacter3 = 'A'; 
    Authentication_code += k_cAuthenticatorCodeCharacter1;
    Authentication_code += k_cAuthenticatorCodeCharacter2;
    Authentication_code += k_cAuthenticatorCodeCharacter3;
    char char1;
    char char2;
    char char3;
    string inputcode;
    cout << "Enter the first character of the message code" << endl;
    cin >> char1;
    inputcode += char1;
    cout << "Enter the second character of the message code" << endl;
    cin >> char2;
    inputcode += char2;
    cout << "Enter the third character of the mssage code" << endl;
    cin >> char3;
    inputcode += char3;
    cout << "Authenticator Code: " << Authentication_code << endl;
    cout << "Message Code: " << inputcode << endl;
    if (Authentication_code == inputcode){
        cout << "Concurrence: message is authentic" << endl;
    }
    else
    {
        cout << "Concurrence: message is invalid" << endl;
    }
    cout << "Characterization of Message Code" << endl;
    cout << "--------------------------------------" << endl;
    cout << "ASCII values of Message Code Characters: " << int(char1) << ", " << int(char2) << ", " << int(char3) << endl;
    int ASCIIsum;
    ASCIIsum = int(char1) + int(char2) + int(char3);
    cout << "Sum of ASCII values for Message Code Characters: " << ASCIIsum << endl;
    const int k_iValidCodeChecksum = 5;
    int checksum;
    checksum = (int(char1) + int(char2) + int(char3)) % 7;
    if (checksum == k_iValidCodeChecksum){
        cout << "Message Code Checksum is valid: 5" << endl;
    }
    else
    {
        cout << "Message Code Checksum is invalid: " << checksum << "; Expected: 5" << endl;
        if (char1 != k_cAuthenticatorCodeCharacter1){
            cout << "First characters do not match: Message: " << char1 << "; Authenticator: E" << endl;
        }
        if (char2 != k_cAuthenticatorCodeCharacter2){
            cout << "Second characters do not match: Message: " << char2 << "; Authenticator: C" << endl;
        }
        if (char3 != k_cAuthenticatorCodeCharacter3){
            cout << "Third characters do not match: Message: " << char3 << "; Authenticator: A" << endl;
        }
        for (int i = 0; i < inputcode.length(); i++){
            if (inputcode.at(i) < Authentication_code.at(i)){
                cout << "Message code (" << inputcode << ") is lexicographically less than Authenticator code (" << Authentication_code << ")" << endl;
                break;
            } else if (inputcode.at(i) > Authentication_code.at(i)){
                cout << "Message code (" << inputcode << ") is lexicographically more than Authenticator code (" << Authentication_code << ")" << endl;
                break;
            }
        }
    }  
    return 0;
}