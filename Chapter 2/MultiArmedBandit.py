import numpy as np

class MultiArmedBandit:
    def __init__(self, n_arms):
        self.n_arms = n_arms
        self.arm_values = np.random.normal(0, 1, self.n_arms)

    def pull(self, arm):
        reward = np.random.normal(self.arm_values[arm], 1)
        return reward

# Example usage
bandit = MultiArmedBandit(10)
reward = bandit.pull(3)
print(f"Reward received: {reward}")