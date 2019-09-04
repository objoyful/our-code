def unicode():
    try:
        key = input("Type a key to convert to unicode. ")
        unicode_value = ord(key)

        print(f""""{key}" in Unicode is {unicode_value}.""")
    
    except TypeError:
        if len(key) != 1:
            print("You can only type one character.")
        else:
            print("Type Error")
        unicode()

unicode()

while(1):
    again = input("Would you like to do it again? (Y, n) ")

    if again == 'Y':
        unicode()
        continue
    elif again == 'n':
        print("Ok, aborting.")
        break
    else:
        print("Abort.")
        break