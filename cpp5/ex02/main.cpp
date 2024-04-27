#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    {
        try {
        Bureaucrat rte("A", 25);
        Bureaucrat kk("B", 1);
        AForm* a = new RobotomyRequestForm("robot");
        PresidentialPardonForm b("RTE");

        rte.signAForm(*a);
        rte.signAForm(b);
        rte.executeForm(*a);
        rte.executeForm(b);
        kk.executeForm(b);

        delete a;
        }
        catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    {
        std::cout <<"----------------------------"<< std::endl;
        Bureaucrat a("\033[0;35mTow Mater\033[m");
        ShrubberyCreationForm scf("shrub");
        a.executeForm(scf);
        a.signAForm(scf);
        for (size_t i = 0; i < 10; ++i) {
            a.increaseGrade();
        }
        a.signAForm(scf);
        a.executeForm(scf);
        for (size_t i = 0; i < 10; ++i) {
            a.increaseGrade();
        }
        a.executeForm(scf);
    }
    return (0);
}
