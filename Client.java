/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package client;

/**
 *
 * @author dell
 */
import java.io.IOException;
import java.net.*;
public class Client {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        try{
        Socket s=new Socket("localhost",3000);
        System.out.println("connect client");
        }catch(Exception e) {}
    }
    
}
