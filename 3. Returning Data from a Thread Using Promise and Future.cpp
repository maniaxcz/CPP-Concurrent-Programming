#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <future>

void fun(std::promise<std::string> && pr)
{
    std::cout<<"\nWorker Thread Sending";
    pr.set_value("\nMessage From Thread");
}


int main()
{
    std::promise<std::string> pr;
    std::future<std::string> fut = pr.get_future();

    std::thread th(fun,std::move(pr));
    std::cout<<"\nMain Receiving....";
    std::string str = fut.get();
    std::cout<<str;
    th.join();
    return 0;
}
