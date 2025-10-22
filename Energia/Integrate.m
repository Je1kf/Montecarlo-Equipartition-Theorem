function S = Integrate(a, b, N, dim, f)
    S = 0;
    for i = 1:N
        S = S + f((b-a).*rand(dim, 1) + a);
    end
    S = (((b-a)^dim)/N)*S;
end