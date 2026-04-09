#include "domain/PomodoroTimer.h"
#include "viewmodels/timerviewmodel.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Focus", "Main");
    pomodoro_timer::PomodoroTimer* pt = new pomodoro_timer::PomodoroTimer(25, 5, 15, 4);
    pt->displayRoutine();

    pomodoro_timer::TimerViewModel timer_VM(*pt);

    engine.rootContext()->setContextProperty("timerViewModel", &timer_VM);
    return QCoreApplication::exec();
}
