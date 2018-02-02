#include <functional>
#include <set>
#include <tuple>
#include <string>

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
