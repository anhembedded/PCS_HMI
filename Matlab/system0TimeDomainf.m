function [systemOut] = system0TimeDomainf(timeVar,pidOut)

systemOut = pidOut - pidOut*exp((-(9*timeVar)/2))*(cosh((3*sqrt(5)*timeVar)/2) + (3*sqrt(5)*sinh((3*sqrt(5)*timeVar)/2))/5);
end

