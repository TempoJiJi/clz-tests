reset

set grid
set key right
set xlabel 'N'
set ylabel 'time(ms)'
set style fill solid
set title 'clz performance'
#set xrange[0:250000]
set yrange[0:0.3]
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot "result_clz" using 1:2 with lp pt 9 lc rgb "blue" title "iteration",\
''using 1:3 with lp pt 1 lc rgb "red" title "recursion",\
''using 1:4 with lp pt 3 lc rgb "purple" title "harley",\
''using 1:5 with lp pt 5 lc rgb "green" title "binary_search",\
''using 1:6 with lp pt 7 lc rgb "orange" title "byte_shift"
