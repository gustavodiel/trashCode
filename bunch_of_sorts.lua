--[[local oi = "Meu nome é gustavo"
local tamLinha = 20
local title = "Teste"

print ("[ " .. ( "=" ):rep(tamLinha - 4 - math.floor(#title/2)) .. "[ " .. title .. " ]" .. ( "=" ):rep(tamLinha - 3 - math.floor(#title/2)) .. " ]" )

for i = 1, #oi, 2 do
    local text = oi:sub(i, #oi + 1 - i)
    if ( #text <= 1 ) then
        break
    end
    local space = (" "):rep( tamLinha - math.floor(#text/2))
    text =  ( "[" .. space .. text )
    print ( text .. space .. "]" )
end

foo = 10;
]]
function randomize( tab, s, e )
	local n = #tab
	for i = s + 1, e do
		local j , k = math.random(s, e), math.random(s, e)
		tab[j], tab[k] = tab[k], tab[j]
	end
	return tab
end

function isSorted( tab, comp, s, e )
	for i = s + 1, e do
		if not comp(tab[i-1], tab[i]) then
			return false
		end
	end
	return true
end

function bogosort( t, comp, s, e )
	while not isSorted(t, comp, s, e) do
		randomize(t, s, e)
	end
	return t
end



function oi(tbl, comp)
  local array_len = #tbl
  comp = comp or function(a, b) return a < b end
  for bound = 2, array_len do
    bogosort(tbl, comp, 1, bound)
  end
  for i = 1, array_len do
  	print(tbl[i])
  end
end

print "as"


