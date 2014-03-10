import datetime

class DayPattern:
    
    def __init__(self,day):
        self.day = day
        
    def matches(self,date):
        return self.day==date.day

class MonthPattern:
    
    def __init__(self,month):
        self.month = month
        
    def matches(self,date):
        return self.month==date.month
        
class YearPattern:
    def __init__(self,year):
        self.year = year
        
    def matches(self,date):
        return self.year==date.year
        

class WeekdayPattern:
    def __init__(self,weekday):
        self.weekday = weekday
    
    def matches(self,date):
        return self.weekday == date.weekday()

class LastWeekdayPattern:
    def __init__(self,weekday):
        self.weekday = weekday
        
    def matches(self,date):
        nextweek = date + datetime.timedelta(7)
        return self.weekday==date.weekday() and nextweek.month!=date.month

class CompositePattern:
    def __init__(self):
        self.patterns = []
    
    def add(self,pattern):
        self.patterns.append(pattern)
    
    def matches(self,date):
        for pattern in self.patterns:
            if not pattern.matches(date):
                return False
        return True

