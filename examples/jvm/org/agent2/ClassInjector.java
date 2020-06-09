package org.agent2;

import java.lang.instrument.ClassFileTransformer;
import java.lang.instrument.IllegalClassFormatException;
import java.security.ProtectionDomain;

import jdk.internal.org.objectweb.asm.ClassReader;
import jdk.internal.org.objectweb.asm.ClassWriter;
import jdk.internal.org.objectweb.asm.tree.*;


class ClassInjector implements ClassFileTransformer {

    public String targetClassName = "com/seriouscompany/business/java/fizzbuzz/packagenamingpackage/impl/strategies/SystemOutFizzBuzzOutputStrategy";

    public byte[] transform(ClassLoader loader,
                            String className,
                            Class<?> classBeingRedefined,
                            ProtectionDomain protectionDomain,
                            byte[] classfileBuffer) throws IllegalClassFormatException {
    if (className.equals(this.targetClassName)){
      System.out.println("TARGET ACQUIRED: " + className + " (" + classfileBuffer.length + " bytes)");

      ClassNode classNode = new ClassNode();
      new ClassReader(classFileBuffer).accept(classNode, 0);
      classNode.methods.stream()
        .filter(method -> method.name.equals("output"))
        .forEach(method -> {

          InsnList instructions = new InsnList();
          instructions.add(new MethodInsnNode(
              Opcodes.INVOKESTATIC,
              "org/agent2/ClassInjector",
              "output",
              "()Ljava/io/IOException;"
          ));
          method.maxStack += 1;
          method.instructions.insertBefore(
              method.instructions.getFirst(),
              instructions
          );
        });
        final ClassWriter classWriter = new ClassWriter(0);
        classNode.accept(classWriter);
        return classWriter.toByteArray();
    }
    return classfileBuffer;
  }

  public static void throwIOException() throws IOException
  {
      throw new IOException();
  }
}
