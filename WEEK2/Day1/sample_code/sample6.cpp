#include <iostream>
#include <functional>

void Magic(int& ref) {

}

int main() {
    int data {10};
    std::reference_wrapper<int> refWrap {data};
    Magic(refWrap);
    std::reference_wrapper<int> arr[] {refWrap};
}
