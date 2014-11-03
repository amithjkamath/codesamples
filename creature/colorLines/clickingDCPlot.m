%Author: Amith Kamath
%Date: 3/7/2013.
function clickingDCPlot(hObj,~, h, y)
%% Inputs: handle of the object to work on, and null for compatibility.
%Setup the mouse movement function tp point to draggingDCPlot.
set(gcf,'WindowButtonMotionFcn', {@draggingDCPlot, h, y});
%Setup the mouse relese function to be releasingDCPlot.
%This is in here because release happens only after clicking.
set(gcf,'WindowButtonUpFcn', {@releasingDCPlot, h, y});
end