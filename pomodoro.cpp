#include "timer.h"
#include <iostream>

using namespace std;

// Функція runPomodoro(), яка запускає класичну сесію таймера Pomodoro:
// 4 робочих цикли по 25 хвилин, між якими йдуть короткі перерви по 5 хвилин.
// Після 4-го робочого циклу запускається довга перерва на 15 хвилин.
// Для відліку часу функція використовує існуючу функцію startTimer(seconds).
void runPomodoro() {
    const int workDuration = 25 * 60; // 25 хвилин
    const int shortBreak = 5 * 60;     // 5 хвилин
    const int longBreak = 15 * 60;     // 15 хвилин

    for (int i = 1; i <= 4; ++i) {
        cout << "Робочий цикл " << i << ": Починаємо роботу!" << endl;
        startTimer(workDuration);

        if (i < 4) {
            cout << "Коротка перерва: Відпочиньте!" << endl;
            startTimer(shortBreak);
        } else {
            cout << "Довга перерва: Відпочиньте довше!" << endl;
            startTimer(longBreak);
        }
    }

    cout << "Сесія Pomodoro завершена! Час відпочити!" << endl;
}
