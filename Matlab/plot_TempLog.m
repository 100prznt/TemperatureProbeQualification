function plot_TempLog(DUT, Ref, Chamber)
%plot_TempLog Erzeugt einen Plot des Temperaturverlaufs
%   Dargestellt werden die erfassten Temperaturen vom DUT (Device under
%   Test), der Referenz und der Kammer (Ofen oder Blockkalibrator). Alle
%   Temperaturen müssen in °C übergeben werden.


figure;
set(gcf, 'Position',  [100, 100, 1500, 800])
hold;

title('Temperaturverlauf')
ylabel('T [°C]')
xlabel('Samples')

ax = gca;
ax.YGrid = 'on';
ax.YMinorGrid = 'on';
ax.XGrid = 'on';

plot(DUT);
plot(Ref);
plot(Chamber);

legend({'DUT_1','Reference','Chamber'}, 'Location', 'northwest')


end

