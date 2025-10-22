figure(1)
title("J1")
histogram(J1(:, 1), 50)

%%
figure(2)
title("J2")
histogram(J2(:, 1), 50)

%%
f3 = figure(3);
title("J1/J2")
lm = fitlm(Dims, mean(J1)./mean(J2))
clf
hold on
    scatter(Dims, mean(J1)./mean(J2), "Filled", "MarkerFaceColor", "k")
    plot(Dims, Dims.*lm.Coefficients{2, 1} + lm.Coefficients{1, 1}, "--r")
hold off
xlabel("Grados de libertad")
ylabel("J1/J2")


str = ['y = ' num2str(lm.Coefficients{2, 1}) ' * x + ' ...
    num2str(lm.Coefficients{1, 1})];

a1 = annotation('textbox',[.2 .7 .6 .2], ...
    'String', str,'EdgeColor','none');

a2 = annotation('textbox',[.2 .6 .4 .2], ...
    'String', ['R^2 = ' num2str(lm.Rsquared.Ordinary)],'EdgeColor','none');

a1.FontName = "Serif";
a2.FontName = "Serif";
a1.FontSize = 14;
a2.FontSize = 14;
grid on

set(gca, "FontSize", 14, "FontName", "Serif")

exportgraphics(f3, "EquiEner.png", "Resolution", 600)
