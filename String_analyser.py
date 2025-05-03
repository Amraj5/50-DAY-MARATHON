import string
#A String analyser in Python

def analyse(s):
    digitCount =0
    spaceCount =0
    vowelCount =0
    punctCount =0
    
    consonantCount =0
    for c in s: 
        if  c.isdigit():
            digitCount+=1
        elif c.isspace():
            spaceCount+=1
        elif c.isalpha():
            c = c.lower()
            vowels ='aeiou'
            if c in vowels:
                vowelCount+=1
            else:
                consonantCount+=1
        if c in string.punctuation:
            punctCount+=1
    print(f"Total characters: {len(s)}")
    print(f"Vowels: {vowelCount}")
    print(f"Consonants: {consonantCount}")
    print(f"Digits: {digitCount}")
    print(f"Spaces: {spaceCount}")
    print(f"Puctuation: {punctCount}")
def main():
    print("How are you doing adventurer?\n")
    print("It is time to know the worth of your words in all five ramifications\n")
    print("The one at the beginning tells you the weight\n")
    print("The next one tells you the power of your spells\n")
    print("The following one tells you the weakness of your powers\n")
    print("The next one gives the light of your powers\n")
    print("The last gives you the evil that resides in you\n")
    text =input("Input your spells so we can know it's worth: ")
    analyse(text)
if __name__ == "__main__":
    main()


