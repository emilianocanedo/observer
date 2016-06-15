#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <functional>

template<class StateT>
class Subject
{
public:
    typedef std::function<void (StateT)> fn_callback_t;
    
    void Notify() {
    	for(auto observer : _observers) 
			observer(_state);
	}
    
    void AddObserver(fn_callback_t observer)
    {
    	_observers.push_back(observer);
	}

	void RemoveObserver(fn_callback_t observer) {    
		for (auto it = _observers.begin(); it != _observers.end(); ++it) {
			if (*it == observer) {
				_observers.erase(it);
				break;
			}
		}
	}

	StateT GetState() {
		return _state;
	}

	void SetState(const StateT stateParam) {
		_state = stateParam;
		Notify();
	}

private:
    std::vector<fn_callback_t> _observers;
    StateT _state;
};

#endif
