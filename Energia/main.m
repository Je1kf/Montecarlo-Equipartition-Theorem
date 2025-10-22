n = 1000;  % Cantidad de veces que se calcula cada integral
N = 10000;  % Cantidad de números aleatorios que se usan para 
           % calcular las integrales

Dims = [1, 2, 3, 4, 5, 6];  % Dimensiones que se van a estudiar

J1 = zeros(n, length(Dims));
J2 = zeros(n, length(Dims));

for j = Dims
    for i = 1:n
        J1(i, j) = Integrate(0, 5, N, j, @Function1);
        J2(i, j) = Integrate(0, 5, N, j, @Function2);
    end
end

figure(1)
title("J1")
histogram(J1(:, 1))

figure(2)
title("J2")
histogram(J2(:, 1))

figure(3)
title("J1/J2")
lm = fitlm(Dims, mean(J1)./mean(J2))
clf
hold on
    scatter(Dims, mean(J1)./mean(J2), "Filled")
    plot(Dims, Dims.*lm.Coefficients{2, 1} + lm.Coefficients{1, 1})
hold off
