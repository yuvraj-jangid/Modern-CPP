#include <iostream>

// we should use enum class not only enum

// enum Rank{
enum class Rank{
    FIRST;
    SECOND;
    THIRD;
};

enum class Gear{
    FIRST;
    SECOND;
    THIRD;

};

enum class Position{
    FIRST;
    SECOND;
    THIRD;
};

int main(){
    // we cannnot force the user to use the enum name as prefix
    // enum Rank r1 = FIRST; // that's why this is wrong because it dont of which FIRST we are talking
    enum Rank r1 = Rank::FIRST;
    enum Gear g1 = Gear::FIRST;
}

