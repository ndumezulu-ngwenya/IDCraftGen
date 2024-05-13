# IDCraftGen
I've developed a Qt Graphical User Interface (GUI) application that calculates a unique ID and a secure initial key for a new user based on their full name. The application adheres to the following specifications for generating the unique ID and the initial key.

Unique ID Generation Rules:
•
The unique ID should be 6 characters long.
•
The first two characters are the uppercase initials of the first and last names. If there is a middle name, use the initial of the middle name as the second character instead of the last name.
•
The remaining four characters are numeric, representing the count of letters in the full name (excluding spaces). If this count is less than 4 digits, pad the number with leading zeros to make it 4 digits.
Initial Key Generation Rules:
•
The initial key should consist of 6 characters randomly selected from the user's full name.
•
The selection should ensure that at least one character is a vowel (a, e, i, o, u), and at least one character is a consonant.
•
No spaces are allowed in the initial key, and all characters should be in lowercase.
