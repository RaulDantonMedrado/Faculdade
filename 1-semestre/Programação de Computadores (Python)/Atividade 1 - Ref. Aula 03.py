HT = float(input("Horas trabalhadas por mês: "))
VH = float(input("Valor da hora Trabalhada: "))
PD = float(input("Percentual de desconto: "))


SB = HT * VH
TD = (PD / 100) * SB
SL = SB - TD

print("Horas trabalhadas:", HT)
print("Salario bruto:", SB)
print("Desconto:", PD)
print("Salario Liquido:", SL)