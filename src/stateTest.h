// fsm_with_passive_data.h
#ifndef FSM_WITH_PASSIVE_DATA_H
#define FSM_WITH_PASSIVE_DATA_H

#include <string.h>
#include <limits.h>     // CHAR_MAX
#include <iostream>
const int range = CHAR_MAX + 1;

class State
{
public:
	State();
	State* transition[range];
	virtual void show_state()=0;
};

class S1 :public State
{
public:
	virtual void show_state() {
		std::cout << "state s1" << std::endl;
	}
};
class S2 :public State 
{
public:
	virtual void show_state() {
		std::cout << "state s2" << std::endl;
	}
};

class S3 :public State
{
public:
	virtual void show_state() {
		std::cout << "state s3" << std::endl;
	}
};

class S4 :public State
{
public:
	virtual void show_state() {
		std::cout << "state s4" << std::endl;
	}
};

class S5 :public State
{
public:
	virtual void show_state() {
		std::cout << "state s5" << std::endl;
	}
};
class S :public State
{
public:
	virtual void show_state() {
		std::cout << "state s" << std::endl;
	}
};

struct TransGraph   // use triple to describe map
{
	int current_state;
	char input_char;
	int next_state;
};

class Fsm
{
public:
	Fsm();
	void Reset();            // move to start state
	void Advance(char c);    // advance one transition
	int EndState();
	int DoomState();
private:
	State* p_current;   // &s1, &s2, ..., &s6; NULL ==> doom
	State* state[6];     // 6 states, state[0] is end state
};


#endif // FSM_WITH_PASSIVE_DATA_H

