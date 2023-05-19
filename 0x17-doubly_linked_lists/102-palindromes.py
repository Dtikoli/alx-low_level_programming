#!/usr/bin/python3
def is_Palin(mul):
    return (str(mul) == str(mul)[::-1])


def seek_largest_palindrome():
    return max([i * j for i in range(999, 99, -1) for j in range(999, 99, -1)
               if is_Palin(i * j)])


print(seek_largest_palindrome())
