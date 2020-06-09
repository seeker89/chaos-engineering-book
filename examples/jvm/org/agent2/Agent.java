package org.agent2;

import java.lang.instrument.Instrumentation;

class Agent {
  public static void premain(String args, Instrumentation instrumentation){
    ClassInjector transformer = new ClassInjector();
    instrumentation.addTransformer(transformer);
  }
}
