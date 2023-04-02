function [outputArg1] = system0TimeDomainf(timeVar,inputVar)
outputArg1 = inputVar - inputVar*exp((-(9*timeVar)/2))*(cosh((3*sqrt(5)*timeVar)/2) + (3*sqrt(5)*sinh((3*sqrt(5)*timeVar)/2))/5);
end

