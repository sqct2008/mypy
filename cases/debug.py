def f():
    a=10
    def b():
        print a
    return b
c=f()
c()

