--print("Hello world")
print("lhy wrl")
a = 1
b = 2
str = string.format("a:%d\n", a)
print(str)
c = a+b
str = string.format("a:%f\n", a)
print(str)

if(a~=1) then
	print("good")
else
	print("bad")
end

n=1
sum=0
while(n<=100)
do
	sum=sum+n
	n=n+1
end
print(sum)

for i=1,10 do
	print(i)
end

list = {1,2,3,4,5}
for i,v in pairs(list)
do
	str = string.format("(%d,%d)\n", i, v)
	print(str)
end
print("---------")
n=1
repeat
	print(n)
	n=n+1
until(n>10)

function max(num1, num2)
	if(num1>num2) then
		return num1
	else
		return num2
	end
end
a = max(2,1)
print(a)

array = {}
for i=1,3 do
   array[i] = {}
	for j=1,3 do
		array[i][j] = i*j
	end
end

for i=1,3 do
	for j=1,3 do
		print(array[i][j])
	end
end


print("*******")
function square(iteratorMaxCount,currentNumber)
   if currentNumber<iteratorMaxCount
   then
      currentNumber = currentNumber+1
   return currentNumber, currentNumber*currentNumber
   end
end

for i,n in square,3,0
do
   print(i,n)
end


mytable = {}
mytable[1]= "Lua"
str = string.format("%s\n", mytable[1])
print(str)
mytable = nil


require("module")

print(module.constant)

module.func3()

require("module")


local m = require("module")
print(m.constant)
