def walk(c, i, path):
    print("i: %d, c[i]: %d" % (i, c[i]))
    print(path)

    if (i + 2) <= len(c) - 1 and c[i + 2] == 0:
        path.append(i+2)
        walk(c, i + 2, path)
    elif (i + 1) <= len(c) - 1 and c[i + 1] == 0:
        path.append(i+1)
        walk(c, i + 1, path)
    else:
        return

    

def jumpingOnClouds(c):
    path = []
    index = 0
    if c[index] == 0 and c[index + 2] == 0:
        path.append(index + 2)
        intermed = walk(c, index + 2, path)
    elif c[index] == 0 and c[index + 1] == 0:
        path.append(index + 1)
        intermed = walk(c, index + 1, path)
    else:
        intermed = walk(c, index, path)
    #print(path)
    result = len(path)
    return result



def main():
    c1 = list([0, 0, 0, 0, 1, 0])
    c2 = list([0, 0, 1, 0, 0, 1, 0])
    result1 = jumpingOnClouds(c1)
    result2 = jumpingOnClouds(c2)
    print("Result1 = %d" % (result1))
    print("Result2 = %d" % (result2))

if __name__ == '__main__':
    main()
