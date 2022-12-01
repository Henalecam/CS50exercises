# TODO
from cs50 import get_int
while True:
    height = get_int("Choose the height of the pyramid:")
    # get_int also check if the input is not a int
    if height > 0 and height < 9:
        break  # Breaks the loop
for row in range(height):
    print(" " * (height - row - 1), end="")
    print("#" * (row + 1))  # + 1 to start from the first line
