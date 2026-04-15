#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <cstdlib>

using namespace std;

void startTimer(int totalSeconds) {
    int initialSeconds = totalSeconds;
    int barWidth = 30; 

    while (totalSeconds > 0) {
        int minutes = totalSeconds / 60;
        int seconds = totalSeconds % 60;

        float progress = 1.0f - (float)totalSeconds / initialSeconds;
        int pos = barWidth * progress;

        cout << "\r[";
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) cout << "#";
            else cout << "-";
        }
        
        cout << "] Залишилось: " 
             << setfill('0') << setw(2) << minutes << ":" 
             << setfill('0') << setw(2) << seconds << flush;

        this_thread::sleep_for(chrono::seconds(1));
        
        totalSeconds--;
    }
    
    cout << "\r[##############################] Час вийшов!                             \n";
    cout << '\a';
    
    system("notify-send 'TickTime' 'Час вийшов! Пора зробити перерву.'");
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