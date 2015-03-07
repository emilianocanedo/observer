#include <iostream>
#include "observer.h"

void ObserverHandler()
{
  std::cout << "I'm observer3" << std::endl;
}

int main()
{
  Observer<int> *observer1 = new Observer<int>;
  Observer<int> *observer2 = new Observer<int>;
  Observer<int> *observer3 = new Observer<int>;

  observer3->Delegate = ObserverHandler;

  Subject<int> *subject1 = new Subject<int>;

  subject1->AddObserver(observer1);
  subject1->AddObserver(observer2);
  subject1->AddObserver(observer3);

  subject1->SetState(3);

  std::cout << observer1->GetState() << " " 
            << observer2->GetState() << " " 
            << observer3->GetState() << std::endl;

  subject1->RemoveObserver(observer2);
  subject1->SetState(2);

  std::cout << observer1->GetState() << " " 
            << observer2->GetState() << " " 
            << observer3->GetState() << std::endl;

  delete observer1;
  delete observer2;
  delete observer3;
  delete subject1;

  return 0;
}
