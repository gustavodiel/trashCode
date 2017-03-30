/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kyroserver;

import com.esotericsoftware.kryonet.Connection;
import com.esotericsoftware.kryonet.Listener;
import com.esotericsoftware.kryonet.Server;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author usuario
 */
public class ServerHandle {

    public static final int TCP_PORT = 2300;
    public static final int UDP_PORT = 2301;

    public void startServer () {
        
        try {
            Server server = new Server ();
            server.getKryo ().register ( Tuple.class );
            server.start ();

            server.bind ( TCP_PORT, UDP_PORT );
            server.addListener ( new Listener () {
                @Override
                public void received ( Connection connection, Object object ) {
                    System.out.println ( "Eitaaa" );
                    
                }

            } );
            System.out.println ( "Conectado!" );
        }
        catch ( IOException ex ) {
            Logger.getLogger ( ServerHandle.class.getName () ).log ( Level.SEVERE, null, ex );
        }
    }

}
