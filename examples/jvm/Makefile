CFLAGS=-O0

all: FizzBuzzEnterpriseEdition/bin/FizzBuzzEnterpriseEdition byteman-download-4.0.11 byte-monkey.jar

src:
	git clone https://github.com/EnterpriseQualityCoding/FizzBuzzEnterpriseEdition.git src

byteman-download-4.0.11:
	wget https://downloads.jboss.org/byteman/4.0.11/byteman-download-4.0.11-bin.zip
	unzip byteman-download-4.0.11-bin.zip
	rm byteman-download-4.0.11-bin.zip

byte-monkey.jar:
	wget https://github.com/mrwilson/byte-monkey/releases/download/1.0.0/byte-monkey.jar

FizzBuzzEnterpriseEdition/bin/FizzBuzzEnterpriseEdition: src
	(cd src && ./gradlew assemble && ./gradlew build)
	unzip src/build/distributions/FizzBuzzEnterpriseEdition.zip

run:
	./FizzBuzzEnterpriseEdition/bin/FizzBuzzEnterpriseEdition

run2:
	java -classpath "./FizzBuzzEnterpriseEdition/lib/*" com.seriouscompany.business.java.fizzbuzz.packagenamingpackage.impl.Main

run3:
	javap -classpath "./FizzBuzzEnterpriseEdition/lib/*" -c com.seriouscompany.business.java.fizzbuzz.packagenamingpackage.impl.Main

run4:
	java -javaagent:./agent1.jar -classpath "./FizzBuzzEnterpriseEdition/lib/*" com.seriouscompany.business.java.fizzbuzz.packagenamingpackage.impl.Main

run5:
	java -javaagent:./agent2.jar -classpath "./FizzBuzzEnterpriseEdition/lib/*" com.seriouscompany.business.java.fizzbuzz.packagenamingpackage.impl.Main

run6:
	java \
		-javaagent:./byteman-download-4.0.11/lib/byteman.jar=script:throw.btm \
		-classpath "./FizzBuzzEnterpriseEdition/lib/*" \
		com.seriouscompany.business.java.fizzbuzz.packagenamingpackage.impl.Main

run7:
	java \
		-javaagent:byte-monkey.jar=mode:fault,rate:0.5,filter:com/seriouscompany/business/java/fizzbuzz/packagenamingpackage/impl/strategies/SystemOutFizzBuzzOutputStrategy/output \
		-classpath "./FizzBuzzEnterpriseEdition/lib/*" \
		com.seriouscompany.business.java.fizzbuzz.packagenamingpackage.impl.Main



example1-compile:
	javac ./org/my/Example1.java
example1-run:
	java org.my.Example1
example1-bytecode:
	javap -c org.my.Example1
example1-agent:
	java -javaagent:./agent1.jar org.my.Example1

example2-compile:
	javac ./org/my/Example2.java
example2-run:
	java org.my.Example2
example2-bytecode:
	javap -c org.my.Example2

.PHONY: run run2 run3 example1-compile example1-run example1-bytecode example2-compile example2-run example2-bytecode

agent1.jar: org/agent/Agent.java org/agent/ClassPrinter.java org/agent/manifest.mf
	javac org/agent/Agent.java
	javac org/agent/ClassPrinter.java
	jar vcmf org/agent/manifest.mf agent1.jar org/agent

agent2.jar: org/agent2/Agent.java org/agent2/ClassInjector.java org/agent2/manifest.mf
	javac -XDignore.symbol.file org/agent2/Agent.java
	javac -XDignore.symbol.file org/agent2/ClassInjector.java
	jar vcmf org/agent2/manifest.mf agent2.jar org/agent2
