N = 100000;  % Cantidad de puntos a utilizar
Val = zeros(N, 1);
Dim = 3;  % Dimensión de la integral

% Número máximo de procesadores trabajando
parfor i = 1:N
    Val(i) = Integrate(0, 5, i, Dim, @Function1);
end

%%
real = pi*sqrt(pi)*(3/16);

f1 = figure(1);
clf
semilogx(1:N, real.*ones(N, 1), "--r", 1:N, Val, 'k')
legend("Valor real de $$J_1(3) = \frac{3\pi\sqrt{\pi}}{16}$$", ...
    'Interpreter','latex')
grid on

xlabel("Cantidad de puntos generados")
ylabel("Calculo de J_1(3)")

set(gca, "FontSize", 14, "FontName", "Serif")
ylim([-1, 7])
exportgraphics(f1, "J1vsN.png", "Resolution", 600)

%%

f2 = figure(2);
clf
err = abs(real - Val)/real;

loglog(1:N, 19./sqrt(1:N), "--r", 1:N, err, 'k')
ylabel("Error relativo")
xlabel("Cantidad de puntos generados")

dim = [.7 .4 .3 .5];
str = '$$\propto \frac{1}{\sqrt{N}}$$';
a = annotation('textbox', 'interpreter', 'latex', 'String', str, ...
    'EdgeColor', 'None', 'Position', dim, "FontSize", 16);
a.Color = "red";
grid on

set(gca, "FontSize", 14, "FontName", "Serif")
exportgraphics(f2, "ErrJ1vsN.png", "Resolution", 600)

