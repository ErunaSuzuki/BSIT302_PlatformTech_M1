#include <iostream>      
#include <thread>     
#include <atomic>  

using namespace std;

atomic<bool> lotto1(false);
atomic<bool> lotto2(false);
atomic<bool> lotto3(false);

atomic<int> counter1 (0);
atomic<int> counter2 (0);
atomic<int> counter3 (0);

void lotto_1(int id) {
  while (!lotto1) {           
    this_thread::yield();
  }
for (volatile int i=1; i<55; ++i) {
++counter1;
if(counter1 <= 6) {
    cout << id;
}
}
}
void lotto_2(int id) {
  while (!lotto2) {           
    this_thread::yield();
  }
for (volatile int i=1; i<55; ++i) {
++counter2;
if(counter2 <= 6) {
    cout << id;
}
}
}
void lotto_3(int id) {
  while (!lotto3) {           
    this_thread::yield();
  }
for (volatile int i=1; i<55; ++i) {
++counter3;
if(counter3 <= 6) {
    cout << id;
}
}
}
int main ()
{
int i = 1;
  thread threads1[55];
  thread threads2[55];
  thread threads3[55];
  cout << "Lotto Winners!\n";
  
  for (int i=1; i<7; ++i) threads1[i]=std::thread(lotto_1,i);
  cout << "\n1st Prize Lottery: ";
  lotto1 = true; 
  this_thread::sleep_for(chrono::seconds(1));
  threads1[i].join();
  
  for (int i=1; i<7; ++i) threads2[i]=std::thread(lotto_2,i);
  cout << "\n2nd Prize Lottery: ";
  lotto2 = true; 
  this_thread::sleep_for(chrono::seconds(2));
  threads2[i].join();
  
  for (int i=1; i<7; ++i) threads3[i]=std::thread(lotto_3,i);
  cout << "\n3rd Prize Lottery: ";
  lotto3 = true; 
  this_thread::sleep_for(chrono::seconds(3));
  threads3[i].join();
  return 0;
 
}
