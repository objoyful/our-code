def Cipher(input_string, encode_decode=0):
    """
    Codes or decodes given first input string according to the second input.
    If the second input is 0, it encodes the string.
    If the second input is 1, it decodes the string.

    output_string = Cipher(input_string, encode_decode)

    Inputs:
    input_string: The string to be encoded or decoded.
    encode_decode: 0 for encoding, 1 for decoding.
    
    Outputs:
    output_string: The encoded or decoded string.
    
    William Carden Cipher function
    EGR 101-02
    Due Date: 04/03/2025
    """

    # Change the string to lowercase
    input_string = input_string.lower()

    # Create encoding dictionary
    encoding = {
        'a': 'y', 'b': 'v', 'c': 'm', 'd': 'k', 'e': 'c', 'f': 'u', 'g': 'd',
        'h': 'w', 'i': 'l', 'j': 'h', 'k': 'z', 'l': 'f', 'm': 'x', 'n': 'e',
        'o': 'a', 'p': 'q', 'q': 'j', 'r': 'n', 's': 'i', 't': 'b', 'u': 'r',
        'v': 'g', 'w': 't', 'x': 'p', 'y': 's', 'z': 'o'
    }

    # Create decoding dictionary
    decoding = {
        'y': 'a', 'v': 'b', 'm': 'c', 'k': 'd', 'c': 'e', 'u': 'f', 'd': 'g',
        'w': 'h', 'l': 'i', 'h': 'j', 'z': 'k', 'f': 'l', 'x': 'm', 'e': 'n',
        'a': 'o', 'q': 'p', 'j': 'q', 'n': 'r', 'i': 's', 'b': 't', 'r': 'u',
        'g': 'v', 't': 'w', 'p': 'x', 's': 'y', 'o': 'z'
    }

    output_string = "" # Create output string variable

    if encode_decode: # Decode the string
        for i in input_string:
            if i in encoding:
                output_string += decoding[i] # Add new string to output string
            else: # If the character is not a letter, such as a space
                output_string += i
    else: # Encode the string
        for i in input_string:
            if i in encoding:
                output_string += encoding[i] # Add new string to output string
            else: # If the character is not a letter, such as a space
                output_string += i
    
    return output_string