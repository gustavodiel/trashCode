/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kyroserver;

/**
 *
 * @author usuario
 */
public class KyroServer {

    /**
     * @param args the command line arguments
     */
    public static void main ( String[] args ) {
        // TODO code application logic here
        ServerHandle sh = new ServerHandle ();
        sh.startServer ();
        
    }
    
}
