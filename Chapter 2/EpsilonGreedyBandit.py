import numpy as np

class Bandit:
    def __init__(self, k_arms, epsilon):
        self.k = k_arms
        self.epsilon = epsilon
        self.q_true = np.random.randn(k_arms)  # True values
        self.q_estimated = np.zeros(k_arms)    # Estimated values
        self.action_count = np.zeros(k_arms)   # Count of actions taken

    def act(self):
        if np.random.rand() < self.epsilon:
            return np.random.choice(self.k)  # Explore
        else:
            return np.argmax(self.q_estimated)  # Exploit

    def step(self, action):
        reward = np.random.randn() + self.q_true[action]
        self.action_count[action] += 1
        self.q_estimated[action] += (reward - self.q_estimated[action]) / self.action_count[action]
        return reward

# Example usage
bandit = Bandit(10, 0.1)
for _ in range(1000):
    action = bandit.act()
    reward = bandit.step(action)
