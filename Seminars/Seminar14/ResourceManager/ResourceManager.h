#pragma once

#include "my_vector.hpp"
#include "my_unique_ptr.hpp"

#include "Resource.h"

class ResourceManager {
    my_vector<my_unique_ptr<Resource>> resources;

public:
    void add(const my_string& name);

    void print_all() const;
};

void ResourceManager::add(const my_string& name) {
    resources.push_back(make_my_unique_ptr<Resource>(name));
}

void ResourceManager::print_all() const {
    for (size_t i = 0; i < resources.size(); ++i) {
        resources[i]->print();
    }
}

