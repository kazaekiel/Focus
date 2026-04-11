#include "PomodoroTimer.h"
#include "utils/casters.h"
#include <iostream>

namespace pomodoro_timer{

PomodoroTimer::PomodoroTimer(unsigned int ft, unsigned int sbt, unsigned int lbt, unsigned int nc):
    routine_(std::vector<Session>()),
    remaining_time_(ft*60),
    current_routine_index_(0),
    nbr_of_cycle_(nc)
{

    createRoutine(ft, sbt, lbt, nc);

}

PomodoroTimer::~PomodoroTimer(){}


void PomodoroTimer::tick(){
    remaining_time_--;
    std::cout << "> Remaining time: " << remaining_time_ << std::endl;
    if(remaining_time_ <= 0){
        routine_.at(current_routine_index_).running_status =  Running_Status::Finished;
        current_routine_index_++;
        remaining_time_ = routine_.at(current_routine_index_).initial_time*60;
        if(current_routine_index_>=routine_.size()){
            std::cerr << "ERROR: new index > routine vector size." << std::endl;
            std::cout << "TODO: ici, on est logiquement à la fin de la session de travail => gérer ce cas" << std::endl;
            return;
        }
    }
}

void PomodoroTimer::start(){
    if(routine_.at(current_routine_index_).running_status == Running_Status::Running){
        std::cerr << "ERROR: Timer is already running" << std::endl;
        return;
    }
    routine_.at(current_routine_index_).running_status = Running_Status::Running;

}
void PomodoroTimer::pause(){
    if(routine_.at(current_routine_index_).running_status == Running_Status::Paused){
        return;
    }

    routine_.at(current_routine_index_).running_status = Running_Status::Paused;
}
void PomodoroTimer::reset(){
    std::cout << "Reset timer" << std::endl;
    for(auto& session : routine_){
        session.running_status = Running_Status::Idle;
    }
    current_routine_index_ = 0;
    remaining_time_ = routine_.at(current_routine_index_).initial_time*60;
}

void PomodoroTimer::skip(){

    std::cout << "Skip timer" << std::endl;
    current_routine_index_++;
    remaining_time_ = routine_.at(current_routine_index_).initial_time*60;
}

void PomodoroTimer::updateTimer(unsigned int ft, unsigned int sbt, unsigned int lbt, unsigned int nc){
    clearTimer();

    remaining_time_ = ft*60;
    current_routine_index_=0;
    nbr_of_cycle_ = nc;

    createRoutine(ft, sbt, lbt, nc);

}

void PomodoroTimer::createRoutine(unsigned int ft, unsigned int sbt, unsigned int lbt, unsigned int nc){
    Session session;
    for(int i = 0; i < nbr_of_cycle_ - 1; i++){
        session.running_status = Running_Status::Idle;
        /*if(i%2==0){
            session.initial_time = ft;
            session.type = Type::Focus;
        }else{
            session.initial_time = sbt;
            session.type = Type::Short_Break;
        } */
        session.initial_time = ft;
        session.type = Type::Focus;
        routine_.push_back(session);

        session.initial_time = sbt;
        session.type = Type::Short_Break;
        routine_.push_back(session);
    }

    session.initial_time = ft;
    session.type = Type::Focus;
    routine_.push_back(session);

    session.initial_time = lbt;
    session.type = Type::Long_Break;
    routine_.push_back(session);
}

void PomodoroTimer::clearTimer(){
    if(routine_.empty()){
        std::cout << "WARNING: try to clear routine vector but is empty." << std::endl;
        return;
    }
    routine_.clear();
    remaining_time_ = 0;
    current_routine_index_ = 0;
    nbr_of_cycle_ = 0;

}

const std::vector<Session>& PomodoroTimer::getRoutine() const{
    return routine_;
}

Session PomodoroTimer::getSession(int index)const {
    return routine_.at(index);
}

int PomodoroTimer::get_remaining_time()const {
    return remaining_time_;
}

int PomodoroTimer::get_current_routine_index() const{
    return current_routine_index_;
}

int PomodoroTimer::get_nbr_of_cycle()const{
    return nbr_of_cycle_;
}

void PomodoroTimer::set_remaining_time(int t){
    remaining_time_ = t;
}

void PomodoroTimer::set_current_routine_index(int i){
    current_routine_index_ = i;
}


void PomodoroTimer::set_running_status(Running_Status rs){
    routine_.at(current_routine_index_).running_status = rs;
}

void PomodoroTimer::set_nbr_of_cycle(int nc){
    nbr_of_cycle_ = nc;
}

void PomodoroTimer::displayRoutine()const{
    if(routine_.empty()){
        std::cout << "WARNING: Routine is empty. No working session." << std::endl;
        return;
    }

    int index = 0;
    for(const auto& session : routine_){
        std::cout << "> Session index:" << index++ << std::endl;
        std::cout << "> Initial time: " << session.initial_time << std::endl;
        std::cout << "> Type: " << utils::Casters::enumToString(session.type) << std::endl;
        std::cout << "> Running status: " << utils::Casters::enumToString(session.running_status) << std::endl;
        std::cout << "-------------------------------------" << std::endl;
    }
}


}//end of namespace pomodoro_timer