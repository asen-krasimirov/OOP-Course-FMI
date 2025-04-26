#pragma once
#include "MovieReview.h"

#include "my_string.h"

class AnimationReview : public MovieReview {
private:
    my_string* animator_names;
    size_t animator_count;

public:
    AnimationReview();
    AnimationReview(const my_string& title, const int* ratings, size_t rating_count, const mystring* animators, size_t animator_count);
    AnimationReview(const AnimationReview& other);
    AnimationReview& operator=(const AnimationReview& other);
    ~AnimationReview();

    void print_info() const;
};

