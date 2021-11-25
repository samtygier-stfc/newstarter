#!/usr/bin/env python3
import sys
from collections import Counter

PUNCTUATION = ".,?'\"!():"

def main():
	count = Counter()
	fname = sys.argv[1]

	for line in open(fname):
		line = line.replace("-", " ").lower()
		for c in PUNCTUATION:
			line = line.replace(c, "")
		words = line.split()
		for word in words:
			if len(word) > 4:
				count[word] += 1

	to_sort = [(v,k) for k,v in count.items()]

	print("Word\tUsage")
	for c, w in sorted(to_sort, reverse=True):
		print(f"{w}\t{c}")



if __name__ == "__main__":
	main()
