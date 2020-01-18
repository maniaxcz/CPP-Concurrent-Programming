#include <iostream>
#include <thread>
using std::cout;
using std::string;

void message(string str, int i)
{
    if(i>0)
    {
        cout<<"\n"<<str;
        message(str,--i);
    }
}

int main()
{
    std::thread t1(message,"Manan",4);
    t1.join();

    return 0;
}
