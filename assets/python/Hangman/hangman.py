# Name:
# Section: 
# 6.189 Project 1: Hangman template
# hangman_template.py

# Import statements: DO NOT delete these! DO NOT write code above this!
from random import randrange
from string import *

# -----------------------------------
# Helper code
# (you don't need to understand this helper code)
# Import hangman words

WORDLIST_FILENAME = "words.txt"

def load_words():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print "Loading word list from file..."
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r', 0)
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = split(line)
    print "  ", len(wordlist), "words loaded."
    print 'Enter play_hangman() to play a game of hangman!'
    return wordlist

# actually load the dictionary of words and point to it with 
# the words_dict variable so that it can be accessed from anywhere
# in the program
words_dict = load_words()


# Run get_word() within your program to generate a random secret word
# by using a line like this within your program:


def get_word():
    """
    Returns a random word from the word list
    """
    word=words_dict[randrange(0,len(words_dict))]
    return word



# end of helper code
# -----------------------------------


# CONSTANTS
MAX_GUESSES = 6

# GLOBAL VARIABLES 
secret_word = get_word()
letters_guessed = []

# From part 3b:
def word_guessed():
    '''
    Returns True if the player has successfully guessed the word,
    and False otherwise.
    '''
    global secret_word
    global letters_guessed
    
    flag = True
    
    for i in range(0,len(secret_word)):
        if not secret_word[i] in letters_guessed:
            flag = False
            
    return flag
    
    ####### YOUR CODE HERE ######
    #pass # This tells your code to skip this function; delete it when you
         # start working on this function


def print_guessed():
    '''
    Prints out the characters you have guessed in the secret word so far
    '''
    global secret_word
    global letters_guessed
    
    temp_list = []
    
    for i in range(0,len(secret_word)):
        if secret_word[i] in letters_guessed:
            temp_list.append(secret_word[i])
        else:
            temp_list.append('-')
    
    print_string = join(temp_list,"")
    
    return print_string
    
    ####### YOUR CODE HERE ######
    #pass # This tells your code to skip this function; delete it when you
         # start working on this function

def play_hangman():
    # Actually play the hangman game
    global secret_word
    global letters_guessed
    # Put the mistakes_made variable here, since you'll only use it in this function
    mistakes_made = 0
    
    print "I have a word in mind. Can you guess it?"
    
    while True:
        print "Enter the next character"
        char = raw_input()
        
        if char in letters_guessed:
            print "You have already guessed this character. Enter another character."
            continue
        
        letters_guessed.append(char)
        
        if char in secret_word:
            print "You guessed the letter correctly."
            print print_guessed()
        else:
            print "The character is not present in the word."
            print print_guessed()
            mistakes_made = mistakes_made+1
        
        if word_guessed():
            print "Congrats. You guessed the word."
            break
        
        if mistakes_made > MAX_GUESSES:
            print "The word was %s"%secret_word
            print "HANGMAN"
            break
    
    # Update secret_word. Don't uncomment this line until you get to Step 8.
    # secret_word  = get_word()

    ####### YOUR CODE HERE ######
    return None

play_hangman()
    
