# detect the sentiment of a given tweet
import sys
import os
import json

import nltk
from nltk.corpus import sentiwordnet as swn

def main():
    # check if the file exists
    if len(sys.argv) != 2:
        print("Usage: python3 tough.py <tweet_file>")
        sys.exit(1)
    tweet_file = sys.argv[1]
    if not os.path.isfile(tweet_file):
        print("Error: file not found")
        sys.exit(1)
# hello
    # open the file
    with open(tweet_file, 'r') as f:
        # read the file
        data = f.read()
        # parse the json
        parsed = json.loads(data)
        # print the sentiment
        print(parsed['sentiment'])
