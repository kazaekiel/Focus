#pragma once


#include "domain/PomodoroTimer.h"
using pomodoro_timer::Type;
using pomodoro_timer::Running_Status;

namespace utils{

class Casters
{
public:
    Casters();
    static std::string enumToString(Type type);
    static std::string enumToString(Running_Status running_status);
};

}//end of namespace utils


