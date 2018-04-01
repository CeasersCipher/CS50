from cs50 import get_int
# import cs50
# from cs50 import * : don't do this. imports bad shit

def main():
    i = get_positive_int("Positive Integer: ")
    print(i)

def get_positive_int(prompt):
    while True:
        n = get_int(prompt) #cs50.get_int
        if n>=1:
            break
    return n


if __name__ == "__main__":
    main()