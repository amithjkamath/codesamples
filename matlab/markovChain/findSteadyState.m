% Author: Amith Kamath
% Date: 3/5/2013.
function finalState = findSteadyState(initialProbability, transitionMatrix, threshold)
%% Inputs: Initial probability, transition matrix (of the right size),
% thresholdfor convergence.

state      = initialProbability;
newState   = state*transitionMatrix;
numOfSteps = 1;
while (max(newState - state) > threshold)
    state = newState
    newState   = newState*transitionMatrix;
    numOfSteps = numOfSteps + 1;
end

finalState = newState;
disp('Number of steps taken to reach steady state is: ');
fprintf('%d\n',numOfSteps);
end