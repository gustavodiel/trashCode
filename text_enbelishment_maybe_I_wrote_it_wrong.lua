for i = 0, 2 do
	local nome = io.read()
	local tam = #nome
	local coisas = ("-"):rep(math.floor((50-tam)/2))
	-- print ( "[ ".. coisas .. " [ " .. nome .. " ] " .. ( tam % 2 == 0 and "" or "-" ) .. coisas .. " ]")
	for i in string.gmatch(nome, "(.)") do
		print(i)
	end
	for i in string.gmatch(nome, "^Nome: (.*)") do
		print ( i )
	end
end
