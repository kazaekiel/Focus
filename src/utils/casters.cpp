#include "casters.h"
namespace utils{
Casters::Casters() {}



std::string Casters::enumToString(Type type){
    switch (type) {
    case Type::Focus:
        return "Focus";
        break;
    case Type::Short_Break:
        return "Short Break";
        break;
    case Type::Long_Break:
        return "Long Break";
        break;
    default:
        break;
    }
    return "error";
}

std::string Casters::enumToString(Running_Status running_status){
    switch (running_status) {
    case Running_Status::Idle:
        return "Idle";
        break;
    case Running_Status::Running:
        return "Running";
        break;
    case Running_Status::Paused:
        return "Paused";
        break;
    case Running_Status::Finished :
        return "Finished";
        break;
    default:
        break;
    }
    return "error";
}

}//end of namespace utils
