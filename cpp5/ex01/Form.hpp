#pragma once

#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _requiredToSign;
        const int _requiredToExecute;
    public:
        Form(void);
        ~Form(void);
        Form(std::string name);
        Form(std::string name, int requiredToSign, int requiredToExecute);
        Form(const Form& copy);
        Form &operator=(const Form& copy);
        std::string getName(void) const;
        int getToSign(void) const;
        int getToExec(void) const;
        std::string getIsSigned(void) const;
        void beSigned(Bureaucrat& b);
        class GradeTooHighException: public std::exception {
            const char* what() const throw();
        };
        class GradeTooLowException: public std::exception {
            const char* what() const throw();
        };
};
std::ostream &operator<<(std::ostream& out, Form& form);
