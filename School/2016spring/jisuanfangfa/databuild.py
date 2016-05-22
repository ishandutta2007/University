# coding = utf-8

def data(n):
    h = 10 / n
    x = []
    y = []
    for i in range(0, n + 1):
        x.append(-5+i*h)
        y.append(1/(1+x[i]**2))
        print(x)
        print(y)

