#include <iostream>
#include <stdexcept>

class Device {
public:
    Device();
    virtual ~Device();
    void enable();
    void activate();
    
private:
    bool m_bEnabled;
};

Device::Device() : m_bEnabled(false) { } // Default Constructor
Device::~Device() { }                    // Default Destructor

void Device::enable()
{
    m_bEnabled = true;
}

void Device::activate()
{
    try{
        if (!m_bEnabled){
            throw std::runtime_error("Devie must be enabled first!");
        }
        std::cout << "Device is now activated!" << std::endl;
    } catch(std::runtime_error ex){
        std::cout << ex.what() << std::endl;
    }
    // Simulate activing the device.
    // TODO: Replace this with a try catch block    
    return;
}

int main(int argc, const char * argv[]) {
    Device device;
    device.activate();
    return 0;
}
