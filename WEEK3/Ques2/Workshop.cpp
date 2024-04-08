#include"Workshop.h"

int Workshop :: auto_token = 1;



Workshop::Workshop(std::variant<std::string, int> id, int service, WorkshopType type, int auto_token, int attendant, float eval, int current)
{
    _centre_id = id;
    _service_point_count = service;
    __type = type;
    _token_number = auto_token++;
    attendant_count = attendant;
    _evaluation_value = eval;
    _current_class = current;

}

std::ostream &operator<<(std::ostream &os, const Workshop &rhs) {
    os << "_centre_id: ";
    std::visit(
        [&](auto&& val){os << val;
        }, rhs._centre_id);
    os   << " _service_point_count: " << rhs._service_point_count
       << " __type: " << DisplayEnum(rhs.__type)
       << " attendant_count: " << rhs.attendant_count
       << " _evaluation_value: " << rhs._evaluation_value
       << " _current_class: " << rhs._current_class;
    return os;
}

std::string DisplayEnum(WorkshopType type)
{
    if(type == WorkshopType::REPAIRS){
        return "REPAIRS";
    }else if(type == WorkshopType::SERVICE){
        return "SERVICE";
    }else{
        return "BOTH";
    }
}
