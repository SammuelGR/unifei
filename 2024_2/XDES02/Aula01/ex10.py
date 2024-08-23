from datetime import datetime, timedelta

def timeToSeconds(timeStr: str):
	timeStamp = datetime.strptime(timeStr, '%H:%M:%S')
	totalSeconds = (timeStamp.hour * 60 * 60) + (timeStamp.minute * 60) + timeStamp.second

	return totalSeconds


def secondsToTime(totalSeconds: int):
	seconds = totalSeconds % 60
	minutes = int(((totalSeconds - seconds) / 60) % 60)
	hours = int((totalSeconds - (minutes * 60) - seconds) / (60 * 60))

	return f"{hours:02}:{minutes:02}:{seconds:02}"

checkInTime = input("Check-in time (HH:MM:ss): ")
checkOutTime = input("Check-out time (HH:MM:ss): ")

checkInSeconds = timeToSeconds(checkInTime)
checkOutSeconds = timeToSeconds(checkOutTime)

elapsedTime = secondsToTime(checkOutSeconds - checkInSeconds)

print(f"Elapsed time was: {elapsedTime}")
