inputCelsius = float(input("Celsius temp: "))
fahrenheit = ((9/5) * inputCelsius) + 32

print(f"{inputCelsius:.2f}°C = {fahrenheit:.2f}° F")

inputFahrenheit = float(input("Fahrenheit temp: "))
celsius = (inputFahrenheit - 32) * (5/9)

print(f"{inputFahrenheit:.2f}°F = {celsius:.2f}° C")
