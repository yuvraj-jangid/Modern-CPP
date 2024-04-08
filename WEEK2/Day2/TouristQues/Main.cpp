#include "Functionalities.h"

int main()
{
    Container data;
    CreateObjects(data);
    Container val = PermitTypeCondition(data, 1);
    float x = AvgPerType(data, 1);

    unsigned long noice = MaxPerBookingCharge(data);

    Container lol=  FirstNinstances(data, 1);
}
