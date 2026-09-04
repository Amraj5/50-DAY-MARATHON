def input_text():
    lines = []
    while True:
        line = input("Enter a line (or 'exit' to finish): ")
        if line.strip().lower() == "exit":
            break
        lines.append(line)
    # Joining  with newlines so line boundaries can be preserved
    return "\n".join(lines)

def main():
    text = input_text()
    if text == "":
        lines = 0
    else:
        lines = text.count('\n') + 1 #chose this because the same logic was what I used in the c++ version
    
    words = text.split()
    wordcount = len(words)
    
    # Longest word
    if words:
        longest_word = max(words, key=len)
    else:
        longest_word = ""   # no words
    
    # Count digits
    number_of_digits = sum(1 for ch in text if ch.isdigit())
    
    # Total characters (including newlines and spaces)
    character_count = len(text)
    
    # Output
    print(f"Lines: {lines}")
    print(f"Words: {wordcount}")
    print(f"Characters: {character_count}")
    print(f"Digits: {number_of_digits}")
    print(f"Longest Word: {longest_word}")

if __name__ == "__main__":
    main()
