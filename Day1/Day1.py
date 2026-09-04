def input_text():
    """Prompt the user to enter lines. Stop when they enter 'exit' (case‑insensitive)."""
    lines = []
    while True:
        line = input("Enter a line (or 'exit' to finish): ")
        if line.strip().lower() == "exit":
            break
        # If the user enters an empty line, we still accept it (it's a line with nothing)
        # but we can optionally warn; we'll just accept it.
        lines.append(line)
    # Join with newlines so we preserve line boundaries
    return "\n".join(lines)

def main():
    text = input_text()
    # If nothing was entered, we still have an empty string.
    
    # Count lines: number of newlines + 1 if text is non‑empty, else 0
    if text == "":
        lines = 0
    else:
        lines = text.count('\n') + 1
    
    # Split into words (by whitespace) – this discards newlines and multiple spaces,
    # but that's what the original C++ version did.
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