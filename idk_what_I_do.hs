
main = do
    let a = sort (take 100000 [100000, 99999 ..])
    putStrLn (show (head a)) 

sort []           = []
sort (pivot:rest) = (sort [y | y <- rest, y < pivot]) ++ [pivot] ++ (sort [y | y <- rest, y >=pivot])
