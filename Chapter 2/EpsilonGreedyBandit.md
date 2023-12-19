# Epsilon Greedy Bandit Algorithm

This document describes the flow and structure of the Epsilon Greedy Bandit algorithm implemented in the `EpsilonGreedyBandit` class.

## Flowchart Description

The flowchart for the Epsilon Greedy Bandit algorithm can be described as follows:

1. **Start**
   - The beginning of the algorithm.

2. **Initialize Bandit**
   - Initialize parameters: number of arms, epsilon value.
   - Set initial estimated values for each arm to zero.
   - Set the initial count of actions for each arm to zero.

3. **For Each Episode**
   - Iterate over each episode or trial.

4. **Choose Action**
   - Decision point: whether to explore or exploit.
   - Generate a random number and compare it with epsilon.

5. **Explore**
   - If the random number is less than epsilon, choose a random arm.

6. **Exploit**
   - If the random number is greater than or equal to epsilon, choose the arm with the highest estimated value.

7. **Update Estimates**
   - Pull the chosen arm and receive a reward.
   - Update the estimated value for the chosen arm.
   - Increment the action count for the chosen arm.

8. **Repeat or End**
   - Check if the episode limit is reached.
   - If not, repeat the process for the next episode.
   - If yes, end the algorithm.

9. **End**
   - The algorithm concludes.

## Algorithm Implementation

The `EpsilonGreedyBandit` class implements the above-described algorithm. It includes methods for initializing the bandit, choosing an action (arm), and updating the estimates based on the received rewards. The class is designed to balance exploration and exploitation to maximize the total reward over time.