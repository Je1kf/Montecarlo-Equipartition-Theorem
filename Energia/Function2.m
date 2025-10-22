function f2 = Function2(X)
    f = 0;
    for i = 1:length(X)
        f = f + (X(i)^2);
    end
    f2 = exp(-f);
end