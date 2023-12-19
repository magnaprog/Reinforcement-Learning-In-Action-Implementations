#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>

class Bandit {
public:
    Bandit(int k_arms, double epsilon) : k(k_arms), epsilon(epsilon), 
        q_estimated(k_arms, 0.0), action_count(k_arms, 0) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);

        for (int i = 0; i < k_arms; ++i) {
            q_true.push_back(d(gen));
        }
    }

    int act() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 1);

        if (dis(gen) < epsilon) {
            std::uniform_int_distribution<> action_dis(0, k - 1);
            return action_dis(gen);
        } else {
            return std::distance(q_estimated.begin(), std::max_element(q_estimated.begin(), q_estimated.end()));
        }
    }

    double step(int action) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> reward_dis(q_true[action], 1);

        double reward = reward_dis(gen);
        ++action_count[action];
        q_estimated[action] += (reward - q_estimated[action]) / action_count[action];
        return reward;
    }

private:
    int k;
    double epsilon;
    std::vector<double> q_true;
    std::vector<double> q_estimated;
    std::vector<int> action_count;
};

int main() {
    Bandit bandit(10, 0.1);
    for (int i = 0; i < 1000; ++i) {
        int action = bandit.act();
        double reward = bandit.step(action);
    }
    return 0;
}
