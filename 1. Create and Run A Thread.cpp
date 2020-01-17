#include <iostream>
#include <thread>
using std::cout;

void greetThread()
{
    cout<<"\nWelcome To C++ Concurrent Programming";
}
int main()
{
    std::thread t(greetThread);
    t.join();
    cout << "\nHello world!";
    return 0;
}
