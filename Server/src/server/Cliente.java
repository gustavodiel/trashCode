/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author gustavo
 */
public class Cliente {

    public Socket socket;
    private InetAddress ip;

    int id;

    Server server;

    boolean dead = false;

    public Cliente(Socket _socket, InetAddress _ip, Server _server, int _id) {
        this.socket = _socket;
        this.ip = _ip;
        this.server = _server;
        this.id = _id;
    }

    public void sendMessage(String msg) {
        new Thread(() -> {
            PrintWriter paraCliente = null;
            try {
                paraCliente = new PrintWriter(socket.getOutputStream());
                paraCliente.write(msg + "\n");
                paraCliente.flush();
            } catch (IOException ex) {
                this.onCloseConnection();
                Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
            }
        }).start();
    }

    private void scanMessage() {
        new Thread(() -> {
            while (true) {
                try {
                    BufferedReader inputCliente = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
                    String msg = inputCliente.readLine();
                    if (msg == null) {

                        this.onCloseConnection();
                        break;
                    }
                    // process msg
                    System.out.println(msg);
                    server.sendAllOthers(msg, this);
                    
                } catch (IOException ex) {
                    Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
                    dead = true;
                    this.onCloseConnection();
                    break;
                }
            }
        }).start();
    }

    void setup() {
        System.out.println("Nova conexão com o cliente via TCP "
                + this.ip.getHostAddress()
        );
        this.scanMessage();
    }

    private void onCloseConnection() {
        try {
            System.out.println("Cliente is dead");
            this.socket.close();
            server.clientes.remove(this);
        } catch (IOException ex) {
            Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
