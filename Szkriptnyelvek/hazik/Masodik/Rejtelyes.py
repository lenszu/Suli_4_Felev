def decoder():
    TEXT = """
Cbcq Dgyk!

Dmeybh kce cew yrwyg hmrylyaqmr
rylsjb kce y Nwrfml npmepykmxyqg lwcjtcr!

Aqmimjjyi

Ynyb
    """

    print(TEXT)

    alphabet2 = "abcdefghijklmnopqrstuvwxyzabABCDEFGHIJKLMNOPQRSTUVWXYZAB"
    decoded_TEXT = ""

    for character in TEXT:
        index = alphabet2.find(character)
        if character == alphabet2[index]:
            decoded_TEXT += alphabet2[index + 2]
        if index == -1:
            decoded_TEXT += character
    print(decoded_TEXT)


def main():
    decoder()


if __name__ == '__main__':
    main()
