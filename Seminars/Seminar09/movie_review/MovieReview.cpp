#include "MovieReview.h"
#include <algorithm>

MovieReview::MovieReview() : movie_title("Untitled"), ratings(nullptr), ratings_count(0) {}

MovieReview::MovieReview(const std::string& title, const int* ratings_input, size_t count)
    : movie_title(title), ratings_count(count) {
    ratings = new int[ratings_count];
    for (int i = 0; i < ratings_count; ++i) {
        ratings[i] = ratings_input[i];
    }
}

MovieReview::MovieReview(const MovieReview& other)
    : movie_title(other.movie_title), ratings_count(other.ratings_count) {
    ratings = new int[ratings_count];
    for (int i = 0; i < ratings_count; ++i) {
        ratings[i] = ratings_input[i];
    }
}

MovieReview& MovieReview::operator=(const MovieReview& other) {
    if (this != &other) {
        delete[] ratings;

        movie_title = other.movie_title;
        ratings_count = other.ratings_count;

        ratings = new int[ratings_count];
        for (int i = 0; i < ratings_count; ++i) {
            ratings[i] = ratings_input[i];
        }
    }
    
    return *this;
}

MovieReview::~MovieReview() {
    delete[] ratings;
}

void MovieReview::print_info() const {
    std::cout << "Movie: " << movie_title << "\nRatings: ";
    for (size_t i = 0; i < ratings_count; ++i) {
        std::cout << ratings[i] << " ";
    }
    std::cout << "\n";
}

