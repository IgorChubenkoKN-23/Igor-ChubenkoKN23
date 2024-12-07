#include <iostream>
#include "Time.h"
using namespace std;

int main() {
    
    Time time1(12, 30, 45);
    Time time2(5, 15, 30);

 
    Time time3 = time1 + time2; 
    Time time4 = time1 - time2;  

    cout << "time1: " << time1 << endl;
    cout << "time2: " << time2 << endl;
    cout << "time3 (time1 + time2): " << time3 << endl;
    cout << "time4 (time1 - time2): " << time4 << endl;

   
    Time time5 = time1++;
    Time time6 = time2--;

    cout << "time1 after increment: " << time1 << endl;
    cout << "time5 (old time1): " << time5 << endl;
    cout << "time2 after decrement: " << time2 << endl;
    cout << "time6 (old time2): " << time6 << endl;

   
    cout << "time1 == time2: " << (time1 == time2 ? "True" : "False") << endl;
    cout << "time1 != time2: " << (time1 != time2 ? "True" : "False") << endl;

    return 0;
}