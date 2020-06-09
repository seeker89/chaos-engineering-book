package org.agent;

import java.lang.instrument.ClassFileTransformer;
import java.lang.instrument.IllegalClassFormatException;
import java.security.ProtectionDomain;


class ClassInjector implements ClassFileTransformer {

    public String targetClassName = "com/seriouscompany/business/java/fizzbuzz/packagenamingpackage/impl/strategies/SystemOutFizzBuzzOutputStrategy";

    public byte[] transform(ClassLoader loader,
                            String className,
                            Class<?> classBeingRedefined,
                            ProtectionDomain protectionDomain,
                            byte[] classfileBuffer) throws IllegalClassFormatException {
    if (className.equals(this.targetClassName)){
      System.out.println("TARGET ACQUIRED: " + className + " (" + classfileBuffer.length + " bytes)");
    }
    return classfileBuffer;
  }
}
