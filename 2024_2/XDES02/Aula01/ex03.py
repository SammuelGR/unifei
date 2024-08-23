from datetime import datetime

pastDateStr = input("Type a past date (dd/mm/yyyy): ")

pastDate = datetime.strptime(pastDateStr, '%d/%m/%Y')

print(f'{str(pastDate.date())} was a {pastDate.strftime("%A")}')
