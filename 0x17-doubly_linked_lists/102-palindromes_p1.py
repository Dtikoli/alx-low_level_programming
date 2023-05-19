#!/usr/bin/python3

def is_Palin(mul):
    if str(mul) == "".join(reversed(str(mul))):
        return True
    else:
        return False

# Note: str(mul)[-1::-1]) == str(mul)[::-1] == "".join(reversed(str(mul)))
# You can simpy: return (str(mul) == str(mul)[::-1])


def seek_largest_palindrome():
    large_Pal = 0
    for i in range(999, 99, -1):
        for j in range(999, 99, -1):
            mul = i * j
            if (is_Palin(mul)) and mul > large_Pal:
                large_Pal = mul
    return(large_Pal)


print(seek_largest_palindrome())
