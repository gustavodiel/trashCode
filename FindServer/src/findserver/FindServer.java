/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package findserver;

import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.util.logging.*;

/**
 *
 * @author gustavo
 */
public class FindServer {

    boolean isTryingToConnect = true;

    Socket socket;

    InetAddress getServerAt(int port) {
        try {
            InetAddress retIp = InetAddress.getLocalHost();
            try {
                DatagramSocket clientSocket = new DatagramSocket();
                /*    -> Broadcast Idiota
                NetworkInterface networkInterface = NetworkInterface.getByInetAddress(Inet4Address.getLocalHost());
                String myIpAndMask = Inet4Address.getLocalHost().getHostAddress() + "/" + networkInterface.getInterfaceAddresses().get(1).getNetworkPrefixLength();
                SubnetUtils netUtils = new SubnetUtils(myIpAndMask);
                for (String ip : netUtils.getInfo().getAllAddresses()) {
                    InetAddress IPAddress = InetAddress.getByName(ip);
                    byte[] sendData = new byte[1024];
                    String sentence = "Hello from " + Inet4Address.getLocalHost().getHostAddress();
                    

                    sendData = sentence.getBytes();
                    DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 2716);
                    clientSocket.send(sendPacket);
                    
                    break;
                }
                 */
                String ip = "255.255.255.255";
                InetAddress IPAddress = InetAddress.getByName(ip);
                byte[] sendData = new byte[1024];
                String sentence = "Hello from " + Inet4Address.getLocalHost().getHostAddress();

                sendData = sentence.getBytes();
                DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 2716);

                clientSocket.send(sendPacket);

                byte[] receiveData = new byte[1024];
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                clientSocket.receive(receivePacket);
                String modifiedSentence = new String(receivePacket.getData(), receivePacket.getOffset(), receivePacket.getLength());
                retIp = InetAddress.getByName(modifiedSentence);
                clientSocket.close();

            } catch (SocketException ex) {
                Logger.getLogger(FindServer.class.getName()).log(Level.SEVERE, null, ex);
                System.out.println("Vesh1");
            } catch (UnknownHostException ex) {
                Logger.getLogger(FindServer.class.getName()).log(Level.SEVERE, null, ex);
                System.out.println("Vesh2");
            } catch (IOException ex) {
                Logger.getLogger(FindServer.class.getName()).log(Level.SEVERE, null, ex);
                System.out.println("Vesh3");
            }

            return retIp;
        } catch (UnknownHostException ex) {
            Logger.getLogger(FindServer.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("Vesh4");
        }
        return null;
    }

    private void listenMessage() {
        new Thread(() -> {
            try {
                BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                while (true) {

                    String answer = input.readLine();
                    System.out.println(answer);

                }
            } catch (IOException ex) {
                Logger.getLogger(FindServer.class.getName()).log(Level.SEVERE, null, ex);
            }
        }).start();
    }

    private void sendMessage() {
        new Thread(() -> {
            while (true) {
                PrintStream saida = null;
                try {
                    saida = new PrintStream(socket.getOutputStream());
                    Scanner teclado = new Scanner(System.in);
                    while (teclado.hasNextLine()) {
                        saida.println(teclado.nextLine());
                    }
                } catch (IOException ex) {
                    Logger.getLogger(FindServer.class.getName()).log(Level.SEVERE, null, ex);
                } finally {
                    saida.close();
                }
            }
        }).start();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            FindServer client = new FindServer();
            InetAddress ip = client.getServerAt(2716);
            System.out.println("Found server at " + ip);

            client.socket = new Socket(ip, 2717);
            client.listenMessage();
            client.sendMessage();
            System.out.println("O cliente se conectou ao servidor!");
        } catch (IOException ex) {
            Logger.getLogger(FindServer.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

}
