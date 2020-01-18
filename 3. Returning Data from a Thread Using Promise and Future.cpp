#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <future>

void fun(std::promise<std::string> && pr)                           // Taking Promise as an Argument
{
    std::cout<<"\nWorker Thread Sending";
    pr.set_value("\nMessage From Thread");
}


int main()
{
    std::promise<std::string> pr;                                   // Step 1 : Creating a Promise
    std::future<std::string> fut = pr.get_future();                 // Step 2 : Creating a Future

    std::thread th(fun,std::move(pr));                              // Step 3 : Thread Created and Promise passed using move function
    std::cout<<"\nMain Receiving....";
    std::string str = fut.get();
    std::cout<<str;
    th.join();
    return 0;
}
