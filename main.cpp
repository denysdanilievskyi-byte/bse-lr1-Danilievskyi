#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

void startTimer(int totalSeconds) {
    while (totalSeconds > 0) {
        int minutes = totalSeconds / 60;
        int seconds = totalSeconds % 60;

        cout << "\rЗалишилось часу: " 
             << setfill('0') << setw(2) << minutes << ":" 
             << setfill('0') << setw(2) << seconds << flush;

        this_thread::sleep_for(chrono::seconds(1));
        
        totalSeconds--;
    }
    
    cout << "\rЧас вийшов!                             \n";
    cout << '\a';
}

int main() {
    int inputSeconds;
    
    cout << "Введіть час для таймера (у секундах): ";
    cin >> inputSeconds;

    if (inputSeconds <= 0) {
        cout << "Будь ласка, введіть додатне число." << endl;
        return 1;
    }

    startTimer(inputSeconds);

    return 0;
}