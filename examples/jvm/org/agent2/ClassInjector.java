package org.agent2;

import java.io.IOException;
import java.util.List;

import java.lang.instrument.ClassFileTransformer;
import java.lang.instrument.IllegalClassFormatException;
import java.security.ProtectionDomain;

import jdk.internal.org.objectweb.asm.ClassReader;
import jdk.internal.org.objectweb.asm.ClassWriter;
import jdk.internal.org.objectweb.asm.tree.*;
import jdk.internal.org.objectweb.asm.Opcodes;


public class ClassInjector implements ClassFileTransformer {

    public String targetClassName = "com/seriouscompany/business/java/fizzbuzz/packagenamingpackage/impl/strategies/SystemOutFizzBuzzOutputStrategy";

    public byte[] transform(ClassLoader loader,
                            String className,
                            Class<?> classBeingRedefined,
                            ProtectionDomain protectionDomain,
                            byte[] classfileBuffer) throws IllegalClassFormatException {
    if (className.equals(this.targetClassName)){
      System.err.println("[CHAOS] TARGET ACQUIRED: " + className + " (" + classfileBuffer.length + " bytes)");

      ClassNode classNode = new ClassNode();
      new ClassReader(classfileBuffer).accept(classNode, 0);
      classNode.methods.stream()
        .filter(method -> method.name.equals("output"))
        .forEach(method -> {
          InsnList instructions = new InsnList();
          instructions.add(new MethodInsnNode(
              Opcodes.INVOKESTATIC,
              "org/agent2/ClassInjector",
              "throwIOException",
              "()V",
              false // not a method
          ));
          method.maxStack += 1;
          method.instructions.insertBefore(method.instructions.getFirst(), instructions);
          System.err.println("[CHAOS] Method " + method.name + " modified");
        });
        final ClassWriter classWriter = new ClassWriter(0);
        classNode.accept(classWriter);
        byte[] bytes = classWriter.toByteArray();
        System.err.println("[CHAOS] Rewrote: " + className + " (" + bytes.length + " bytes)");
        return bytes;
    }
    return classfileBuffer;
  }

  public static void throwIOException() throws IOException
  {
      System.err.println("[CHAOS] BOOM! Throwing");
      throw new IOException("CHAOS");
  }
}
