#pragma once

#include "my_string.h"

using namespace std;

class ConfigurationManager {
private:
    // Private constructor to prevent external instantiation
    ConfigurationManager() {
        app_name = "MyCoolApp";
        version = "1.0.0";
        debug_mode = false;
        cout << "Configuration loaded." << endl;
    }

    ConfigurationManager(const ConfigurationManager&) = delete;
    ConfigurationManager& operator=(const ConfigurationManager&) = delete;

    my_string app_name;
    my_string version;
    bool debug_mode;

public:
    static ConfigurationManager& getInstance() {
        static ConfigurationManager instance; // Guaranteed to be lazy-loaded and thread-safe in C++11+
        return instance;
    }

    my_string getAppName() const { return app_name; }
    my_string getVersion() const { return version; }
    bool isDebugMode() const { return debug_mode; }

    void setDebugMode(bool mode) { debug_mode = mode; }
};

