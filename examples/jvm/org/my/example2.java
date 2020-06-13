package org.my;
import java.io.IOException;

class Example2
{
    public static void main(String[] args) throws IOException
    {
        Example2.throwIOException();
    }

    public static void throwIOException() throws IOException
    {
        throw new IOException("Oops");
    }
}
