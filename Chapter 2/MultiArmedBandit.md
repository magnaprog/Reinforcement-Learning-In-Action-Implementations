# Multi-Armed Bandit Algorithm

This document outlines the flow and structure of the Multi-Armed Bandit algorithm, as implemented in the `MultiArmedBandit` class.

## Flowchart Description

The flowchart for the Multi-Armed Bandit algorithm is as follows:

1. **Start**
   - Initiation of the algorithm.

2. **Initialize Bandit**
   - Initialize the bandit with a specified number of arms.
   - Initialize the true value (q_true) for each arm, typically with a normal distribution.
   - Initialize the estimated value (q_estimated) for each arm to zero.
   - Initialize the count of actions taken for each arm to zero.

3. **For Each Iteration**
   - Loop over each iteration or trial.

4. **Select Action**
   - Based on a strategy (e.g., ε-greedy), select an action. This might involve:
     - Generating a random number.
     - If the number is below a threshold (like ε), select a random arm (explore).
     - Otherwise, select the arm with the highest estimated value (exploit).

5. **Pull Selected Arm**
   - Simulate the action of pulling the selected arm.
   - Obtain a reward, typically based on a normal distribution centered around the true value of the selected arm.

6. **Update Estimates**
   - Update the estimated value of the selected arm based on the received reward.
   - Increment the action count for the selected arm.

7. **Repeat or Terminate**
   - Check if the desired number of iterations is reached.
   - If not, repeat the process for the next iteration.
   - If yes, terminate the algorithm.

8. **End**
   - Conclusion of the algorithm.

## Algorithm Implementation

The `MultiArmedBandit` class encapsulates the implementation of the Multi-Armed Bandit algorithm. It includes methods for initializing the bandit, selecting an action based on a specified strategy, pulling an arm to receive a reward, and updating the estimates of each arm's value. The class is designed to simulate the decision-making process in a multi-armed bandit scenario, focusing on the balance between exploration and exploitation.
