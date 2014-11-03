%% Test script for iterative prisoners dilemma.
% Author: Amith Kamath
% Date: 3/5/2013.

%%Good case.
hist.them = ones(1000);
hist.you = [];
assert(amith(hist) == 0) %Defect here.

%%Evil case.
hist.them = zeros(1000);
hist.you = [];
assert(amith(hist) == 0) %Defect here.

%%No history case.
hist.them = [];
hist.you = [];
assert(amith(hist) == 1) %Cooperate here.

%%Chaos case.
hist.them = round(rand(1000));
hist.you = [];
decision = amith(hist);