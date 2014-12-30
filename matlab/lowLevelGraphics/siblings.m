function hout = siblings(hin)
%% Inputs: A guaranteed graphics object handle (scalar), of whose the siblings of a common parent has to be found.
% Author: Amith Kamath
% Date: 3/5/2013.

parent = get(hin,'parent');
hout = get(parent,'Children');
hout(hout == hin) = [];
end