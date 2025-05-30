#include <iostream>

#include "ResourceManager.h"

using namespace std;

int main() {
    {
        ResourceManager manager;
        manager.add("texture_diffuse");
        manager.add("sound_explosion");
        manager.add("model_enemy");

        cout << endl << "--- Resources ---" << endl;
        manager.print_all();
    }

    cout << endl << "--- Exiting main ---" << endl;
    return 0;
}

