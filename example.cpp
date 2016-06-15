#include <iostream>
#include "observer.h"

class Business
{
public:
    Business(Subject<int>& subjectHola, Subject<int>& subjectChau)
    {
        subjectHola.AddObserver(std::bind(&Business::OnChangeSubjectHola, this, "Hola", std::placeholders::_1));
        subjectChau.AddObserver(std::bind(&Business::OnChangeSubjectChau, this, "Chau", std::placeholders::_1));
    }
private:
    void OnChangeSubjectHola(const char* subjectName, int state)
    {
        std::cout << "Subject changed " << subjectName << state << std::endl;
    }
    
    void OnChangeSubjectChau(const char* subjectName, int state)
    {
        std::cout << "Subject changed " << subjectName << state << std::endl;
    }
};

int main()
{
    Subject<int> subjectHola;
    Subject<int> subjectChau;
    
    Business b(subjectHola, subjectChau);
    
    subjectHola.SetState(45);
    subjectChau.SetState(123);

    return 0;
}
