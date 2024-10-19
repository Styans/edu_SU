
try:
    hours = float(input("Enter Hours: "))
    rate = float(input("Enter Rate: "))
    res = float(0.0)

    if hours > 40:
        res = (40 * rate) + ((hours - 40) * (rate * 1.5))
    else:
        res = hours * rate

    print("Pay:",res)


except ValueError:
    print("Error, please enter numeric input")
