/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package server;

import java.io.IOException;
import java.net.*;
import java.util.*;
import java.util.logging.*;

/**
 *
 * @author gustavo
 */
public class Server {

    ArrayList<Cliente> clientes = new ArrayList<>();

    public void answerUdp() {
        new Thread(() -> {
            try {
                DatagramSocket serverSocket = new DatagramSocket(2716);
                byte[] receivedData = new byte[1024];
                byte[] sentData;
                while (true) {
                    DatagramPacket received = new DatagramPacket(receivedData, receivedData.length);
                    serverSocket.receive(received);
                    String msg = new String(received.getData(), received.getOffset(), received.getLength());

                    InetAddress ip = received.getAddress();
                    int port = received.getPort();

                    msg += ". He is at " + ip + ":" + port;

                    String toClient = Inet4Address.getLocalHost().getHostAddress();

                    System.out.println("Found client: " + msg);

                    sentData = toClient.getBytes();

                    DatagramPacket sendPacket = new DatagramPacket(sentData, sentData.length, ip, port);
                    serverSocket.send(sendPacket);

                }
            } catch (SocketException ex) {
                Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
            } catch (IOException ex) {
                Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
            }

        }).start();
    }

    public void sendAllOthers(String msg, Cliente cli) {
        for (Cliente c : clientes) {
            if (cli == c)
                continue;
            c.sendMessage("Cliente " + cli.id + ": " + msg);
        }
    }

    ArrayList<Cliente> getAliveClientes() {
        ArrayList<Cliente> alives = new ArrayList<>();
        clientes.stream().filter((c) -> (!c.socket.isClosed())).forEachOrdered((c) -> {
            alives.add(c);
        });
        return alives;
    }

    public void connectTcp() {
        new Thread(() -> {
            try {
                ServerSocket servidor = new ServerSocket(2717);
                while (true) {
                    Socket cliente = servidor.accept();
                    clientes.add(new Cliente(cliente, cliente.getInetAddress(), this, clientes.size()));
                    clientes.get(clientes.size() - 1).setup();
                    System.out.println("Temos agora " + clientes.size());
                    clientes.get(clientes.size() - 1).sendMessage("Voce é o usuario numero " + (clientes.size() - 1));
                }
            } catch (IOException ex) {
                Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
            }
        }).start();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Server server = new Server();
        server.answerUdp();
        server.connectTcp();

    }

}
