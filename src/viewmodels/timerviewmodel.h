#pragma once

#include "domain/PomodoroTimer.h"
#include <QTimer>

namespace pomodoro_timer{

class TimerViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString remainingTimeText READ remainingTimeText  NOTIFY remainingTimeTextChanged FINAL)
    Q_PROPERTY(QString type READ type NOTIFY typeChanged FINAL)
    Q_PROPERTY(int routineCurrentIndex READ routineCurrentIndex NOTIFY routineCurrentIndexChanged FINAL)
    Q_PROPERTY(int routineSize READ routineSize WRITE setRoutineSize NOTIFY routineSizeChanged FINAL)
    Q_PROPERTY(int nbrOfCycle READ nbrOfCycle WRITE setNbrOfCycle NOTIFY nbrOfCycleChanged FINAL)
    Q_PROPERTY(QString timerStatus READ timerStatus NOTIFY timerStatusChanged FINAL)
public:
    TimerViewModel(PomodoroTimer& pt, QObject* parent = 0);
    QString remainingTimeText()const;
    QString type()const;
    int routineCurrentIndex()const;
    int routineSize()const;
    int nbrOfCycle()const;
    QString timerStatus()const;

    void setRoutineSize(int rs);
    void setNbrOfCycle(int nc);
public slots:
    void update(unsigned int ft, unsigned int sbt, unsigned int lbt, unsigned int nc);
    void tick();
    void start();
    void pause();
    void reset();
    void skip();
private:
    PomodoroTimer& pt_;
    QTimer* timer_;
signals:
    void updateTime(int new_time);
    void remainingTimeTextChanged();
    void typeChanged();
    void routineCurrentIndexChanged();
    void routineSizeChanged();
    void timerStatusChanged();
    void nbrOfCycleChanged();

};

}// end of namespace pomodoro_timer
