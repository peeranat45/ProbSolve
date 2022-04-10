// #include <iostream>
// #include <chrono>
 
// int main()
// {
//     const auto p1 = std::chrono::system_clock::now();
 
//     std::cout << "seconds since epoch: "
//               << std::chrono::duration_cast<std::chrono::seconds>(
//                    p1.time_since_epoch()).count() << '\n';
// }

#include <ctime>
#include <iostream>
 
int main()
{
    std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result));
}