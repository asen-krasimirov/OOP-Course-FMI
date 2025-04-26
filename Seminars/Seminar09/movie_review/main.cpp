#include "AnimationReview.h"

int main() {
    int ratings[] = {9, 10, 8};
    my_string animators[] = {"Alice", "Bob"};

    AnimationReview a1("The Flying Fox", ratings, 3, animators, 2);
    a1.print_info();

    AnimationReview a2 = a1;
    a2.print_info();

    AnimationReview a3;
    a3 = a1;
    a3.print_info();

    return 0;
}

