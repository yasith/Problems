months = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def leap_year(year):
    """Return if the year is a leap year"""
    if year % 4 == 0:
        if year % 100 == 0:
            if year % 400 == 0:
                return True
        else:
            return True
    return False

def get_days(month, year):
    if month == 2 and leap_year(year):
        return 29
    return months[month]

if __name__ == '__main__':
    days = 0
    sundays = 0
    for year in range(1900, 2001):
        for month in range(1, 13):
            for day in range(1, get_days(month, year)+1):
                if days % 7 == 6 and day == 1 and year >= 1901:
                    sundays += 1
                days += 1
                days %= 7
    print sundays
