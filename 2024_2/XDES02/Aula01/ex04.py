salary = float(input("Provide your salary amount: "))

if salary < 1903.99:
    print("safe! 🙏")
elif salary <= 2826.65:
    print("7.5% 😐")
elif salary <= 3751.05:
    print("15% 😢")
elif salary <= 4664.68:
    print("22.5% 🤬")
else: print("27.5% ☠️")
