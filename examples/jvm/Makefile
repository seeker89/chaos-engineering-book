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
	javac org/my/AppMain.java
example1-run:
	java org.my.Example1
example1-bytecode:
	javap -c org.my.Example1

.PHONY: run run2 run3 example1-compile example1-run example1-bytecode
