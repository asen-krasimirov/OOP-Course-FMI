#include "Probe.h"
#include <iostream>

int main() {
    try {
        // This will throw due to name not ending in "AA"
        // Probe invalid_probe("Probe01");
        // Valid probe
        Probe p("ExplorerAA");

        // Create and add packages
        p.add_package(new MineralPackage("Gold", 10));      // serial #1
        p.add_package(new MineralPackage("Silver", 8));     // serial #2
        p.add_package(new LiquidPackage("Water", 1.0, 12)); // serial #3
        p.add_package(new LiquidPackage("Mercury", 13.6, 5)); // serial #4

        // Print descriptions via polymorphism
        cout << "All packages:" << endl;
        for (int i = 0; i < 4; ++i) {
            cout << "- " << p.get_package(i)->get_description() << endl;
        }

        cout << "\nSending first package:" << endl;
        p.send_package(0); // Sends Gold

        cout << "\nSending second package (originally at index 1):" << endl;
        p.send_package(0); // Now Silver is at index 0

        // Attempt to send out-of-range index (triggers exception)
        // p.send_package(10); 

        // Attempt to add invalid mineral
        // p.add_package(new MineralPackage("Unobtainium", 15));

    } catch (const exception& ex) {
        cerr << Exception: " << ex.what() << endl;
    }

    return 0;
}

