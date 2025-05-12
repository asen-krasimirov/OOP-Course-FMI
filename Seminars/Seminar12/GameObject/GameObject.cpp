#include <iostream>

#include "my_string.h"

using namespace std;

class Player;
class Enemy;
class Npc;

class GameObject {
public:
    virtual my_string get_name() const = 0;
    virtual void interact(GameObject* other) = 0;

    virtual void interact_with(Player* player) {}
    virtual void interact_with(Enemy* enemy) {}
    virtual void interact_with(Npc* npc) {}

    virtual ~GameObject() {}
};

class Player : public GameObject {
public:
    my_string get_name() const override { return my_string("player"); }

    void interact(GameObject* other) override {
        other->interact_with(this);
    }

    void interact_with(Player* player) override {
        cout << "Player greets another player." << endl;
    }

    void interact_with(Enemy* enemy) override {
        cout << "Player attacks the enemy!" << endl;
    }

    void interact_with(Npc* npc) override {
        cout << "Player starts a conversation with the NPC." << endl;
    }
};

class Enemy : public GameObject {
public:
    my_string get_name() const override { return my_string("enemy"); }

    void interact(GameObject* other) override {
        other->interact_with(this);
    }

    void interact_with(Player* player) override {
        cout << "Enemy lunges at the player!" << endl;
    }

    void interact_with(Enemy* enemy) override {
        cout << "Enemy growls at another enemy." << endl;
    }

    void interact_with(Npc* npc) override {
        cout << "Enemy scares the NPC." << endl;
    }
};

class Npc : public GameObject {
public:
    my_string get_name() const override { return my_string("npc"); }

    void interact(GameObject* other) override {
        other->interact_with(this);
    }

    void interact_with(Player* player) override {
        cout << "NPC offers help to the player." << endl;
    }

    void interact_with(Enemy* enemy) override {
        cout << "NPC runs away from the enemy!" << endl;
    }

    void interact_with(Npc* npc) override {
        cout << "NPC chats with another NPC." << endl;
    }
};

int main() {
    const int num_objects = 3;

    GameObject* objects[num_objects];
    objects[0] = new Player();
    objects[1] = new Enemy();
    objects[2] = new Npc();

    for (int i = 0; i < num_objects; ++i) {
        for (int j = 0; j < num_objects; ++j) {
            if (i != j) {
                cout << objects[i]->get_name().c_str() << " interacts with " << objects[j]->get_name().c_str() << ": ";
                objects[i]->interact(objects[j]);
            }
        }

        cout << "----------------------" << endl;
    }

    for (int i = 0; i < num_objects; ++i) {
        delete objects[i];
    }

    return 0;
}

