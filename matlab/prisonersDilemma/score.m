function [pointsYou, pointsThem] = score(decisionMe, decisionOpp)
%% Inputs: your decision and opponents decision.
% Author: Amith Kamath
% Date: 3/5/2013.
    if((decisionMe == 1) && (decisionOpp == 1))
        pointsYou = 3;
        pointsThem = 3;
    elseif((decisionMe == 0) && (decisionOpp == 1))
        pointsYou = 4;
        pointsThem = 1;
    elseif((decisionMe == 1) && (decisionOpp == 0))
        pointsYou = 1;
        pointsThem = 4;
    elseif((decisionMe == 0) && (decisionOpp == 0))
        pointsYou = 2;
        pointsThem = 2;
    end
end