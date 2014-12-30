%Author: Amith Kamath
%Date: 3/6/2013.
function draggingDCPlot(hObj,~, h, y)
%% Inputs: handle of the object to work on, and null for compatibility.
%Call this function every time mouse moves, and has a new y coordinate.
point = get(gca,'currentPoint');
%point = get(gca,'currentPoint')
%
%point =
%    x         y         z
%    0.9028    0.0085    1.0000
%    0.9028    0.0085   -1.0000
updateDCPlot(h,point(1,2),y);                                                                                                                                                                                                                                                                                                      
end