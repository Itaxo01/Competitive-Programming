#include <iostream>
#include <thread>
#include <chrono>
#include <omp.h>
using namespace std;

void showProgressBar(int& progress, int total, int &soma) {
    int barWidth = 70;

    while (progress <= total) {
        float progressRatio = static_cast<float>(progress) / total;
        int pos = barWidth * progressRatio;
		  cout<<"\033[A";
		  cout<<"\033[A";
		  cout<<endl<<"Soma: "<<soma<<endl;
        cout << "[";
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) cout << "=";
            else if (i == pos) cout << ">";
            else cout << " ";
        }
        cout << "] " << int(progressRatio * 100.0) << " %\r";
        cout.flush();

        this_thread::sleep_for(chrono::milliseconds(1));
    }
    cout << endl;
}

int main() {
    int total = 1000;
    int progress = 0;
	 int soma = 0;
    // Start the progress bar in a separate thread
    thread progressBarThread(showProgressBar, ref(progress), total, ref(soma));

    // Parallelize the main computation using OpenMP
    #pragma omp parallel for reduction(+:soma)
    for (int i = 0; i <= total; ++i) {
        soma += i;
        this_thread::sleep_for(chrono::milliseconds(1));
        #pragma omp atomic
        ++progress;
    }

    // Wait for the progress bar thread to finish
    progressBarThread.join();
	 cout<<soma<<endl;
    return 0;
}