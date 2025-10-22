function f1 = Function1(X)
    f = 0;
    for i = 1:length(X)
        f = f + (X(i)^2);
    end
    f1 = f.*exp(-f);
end