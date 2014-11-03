%Author: Amith Kamath
%Date: 3/6/2013.
function updateDCPlot(h,level,y)
%% Inputs: handle created by createDCPlot, scalar horizontal level and ydata.
len = size(y,2);
set(h.lev,'ydata',level.*ones(1,len));
hi = y;
hi(y < level) = nan;
set(h.hi,'ydata',hi);
lo = y;
lo(y > level) = nan;
set(h.lo,'ydata',lo);
end