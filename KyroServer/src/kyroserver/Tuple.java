package kyroserver;


import java.util.Objects;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author usuario
 */
class Tuple<T0, T1> {
    
    private final T0 var1;
    private final T1 var2;
    
    public Tuple(T0 var1, T1 var2){
        this.var1 = var1;
        this.var2 = var2;
    }
    
    public T0 first(){
        return var1;
    }
    
    public T1 second(){
        return var2;
    }
    
    @Override
    public boolean equals(Object e){
        if (e instanceof Tuple) {
            Tuple<Integer, Integer> tuple = ( Tuple<Integer, Integer> ) e;
            return (tuple.first ().equals ( first () ) && tuple.second ().equals ( second () ));
        }
        return false;
    }

    @Override
    public int hashCode () {
        int hash = 7;
        hash = 73 * hash + Objects.hashCode ( this.var1 );
        hash = 79 * hash + Objects.hashCode ( this.var2 );
        return hash;
    }
    
    @Override
    public String toString(){
        return String.format ( "(%s, %s)", var1.toString (), var2.toString () );
    }
    
}
