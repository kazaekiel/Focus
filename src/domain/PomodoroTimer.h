#pragma once

#include <string>
#include <vector>

namespace pomodoro_timer {

enum class Type {
    Focus, Short_Break, Long_Break
};

enum class Running_Status {
    Idle, Running, Paused, Finished
};

struct Session{
    unsigned int initial_time;
    Type type;
    Running_Status running_status;
};

class PomodoroTimer {
    //METHODES
public:
    PomodoroTimer(unsigned int ft, unsigned int sbt, unsigned int lbt, unsigned int nc);
    ~PomodoroTimer();

    void tick();
    void start();
    void pause();
    void reset();
    void skip();

    const  std::vector<Session>& getRoutine() const;
    Session getSession(int routine_index)const;
    int get_remaining_time()const;
    int get_current_routine_index()const;
    int get_nbr_of_cycle()const;

    void set_remaining_time(int t);
    void set_current_routine_index(int i);
    void set_running_status(Running_Status rs);
    void set_nbr_of_cycle(int nc);

    void displayRoutine()const;
private:
    //ATTRIBUTS
    std::vector<Session> routine_;
    int remaining_time_;
    // Running_Status runing_status_;
    int current_routine_index_;
    int nbr_of_cycle_;
};


std::string enumToString(Type type);

std::string enumToString(Running_Status running_status);

}//end of namespace pomodoro_timer


