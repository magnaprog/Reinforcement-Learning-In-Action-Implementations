#include <iostream>
#include <vector>
#include <random>

class MultiArmedBandit {
public:
    MultiArmedBandit(int n_arms) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);

        for (int i = 0; i < n_arms; ++i) {
            arm_values.push_back(d(gen));
        }
    }

    double pull(int arm) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(arm_values[arm], 1);
        return d(gen);
    }

private:
    std::vector<double> arm_values;
};

int main() {
    MultiArmedBandit bandit(10);
    double reward = bandit.pull(3);
    std::cout << "Reward received: " << reward << std::endl;
    return 0;
}