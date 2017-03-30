/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kryoclient;

import com.esotericsoftware.kryo.Kryo;
import com.esotericsoftware.kryonet.Client;

/**
 * Classe KryoClient
 *
 * @author Gustavo Diel ( UDESC )
 */
public class KryoClient {

    /**
     * Construtor da classe KryoClient
     */
    public KryoClient () {
        
    }

    /**
     * @param args the command line arguments
     */
    public static void main ( String[] args ) {
        // TODO code application logic here
        Client cliente = new Client();
        Kryo kryo = cliente.getKryo ();
        kryo.register ( Tuple.class );
        cliente
        
    }

}
