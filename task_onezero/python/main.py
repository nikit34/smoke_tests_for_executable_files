a = input()
print(a)
b = input()
print(b)


def split_line(l):
    l = l.replace("zerozero", "zero zero")\
        .replace("oneone", "one one")\
        .replace("zeroone", "zero one")\
        .replace("onezero", "one zero")
    return l.split()


a_sep = split_line(a)
b_sep = split_line(b)

if len(a_sep) > len(b_sep):
    print(">")

elif len(a_sep) < len(b_sep):
    print("<")

else:
    for a_item, b_item in zip(a_sep, b_sep):
        if a_item == "one" and b_item == "zero":
            print(">")
            break
        elif a_item == "zero" and b_item == "one":
            print("<")
            break
    else:
        print("=")
