entrada = round(float(input()), 2);
valores = [[100.00, 0], [50.00, 0], [20.00, 0], [10.00, 0], [5.00, 0], [2.00, 0], [1.00, 0], [0.50, 0], [0.25, 0], [0.10, 0], [0.05, 0], [0.01, 0]]
i = 0;
while (entrada >= 0.01):
    if ((entrada - valores[i][0]) >= 0):
        entrada -= valores[i][0];
        valores[i][1] += 1;
        i += 1;
    else:
        i += 1;

i2 = 0;
while (i2 <= i):
    if (valores[i2][1] > 0):
        print("{} nota(s) de R$ {}".format(valores[i2][1], valores[i2][0]));
        i2 += 1;
    else:
        i2 += 1;