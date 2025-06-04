#include <iostream>

#include "ConfigurationManager.h"

int main() {
    ConfigurationManager& config1 = ConfigurationManager::getInstance();
    
    cout << "App Name: " << config1.getAppName() << endl;
    cout << "Version: " << config1.getVersion() << endl;
    cout << "Debug Mode: " << (config1.isDebugMode() ? "ON" : "OFF") << endl;

    cout << endl << "Turning debug mode ON..." << endl;
    config1.setDebugMode(true);

    ConfigurationManager& config2 = ConfigurationManager::getInstance();
    cout << "Debug Mode: " << (config2.isDebugMode() ? "ON" : "OFF") << endl;

    // Confirming singleton behavior
    if (&config1 == &config2) {
        cout << endl <<"Both config1 and config2 point to the same instance" << endl;
    }

    return 0;
}

