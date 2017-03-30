function ler( prod )
	local status, valor = coroutine.resume(prod)
	return valor
end

function enviar( msg )
	coroutine.yield(msg)
end

function produtor( )
	return coroutine.create(function ( )
		while true do
			local x = io.read()
			enviar(x)
		end
	end)
end

function filtro( prod )
	return coroutine.create(function (  )
		local line = 1
		while true do 
			local x = ler(prod)
			x = string.format("%5d %s", line, x)
			enviar(x)
			line = line + 1
		end
	end)
end

function consumer( prod )
	while true do
		local x = ler(prod)
		io.write(x, "\n")
	end
end

consumer(filtro(produtor()))