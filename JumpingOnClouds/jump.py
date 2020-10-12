

def jumpingOnClouds(c):
    path = []
    jumps = 0
    for index, cloud in enumerate(c):
        print("cloud[%d]: %d" % (index, cloud))
        if cloud == 1:
            if c[index + 1] == 0:
                path.append(index + 1)
                continue
            elif c[index + 1] == 1 and c[index + 2] == 0:
                path.append(index + 2)
                continue
        elif cloud == 0 and index > 0:
            newPath = set(path)
            if index in newPath:
                continue
            else:
                path.append(index)
                jumps += 1
            #print("cloud[%d]: %d" % (index, cloud))
    i = 0
    for x in path:
        #print("path[%d] = cloud[%d]" % (i, x))
        i += 1
    #print(path)
    return i

if __name__ == '__main__':
    n = 7
    c = [0, 0, 1, 0, 0, 1, 0]
    result = jumpingOnClouds(c)
    print("result: %d" % result)
