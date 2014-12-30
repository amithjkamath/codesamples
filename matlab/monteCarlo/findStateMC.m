% Author: Amith Kamath
% Date: 3/5/2013.
function finalState = findStateMC(seeds, steps)
%% Inputs: Number of workers, and number of steps to run the simulation.

% initial location is all ones.
initLoc = ones(1,seeds);
for i = 1:steps
   newLoc = moveBlocks(initLoc,2,4);
   initLoc = newLoc; %this is the new 'current' state. 
   hist(initLoc,[1 2 3 4]);
   pause;
end
finalState = hist(initLoc,[1 2 3 4])/seeds;
%fprintf('Final state is : %d', finalState);
%fprintf('\n');
end
% Author: Amith Kamath
% Date: 3/5/2013.
function newLoc = moveBlocks(currLoc, numCoins, boardSize)
%% Inputs: Current location of the blocks, number of coins and board size.

%Preallocate.
newLoc = zeros(size(currLoc));

for i = 1:numel(currLoc)
   result = flipCoins(numCoins);
   if(sum(result) == 0) % if both are 0, then go to jail.
       newLoc(i) = 1; 
   else % use thhe logic below to find out which state to go to. This is per seed.
       newLoc(i) = mod((currLoc(i) + sum(result) - 1),boardSize)+1;
   end
end
end

% Author: Amith Kamath
% Date: 3/5/2013.
function result = flipCoins(numOfCoins)
%% Inputs: number of coins to flip.
% Outputs either 1 or 0 with a near uniform distribution.
result = round(rand(1,numOfCoins));
end