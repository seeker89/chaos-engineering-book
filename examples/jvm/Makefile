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

.PHONY: run run2
