import matplotlib.pyplot as plt
import csv

words = []
counts = []

with open("word_freq.csv", "r") as f:
    next(f)
    for line in f:
        word, count = line.strip().split(',')
        words.append(word)
        counts.append(int(count))

plt.figure(figsize=(10, 5))
plt.bar(words[:10], counts[:10], color='orange')
plt.xlabel("Word")
plt.ylabel("Frequency")
plt.title("Top 10 Word Frequencies")
plt.tight_layout()
plt.show()
