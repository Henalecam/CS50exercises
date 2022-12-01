# TODO
from cs50 import get_float

while True:
    money = get_float("Enter your money: ")
    money = round(money * 100)  # convert double(float 2 houses) to int

    if money > 0:
        coins = 0
        while money > 0:  # Domino effect getting the value lower and lower increasing coins
            if money >= 25:
                money -= 25
                coins += 1
            elif money >= 10:
                money -= 10
                coins += 1
            elif money >= 5:
                money -= 5
                coins += 1
            elif money >= 1:
                money -= 1
                coins += 1
        print(coins)
        break
