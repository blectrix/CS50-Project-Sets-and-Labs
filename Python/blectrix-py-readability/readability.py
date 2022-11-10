# TODO
from cs50 import get_string

# Promt user for text
text = get_string("Text: ")

# Declare variables
letter_count = 0
word_count = 1
sentence_count = 0

# Count number of letters, words and sentences
for i in text:
    if i.isalpha():
        letter_count += 1
    elif i == " ":
        word_count += 1
    elif i == "." or i == "!" or i == "?":
        sentence_count += 1

# Colman-Liau Index
index = 0.0588 * (letter_count/word_count*100) - 0.296 * (sentence_count/word_count*100) - 15.8

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade", round(index))