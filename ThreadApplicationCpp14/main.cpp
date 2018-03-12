#include <iostream>
#include <thread>

using namespace std;

static bool s_Finished = false;


void DoWork() {

    while(!s_Finished) {
        std::cout << "Working..." <<std::endl;
    }
}

int main()
{
    std::thread worker(DoWork);

    std::cin.get();
    s_Finished = true;

    worker.join();

    std::cin.get();

}
