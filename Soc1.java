/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package soc1;

/**
 *
 * @author dell
 */
import java.io.IOException;
import java.net.*;
public class Soc1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        try{
        ServerSocket server=new ServerSocket(3000);
        Socket s=server.accept();
        System.out.println("connected server");
        }catch(Exception e) {}
    }
    
}
