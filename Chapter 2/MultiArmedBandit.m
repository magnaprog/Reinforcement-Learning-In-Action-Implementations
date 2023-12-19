classdef MultiArmedBandit
    properties
        n_arms
        arm_values
    end
    
    methods
        function obj = MultiArmedBandit(n_arms)
            obj.n_arms = n_arms;
            obj.arm_values = normrnd(0, 1, [1, n_arms]);
        end
        
        function reward = pull(obj, arm)
            reward = normrnd(obj.arm_values(arm), 1);
        end
    end
end

% Example usage
bandit = MultiArmedBandit(10);
reward = bandit.pull(3);
disp(['Reward received: ', num2str(reward)]);