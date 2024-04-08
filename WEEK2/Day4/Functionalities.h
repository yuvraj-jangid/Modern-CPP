#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <functional>
#include <vector>
#include <iostream>

using Container  = std::vector<int>;
using FnType = std::function<void(Container&)>;

void Adaptor(FnType fn, Container& data);


extern FnType lfn1;
extern FnType lfn2;
extern FnType lfn3;

#endif // FUNCTIONALITIES_H
