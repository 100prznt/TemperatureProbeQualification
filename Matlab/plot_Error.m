function plot_Error(SP, Error)
%plot_TempLog Erzeugt einen Stem der Fehler an den Stützpunkten


figure;
set(gcf, 'Position',  [100, 100, 1500, 800])
hold;

title('Fehler')
ylabel('T_E_r_r_o_r [K]')
xlabel('T_S_e_t_p_o_i_n_t [°C]')

ax = gca;
ax.YGrid = 'on';
ax.YMinorGrid = 'on';
ax.XGrid = 'on';
xlim([-5 110]);
xticks(SP);

stem(SP, Error,'+r');


end

