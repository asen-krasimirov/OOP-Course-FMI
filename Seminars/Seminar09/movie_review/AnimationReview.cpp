#include "AnimationReview.h"
#include <algorithm>

AnimationReview::AnimationReview()
    : MovieReview(), animator_names(nullptr), animator_count(0) {}

AnimationReview::AnimationReview(const std::string& title, const int* ratings, size_t rating_count,
                                 const std::string* animators, size_t count)
    : MovieReview(title, ratings, rating_count), animator_count(count) {
    animator_names = new my_string[animator_count];
    for (size_t i = 0; i < animator_count; ++i) {
        animator_names[i] = animators[i];
    }
}

AnimationReview::AnimationReview(const AnimationReview& other)
    : MovieReview(other), animator_count(other.animator_count) {
    animator_names = new my_string[animator_count];
    for (size_t i = 0; i < animator_count; ++i) {
        animator_names[i] = other.animator_names[i];
    }
}

AnimationReview& AnimationReview::operator=(const AnimationReview& other) {
    if (this != &other) {
        MovieReview::operator=(other);

        delete[] animator_names;

        animator_count = other.animator_count;
        animator_names = new my_string[animator_count];
        for (size_t i = 0; i < animator_count; ++i) {
            animator_names[i] = other.animator_names[i];
        }
    }
    return *this;
}

AnimationReview::~AnimationReview() {
    delete[] animator_names;
}

void AnimationReview::print_info() const {
    MovieReview::print_info();
    std::cout << "Animators: ";
    for (size_t i = 0; i < animator_count; ++i) {
        std::cout << animator_names[i] << " ";
    }
    std::cout << "\n";
}

