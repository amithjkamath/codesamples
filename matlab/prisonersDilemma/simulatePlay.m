%% Test script to simulate play with opponent.
% Author: Amith Kamath
% Date: 3/5/2013.

numberOfGames = 1000;

hist.you = [];
hist.them = [];

points.you = zeros(numberOfGames);
points.them = zeros(numberOfGames);
for i = 1:numberOfGames
    decisionOpp = chaos(hist);
    hist.them = [hist.them decisionOpp];
    decisionMe = amith(hist);
    hist.you = [hist.you decisionMe];
    [points.you(i), points.them(i)] = score(decisionMe, decisionOpp); 
end

myPoints = sum(points.you,2);
OppPoints = sum(points.them,2);

if(myPoints > OppPoints)
    disp('You Won!');
else
    disp('You Lost!');
end
