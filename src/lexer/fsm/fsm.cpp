#include "lexer/fsm/fsm.hpp"

FSM::FSM(std::set<int> states, int startState, std::set<int> endStates, std::function<int(int, char)> transition) : states(states), startState(startState), endStates(endStates), transition(transition) {}

std::tuple<bool, std::string> FSM::run(std::string input) {
    std::string buffer;
    int state = startState;

    for (int i = 0; i < input.size(); i++) {
        char symbol = input.at(i);
        int nextState = transition(state, symbol);
        if (nextState == INVALID_FSM_STATE) {
            break;
        }

        buffer += symbol;
        state = nextState;
    }
    return std::make_tuple(endStates.find(state) != endStates.end(), buffer);
}
