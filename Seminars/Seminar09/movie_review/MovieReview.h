#pragma once

#include <iostream>

#include "my_string.h"

class MovieReview {
protected:
    my_string movie_title;
    int* ratings;
    size_t ratings_count;

public:
    MovieReview();
    MovieReview(const my_string& title, const int* ratings, size_t count);
    MovieReview(const MovieReview& other);
    MovieReview& operator=(const MovieReview& other);
    ~MovieReview();

    void print_info() const;
};

