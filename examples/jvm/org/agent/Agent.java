package org.agent;

import java.lang.instrument.Instrumentation;

class Agent {
  public static void premain(String args, Instrumentation instrumentation){
    ClassPrinter transformer = new ClassPrinter();
    instrumentation.addTransformer(transformer);
  }
}
