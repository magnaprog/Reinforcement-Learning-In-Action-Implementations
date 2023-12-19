classdef Bandit
    properties
        k
        epsilon
        q_true
        q_estimated
        action_count
    end
    
    methods
        function obj = Bandit(k_arms, epsilon)
            obj.k = k_arms;
            obj.epsilon = epsilon;
            obj.q_true = randn(1, k_arms);
            obj.q_estimated = zeros(1, k_arms);
            obj.action_count = zeros(1, k_arms);
        end
        
        function action = act(obj)
            if rand() < obj.epsilon
                action = randi(obj.k);
            else
                [~, action] = max(obj.q_estimated);
            end
        end
        
        function reward = step(obj, action)
            reward = randn() + obj.q_true(action);
            obj.action_count(action) = obj.action_count(action) + 1;
            obj.q_estimated(action) = obj.q_estimated(action) + ...
                (reward - obj.q_estimated(action)) / obj.action_count(action);
        end
    end
end

% Example usage
bandit = Bandit(10, 0.1);
for i = 1:1000
    action = bandit.act();
    reward = bandit.step(action);
end
