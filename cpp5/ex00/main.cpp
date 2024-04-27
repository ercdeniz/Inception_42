#include "Bureaucrat.hpp"
#include <cstdlib>

int main()
{
    try {
        Bureaucrat rte("tayyip", 1);
        std::cout << rte << std::endl;
        rte.gradeDown();
        std::cout << rte << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return(1);
    }
    try {
        Bureaucrat kk("kemal", 150);
        std::cout << kk << std::endl;
        kk.gradeDown();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return(1);
    }
    return 0;
}