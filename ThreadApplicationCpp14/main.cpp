#include <iostream>
#include <thread>

//using namespace std;

static bool s_Finished = false;

void DoWork() {

    using namespace std::literals::chrono_literals;

    std::cout << "Starting thread id=" << std::this_thread::get_id() << std::endl;

    while(!s_Finished) {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(1s);
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
