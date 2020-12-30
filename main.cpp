//
//  main.cpp
//  officeHrs
//
// Students arrive at the professor's office one at a time
// served one at a time in the order of arrival.
// Use the STL <queue> class
//
//  Created by Emma Hermanson on 11/17/20.
//

#include <iostream>
#include <queue>
#include <stdlib.h>
#include <time.h>

using namespace std;

void arrivalRate(int& aTime, queue<int>& student, int& size);
void serviceRate(int& sTime, queue<int>& student, int& size);
void student(queue<int>& position, queue<int>& student, int size);

int main(int argc, const char * argv[]) {
    int aTime = 0;
    int sTime = 0;
    double avg1, avg2, avg3;
    queue<int> student, position;
    int size;
    
    arrivalRate(aTime, position, size);
    serviceRate(sTime, student, size);
    
    size = position.size();
    while (!student.empty()) {
        if (position.front() == 60) {
            //nobody showed up
            avg3 += position.front();
            position.pop();
            student.pop();
        }
        else {
            cout << "student arrived at : " << position.front() << ". spent " << student.front() << " minutes in office hours." << endl;
        }
        avg1 += position.front();
        avg2 += student.front();
        
        position.pop();
        student.pop();
    }
        
    avg1 /= size;
    avg2 /= size;
    avg3 /= size;
    
    cout << "\n";
    cout << "average wait time : " << avg1 << endl;
    cout << "average visit time : " << avg2 << endl;
    cout << "average times nobody visited office hours : " << avg3 << endl;
    cout << "average overtime : " << avg2/100 << endl;
    
    
    return 0;
}


//function to generate arrival rate (random num)
// The Professor plans to not be in his office for more than 1 hour but if there are students still waiting then he will continue the office hour until no more students are waiting.
// 1 hour = 1 minute in program
// The arrival rate is a random number
// no new arrivals occur after 1 hour (1 minute) has passed.
void arrivalRate(int& aTime, queue<int>& student, int&size) {
    srand (time(NULL));
    
    aTime = rand() % 60 + 1;
    int curr = aTime;
    
    for (int i = 0; i < 100; i++) {
        aTime = rand() * 60 + 1;
        curr = aTime;
        student.push(aTime);
    }
    
    size = student.size();
}

// The service rate is a random number within minutes (seconds in your program). You can assume this number is the data value in each student (queue item) which pauses the professor from popping the next student from the queue for that duration.
void serviceRate(int& sTime, queue<int>& student, int& size) {
    srand(time(NULL));
    
    size = size - 1;
    sTime = rand() * 20 + 1;
    
    for (int i = 0; i < size - 1; i++) {
        sTime = rand() * 20 + 1;
        if (student.size() < size) {
            student.push(sTime);
        }
    }
}
