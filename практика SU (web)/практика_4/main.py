

def convertStr(s):

    try:
        ret = int(s)
    except ValueError:
        #Try float.
        ret = float(s)
    return ret


def check_number(number: int):   
    match number:
        case _ if 0 <= number <= 59:
            return "F"
        case _ if 60 <= number <= 69:
            return "D"
        case _ if 70 <= number <= 79:
            return "C"
        case _ if 80 <= number <= 89:
            return "B"
        case _ if 90 <= number <= 100:
            return "A"
      


n = input("сколько у вас баллов?: от 0-100 ")
number = convertStr(n)
print("оценка:", check_number(number))
