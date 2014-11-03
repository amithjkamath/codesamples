%Author: Amith Kamath
%Date: 3/6/2013.
%% Driver script for interactive level line movement demo.

%Make sure all other figures are closed. Clear all variables as well.
clear all
close all
clc

%Setup x-y data.
x =0:0.01:10;
y = sin(2*pi*0.5*x);

%Get handle for plot created and store in h.
h = createDCPlot(x,y,0.5); %Start the level line at 0.5.
%Setup the button down function for level line to be clickingDCPlot.
set(h.lev,'ButtonDownFcn', {@clickingDCPlot, h, y});