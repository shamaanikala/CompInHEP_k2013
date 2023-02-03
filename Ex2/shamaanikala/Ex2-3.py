# -*- coding: utf-8 -*-

# Computing Methods in HEP 
# Spring 2023
# Exercise 2.3

# Idea:
# Modify the solution 2 such that now take the last numerical values
# before the #Summary

import re
from functools import reduce

def summa(data):
    return reduce(lambda x,y: x+y, data)

def re_check_summary(row):
    if re.findall(r'#Summary',row):
        return True
    return False

def re_check_line(row):
    # [\|]? match the | character one or more times
    # capture a group () with:
    # \d+   : one or more numerals
    # \.    : a dot
    # \d+   : one or more numerals
    # Then after the group:
    # \s+   : one ore more whitespace characters
    # \|?   : zero or one |
    # $     : end of the string
    match = re.findall(r'[\|]?(\d+\.\d+)\s+\|?$',row)
    if match:
        return match[0]
    else:
        return None

def format_number(num):
    # Using the "Formatted String Literals" or f-strings
    # https://docs.python.org/3/tutorial/inputoutput.html
    num = float(num) # change the type
    #print(f"{num:.1f}")
    return f"{num:.1f}"

def find_luminosity_recorded(filename):
    inSummary = True
    datapoints = []
    with open(filename,'r') as t:
        for row in t:
            if inSummary:
                #print(row)
                if re_check_summary(row):
                    return datapoints
                r = re_check_line(row)
                if re_check_line(row):
                    #print(r)
                    datapoints.append(float(r))
    return datapoints

def find_luminosity_total(filename):
    inSummary = False
    with open(filename,'r') as t:
        for row in t:
            if not inSummary:
                if re_check_summary(row):
                    inSummary = True
            else:
                #print(row)
                r = re_check_line(row)
                if re_check_line(row):
                    return r
    return None

if __name__ == '__main__':
    data = find_luminosity_recorded('brilcalc.log')
    #print(data)
    lum = find_luminosity_total('brilcalc.log')
    print(f"Calculated total luminosity: {summa(data):.1f} fb^-1")
    # let's match the length of the output strings
    l = len('Calculated total luminosity:')
    if lum:
        value = format_number(lum)
        print(f'{"Recorded total uminosity:":<{l}} {value} fb^-1')