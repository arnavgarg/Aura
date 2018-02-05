#include <functional>
#include <set>
#include <tuple>
#include <string>

/*
 * This class simulates a finite state machine. The transition function is used to switch to the next state,
 * and it should be provided by the user upon construction. It should return INVALID_FSM_STATE when it is
 * time for the FSM to stop running. 
 */
class FSM {
public:
    static const int INVALID_FSM_STATE = -1;

    FSM(std::set<int> states, int startState, std::set<int> endStates, std::function<int(int, char)> transition);
    std::tuple<bool, std::string> run(std::string input);

private:
    std::set<int> states;
    int startState;
    std::set<int> endStates;
    std::function<int(int, char)> transition;
    std::string buffer;
};
