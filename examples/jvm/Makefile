CFLAGS=-O0

all: FizzBuzzEnterpriseEdition/bin/FizzBuzzEnterpriseEdition

src:
	git clone https://github.com/EnterpriseQualityCoding/FizzBuzzEnterpriseEdition.git src

FizzBuzzEnterpriseEdition/bin/FizzBuzzEnterpriseEdition: src
	(cd src && ./gradlew assemble && ./gradlew build)
	unzip src/build/distributions/FizzBuzzEnterpriseEdition.zip

run:
	./FizzBuzzEnterpriseEdition/bin/FizzBuzzEnterpriseEdition

run2:
	java -classpath "./FizzBuzzEnterpriseEdition/lib/*" com.seriouscompany.business.java.fizzbuzz.packagenamingpackage.impl.Main

run3:
	javap -classpath "./FizzBuzzEnterpriseEdition/lib/*" -c com.seriouscompany.business.java.fizzbuzz.packagenamingpackage.impl.Main


example1-compile:
	javac ./org/my/example1.java
example1-run:
	java org.my.Example1
example1-bytecode:
	javap -c org.my.Example1
example1-agent:
	java -javaagent:./agent1.jar org.my.Example1

example2-compile:
	javac ./org/my/example2.java
example2-run:
	java org.my.Example2
example2-bytecode:
	javap -c org.my.Example2

.PHONY: run run2 run3 example1-compile example1-run example1-bytecode example2-compile example2-run example2-bytecode

agent1.jar: org/agent/Agent.java org/agent/ClassPrinter.java
	javac org/agent/Agent.java
	javac org/agent/ClassPrinter.java
	jar vcmf org/agent/manifest.mf agent1.jar org/agent
