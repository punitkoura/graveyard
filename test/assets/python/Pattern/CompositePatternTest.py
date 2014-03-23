import datetime
import unittest

from CompositePattern import CompositePattern,DayPattern,MonthPattern,YearPattern,LastWeekdayPattern

MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY,SUNDAY = range(0,7)

class DatePatternTest(unittest.TestCase):
    def testYearMatches(self):
        y = YearPattern(2004)
        d = datetime.date(2004,3,14)
        self.failUnless(y.matches(d))
    
    def testYearDoesntMatch(self):
        y = YearPattern(2003)
        d = datetime.date(2004,3,14)
        self.failIf(y.matches(d))
    
    def testCompositePatternMatches(self):
        c = CompositePattern()
        c.add(YearPattern(2004))
        c.add(MonthPattern(3))
        c.add(DayPattern(24))
        d = datetime.date(2004,3,24)
        self.failUnless(c.matches(d))
    
    def testLastThursdayMatches(self):
        c = CompositePattern()
        c.add(LastWeekdayPattern(THURSDAY))
        d = datetime.date(2014,2,27)    
        self.failUnless(c.matches(d))
    
    def testLastThursdayDoesntMatch(self):
        c = CompositePattern()
        c.add(LastWeekdayPattern(THURSDAY))
        d = datetime.date(2014,3,6)    
        self.failIf(c.matches(d))

def main():
    unittest.main()

if __name__ == '__main__':
    main()
