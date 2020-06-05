package org.agent;

import java.lang.instrument.ClassFileTransformer;

public class ClassPrinter implements ClassFileTransformer {
    public byte[] transform(ClassLoader loader,
                            String className,
                            Class<?> classBeingRedefined,
                            ProtectionDomain protectionDomain,
                            byte[] classfileBuffer) throws IllegalClassFormatException {
    System.out.println("Found class: " + className + " (" + classfileBuffer.length + " bytes)");
  }
