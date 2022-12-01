# TODO
from cs50 import get_string

# just a literal translate of C


def main():
    letters = 0
    words = 1
    sentences = 0
    text = get_string("Enter your text: ".lower())
    for char in text:  # Char actually becomes text[char]
        if char.isalpha():
            letters += 1
        if char == " ":
            words += 1
        if char == "." or char == "!" or char == "?":
            sentences += 1
        # To debug print(f"{sentences} sentences, {letters} letters, {words} words")
    lavg = (letters / words) * 100
    savg = (sentences / words) * 100
    index = round(0.0588 * lavg - 0.296 * savg - 15.8)
    if index >= 16:
        print("Grade 16+")
    elif index <= 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


main()
