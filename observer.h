#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

//forward declaration
template<class Type>
class Subject;

template<class Type>
class Observer 
{
private:
	Type state;
	unsigned int id;
	Subject<Type>* subject;

public:
	void (*Delegate)();

	void SetSubject(Subject<Type>* sbj) {
		subject = sbj;
	}

	void SetId(const unsigned int idParam) {
		id = idParam;
	}

	unsigned int GetId() {
		return id;
	}

	void Update() {
		state = subject->GetState();
		if (Delegate != NULL) {
			Delegate();
		}
	}

	bool operator==(const Observer* rvalue) {
		if (this->id == rvalue->GetId()) {
			return true;	
		} else {
			return false;
		}
	}

	Type GetState() {
		return state;
	}

	Observer() : Delegate(NULL) {}
};

template<class Type>
class Subject
{
private:
	Type state;
	std::vector<Observer<Type>*> observers;

public:
	void AddObserver(Observer<Type>* obs) {
		observers.push_back(obs);
		obs->SetSubject(this);
		obs->SetId(observers.size());
	}

	void RemoveObserver(Observer<Type>* obs) {
		int iter = 0;
		for(auto observer : observers) {
			if (observer == obs) {
				observers.erase(observers.begin()+iter);
				break;
			}
			iter++;
		}
	}
  
	void Notify() {
		for(auto observer : observers) {
			observer->Update();
		}
	}

	Type GetState() {
		return state;
	}
	
	void SetState(const Type stateParam) {
		state = stateParam;
		Notify();
	}
};

#endif