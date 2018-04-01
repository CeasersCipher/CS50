from cs50 import get_int

#half pyramid recreated using hashes
#integer no greater than 23(and not negative)
#bottom left aligned with left-hand edge
def main():

    # prompt user for integer no greater than 23 and not negative
    while True:
        pyramid = get_int("Height: ")
        if pyramid <= 23 and pyramid >= 0:
            break

    # loop through each value in range chosen
    for i in range(pyramid):
        # prints white space
        for j in range(pyramid - i - 1):
            print(" ", end = "")

        # prints hashtags
        for k in range(i+2):
            print("#", end = "")
        print("")



if __name__ == "__main__":
    main()