#include <iostream>
using namespace std;

class ElectronicControlUnit{
public:
    ElectronicControlUnit(){}
    ~ElectronicControlUnit(){}
    void handleCommand(char cCommand);
private:
    bool m_bActivatedHydraulicJacks; // A
    bool m_bActivatedBeltTires; // B
    bool m_bActivatedIRIllumination; // E

    void actauteHydraulicJacks(){
        if (!m_bActivatedHydraulicJacks && m_bActivatedBeltTires){
            m_bActivatedBeltTires = false;
            m_bActivatedHydraulicJacks = true;
            cout << "Hydraulic Jacks Actived" << endl;
            cout << "Belt Tires Deactivated" << endl;
        } else if (!m_bActivatedHydraulicJacks){
            m_bActivatedHydraulicJacks = true;
            cout << "Hydraulic Jacks Actived" << endl;
        } else if (m_bActivatedHydraulicJacks){
            m_bActivatedHydraulicJacks = false;
            cout << "Hydraulic Jacks Deactivated" << endl;
        }
        
    }
    void actuateBeltTires(){
        if (!m_bActivatedBeltTires){
            m_bActivatedBeltTires = true;
            cout << "Belt Tires Activated" << endl;
        } else if (m_bActivatedBeltTires){
            m_bActivatedBeltTires = false;
            cout << "Belt Tires Deactived" << endl;
        } 
    }
    void actuateIRIllumination(){
        if (!m_bActivatedIRIllumination){
            m_bActivatedIRIllumination = true;
            cout << "Infrared Illumination Activated" << endl;
        } else {
            m_bActivatedIRIllumination = false;
            cout << "Infrared Illumination Deactivated" << endl;
        }
    }
};
void ElectronicControlUnit::handleCommand(char cCommand){
    
    switch(cCommand){
    case 'A':
    case 'a':
        actauteHydraulicJacks();
        break;
    case 'B':
    case 'b':
        actuateBeltTires();
        break;
    case 'E':
    case 'e':
        actuateIRIllumination();
        break;
    }
}

int main(){
    ElectronicControlUnit test;
    char choice;
    while (choice != 'X'){
        cout << "Press X to turn off ignition or enter a steering wheel button (A, B, or E)" << endl;
        cout << "    (A)" << endl;
        cout << "(F) (G) (B)" << endl;
        cout << "(E)     (C)" << endl;
        cout << "    (D)" << endl;
        cin >> choice;
        test.handleCommand(choice);
    }
    return 0;
}
