function decision = amith(hist)
%% Inputs: Struct with history of cooperation as hist.you and hist.them to
%make a decision.
% Author: Amith Kamath
% Date: 3/5/2013.

cooperate = 1;
defect = 0;

% % The I brought friends version! muhahaha!
% n_play = length(hist.you) + 1 ;
% code = [1,0,1,1,0,0,1,1,1] ;
% n_code = length(code) ;
% 
% if ( n_play <= n_code )
%     decision = code(n_play) ;
% else
%     if ( hist.them(1:n_code) == code )
%         decision = defect ;
%     else
%         decision = defect ;
%     end
% end

% The boring version
%Setup trust levels, to cooperate or defect in reverse to 
trustHigh = 0.75;
trustLow = 0.25;
noTrust = 0.5;

if isempty(hist.them)
   decision = cooperate; %cooperate if no history.
   hist.you = [hist.you cooperate];
end

averageOpponent = mean(hist.them);
if(averageOpponent > trustHigh)
    decision = defect; %Defect if they cooperate most times.
    hist.you = [hist.you decision];
elseif ((averageOpponent <= trustHigh) && (averageOpponent > trustLow))
    %In this case, look at the nearest 50% of the history?
    newAverageOpponent = mean(hist.them(round(end/2):end));
    decision = newAverageOpponent >= noTrust; %Cooperate if they are random in this interval.
    hist.you = [hist.you decision];
elseif (averageOpponent <= trustLow)
    decision = defect; %Defect if they defect most times.
    hist.you = [hist.you decision];
end

end