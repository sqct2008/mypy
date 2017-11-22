#mult_tuple_nest
x=(1,2,"abc")
print x
y=[x,(2,3)]
print y
print y*2
y+=["def",["xyz",10],(2,5,"ijk",[1,2,3]),"lmn"]
print y
#multi_assign
x,y,z=a,b,c=[(1,2,"a"),[3,4,(9,10)],{5,6,7}]
print x,y,z
print a,b,c
(d,e,(f,g))=(1,2,(3,4))
print d,e,f,g

