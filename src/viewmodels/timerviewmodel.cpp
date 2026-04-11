#include "timerviewmodel.h"
#include "utils/casters.h"
#include <QDebug>

namespace pomodoro_timer{

TimerViewModel::TimerViewModel(PomodoroTimer& pt, QObject* parent):
    pt_(pt){
    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &TimerViewModel::tick);
    // connect(timer_, &QTimer::timeout, this, &TimerViewModel::update);

    //timer_->start(1000);

}


QString TimerViewModel::remainingTimeText() const{
    // return pt_.get_remaining_time();
    int sec = pt_.get_remaining_time();
    int min = sec / 60;
    int s = sec % 60;

    return QString("%1:%2")
        .arg(min, 2, 10, QChar('0'))
        .arg(s, 2, 10, QChar('0'));
}

QString TimerViewModel::type()const{
    QString type;
    std::string type_str = utils::Casters::enumToString(pt_.getSession(pt_.get_current_routine_index()).type);

    return QString(type_str.c_str());
  }

int TimerViewModel::routineCurrentIndex()const{
    return pt_.get_current_routine_index();
}

int TimerViewModel::routineSize()const{
    return pt_.getRoutine().size();
}

void TimerViewModel::setRoutineSize(int rs){

}

int TimerViewModel::nbrOfCycle()const{
    return pt_.get_nbr_of_cycle();
}

void TimerViewModel::setNbrOfCycle(int nc){
    pt_.set_nbr_of_cycle(nc);
}

QString TimerViewModel::timerStatus()const{
    std::string timer_status = utils::Casters::enumToString(pt_.getSession(pt_.get_current_routine_index()).running_status);
    return QString(timer_status.c_str());
}

void TimerViewModel::tick(){
    pt_.tick();
    emit remainingTimeTextChanged();
}


void TimerViewModel::start(){
    timer_->start(1000);
    pt_.start();
    emit timerStatusChanged();
}

void TimerViewModel::pause(){
    if(!timer_){
        qFatal() << "ERROR: timer pointer is null.";
        return;
    }
    timer_->stop();
    pt_.pause();
    emit timerStatusChanged();
}

void TimerViewModel::reset(){
    timer_->stop();
    pt_.reset();

    emit remainingTimeTextChanged();
    emit timerStatusChanged();
    emit routineCurrentIndexChanged();

}
void TimerViewModel::skip(){
    timer_->stop();
    pt_.skip();

    emit remainingTimeTextChanged();
    emit timerStatusChanged();
    emit routineCurrentIndexChanged();
}

void TimerViewModel::update(unsigned int ft, unsigned int sbt, unsigned int lbt, unsigned int nc){
    pt_.updateTimer(ft, sbt, lbt, nc);

    emit remainingTimeTextChanged();
    emit timerStatusChanged();
    emit routineCurrentIndexChanged();
}

}// end of namespace pomodoro_timer
