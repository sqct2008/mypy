def g():
    print 1
g()

def f(x):
    print x
    def g():
        print 23
    g()
f(1)

def k(x):
    print x
    g()

k(4)

def f(x,y):
    print x,y
    return f
f(1,2)(3,4)

def g(x):
    print x
    return g
g(1)(2)(3)(4)(5)(6)(7)

def g(x):
    print x
    f(x,x)
    return g
g(1)(2)(3)

def h(x):
    print x
    def a(z):
        print z
    a(3)
h(2)
h(3)

a=h
a(4)

def f(x):
    z=35
    def y():
        c=z
        print c
    return y
f(2)
a=f(3)
a()

