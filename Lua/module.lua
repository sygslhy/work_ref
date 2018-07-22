-- 文件名为 module.lua
-- 定义一个名为 module 的模块
module = {}
module.constant = "sunyuan"
function module.func1()
    io.write("这是一个公有函数！\n")
end

local function func2()
    print("这是一个私有函数！")
end

function module.func3()
    func2()
end


function module.add(x, y)
	return x+y
end

return module
