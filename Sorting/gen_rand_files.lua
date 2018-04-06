ord = io.open("ord.txt", "w")
desord = io.open("desord.txt", "w")
randF = io.open("rand.txt", "w")
igual = io.open("igual.txt", "w")

max = 100000
escritos = {}

for i = 0, max do
    ord:write(i, "\n")
    igual:write( 1, "\n")
    desord:write(max - i, "\n")
    rand = math.random(0, max)

    if not escritos[rand] then
        randF:write(rand, "\n")
        escritos[rand] = true
    else
        while escritos[rand] do
            if not escritos[rand] then
                escritos[rand] = true
                break
            else
                rand = math.random(0, max)
            end
        end
        randF:write(rand, "\n")
    end    
end

igual:close();
ord:close();
desord:close();
randF:close();
