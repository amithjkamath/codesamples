function years = retireNow(startSalary,raisePct,investRatePct,growthRatePct)
%% Inputs: starting salary, raise percentage, investment percentage, growth rate.
% Author: Amith Kamath
% Date: 3/4/2013.

%Initialize parameters.
salary     = startSalary;
investment = salary*(investRatePct*0.01);
savings    = startSalary*(investRatePct*0.01);
years      = 2;
limit      = 1000000;

%Loop through the years until savings limit is reached.
while(savings(years - 1) < limit)
    salary(years)     = salary(years - 1)*(1 + (raisePct*0.01));
    investment(years) = salary(years)*(investRatePct*0.01);    
    savings(years)    = savings(years-1)*(1 + (growthRatePct*0.01)) + investment(years);
    years             = years + 1;    
end

%Visualize.
figure,
subplot(3,1,1);bar(1:years-1,salary);         ylabel('Salary');    xlabel('Years'); grid on;
subplot(3,1,2);bar(1:years-1,investment,'r'); ylabel('Investment');xlabel('Years'); grid on;
subplot(3,1,3);bar(1:years-1,savings,'g');    ylabel('Savings');   xlabel('Years'); grid on;

xlswrite('myRetirementPlan',[salary; investment; savings]');
end