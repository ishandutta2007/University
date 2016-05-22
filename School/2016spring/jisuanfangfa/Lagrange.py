# coding = utf-8

def data(n):
    h = 10 / n
    for i in range(0, n + 1):
        x = (-5+i*h)
        y = (1/(1+x**2))
        print(x)
        print(y)

def Lagrange(n):
    xk = []
    yk = []
    # T = [0.75, 1.75, 2.75, 3.75, 4.75]
    T = [-0.95, -0.05, 0.05, 0.95]
    h = 2 / n
    for i in range(0,n+1):
        xk.append(-1+i*h)
        yk.append(2.71828182846**xk[i])
    print(xk)
    print(yk)
    for x in T:
        y = 0.0
        # x = float(input())
        for k in range(0,n+1):
            l = 1.0
            for i in range(0,n+1):
                if i != k:
                    l *= (x-xk[i])/(xk[k]-xk[i])
            y += l*yk[k]
        print(x, y)
    # return x, y